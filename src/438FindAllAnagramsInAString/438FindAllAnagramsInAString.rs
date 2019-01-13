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

/*
//https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem.
the template:
public class Solution {
    public List<Integer> slidingWindowTemplateByHarryChaoyangHe(String s, String t) {
        //init a collection or int value to save the result according the question.
        List<Integer> result = new LinkedList<>();
        if(t.length()> s.length()) return result;
        
        //create a hashmap to save the Characters of the target substring.
        //(K, V) = (Character, Frequence of the Characters)
        Map<Character, Integer> map = new HashMap<>();
        for(char c : t.toCharArray()){
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        //maintain a counter to check whether match the target string.
        int counter = map.size();//must be the map size, NOT the string size because the char may be duplicate.
        
        //Two Pointers: begin - left pointer of the window; end - right pointer of the window
        int begin = 0, end = 0;
        
        //the length of the substring which match the target string.
        int len = Integer.MAX_VALUE; 
        
        //loop at the begining of the source string
        while(end < s.length()){
            
            char c = s.charAt(end);//get a character
            
            if( map.containsKey(c) ){
                map.put(c, map.get(c)-1);// plus or minus one
                if(map.get(c) == 0) counter--;//modify the counter according the requirement(different condition).
            }
            end++;
            
            //increase begin pointer to make it invalid/valid again
            while(counter == 0 ){// counter condition. different question may have different condition 
                
                char tempc = s.charAt(begin);//***be careful here: choose the char at begin pointer, NOT the end pointer
                if(map.containsKey(tempc)){
                    map.put(tempc, map.get(tempc) + 1);//plus or minus one
                    if(map.get(tempc) > 0) counter++;//modify the counter according the requirement(different condition).
                }
                
                // save / update(min/max) the result if find a target
                // result collections or result int value
                
                begin++;
            }
        }
        return result;
    }
}
*/
