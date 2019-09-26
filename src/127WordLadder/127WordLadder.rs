use std::collections::HashSet;
use std::collections::VecDeque;
impl Solution {
    pub fn ladder_length(begin_word: String, end_word: String, word_list: Vec<String>) -> i32 {
        let end = end_word.as_bytes().to_vec(); 
        let mut set = HashSet::new();
        for word in word_list {
            set.insert(word.as_bytes().to_vec());
        }
        if !set.contains(&end) {
            return 0;
        }
        let begin = begin_word.as_bytes().to_vec();
        
        let mut queue = VecDeque::new();
        queue.push_back((begin, 1));
        while !queue.is_empty() {
            let (word, n) = queue.pop_front().unwrap();
            for i in 0..word.len() {
                for j in 0..27{
                    let ch = 'a' as u8 + j;
                    if word[i] != ch {
                        let mut next = word.clone();
                        next[i] = ch;
                        if set.contains(&next) {
                            if next == end {
                                return n+1;
                            }else{
                                set.remove(&next);
                                queue.push_back((next, n+1));
                            }
                        }
                    }
                }
            }   
        }
        
        0
    }
}
