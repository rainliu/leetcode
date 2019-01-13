use std::collections::HashMap;
impl Solution {
    pub fn subdomain_visits(cpdomains: Vec<String>) -> Vec<String> {
        let mut map = HashMap::new();
        for cpdomain in cpdomains {
            let mut iter = cpdomain.split_whitespace();
            let count:i32 = iter.next().unwrap().parse().unwrap();
            let subdomains: Vec<&str> = iter.next().unwrap().split('.').collect();
            for i in 0..subdomains.len() {
                let mut domain = String::new();
                domain.push_str(subdomains[i]);
                for j in i+1..subdomains.len() {
                    domain.push_str(".");
                    domain.push_str(subdomains[j]);
                }
                if let Some(x) = map.get_mut(&domain) {
                    *x += count;
                }else{
                    map.insert(domain, count);
                }
            }
        }
        let mut result = vec![];
        for (key, val) in map.iter() {
            result.push(val.to_string() + " " + key);
        }
        result
    }
}
