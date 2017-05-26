package main

func minPathSum(grid [][]int) int {
	if grid == nil {
		return 0
	}
	n := len(grid)
	if n == 0 {
		return 0
	}
	m := len(grid[0])
	if m == 0 {
		return 0
	}
	sum := make([]int, m*n)
	sum[0] = grid[0][0]
	for i := 1; i < m; i++ {
		sum[i] = sum[i-1] + grid[0][i]
	}
	for j := 1; j < n; j++ {
		sum[j*m] = sum[(j-1)*m] + grid[j][0]
	}
	for j := 1; j < n; j++ {
		for i := 1; i < m; i++ {
			if sum[(j-1)*m+i] < sum[j*m+i-1] {
				sum[j*m+i] = sum[(j-1)*m+i] + grid[j][i]
			} else {
				sum[j*m+i] = sum[j*m+i-1] + grid[j][i]
			}
		}
	}
	return sum[m*n-1]
}

func main() {

}
