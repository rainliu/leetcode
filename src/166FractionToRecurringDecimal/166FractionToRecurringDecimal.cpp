class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==0) return "";
        if(denominator==1) return to_string(numerator);
        if(denominator==-1){
            if(numerator<0) return to_string(abs((int64_t)numerator));
            else return "-"+to_string(numerator);
        }
        
        string sign = (numerator>0&&denominator<0) || (numerator<0&&denominator>0) ? "-": "";
        
        int64_t numerator2 = abs((int64_t)numerator);
        int64_t denominator2 = abs((int64_t)denominator);
        
        unordered_map<int64_t, int> m;
        int integer = numerator2/denominator2;
        numerator2  -= integer*denominator2;
        string fraction = "";
        int pos = 0;
        while(numerator2 != 0){
            if(m.find(numerator2) != m.end()){
                //cout<<m[numerator]<<":"<<fraction<<endl;
                return sign+to_string(integer)+"."+fraction.substr(0, m[numerator2])+"("+fraction.substr(m[numerator2])+")";
            }
            m[numerator2] = pos;
            numerator2 *= 10;
            if(numerator2 < denominator2){
                fraction += "0";
            }else{
                int integer2 = numerator2/denominator2;
                numerator2 -= integer2*denominator2;
                fraction += to_string(integer2);
            }
            ++pos;
        }
        
        if(fraction == ""){
            return sign+to_string(integer);
        }else{
            return sign+to_string(integer)+"."+fraction;
        }
    }
};

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
using namespace patch;
/*
Given two integers representing the numerator and denominator of a fraction, 
return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Credits:
Special thanks to @Shangrila for adding this problem and creating all test cases.
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        ostringstream oss;  
        long long num, den;
       
        int sign[2];
        if(numerator>=0){
            sign[0] = 0; 
            num = numerator;
        }else{
            sign[0] = 1; 
            num =-(long long)(numerator);
        }
        if(denominator>=0){
            sign[1] = 0; 
            den = denominator;
        }else{
            sign[1] = 1; 
            den =-(long long)(denominator);
        }
        int s = (sign[0]+sign[1])&0x1;
        if(s==1&&numerator!=0) oss<<"-";

        oss<<num/den;
        num = num%den;
        oss<<(num?".":"");

        unordered_map<long long, int> repeat;
        ostringstream oss_repeat;  
        int i=0, first=0, repeated=false;
        while(num!=0){
            if(repeat.find(num)!=repeat.end()){
                string fraction = oss_repeat.str();
                fraction.insert(repeat[num],1,'(');
                oss<<fraction<<")";
                repeated = true;
                break;
            }else{
                repeat[num] = i++;
            }
            num *=10;            
            oss_repeat<<num/den;
            num = num%den;  
        }
        if(!repeated){
            oss<<oss_repeat.str();
        }
        return oss.str();
    }
};


int main(){
	Solution s;
	cout<<s.fractionToDecimal(1,2)<<endl;
    cout<<s.fractionToDecimal(2,1)<<endl;
    cout<<s.fractionToDecimal(2,3)<<endl;
    cout<<s.fractionToDecimal(1,13)<<endl;
    cout<<s.fractionToDecimal(1,6)<<endl;
    cout<<s.fractionToDecimal(-1, -2147483648)<<endl;
	return 0;
}
