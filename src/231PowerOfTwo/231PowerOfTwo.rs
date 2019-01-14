impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        if n <=0  {return false;}
        n&(n-1)==0
    }
}
