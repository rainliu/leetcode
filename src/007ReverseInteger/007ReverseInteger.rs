impl Solution {
    pub fn reverse(x: i32) -> i32 {
        if x == std::i32::MIN {
            return 0;
        }
        let mut n = 0;
        let mut y = 0;
        let sign = x >= 0;
        let mut x = if x >= 0 {
            x
        }else{
            -x
        };
        let max_div_10 = std::i32::MAX/10;
        let max_mod_10 = std::i32::MAX%10;
        while x != 0 {
            let d = x%10;
            if y > max_div_10 ||
                (y == max_div_10 && 
                ((sign && d > max_mod_10) || 
                (!sign && d > max_mod_10 + 1))) {
                return 0;
            }
            y = y*10 + d;
            x = x/10;
        }
        
        if sign {
            y
        }else{
            -y
        }
    }
}
