use std::collections::VecDeque;
impl Solution {
    pub fn walls_and_gates(rooms: &mut Vec<Vec<i32>>) {
        let m = rooms.len(); if m==0 {return;}
        let n = rooms[0].len(); if n==0 {return;}
        let mut queue = VecDeque::new();
        for j in 0..m {
            for i in 0..n {
                if rooms[j][i] == 0 {
                    queue.push_back((j, i));
                }
            }
        }
        let offset_x = vec![-1,1,0,0];
        let offset_y = vec![0,0,-1,1];
        while !queue.is_empty() {
            let (j, i) = queue.pop_front().unwrap();
            for d in 0..4 {
                let y = j as i32 + offset_y[d];
                let x = i as i32 + offset_x[d];
                if x>=0 && y>=0 && x<n as i32 && y<m as i32 && 
                   rooms[y as usize][x as usize ] == std::i32::MAX {
                    rooms[y as usize][x as usize ] = rooms[j][i]+1;
                    queue.push_back((y as usize, x as usize));
                }
            }
        }
    }
}
