impl Solution {
    pub fn reverse_string(s: String) -> String {
        let n = s.len();
        if n <= 1 {return s;}
        let mut chars = s.into_bytes();    
        let mut i = 0;
        let mut j = n-1;
        while i<j {
            chars.swap(i,j);
            i+=1;
            j-=1;
        }
        String::from_utf8(chars).unwrap()
    }
}
