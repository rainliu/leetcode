impl Solution {
    pub fn surface_area(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len() as i32;
        if n==0 {return 0;}
        let m = grid[0].len() as i32;
        let mut sum = 0;
        for j in 0..n {
            for i in 0..m{
                sum += grid[j as usize][i as usize]*6;
                if grid[j as usize][i as usize] > 0 {
                    sum -= 2*(grid[j as usize][i as usize]-1);
                }
                if i < m-1 {
                    sum -= 2*std::cmp::min(grid[j as usize][i as usize], grid[j as usize][i as usize + 1]);
                }
                if j < n-1 {
                    sum -= 2*std::cmp::min(grid[j as usize][i as usize], grid[j as usize + 1][i as usize])
                }
            }
        }
        sum
    }
}
