impl Solution {
    fn count_and_say_helper(strs: String) -> String {
        let strs = strs.as_bytes();
        let n = strs.len();
        let mut i = 0;
        let mut j = 0;
        let mut count = 0;
        let mut buffer = String::new();
        while j < n {
            while j < n && strs[j] == strs[i] {
                j += 1;
                count += 1;
            }    
            buffer.push_str(count.to_string().as_str());
            buffer.push_str((strs[i] as char).to_string().as_str());
            count = 0;
            i = j;
        }
        buffer
    }
    
    pub fn count_and_say(n: i32) -> String {
        let mut buffer = "1".to_string();
        for i in 1..n {
            buffer = Self::count_and_say_helper(buffer);
        }
        buffer
    }
}
