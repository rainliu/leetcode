package main

import "fmt"

func solve(board [][]byte) {
	n := len(board)
	if n == 0 {
		return
	}
	m := len(board[0])
	if m == 0 {
		return
	}
	visited := make([]bool, n*m)
	var q []int
	for i := 0; i < m; i++ {
		if board[0][i] == 'O' {
			q = append(q, 0*m+i)
		}
		if board[n-1][i] == 'O' {
			q = append(q, (n-1)*m+i)
		}
	}
	for j := 1; j < n-1; j++ {
		if board[j][0] == 'O' {
			q = append(q, j*m+0)
		}
		if board[j][m-1] == 'O' {
			q = append(q, j*m+m-1)
		}
	}
	offset_i := []int{-1, 1, 0, 0}
	offset_j := []int{0, 0, -1, 1}
	for len(q) != 0 {
		p := q[0]
		q = q[1:]
		if !visited[p] {
			visited[p] = true
			j := p / m
			i := p % m
			for k := 0; k < 4; k++ {
				x := i + offset_i[k]
				y := j + offset_j[k]
				if x >= 0 && x < m && y >= 0 && y < n && board[y][x] == 'O' && !visited[y*m+x] {
					q = append(q, y*m+x)
				}
			}
		}
	}
	for j := 0; j < n; j++ {
		for i := 0; i < m; i++ {
			if !visited[j*m+i] {
				board[j][i] = 'X'
			}
		}
	}
}

func main() {
	board := [][]byte{
		[]byte{'X', 'X', 'X', 'X'},
		[]byte{'X', 'O', 'O', 'X'},
		[]byte{'X', 'X', 'O', 'X'},
		[]byte{'X', 'O', 'X', 'X'},
	}
	solve(board)
	fmt.Printf("%v\n", board)
}
