impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut results = vec![];
        for i in 0..num_rows{
            if i==0 {
                results.push(vec![1]);
            }else{
                let mut result = vec![];
                for j in 0..i+1 {
                    let l = if j-1<0 {0} else {results[(i-1) as usize][(j-1) as usize]};
                    let r = if j>i-1 {0} else {results[(i-1) as usize][j as usize]};
                    result.push(l+r);
                }
                results.push(result);
            } 
        }
        results
    }
}
