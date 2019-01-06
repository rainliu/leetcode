impl Solution {
    pub fn count_primes(n: i32) -> i32 {
        let mut is_prime = vec![false; n as usize];
        let mut count = 0;
        for i in 2..n {
            if !is_prime[i as usize] {
                count += 1;
                for j in (i..n).step_by(i as usize){
                    is_prime[j as usize] = true;
                }
            }
        }
        count
    }
}
