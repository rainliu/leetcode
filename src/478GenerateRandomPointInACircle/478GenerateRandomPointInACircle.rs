use rand::{thread_rng, Rng};

struct Solution {
    radius: f64,
    x_center: f64,
    y_center: f64,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Solution {

    fn new(radius: f64, x_center: f64, y_center: f64) -> Self {
        Solution {
            radius,
            x_center,
            y_center,
        }
    }
    
    fn rand_point(&self) -> Vec<f64> {
        let mut rng = thread_rng();
        
        let mut x: f64;
        let mut y: f64; 
        
        loop{
            x = rng.gen_range(self.x_center-self.radius, self.x_center+self.radius);
            y = rng.gen_range(self.y_center-self.radius, self.y_center+self.radius);
            let mut r = (x-self.x_center)*(x-self.x_center)+(y-self.y_center)*(y-self.y_center);
            r = r.sqrt();
            if r <= self.radius {
                break;
            }
        }
        
        vec![x, y]
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * let obj = Solution::new(radius, x_center, y_center);
 * let ret_1: Vec<f64> = obj.rand_point();
 */
