class Solution {
    static constexpr int max_threshold = 214748364;
public:
    int myAtoi(string str) {
        bool sign = false;
        bool neg = false;
        int val = 0;
        for(const auto& ch : str){
            if(!sign&&ch==' '){
            }else if(!sign && (ch=='-'||ch=='+')){
                sign = true;
                neg = ch=='-';
            }else if(ch>='0'&&ch<='9'){
                sign = true;
                if(val>max_threshold ||
                   (val == max_threshold && 
                    ((neg&&ch>='8')||(!neg&&ch>='7'))
                   )){
                    return neg ? numeric_limits<int>::min() : numeric_limits<int>::max();
                }else{
                    val = val*10+int(ch-'0');
                }
            }else{
                break;
            }
        }
        return neg ? -val : val;
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

/*
https://oj.leetcode.com/problems/string-to-integer-atoi/

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, 
please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. 
If you still see your function signature accepts a const char * argument, 
please click the reload button  to reset your code definition.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, 
or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. 
If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

class Solution {
public:
    int atoi(string str) {
    	int b = 0;
    	int e = str.size()-1;
    	while(b<=e&&str[b]==' ') ++b;
    	while(b<=e&&str[e]==' ') --e;

    	bool digits_start = false;
    	bool negative = false;
    	long long early_terminated_value = -((long long)numeric_limits<int>::min());
    	long long val = 0;
    	while(b<=e){
    		if(str[b]=='+' && !digits_start){
    			digits_start = true;
    		}else if(str[b]=='-' && !digits_start){
    			negative = true;
    			digits_start = true;
    		}else if(str[b]>='0' &&str[b]<='9'){
    			val = ((long long)(str[b]-'0'))+ val*10;
    			if(val>=early_terminated_value){
    				break;
    			}
    		}else{
    			break;
    		}

    		b++;
    	}    
    	
    	val = negative ? -val: val;
    	return val>numeric_limits<int>::max() ? numeric_limits<int>::max() :
    	       val<numeric_limits<int>::min() ? numeric_limits<int>::min() : val;
    }
};

int main(){
	Solution s;
	cout<<s.atoi("  +120  ")<<endl;
	cout<<s.atoi("  -120  ")<<endl;
	cout<<s.atoi("  -120w  ")<<endl;
	cout<<s.atoi("  -2147483648  ")<<endl;
	cout<<s.atoi(" 2147483647 w")<<endl;
	cout<<s.atoi(" -2147483647 w")<<endl;
	cout<<s.atoi("  +2147483648  ")<<endl;
	cout<<s.atoi("  -21474836483800  ")<<endl;
	return 0;
}
