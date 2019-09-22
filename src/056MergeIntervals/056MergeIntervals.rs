impl Solution {
    pub fn merge(intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut intervals = intervals;
        intervals.sort_by(|a, b| a[0].cmp(&b[0]));
        
        let mut merged_intervals:Vec<Vec<i32>> = vec![];
        for interval in intervals {
            let len = merged_intervals.len();
            if len == 0 || interval[0] > merged_intervals[len-1][1] {
                merged_intervals.push(interval);
            }else{
                merged_intervals[len-1][1] = std::cmp::max(merged_intervals[len-1][1], interval[1]);
            }
        }
        
        merged_intervals
    }
}
