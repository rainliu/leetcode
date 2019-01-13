impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut count = vec![0;26];
        let chars = s.into_bytes();
        for c in &chars {
            count[(c - 'a' as u8) as usize] += 1;
        }
        for i in 0..chars.len(){
            if count[(chars[i] - 'a' as u8) as usize] == 1 {
                return i as i32;
            }    
        }
        -1
    }
}
