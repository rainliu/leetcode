package main

func isValidSudoku(board [][]byte) bool {
	for j := 0; j < 9; j++ {
		m := make(map[byte]struct{})
		for i := 0; i < 9; i++ {
			if board[j][i] != '.' {
				if _, ok := m[board[j][i]]; ok {
					return false
				} else {
					m[board[j][i]] = struct{}{}
				}
			}
		}
	}
	for i := 0; i < 9; i++ {
		m := make(map[byte]struct{})
		for j := 0; j < 9; j++ {
			if board[j][i] != '.' {
				if _, ok := m[board[j][i]]; ok {
					return false
				} else {
					m[board[j][i]] = struct{}{}
				}
			}
		}
	}
	offset_x := []int{0, 3, 6, 0, 3, 6, 0, 3, 6}
	offset_y := []int{0, 0, 0, 3, 3, 3, 6, 6, 6}
	for k := 0; k < 9; k++ {
		m := make(map[byte]struct{})
		for j := 0; j < 3; j++ {
			for i := 0; i < 3; i++ {
				if board[offset_y[k]+j][offset_x[k]+i] != '.' {
					if _, ok := m[board[offset_y[k]+j][offset_x[k]+i]]; ok {
						return false
					} else {
						m[board[offset_y[k]+j][offset_x[k]+i]] = struct{}{}
					}
				}
			}
		}
	}
	return true
}

func main() {

}
