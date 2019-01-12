impl Solution {
    pub fn valid_mountain_array(a: Vec<i32>) -> bool {
        let n = a.len();
        if n < 3 || a[1]<a[0] {return false;}
        let mut i = 1;
        while i<n {
            let diff = a[i]-a[i-1];
            if diff==0 {return false;}
            if diff<0{
                break;
            }
            i+=1;
        }
        if i==n{return false;}
        while i<n {
            let diff = a[i]-a[i-1];
            if diff>=0 {return false;}
            i+=1;
        }
        true
    }
}

impl Solution2 {
    pub fn valid_mountain_array(a: Vec<i32>) -> bool {
        let n = a.len() as i32;
        let mut i = 0;
        while i+1<n && a[i as usize]<a[i as usize+1] {i+=1;}
        if i==0 || i==n-1 {return false;}
        while i+1<n && a[i as usize]>a[i as usize+1] {i+=1;}
        return i==n-1;
    }
}
