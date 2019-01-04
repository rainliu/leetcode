impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut profit = 0;
        for i in 0..prices.len() as i32 - 1 {
            profit += std::cmp::max(0, prices[i as usize + 1] - prices[i as usize]);
        }
        profit
    }
}
