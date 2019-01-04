impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut chars = s.chars();
        let mut stack = Vec::new();
        while let Some(c) = chars.next() {
            if c == '(' || c == '{' || c == '[' {
                stack.push(c);
            }else{
                if let Some(d) = stack.pop() {
                    if (d == '(' && c != ')') ||
                       (d == '{' && c != '}') ||
                       (d == '[' && c != ']') {
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        
        stack.is_empty()
    }
}
