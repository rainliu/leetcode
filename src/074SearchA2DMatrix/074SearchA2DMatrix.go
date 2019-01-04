package main

import "fmt"

func searchMatrixHelperRow(matrix [][]int, target int, lo, hi int) int {
	for lo <= hi {
		mi := lo + (hi-lo)/2
		if matrix[mi][0] == target {
			return mi
		} else if matrix[mi][0] < target {
			lo = mi + 1
		} else {
			hi = mi - 1
		}
	}
	return hi
}

func searchMatrixHelperCol(matrix [][]int, target int, lo, hi, row int) bool {
	for lo <= hi {
		mi := lo + (hi-lo)/2
		if matrix[row][mi] == target {
			return true
		} else if matrix[row][mi] < target {
			lo = mi + 1
		} else {
			hi = mi - 1
		}
	}
	return false
}

func searchMatrix(matrix [][]int, target int) bool {
	if matrix == nil || len(matrix) == 0 {
		return false
	}
	for i := 0; i < len(matrix); i++ {
		if len(matrix[i]) == 0 {
			return false
		}
	}
	mi := searchMatrixHelperRow(matrix, target, 0, len(matrix)-1)
	if mi >= 0 {
		return searchMatrixHelperCol(matrix, target, 0, len(matrix[mi])-1, mi)
	} else {
		return false
	}
}

func main() {
	fmt.Printf("%v\n", searchMatrix([][]int{
		[]int{1},
	}, 0))
}
