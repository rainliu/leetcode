impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let n = s.len();
        let s = s.into_bytes();
        let mut result = 0;
        let mut i = 0;
        while i<n {
            let mut cnt = 1;
            let mut j = i+1;
            while j<n && s[j]==s[i] {cnt+=1;j+=1;}
            while j<n && s[j]!=s[i] && cnt>0 {cnt-=1;j+=1;}
            if cnt==0 {
                result+=(j-i)/2;
                i+=(j-i)/2;
            } else {
                i+=1;
            }
        }
        result as i32
    }
}
