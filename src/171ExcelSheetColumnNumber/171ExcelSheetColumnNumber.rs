impl Solution {
    pub fn title_to_number(s: String) -> i32 {
        let mut iter = s.chars();
        let mut num = 0;
        while let Some(c) = iter.next() {
            num = num*26 + (c as u8 - 'A' as u8) as i32 + 1;
        }
        num
    }
}
