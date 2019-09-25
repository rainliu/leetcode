impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let mut n = matrix.len() as i32;
        if n == 0 {
            return vec![];
        }
        let mut m = matrix[0].len() as i32;
        if m == 0 {
            return vec![];
        }
        
        let mut result = vec![];
        
        let (mut u, mut v, mut k) = (0 as i32, 0 as i32, m*n);
        
        while k!= 0{
            let (mut i, mut j) = (u, v);
            while i < m && k != 0 { result.push(matrix[j as usize][i as usize]); i+=1; k-=1;}
            j+=1;i-=1; m-=1;
            while j < n && k != 0 { result.push(matrix[j as usize][i as usize]); j+=1; k-=1;}
            i-=1;j-=1; n-=1;
            while i >= u && k != 0 { result.push(matrix[j as usize][i as usize]); i-=1; k-=1;}
            j-=1;i+=1; v+=1;
            while j >= v && k != 0 { result.push(matrix[j as usize][i as usize]); j-=1; k-=1;}
            u+=1;
        }
        
        return result;
    }
}
