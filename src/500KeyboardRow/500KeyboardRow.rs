impl Solution {
    pub fn find_words(words: Vec<String>) -> Vec<String> {
        let mut map = vec![
            //A,B,C,D,E,F,G,
              1,2,2,1,0,1,1,
            //H,I,J,K,L,M,N,
              1,0,1,1,1,2,2,
            //O,P,Q,R,S,T,
              0,0,0,0,1,0,
            //U,V,W,X,Y,Z,
              0,2,0,2,0,2,
        ];
        let mut result = vec![];
        for word in &words{
            let lc = word.to_lowercase().into_bytes();
            let mut i = 1;
            let row = map[(lc[0]-'a' as u8) as usize];
            while i<lc.len() {
                if map[(lc[i]-'a' as u8) as usize] != row {
                    break;
                }
                i+=1;
            }
            if i>=lc.len() {
                result.push(word.clone());
            }
        }
        result
    }
}
