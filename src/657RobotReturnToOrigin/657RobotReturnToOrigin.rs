impl Solution {
    pub fn judge_circle(moves: String) -> bool {
        let mut chars = moves.chars();
        let mut x = 0;
        let mut y = 0;
        while let Some(d) = chars.next() {
            match d {
                'U' => y += 1,
                'D' => y -= 1,
                'L' => x -= 1,
                _   => x += 1,
            };
        }
        x==0 && y== 0
    }
}
