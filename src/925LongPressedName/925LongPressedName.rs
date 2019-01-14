impl Solution {
    pub fn is_long_pressed_name(name: String, typed: String) -> bool {
        let nc = name.len();
        let nt = typed.len();
        let name = name.into_bytes();
        let typed = typed.into_bytes();
        let mut i = 0;
        let mut j = 0;
        while i<nc && j<nt {
            if name[i]==typed[j] {
                i+=1;
                j+=1;
            }else if j>0 && typed[j]==typed[j-1]{
                j+=1;
            }else{
                return false;
            }
        }
        if i==nc {
            while j<nt && j>0 && typed[j]==typed[j-1] {j+=1;}
            j==nt
        }else{
            false
        }
    }
}
