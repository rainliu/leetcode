impl Solution {
    pub fn can_attend_meetings(intervals: Vec<Vec<i32>>) -> bool {
        let mut intervals = intervals;
        intervals.sort_by(|a, b| a[0].cmp(&b[0]));
        for i in 1..intervals.len() {
            if intervals[i][0] < intervals[i-1][1] {
                return false;
            }
        }
        true
    }
}
