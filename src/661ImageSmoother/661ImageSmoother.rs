const dir_x:[i32;9] = [-1, 0, 1, -1, 0, 1, -1, 0, 1];
const dir_y:[i32;9] = [-1, -1, -1, 0, 0, 0, 1, 1, 1];
impl Solution {
    pub fn image_smoother(m: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let u = m.len();
        if u==0 {return m;}
        let v = m[0].len();
        let mut result = vec![vec![0;v];u];
        
        for y in 0..u {
            for x in 0..v {
                let mut sum = 0;
                let mut cnt = 0;
                for k in 0..9 {
                    let j = y as i32 +dir_y[k];
                    let i = x as i32 +dir_x[k];
                    if j >= 0 && j < u as i32 && i >= 0 && i < v as i32 {
                        sum += m[j as usize][i as usize];
                        cnt += 1;
                    }
                }
                result[y][x] = sum/cnt;
            }
        }
        result
    }
}
