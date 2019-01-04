impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut local = 0;
        let mut global = 0;
        for i in 0..(prices.len() as i32)-1 {
            local = std::cmp::max(local+prices[i as usize +1]-prices[i as usize],0);
            global= std::cmp::max(local, global);
        }
        global
    }
}
