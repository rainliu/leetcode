impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let n = s.len() as i32;
        let mut chars = s.into_bytes();
        let mut i = 0;
        let mut j = n-1;
        while i<j{
            while i<j && !Self::is_vowel(chars[i as usize]) {i+=1;}
            while i<j && !Self::is_vowel(chars[j as usize]) {j-=1;}
            if i<j {
                chars.swap(i as usize,j as usize);
                i+=1;
                j-=1;
            }
        }
        String::from_utf8(chars).unwrap()
    }
    
    fn is_vowel(c: u8) -> bool {
        c=='a' as u8 ||
        c=='A' as u8 ||
        c=='e' as u8 ||
        c=='E' as u8 ||
        c=='i' as u8 ||
        c=='I' as u8 ||
        c=='u' as u8 ||
        c=='U' as u8 ||
        c=='o' as u8 ||
        c=='O' as u8
    }
}
