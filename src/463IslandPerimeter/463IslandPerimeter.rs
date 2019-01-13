impl Solution {
    pub fn island_perimeter(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        if m == 0 {return 0;}
        let n = grid[0].len();
        if n == 0 {return 0;}
        let mut result = 0;
        for j in 0..m {
            for i in 0..n {
                if grid[j][i]!=0 {
                    let top  = if j>0 && grid[j-1][i]==1 {1} else {0};
                    let left = if i>0 && grid[j][i-1]==1 {1} else {0};
                    let right= if i<n-1 && grid[j][i+1]==1 {1} else {0};
                    let bottom=if j<m-1 && grid[j+1][i]==1 {1} else {0};
                    result += 4-top-left-right-bottom;
                }     
            }
        }
        result
    }
}
