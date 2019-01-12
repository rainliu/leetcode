impl Solution {
    pub fn sort_array_by_parity_ii(a: Vec<i32>) -> Vec<i32> {
        let mut a = a;
        let mut i = 0;
        let mut j = 0;
        let n = a.len();
        while j < n {
            if a[j]&1 == 0 {
                a.swap(i,j);
                i+=1;
            }
            j+=1;
        }
        i = (n-1)/2;
        j = n-1;
        while j>0 {
            if j&1 == 0 {
                a.swap(i,j);
                i-=1;
            }
            j-=1;
        }
        a
    }
}
