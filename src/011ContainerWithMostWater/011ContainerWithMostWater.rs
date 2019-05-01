impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut i = 0 as i32;
        let mut j = height.len() as i32 - 1;
        let mut global = 0;
        while i < j {
            global = std::cmp::max(global, (j-i)*std::cmp::min(height[i as usize], height[j as usize]));
            if height[i as usize] < height[j as usize] {
                i+=1;
            }else{
                j-=1;
            }
        }
        global
    }
}
