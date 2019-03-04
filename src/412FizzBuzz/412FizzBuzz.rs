impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        let mut result = vec![];
        for i in 1..=n{
            if i%15==0{
                result.push("FizzBuzz".to_string());
            } else if i%5==0{
                result.push("Buzz".to_string());
            } else if i%3==0{
                result.push("Fizz".to_string());
            } else{
                result.push(i.to_string());
            }
        }
        result
    }
}
