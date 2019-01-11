impl Solution {
    pub fn max_dist_to_closest(seats: Vec<i32>) -> i32 {
        let n = seats.len();
        let mut left = vec![0;n];
        let mut right = vec![0;n];
        for i in 0..n {
            left[i] = if seats[i]==1 {
                0
            } else if i==0 {
                n
            } else {
                left[i-1]+1
            };
            right[n-1-i] = if seats[n-1-i]==1{
                0
            } else if i==0{
                n
            } else {
                right[n-i]+1
            };
        }
        let mut global = 0;
        for i in 0..n {
            let local = std::cmp::min(left[i], right[i]);
            global = std::cmp::max(global, local);
        }
        global as i32
    }
}
