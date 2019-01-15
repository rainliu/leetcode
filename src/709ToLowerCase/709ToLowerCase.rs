impl Solution {
    pub fn to_lower_case(str: String) -> String {
        let mut chars = str.into_bytes();
        for c in &mut chars{
            if *c <= 'Z' as u8 && *c >= 'A' as u8 {
                *c += 'a' as u8 - 'A' as u8;
            }
        }
        String::from_utf8(chars).unwrap()
    }
}
