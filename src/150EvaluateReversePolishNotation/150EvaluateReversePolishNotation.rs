impl Solution {
    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut stack:Vec<i32> = vec![];
        for token in tokens {
            match token.as_str() {
            t @ "+" | t@ "-" | t@ "*" | t@ "/" => {
                    let a = stack.pop().unwrap();
                    let b = stack.pop().unwrap();
                    let mut c;
                    if t == "+" {
                        c = b + a;    
                    }else if t == "-" {
                        c = b - a;
                    }else if t == "*" {
                        c = b * a;
                    }else{
                        c = b / a;    
                    }
                    stack.push(c);
                }
            _   => stack.push(token.parse::<i32>().unwrap()),
            };
        }
        
        stack.pop().unwrap()
    }
}
