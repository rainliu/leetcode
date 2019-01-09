impl Solution {
    pub fn matrix_reshape(nums: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>> {
        let m = nums.len();
        if m==0 || r <= 0 || c <= 0 {return nums;}
        let n = nums[0].len();
        if (m*n) as i32 != r*c {return nums;}
        
        let mut result = vec![vec![0;c as usize]; r as usize];
        let mut k:usize = 0;
        for j in 0..r as usize {
            for i in 0..c as usize{
                result[j][i] = nums[k/n][k%n];
                k += 1;
            }
        }
        result
    }
}
