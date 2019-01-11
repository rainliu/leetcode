impl Solution {
    pub fn large_group_positions(s: String) -> Vec<Vec<i32>> {
        let s = s.into_bytes();
        let n = s.len();
        let mut result = vec![];
        let mut i = 0;
        let mut j = 0;
        while j < n {
            while j < n && s[j]==s[i] {j+=1;}
            if j>=i+3 {
                result.push(vec![i as i32, j as i32 - 1]);
            }
            i = j;
        }
        result
    }
}
