use std::collections::HashMap;
impl Solution {
    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        let mut map:HashMap<i32,i32> = HashMap::new();
        for num in deck {
            if let Some(x) = map.get_mut(&num){
                *x += 1;
            }else{
                map.insert(num, 1);
            }
        }
        if let Some(min) = map.values().min(){
            let mut X = *min;
            while X >= 2 {
                let mut matched = true;
                for value in map.values() {
                    if *value % X != 0 {
                        matched = false;
                        break;
                    }
                }
                if matched{
                    return true;
                }
                X-=1;
            }
        }
        false
    }
}
