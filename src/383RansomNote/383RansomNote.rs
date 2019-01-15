impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut count = vec![0;128];
        for c in magazine.into_bytes() {
            count[c as usize] += 1;
        }
        for c in ransom_note.into_bytes() {
            if count[c as usize] == 0{
                return false;
            }else{
                count[c as usize] -= 1;
            }
        }
        true
    }
}
