impl Solution {
    pub fn fib(n: i32) -> i32 {
        if n == 0 {return 0;}
        if n == 1 {return 1;}
        let mut fn_2 = 0;
        let mut fn_1 = 1;
        let mut fn_0 = 0;
        for i in 2..=n {
            fn_0 = fn_1+fn_2;
            fn_2 = fn_1;
            fn_1 = fn_0;
        }
        fn_0
    }
}
