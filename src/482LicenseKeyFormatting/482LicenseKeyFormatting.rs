impl Solution {
    pub fn license_key_formatting(s: String, k: i32) -> String {
        let mut i = 0;
        let mut result = String::new();
        for ch in s.chars().rev() {
            if ch != '-' {
                if i!=0 && i%k == 0 {
                    result.push('-');
                }    
                result.push(ch.to_ascii_uppercase());
                i+=1;
            }
        }
        
        result.chars().rev().collect::<String>()
    }
}
