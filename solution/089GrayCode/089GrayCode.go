package main

import "fmt"

func grayCode(n int) []int {
	if n < 0 {
		return nil
	} else if n == 0 {
		return []int{0}
	}
	results := make([]int, 1<<uint(n))
	for i := 1; i <= n; i++ {
		k := 1 << uint(i)
		for j := k >> 1; j < k; j++ {
			results[j] = results[k-1-j] | (1 << uint(i-1))
		}
	}
	return results
}

func main() {
	fmt.Printf("%v\n", grayCode(0))
	fmt.Printf("%v\n", grayCode(1))
	fmt.Printf("%v\n", grayCode(2))
	fmt.Printf("%v\n", grayCode(3))
}
