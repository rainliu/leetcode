impl Solution {
    pub fn is_monotonic(a: Vec<i32>) -> bool {
        let n = a.len();
        for i in 1..n {
            if (a[n-1]==a[0] && a[i]!=a[0]) || (a[n-1]-a[0])*(a[i]-a[i-1])<0 {
                return false;
            }
        }
        true
    }
}
