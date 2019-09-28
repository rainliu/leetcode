#[derive(Clone, PartialEq)]
enum VisitState {
    Unvisited,
    Visited,
    Visiting,
}

impl Solution {
    pub fn find_order(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {
        let mut courses:Vec<Vec<i32>> = vec![vec![]; num_courses as usize];
        for pair in prerequisites {
            courses[pair[0] as usize].push(pair[1]);
        }
        
        let mut order = vec![];
        let mut visited = vec![VisitState::Unvisited; num_courses as usize];
        for course in 0..num_courses{
            if visited[course as usize] == VisitState::Unvisited {
                if Solution::dfs(&courses, &mut visited, course as usize, &mut order) {
                    return vec![];
                }
            } 
        }
        
        return order;
    }
    
    fn dfs(courses: &Vec<Vec<i32>>, visited: &mut Vec<VisitState>, course: usize, order: &mut Vec<i32>) -> bool{
        let backup = visited[course].clone();
        visited[course] = VisitState::Visiting;
        
        if courses[course].len() > 0 {
            for prerequisite in &courses[course] {
                if visited[*prerequisite as usize] == VisitState::Visiting {
                    return true;
                }
                if Solution::dfs(courses, visited, *prerequisite as usize, order) {
                    return true;
                }
            }
        }
        
        if backup != VisitState::Visited{
            order.push(course as i32);
        }
        visited[course] = VisitState::Visited;
        return false;
    }
}
