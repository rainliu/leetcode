package main

import (
	"fmt"
)

var direction_x = []int{-1, +1, 0, 0}
var direction_y = []int{0, 0, -1, +1}

func dfs(board [][]byte, word string, i, j, m, n int, visited []bool, pos int) bool {
	pos++
	visited[j*m+i] = true
	result := false
	if pos < len(word) && word[pos] == board[j][i] {
		if pos == len(word)-1 {
			return true
		} else {
			for k := 0; k < 4; k++ {
				if j+direction_y[k] >= 0 &&
					j+direction_y[k] < n &&
					i+direction_x[k] >= 0 &&
					i+direction_x[k] < m &&
					!visited[(j+direction_y[k])*m+i+direction_x[k]] {
					visited_clone := make([]bool, m*n)
					copy(visited_clone, visited)
					if dfs(board, word, i+direction_x[k], j+direction_y[k], m, n, visited_clone, pos) {
						return true
					}
				}
			}
		}
	} else {
		result = result || false
	}
	return result
}

func exist(board [][]byte, word string) bool {
	if board == nil {
		return false
	}
	n := len(board)
	if n == 0 {
		return false
	}
	m := len(board[0])
	if m == 0 {
		return false
	}
	for j := 0; j < n; j++ {
		for i := 0; i < m; i++ {
			visited := make([]bool, m*n)
			pos := -1
			if dfs(board, word, i, j, m, n, visited, pos) {
				return true
			}
		}
	}
	return false
}

func main() {
	fmt.Printf("%v\n", exist([][]byte{
		[]byte{'a', 'b'},
		[]byte{'c', 'd'},
	}, "acdb"))
}
