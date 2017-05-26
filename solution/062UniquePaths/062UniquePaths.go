package main

import "fmt"

func uniquePaths(m int, n int) int {
	if m*n <= 0 {
		return 0
	}
	d := make([]int, m*n)
	for i := 0; i < m; i++ {
		d[i] = 1
	}
	for j := 1; j < n; j++ {
		d[j*m] = 1
	}
	for j := 1; j < n; j++ {
		for i := 1; i < m; i++ {
			d[j*m+i] = d[(j-1)*m+i] + d[j*m+i-1]
		}
	}
	return d[n*m-1]
}

func main() {
	fmt.Printf("%d\n", uniquePaths(4, 3))
}
