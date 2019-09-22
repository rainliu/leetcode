//sliding_window_length - number_of_most_frequent_char_in_window > k
impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let s = s.as_bytes();
        let (mut i, mut j, mut c) = (0, 0, 0);
        let mut n = 0;
        let mut count = vec![0; 26];
        let mut local_freq_num = 0;
        while j < s.len() {
            count[(s[j]-'A' as u8) as usize] += 1;
            local_freq_num = std::cmp::max(local_freq_num, count[(s[j]-'A' as u8) as usize]);
            let len = j - i + 1;
            if (len - local_freq_num) as i32 > k {
                count[(s[i]-'A' as u8) as usize] -= 1;
                i += 1;    
                local_freq_num = *(count.iter().max().unwrap());
            }else{
                n = std::cmp::max(n, len);
            }
            j += 1;
        }
        
        n as i32
    }
}
