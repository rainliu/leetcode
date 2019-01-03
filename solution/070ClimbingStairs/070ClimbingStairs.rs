impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        // f(n) = f(n-1)+f(n-2)
        if n == 1 {return 1;}
        let mut fn_2 = 1;
        let mut fn_1 = 1;
        let mut fn_0 = fn_1+fn_2;
        for i in 1..n {
            fn_0 = fn_1+fn_2;
            fn_2 = fn_1;
            fn_1 = fn_0;
        }
        fn_0
    }
}
