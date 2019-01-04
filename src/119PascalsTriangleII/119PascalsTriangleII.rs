impl Solution {
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut result = vec![0; (row_index+1) as usize];
        result[0] = 1;
        for i in 1..row_index+1 {
            for j in (0..i+1).rev() {
                let l = if j-1<0 {0} else {result[(j-1) as usize]};
                let r = if j>i-1 {0} else {result[j as usize]};
                result[j as usize] = l + r;
            }
        }
        result
    }
}
