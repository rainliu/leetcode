impl Solution {
    pub fn is_strobogrammatic(num: String) -> bool {
        if num.len() == 0 {return true;}
        
        let map:Vec<u8> = vec![0,1,255,255,255,255,9,255,8,6];
                             //0,1,  2,  3,  4,  5,6,  7,8,9
        
        let num = num.as_bytes();
        let (mut i, mut j) = (0 as i32, num.len() as i32 - 1);
        while i <= j {
            let (m, n) = (num[i as usize] - ('0' as u8), num[j as usize] - ('0' as u8));
            if map[m as usize] != n {
                return false;
            }
            i += 1;
            j -= 1;
        }
        true
    }
}
