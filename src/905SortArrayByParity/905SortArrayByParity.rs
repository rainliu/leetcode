impl Solution {
    pub fn sort_array_by_parity(a: Vec<i32>) -> Vec<i32> {
        let mut a = a;
        let mut i = 0;
        let mut j = 0;
        while j < a.len() {
            if a[j]&1 == 0 {
                a.swap(i,j);
                i+=1;
            }
            j+=1;
        }
        a
    }
}
