#[derive(Clone, PartialEq)]
enum VisitState {
    Unvisited,
    Visited,
    Visiting,
}

use std::collections::HashMap;
impl Solution {
    pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
        let mut map:HashMap<i32, Vec<i32>> = HashMap::new();
        for pair in prerequisites {
            if let Some(neighbors) = map.get_mut(&pair[0]) {
                neighbors.push(pair[1]);
            }else{
                map.insert(pair[0], vec![pair[1]]);
            }
        }
        let mut visited = vec![VisitState::Unvisited; num_courses as usize];
        for key in map.keys() {
            if visited[*key as usize] == VisitState::Unvisited {
                visited[*key as usize] = VisitState::Visited;
                if Solution::dfs(&map, &mut visited, *key) {
                    return false;
                }
            }
        }
        true
    }
    
    fn dfs(map:&HashMap<i32, Vec<i32>>, visited: &mut Vec<VisitState>, key: i32) -> bool {
        visited[key as usize] = VisitState::Visiting;
        
        if let Some(neighbors) = map.get(&key) {
            for neihbor in neighbors {
                if visited[*neihbor as usize] == VisitState::Visiting {
                    return true;
                }
                if map.get(neihbor).is_some() {
                    if Solution::dfs(map, visited, *neihbor) {
                        return true;
                    }
                }
            }
        }
        
        visited[key as usize] = VisitState::Visited;
        return false;
    }
}
