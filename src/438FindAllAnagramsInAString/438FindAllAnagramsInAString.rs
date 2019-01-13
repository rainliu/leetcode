impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let sn = s.len() as i32;
        let pn = p.len() as i32;
        let mut countp = vec![0;26];
        let pc = p.into_bytes();
        for c in &pc {
            countp[(c-'a' as u8) as usize] += 1;
        }
        let mut result = vec![];
        let sc = s.into_bytes();
        for i in 0..=(sn-pn) {
            let mut counts = countp.clone();
            let mut j = i;
            while j<i+pn {
                let k = (sc[j as usize]-'a' as u8) as usize;
                if counts[k] <= 0 {
                    break;
                }else{
                    counts[k]-=1;
                }
                j+=1;
            }
            if j==i+pn {
                result.push(i);
            }
        }
        result
    }
}
