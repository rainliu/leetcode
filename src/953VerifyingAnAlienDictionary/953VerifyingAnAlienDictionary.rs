impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let mut order_map = vec![0;26];
        let order_chars = order.into_bytes();
        for i in 0..order_chars.len() {
            order_map[(order_chars[i]-'a' as u8) as usize] = i;
        }
        for i in 1..words.len() {
            let word1 = words[i-1].as_bytes();
            let word2 = words[i].as_bytes();
            if !Self::is_sorted(word1, word2, &order_map) {
                return false;
            }
        }
        true
    }
    
    fn is_sorted(word1:&[u8], word2:&[u8], order_map:&[usize]) -> bool {
        let mut i = 0;
        let mut j = 0;
        while i<word1.len() && j<word2.len() {
            let index1=order_map[(word1[i]-'a' as u8) as usize];
            let index2=order_map[(word2[j]-'a' as u8) as usize];
            if index1<index2 {
                return true;
            }else if index1>index2 {
                return false;
            }
            i+=1;
            j+=1;
        }
        i==word1.len()
    }
}
