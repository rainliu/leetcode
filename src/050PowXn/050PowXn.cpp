class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(n==0) return 1;
        if(n<0) {
            if(n==numeric_limits<int>::min()){
                return 1.0/(x*myPow(x, -(n+1)));
            }else{
                return 1.0/myPow(x,-n);
            }
        }
        if(n==1) return x;
        double z = myPow(x, n/2);
        if(n&0x1){
            return z*z*x;    
        }else{
            return z*z;
        }
    }
};

#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Implement pow(x, n).
*/

class Solution {
public:
    double pow(double x, int n) {
    	if(n==numeric_limits<int>::min()) return 1.0/(pow(x,numeric_limits<int>::max())*x);
    	else if(n<0) return 1.0/pow(x,-n);
        else if(n==0||x==1) return 1;
        else if(n==1) return x;
        else{
	        double y = pow(x, n>>1);
	        	
	        if(n&0x1){//odd
	        	return x*y*y;
	        }else{//even
	        	return y*y;
	        }
	    }
    }
};


int main(){
	Solution s;

	cout<<s.pow(3, -1)<<endl;
	cout<<s.pow(3, 0)<<endl;
	cout<<s.pow(3, 1)<<endl;
	cout<<s.pow(3, 2)<<endl;
	cout<<s.pow(3, 3)<<endl;
	cout<<s.pow(3, 4)<<endl;

	return 0;
}
