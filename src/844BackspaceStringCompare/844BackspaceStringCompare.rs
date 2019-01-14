impl Solution {
    pub fn backspace_compare(s: String, t: String) -> bool {
        let mut sv = s.into_bytes();
        let mut tv = t.into_bytes();
        let sb = Self::backspace(&mut sv);
        let tb = Self::backspace(&mut tv);
        sb==tb
    }
    
    fn backspace(v:&mut [u8])->&[u8] {
        let n = v.len();
        let mut i = 0;
        let mut j = 0;
        while j<n {
            if v[j]=='#' as u8 {
                i = if i==0 {0} else {i-1};
            }else{
                v.swap(i,j);
                i+=1;
            }
            j+=1;
        }
        &v[0..i]
    }
}
