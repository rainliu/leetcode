use std::collections::HashSet;
impl Solution {
    pub fn get_hint(secret: String, guess: String) -> String {
        let secret = secret.as_bytes();
        let guess = guess.as_bytes();
        let mut secret_set:Vec<HashSet<usize>> = vec![HashSet::new(); 10];
        let mut guess_set:Vec<HashSet<usize>> = vec![HashSet::new(); 10];
        for i in 0..secret.len() {
            secret_set[(secret[i] - ('0' as u8)) as usize].insert(i);
            guess_set [(guess[i]  - ('0' as u8)) as usize].insert(i);
        }
        let (mut bulls, mut cows) = (0, 0);
        for j in 0..10 {
            if !secret_set[j].is_empty() && !guess_set[j].is_empty() {
                let mut bull = 0;
                for i in secret_set[j].iter() {
                    if guess_set[j].contains(&i) {
                        bull += 1;
                    }
                }    
                bulls += bull;
                cows  += std::cmp::min(secret_set[j].len()-bull, guess_set[j].len()-bull);
            }
        }
        return format!("{}A{}B", bulls, cows);
    }
}
