impl Solution {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        let m = matrix.len() as i32;
        let n = matrix[0].len() as i32;
        for i in 0..n {
            for j in 1..=n-1-i {
                if j < m && matrix[j as usize][(i+j) as usize] != matrix[0][i as usize] {
                    return false;
                }
            }    
        }
        for j in 1..m {
            for i in 1..=m-1-j {
                if i < n && matrix[(i+j) as usize][i as usize] != matrix[j as usize][0] {
                    return false;
                }
            }  
        }
        true
    }
}

impl Solution2 {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        for j in 0..matrix.len() {
            for i in 0..matrix[0].len() {
                if i>0 && j>0 && matrix[j-1][i-1] != matrix[j][i] {
                    return false;
                }
            }
        }   
        true
    }
}
