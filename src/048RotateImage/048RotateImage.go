package main

import "fmt"

func rotate(matrix [][]int) {
	//row swap
	n := len(matrix)
	for j := 0; j < n/2; j++ {
		matrix[j], matrix[n-1-j] = matrix[n-1-j], matrix[j]
	}
	//diag swap
	for j := 0; j < n; j++ {
		for i := 0; i < j; i++ {
			matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i]
		}
	}
}

func main() {
	matrix := [][]int{
		[]int{1, 2, 3, 4},
		[]int{5, 6, 7, 8},
		[]int{9, 10, 11, 12},
		[]int{13, 14, 15, 16},
	}
	rotate(matrix)
	fmt.Printf("%v\n", matrix)
}
