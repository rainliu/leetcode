package main

func minimumTotal(triangle [][]int) int {
	n := len(triangle)
	if n == 0 {
		return 0
	}
	d := make([]int, n)
	for j := 0; j < n; j++ {
		for i := j; i >= 0; i-- {
			if j == 0 || i == 0 {
				d[i] += triangle[j][i]
			} else if i == j {
				d[i] = triangle[j][i] + d[i-1]
			} else {
				if d[i-1] < d[i] {
					d[i] = triangle[j][i] + d[i-1]
				} else {
					d[i] = triangle[j][i] + d[i]
				}
			}
		}
	}
	m := d[0]
	for i := 1; i < n; i++ {
		if d[i] < m {
			m = d[i]
		}
	}
	return m
}

func main() {

}
