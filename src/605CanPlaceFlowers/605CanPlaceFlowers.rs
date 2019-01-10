impl Solution {
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        let mut flowerbed = flowerbed;
        let m = flowerbed.len() as i32;
        let mut n = n;
        let mut i = 0;
        while i < m && n > 0 {
            if flowerbed[i as usize]==0 && 
                (i==0 || flowerbed[(i-1) as usize]==0) &&
                (i==m-1 || flowerbed[(i+1) as usize]==0) {
                flowerbed[i as usize] = 1;
                n -= 1;
            } 
            i += 1;
        }
        n==0
    }
}
