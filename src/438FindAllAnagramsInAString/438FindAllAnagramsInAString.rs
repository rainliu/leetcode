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

impl Solution2 {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        let sn = s.len();
        let pn = p.len();
        let mut countp = vec![0;26];
        let pc = p.into_bytes();
        for c in &pc {
            countp[(c-'a' as u8) as usize] += 1;
        }
        let mut result = vec![];
        let sc = s.into_bytes();
        let mut last_match = false;
        let mut j = pn-1;
        while j<sn {
            if !last_match {
                let mut counts = countp.clone();
                if Self::is_anagrams(&mut counts, &sc, j-pn+1, j+1) {
                    last_match = true;
                    result.push((j-pn+1) as i32);
                }
            }else if sc[j as usize]==sc[(j-pn) as usize]{
                result.push((j-pn+1) as i32);
            }else{
                last_match = false;
            }
            j+=1;
        }
        result
    }
    
    fn is_anagrams(counts: &mut [i32], sc:&[u8], i:usize, j:usize) -> bool {
        let mut i = i;
        let mut j = j;
        while i<j {
            let k = (sc[i as usize]-'a' as u8) as usize;
            if counts[k] <= 0 {
                break;
            }else{
                counts[k]-=1;
            }
            i+=1;
        }
        i==j
    }
}
