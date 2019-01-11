impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let mut f2=cost[0];
        let mut f1=cost[1];
        for i in 2..cost.len() {
            let f0=cost[i]+std::cmp::min(f1, f2);
            f2=f1;
            f1=f0;
        }
        std::cmp::min(f1, f2)
    }
}
