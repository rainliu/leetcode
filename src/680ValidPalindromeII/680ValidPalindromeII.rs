impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        let n = s.len();
        if n == 0 {return true;}
        let s = s.into_bytes();
        let mut i = 0;
        let mut j = n-1;
        while i < j && s[i]==s[j] {i+=1;j-=1;}
        i>j || Self::is_valid_palindrome(&s, i+1,j) || Self::is_valid_palindrome(&s, i,j-1)
    }
    
    fn is_valid_palindrome(s: &[u8], i:usize, j:usize) -> bool {
        let mut i = i;
        let mut j = j;
        while i < j && s[i]==s[j] {i+=1;j-=1;}
        i>=j
    }
}
