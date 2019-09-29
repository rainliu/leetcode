use std::collections::HashSet;
impl Solution {
    pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        if n == 1 {
            return vec![0];
        }
        let mut map:Vec<HashSet<i32>> = vec![HashSet::new(); n as usize];
        for edge in edges {
            map[edge[0] as usize].insert(edge[1]);
            map[edge[1] as usize].insert(edge[0]);
        }
        
        let mut leaves = vec![];
        for i in 0..n {
            if map[i as usize].len() == 1 {
                leaves.push(i);
            }
        }
        
        let mut n = n;
        while n > 2 {
            n -= leaves.len() as i32;
            let mut new_leaves = vec![];
            for i in leaves {
                let neibhors:Vec<i32> = map[i as usize].iter().cloned().collect();
                for j in neibhors {
                    map[j as usize].remove(&i);
                    if (map[j as usize].len() == 1) {
                        new_leaves.push(j);
                    }
                }
            }
            leaves = new_leaves;
            
        }
        return leaves;
    }
    
}
