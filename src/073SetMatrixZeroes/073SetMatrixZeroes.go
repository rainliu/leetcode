package main

func setZeroes(matrix [][]int) {
	if matrix == nil {
		return
	}
	n := len(matrix)
	if n == 0 {
		return
	}
	m := len(matrix[0])
	if m == 0 {
		return
	}
	row := false
	for i := 0; i < m; i++ {
		row = row || (matrix[0][i] == 0)
	}
	col := false
	for j := 0; j < n; j++ {
		col = col || (matrix[j][0] == 0)
	}
	for j := 1; j < n; j++ {
		for i := 1; i < m; i++ {
			if matrix[j][i] == 0 {
				matrix[j][0] = 0
				matrix[0][i] = 0
			}
		}
	}
	for j := 1; j < n; j++ {
		if matrix[j][0] == 0 {
			for i := 1; i < m; i++ {
				matrix[j][i] = 0
			}
		}
	}
	for i := 1; i < m; i++ {
		if matrix[0][i] == 0 {
			for j := 1; j < n; j++ {
				matrix[j][i] = 0
			}
		}
	}
	if row {
		for i := 0; i < m; i++ {
			matrix[0][i] = 0
		}
	}
	if col {
		for j := 0; j < n; j++ {
			matrix[j][0] = 0
		}
	}
}

func main() {

}
