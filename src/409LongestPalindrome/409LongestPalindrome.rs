impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut count = vec![0;128];
        for c in s.into_bytes() {
            count[c as usize] += 1;
        }
        let mut odd = 0;
        let mut result = 0;
        for cnt in count{
            if cnt > 0 {
                odd |= cnt&1;
                result += cnt - (cnt&1);
            }
        }
        result+odd
    }
}
