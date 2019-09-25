impl Solution {
    pub fn multiply(num1: String, num2: String) -> String {
        let num1 = num1.as_bytes();
        let num2 = num2.as_bytes();
        let n1 = num1.len();
        let n2 = num2.len();
        let mut num: Vec<u8> = vec![0; n1+n2];
        for j in 0..n2 {
            let y = num2[n2-1-j] - '0' as u8;
            let mut c = 0;
            for i in 0..n1 {
                let x = num1[n1-1-i] - '0' as u8;
                let d = x*y+c+num[j+i];
                c = d/10;
                num[j+i] = d%10;
            }
            if c!=0 {
                num[j+n1] = c;
            }
        }
        let mut k = num.len()-1;
        while k > 0 && num[k]==0 {
            k -= 1;
        }
        for i in 0..=k{
            num[i] += '0' as u8;
        }
        num[0..k+1].reverse();
        
        String::from_utf8(num[0..k+1].to_vec()).unwrap()
    }
}
