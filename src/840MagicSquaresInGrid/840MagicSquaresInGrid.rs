const dir_x:[usize;9] = [0,1,2,0,1,2,0,1,2];
const dir_y:[usize;9] = [0,0,0,1,1,1,2,2,2];

impl Solution {
    pub fn num_magic_squares_inside(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();  
        if m<3 {return 0;}
        let n = grid[0].len();
        if n<3 {return 0;}
        
        let mut result = 0;
        for j in 0..=m-3{
            for i in 0..=n-3{
                let mut subgrid = vec![0;10];
                let mut k = 0;
                while k < 9 {
                    let y = j+dir_y[k];
                    let x = i+dir_x[k];
                    if grid[y][x]>9 || grid[y][x]<1 || subgrid[grid[y][x] as usize]!=0{
                        break;
                    }else{
                        subgrid[grid[y][x] as usize] = 1;
                    }
                    k += 1;
                }
                if k==9 {
                    if  grid[j+0][i+0]+grid[j+0][i+1]+grid[j+0][i+2]==15 &&
                        grid[j+1][i+0]+grid[j+1][i+1]+grid[j+1][i+2]==15 &&
                        grid[j+2][i+0]+grid[j+2][i+1]+grid[j+2][i+2]==15 &&
                        grid[j+0][i+0]+grid[j+1][i+0]+grid[j+2][i+0]==15 &&
                        grid[j+0][i+1]+grid[j+1][i+1]+grid[j+2][i+1]==15 &&
                        grid[j+0][i+2]+grid[j+1][i+2]+grid[j+2][i+2]==15 &&
                        grid[j+0][i+0]+grid[j+1][i+1]+grid[j+2][i+2]==15 &&
                        grid[j+0][i+2]+grid[j+1][i+1]+grid[j+2][i+0]==15 {
                        result += 1;        
                    }
                }
            }
        }
        result
    }
}
