impl Solution {
    pub fn transpose(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m = a.len();
        let n = a[0].len();
        let mut result = vec![vec![0;m];n];
        for j in 0..m {
            for i in 0..n {
                result[i][j] = a[j][i];
            }
        }
        result
    }
}
