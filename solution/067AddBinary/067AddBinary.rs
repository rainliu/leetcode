impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        if a.len() < b.len() {return Solution::add_binary(b, a);}
        let mut ca = a.chars().rev().peekable();
        let mut cb = b.chars().rev().peekable();
        let mut c = 0;
        let mut result = String::new();
        while let (Some(cha), Some(chb)) = (ca.peek(), cb.peek()){
            let da = cha.to_digit(2).unwrap();
            let db = chb.to_digit(2).unwrap();
            let mut d = da+db+c;
            c = d/2;
            d = d%2;
            result.push(std::char::from_digit(d,2).unwrap());
            ca.next();
            cb.next();
        }
        while let Some(cha) = ca.peek() {
            let da = cha.to_digit(2).unwrap();
            let mut d = da + c;
            c = d/2;
            d = d%2;
            result.push(std::char::from_digit(d,2).unwrap());
            ca.next();
        }
        if c > 0 {
            result.push(std::char::from_digit(c,2).unwrap())
        }
        result.chars().rev().collect()
    }
}
