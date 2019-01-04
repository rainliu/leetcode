impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let b = s.as_bytes();
        let mut i = 0;
        let mut j = b.len() as i32 - 1;
        while i<j {
            while i<j && !(b[i as usize] as char).is_alphanumeric() {i += 1;}
            while i<j && !(b[j as usize] as char).is_alphanumeric() {j -= 1;}
            if (b[i as usize] as char).to_ascii_lowercase() != (b[j as usize] as char).to_ascii_lowercase() {return false;}
            i += 1;
            j -= 1;
        }
        true
    }
}

impl Solution2 {
    pub fn is_palindrome(s: String) -> bool {
        let mut iter = s.chars();
        let mut buf = String::new();
        while let Some(c) = iter.next() {
            if c.is_alphanumeric() {
                buf.push(c.to_ascii_lowercase());
            }
        }
        iter = buf.chars();
        while let (Some(p), Some(q)) = (iter.next(), iter.next_back()) {
            if p != q {
                return false;
            }
        }
        true
    }
}
