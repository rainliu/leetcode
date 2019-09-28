use std::collections::VecDeque;
impl Solution {
    pub fn num_islands(grid: Vec<Vec<char>>) -> i32 {
        let m = grid.len(); if m==0 {return 0};
        let n = grid[0].len(); if n==0 {return 0};
        let mut grid = grid;
        let offset_x = vec![-1, 1,  0, 0];
        let offset_y = vec![ 0, 0, -1, 1];
        let mut queue: VecDeque<(i32, i32)> = VecDeque::new();
        let mut count = 0;
        for j in 0..m {
            for i in 0..n {
                if grid[j][i] == '1' {
                    count += 1;
                    grid[j as usize][i as usize] = '0';
                    queue.push_back((i as i32, j as i32));
                    while !queue.is_empty() {
                        let (u, v) = queue.pop_front().unwrap();                        
                        for d in 0..4 {
                            let y = v + offset_y[d];
                            let x = u + offset_x[d];
                            if y>=0 && x>=0 && y<m as i32 && x<n as i32 
                              && grid[y as usize][x as usize] == '1' {
                                grid[y as usize][x as usize] = '0';
                                queue.push_back((x as i32, y as i32));
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
}
