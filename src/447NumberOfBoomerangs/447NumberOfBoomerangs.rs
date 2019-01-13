use std::collections::HashMap;
impl Solution {
    pub fn number_of_boomerangs(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut result = 0;
        for i in 0..n {
            let mut map = HashMap::new();
            for j in 0..n {
                if i==j {continue;}
                let d = (points[i][0]-points[j][0])*(points[i][0]-points[j][0])+
                        (points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                if let Some(x) = map.get_mut(&d){
                    result += 2*(*x);
                    *x += 1;
                }else{
                    map.insert(d, 1);
                }
            }
        }
        result
    }
}
