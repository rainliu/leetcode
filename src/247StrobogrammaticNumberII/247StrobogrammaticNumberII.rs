impl Solution {
    pub fn find_strobogrammatic(n: i32) -> Vec<String> {
        Solution::find_strobogrammatic_helper(n, n)
    }
    fn find_strobogrammatic_helper(n: i32, m: i32) -> Vec<String> {
        if n <=0 {
            return vec!["".to_string()];
        }else if n==1 {
            return vec!["0".to_string(), "1".to_string(), "8".to_string()];
        }
        
        let strobogrammatic = Solution::find_strobogrammatic_helper(n-2, m);
        let mut results = vec![];
        for s in &strobogrammatic{
            if m!=n{
                results.push("0".to_string()+s+"0");
            }
            results.push("1".to_string()+s+"1");
            results.push("6".to_string()+s+"9");
            results.push("8".to_string()+s+"8");
            results.push("9".to_string()+s+"6");
        }
        results        
    }
}
