package main

import "fmt"

func spiralOrder(matrix [][]int) []int {
	if matrix == nil {
		return nil
	}
	M := len(matrix)
	if M == 0 {
		return nil
	}
	N := len(matrix[0])
	if N == 0 {
		return nil
	}
	result := make([]int, M*N)
	k := 0
	m := M
	n := N
	u := 0
	v := 0
	i := u
	j := v
	for k < M*N {
		for i < n {
			result[k] = matrix[j][i]
			i++
			k++
		}
		if k >= M*N {
			break
		}
		i--
		j++

		for j < m {
			result[k] = matrix[j][i]
			j++
			k++
		}
		if k >= M*N {
			break
		}
		i--
		j--

		for i >= u {
			result[k] = matrix[j][i]
			i--
			k++
		}
		if k >= M*N {
			break
		}
		i++
		j--

		for j >= v+1 {
			result[k] = matrix[j][i]
			j--
			k++
		}
		if k >= M*N {
			break
		}
		i++
		j++

		m--
		n--
		u++
		v++
	}

	return result
}

func main() {
	fmt.Printf("%v\n", spiralOrder([][]int{}))
	fmt.Printf("%v\n", spiralOrder([][]int{
		{1, 2, 3},
	}))
	fmt.Printf("%v\n", spiralOrder([][]int{
		{1, 2},
		{4, 5},
	}))
	fmt.Printf("%v\n", spiralOrder([][]int{
		{1, 2, 3},
		{4, 5, 6},
	}))
	fmt.Printf("%v\n", spiralOrder([][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}))
	fmt.Printf("%v\n", spiralOrder([][]int{
		{1, 2, 3, 4},
		{10, 11, 12, 5},
		{9, 8, 7, 6},
	}))
}
