impl Solution {
    pub fn max_product(words: Vec<String>) -> i32 {
        if words.len() == 0 {return 0;}
        let mut bits = vec![];
        for word in &words {
            bits.push(Solution::convert2bit(word.as_bytes()));
        }
        let mut global = 0;
        for i in 0..bits.len()-1 {
            for j in i+1..bits.len() {
                if bits[i]&bits[j] == 0 {
                    global = std::cmp::max(global, words[i].len()*words[j].len());
                }
            }
        }
        global as i32
    }
    fn convert2bit(word: &[u8]) -> i32 {
        let mut bit = 0;
        for i in 0..word.len() {
            bit |= 1<<(word[i] - 'a' as u8);
        }
        return bit;
    }
}
