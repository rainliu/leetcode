impl Solution {
    pub fn flip_and_invert_image(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut a = a;
        let n = a[0].len();
        for j in 0..a.len() {
            for i in 0..(n+1)/2 {
                let tmp = 1- a[j][i];
                a[j][i] = 1- a[j][n-1-i];
                a[j][n-1-i]=tmp;
            }
        }
        a
    }
}
