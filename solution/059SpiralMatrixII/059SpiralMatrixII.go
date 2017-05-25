package main

import "fmt"

func generateMatrix(n int) [][]int {
	if n <= 0 {
		return nil
	}
	var matrix [][]int
	for j := 0; j < n; j++ {
		m := make([]int, n)
		matrix = append(matrix, m)
	}
	k := 0
	N := n
	u := 0
	v := 0
	i := u
	j := v
	for k < n*n {
		for i < N {
			matrix[j][i] = k + 1
			i++
			k++
		}
		if k >= n*n {
			break
		}
		i--
		j++

		for j < N {
			matrix[j][i] = k + 1
			j++
			k++
		}
		if k >= n*n {
			break
		}
		i--
		j--

		for i >= u {
			matrix[j][i] = k + 1
			i--
			k++
		}
		if k >= n*n {
			break
		}
		i++
		j--

		for j >= v+1 {
			matrix[j][i] = k + 1
			j--
			k++
		}
		if k >= n*n {
			break
		}
		i++
		j++

		N--
		u++
		v++
	}
	return matrix
}

func main() {
	fmt.Printf("%v\n", generateMatrix(0))
	fmt.Printf("%v\n", generateMatrix(1))
	fmt.Printf("%v\n", generateMatrix(2))
	fmt.Printf("%v\n", generateMatrix(3))
	fmt.Printf("%v\n", generateMatrix(4))
}
