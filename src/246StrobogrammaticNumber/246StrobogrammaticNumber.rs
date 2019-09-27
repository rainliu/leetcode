impl Solution {
    pub fn is_strobogrammatic(num: String) -> bool {
        if num.len() == 0 {return true;}
        
        let map:Vec<u8> = vec![0,1,255,255,255,255,9,255,8,6];
                             //0,1,  2,  3,  4,  5,6,  7,8,9
        
        let num = num.as_bytes();
        let (mut i, mut j) = (0, num.len() - 1);
        while i <= j {
            if i==j{
                return num[i]=='0' as u8 || num[i]=='1' as u8 || num[i]=='8' as u8;    
            }
            let (m, n) = (num[i] - ('0' as u8), num[j] - ('0' as u8));
            if map[m as usize] != n {
                return false;
            }
            i += 1;
            j -= 1;
        }
        true
    }
}
