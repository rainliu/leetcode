impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let pattern = vec![
            vec!['I', 'V', 'X'],
            vec!['X', 'L', 'C'],
            vec!['C', 'D', 'M'],
            vec!['M'],
        ];
        let base = vec![1, 10, 100, 1000];
        let value = vec![1, 5, 10];
        let mut c = s.chars().rev().peekable();
        let mut j = 0;
        let mut sum = 0;
        while let Some(ch) = c.peek() {
            if *ch == pattern[j][0] {
                c.next();
                sum += base[j]*value[0];
                j -= 1;
            }else if *ch == pattern[j][1]{
                c.next();
                sum += base[j]*value[1];
                if let Some(cn) = c.peek() {
                    if *cn == pattern[j][0]{
                        sum -= base[j]*value[0];
                        c.next();
                    }
                }
            }else if *ch == pattern[j][2]{
                c.next();
                sum += base[j]*value[2];
                if let Some(cn) = c.peek() {
                    if *cn == pattern[j][0]{
                        sum -= base[j]*value[0];
                        c.next();
                    }
                }
            }
            j += 1;
        }
        sum
    }
}
