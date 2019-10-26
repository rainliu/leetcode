class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0) return numeric_limits<int>::max();
        if(divisor==1) return dividend;
        if(dividend==numeric_limits<int>::min()){
            if(divisor==-1) return numeric_limits<int>::max();
            if(divisor==1) return dividend;
        }
        
        bool sign = (dividend<0 && divisor>0) || (dividend>0 && divisor<0);
        int64_t dividend2 = abs(int64_t(dividend));
        int64_t divisor2 = abs(int64_t(divisor));
           
        int result = 0;
        int r;
        do{
            r = divideHelper(dividend2, divisor2);
            if(r>=0){
                result += 1<<r;
                dividend2 -= divisor2<<r;
            }
        }while(r>0);
        return sign ? -result : result;
    }
    
    int divideHelper(int64_t dividend, int64_t divisor) {
        if(dividend < divisor) return -1;
        if(dividend == divisor) return 0;
        int lo = 0;
        int hi = 31;
        while(lo<=hi){
            int mi = lo + ((hi-lo)>>1);
            int d = dividend>>mi;
            if(divisor==d) return mi;
            else if(divisor < d) {
                lo = mi+1;
            }else{
                hi = mi-1;
            }
        }
        return max(hi,0);
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
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
    	if(divisor==0) return numeric_limits<int>::max();
    	if(dividend==0) return 0;
    	long long dividend2, divisor2;

    	int sign[2];
    	if(dividend>0){
	    	sign[0] = 0;
	    	dividend2 = (long long)dividend;
	    }else{
	    	sign[0] = 1;
	    	dividend2 = -(long long)dividend;
	    }
	    if(divisor>0){
	    	sign[1] = 0;
	    	divisor2 = (long long)divisor;
	    }else{
	    	sign[1] = 1;
	    	divisor2 = -(long long)divisor;
	    }
	    int s = (sign[0]+sign[1])&0x1;

	    if(dividend2<divisor2) return 0;
	    if(divisor2==1) return s?-dividend2:(dividend2>numeric_limits<int>::max()?numeric_limits<int>::max():dividend2);
	    if(divisor2==2) return s?-(dividend2>>1):(dividend2>>1);
	    
	    int ret = 0;

	    int k;
	    do{
	    	k = 0;
		    while((divisor2<<k)<=dividend2){
		    	k++;
		    }
		    ret += 1<<(k-1);

		    dividend2-=divisor2<<(k-1);
		}while(divisor2<dividend2);  

    	return s?-ret:ret;
    }
};


class Solution2 {
public:
    int divide(int dividend, int divisor) {
    	if(divisor==0) return numeric_limits<int>::max();
    	if(dividend==0) return 0;
    	long long dividend2, divisor2;

    	int sign[2];
    	if(dividend>0){
	    	sign[0] = 0;
	    	dividend2 = (long long)dividend;
	    }else{
	    	sign[0] = 1;
	    	dividend2 = -(long long)dividend;
	    }
	    if(divisor>0){
	    	sign[1] = 0;
	    	divisor2 = (long long)divisor;
	    }else{
	    	sign[1] = 1;
	    	divisor2 = -(long long)divisor;
	    }
	    int s = (sign[0]+sign[1])&0x1;

	    if(dividend2<divisor2) return 0;
	    if(divisor2==1) return s?-dividend2:(dividend2>numeric_limits<int>::max()?numeric_limits<int>::max():dividend2);

	    long long lo = 0;
    	long long hi = dividend2;
    	long long mi;
    	while(lo<=hi){
    		mi = lo+((hi-lo)>>1);
    		long long mm = divisor2*mi;
    		if(mm==dividend2) return s?-mi:mi;
    		else if(mm>dividend2) hi=mi-1;
    		else lo = mi+1;
    	}
    	return s?-hi:hi;
    }
};

int main(){
	Solution s;

	cout<<"1/1="<<s.divide(1,1)<<endl;
	cout<<"123/10="<<s.divide(123,10)<<endl;
	cout<<"23/-7="<<s.divide(23,-7)<<endl;
	cout<<"-2147483648/-1="<<s.divide(-2147483648,-1)<<endl;
	cout<<"1026117192/-874002063="<<s.divide(1026117192, -874002063)<<endl;
	cout<<"1036963541/-24409858="<<s.divide(1036963541, -24409858)<<endl;
	return 0;
}
