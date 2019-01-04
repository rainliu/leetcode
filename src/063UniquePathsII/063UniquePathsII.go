package main

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	if obstacleGrid == nil {
		return 0
	}
	n := len(obstacleGrid)
	if n == 0 {
		return 0
	}
	m := len(obstacleGrid[0])
	if m == 0 {
		return 0
	}
	d := make([]int, m*n)
	if obstacleGrid[0][0] == 1 {
		d[0] = 0
	} else {
		d[0] = 1
	}
	for i := 1; i < m; i++ {
		if obstacleGrid[0][i] == 1 {
			d[i] = 0
		} else {
			d[i] = d[i-1]
		}
	}
	for j := 1; j < n; j++ {
		if obstacleGrid[j][0] == 1 {
			d[j*m] = 0
		} else {
			d[j*m] = d[(j-1)*m]
		}
	}

	for j := 1; j < n; j++ {
		for i := 1; i < m; i++ {
			if obstacleGrid[j][i] == 1 {
				d[j*m+i] = 0
			} else {
				d[j*m+i] = d[(j-1)*m+i] + d[j*m+i-1]
			}
		}
	}
	return d[n*m-1]
}

func main() {

}
