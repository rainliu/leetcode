impl Solution {
    pub fn check_record(s: String) -> bool {
        let mut iter = s.chars();
        let mut A = 0;
        let mut L = 0;
        while let Some(c) = iter.next() {
            if c == 'L' {
                L += 1;
            }else{
                if c == 'A' {
                    A += 1;
                }
                L = 0;
            }
            if A>1 || L>2 {
                return false;
            }
        }
        true
    }
}
