use std::collections::BTreeMap;
impl Solution {
    pub fn min_meeting_rooms(intervals: Vec<Vec<i32>>) -> i32 {
        let mut map:BTreeMap<i32, i32> = BTreeMap::new();
        for interval in &intervals {
            if let Some(x) = map.get_mut(&interval[0]){
                *x += 1;
            }else{
                map.insert(interval[0], 1);
            }
            if let Some(x) = map.get_mut(&interval[1]){
                *x -= 1;
            }else{
                map.insert(interval[1], -1);
            }
        }
        let (mut global, mut local) = (0, 0);
        for (key, val) in map.iter() {
            local += val;
            global = std::cmp::max(global, local);
        }
        
        global as i32
    }
}
