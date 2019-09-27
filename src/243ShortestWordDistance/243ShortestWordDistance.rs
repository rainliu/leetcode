impl Solution {
    pub fn shortest_distance(words: Vec<String>, word1: String, word2: String) -> i32 {
        let (mut w1, mut w2) = (-1, -1);
        let mut global = std::i32::MAX;
        for i in 0..words.len() {
            if (words[i] == word1 || words[i] == word2) {
                if(words[i] == word1){
                    w1 = i as i32;
                }else if (words[i] == word2) {
                    w2 = i as i32;
                }
                if w1 != -1 && w2 != -1 {
                    global = std::cmp::min(global, (w1-w2).abs());
                }
            }
        }
        global
    }
}
