use std::collections::VecDeque;
impl Solution {
    pub fn solve(board: &mut Vec<Vec<char>>) {
        let m = board.len(); if m==0 {return;}
        let n = board[0].len(); if n==0 {return;}
        
        let mut queue = VecDeque::new();
        for j in 0..m {
            if board[j][0] == 'O' { queue.push_back((0, j));}
            if n!=1 && board[j][n-1] == 'O' { queue.push_back((n-1, j)); }
        }
        for i in 1..n-1 {
            if board[0][i] == 'O' { queue.push_back((i, 0));}
            if m!=1 && board[m-1][i] == 'O' { queue.push_back((i, m-1));}
        }
        
        let offset_x:Vec<i32> = vec![-1, 1, 0, 0];
        let offset_y:Vec<i32> = vec![ 0, 0,-1, 1];
        while !queue.is_empty() {
            let (x, y) = queue.pop_front().unwrap();
            board[y][x] = 'Z';
            for d in 0..4 {
                let u:i32 = x as i32 + offset_x[d];
                let v:i32 = y as i32 + offset_y[d];
                if u>=0 && v>=0 && u<n as i32 && v<m as i32 && board[v as usize][u as usize] == 'O' {
                    queue.push_back((u as usize, v as usize));
                }
            }
        }
        
        for j in 0..m {
            for i in 0..n {
                if board[j][i] == 'O' {
                    board[j][i] = 'X';
                }else if board[j][i] == 'Z' {
                    board[j][i] = 'O';
                }
            }
        }
    }
}
