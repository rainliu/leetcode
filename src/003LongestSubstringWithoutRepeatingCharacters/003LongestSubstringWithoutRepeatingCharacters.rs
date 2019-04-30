impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut map = vec![0;256];
        let mut counter = 0; // check whether the substring is valid
        //two pointers, one point to tail and one head
        let mut begin = 0;
        let mut end = 0; 
        let mut d = 0; //the length of substring
        
        let s = s.as_bytes();
        //for() { /* initialize the hash map here */ }
        while end<s.len() {
            if map[s[end] as usize]>0 {
                counter += 1;
            }
            map[s[end] as usize] += 1;
            end+=1;
        
            while counter > 0 {     
                if map[s[begin] as usize]>1 {
                    counter-=1;
                }
                map[s[begin] as usize]-=1;
                begin += 1;
            }  
            d = std::cmp::max(d, end-begin);
        }
        d as i32
    }
}
