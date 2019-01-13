impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {return false;}
        let mut count = vec![0;128];
        let si = s.into_bytes();
        let ti = t.into_bytes();
        for c in si{
            count[c as usize]+=1;
        }
        for c in ti{
            count[c as usize]-=1;
            if count[c as usize]<0 {
                return false;
            }
        }
        true
    }
}
