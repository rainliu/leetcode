impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        if n == 0 {
            return 1.0;
        }else if x == 0.0 {
            return 0.0;
        }else if n == std::i32::MIN {
            return 1.0/(Solution::my_pow(x, -(n+1))*x);
        }else if n < 0 {
            return 1.0/Solution::my_pow(x, -n);
        }else if n == 1 {
            return x;
        }
        
        let y = Solution::my_pow(x, n/2);
        
        if n%2 == 1 {
            y*y*x
        }else{
            y*y
        }
    }
}
