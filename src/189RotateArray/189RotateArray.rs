impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        let n = nums.len() as i32;
        if n==0 {return;}
        let k = (k % n + n) % n;
        let mut i = 0;
        let mut j = n-k-1;
        let mut l = n-1;
        while i<j {nums.swap(i as usize,j as usize);i+=1;j-=1;}
        j=n-k;
        while j<l {nums.swap(j as usize,l as usize);j+=1;l-=1;}
        i=0;
        l=n-1;
        while i<l {nums.swap(i as usize,l as usize);i+=1;l-=1;}
    }
}
