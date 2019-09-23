// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int r = 0;
        do {
            r = rand7() + (rand7()-1) * 7;
        }while(r>40);
        return ((r-1)%10)+1;
    }
};
