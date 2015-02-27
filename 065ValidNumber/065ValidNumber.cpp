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
https://oj.leetcode.com/problems/valid-number/

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument,
please click the reload button  to reset your code definition.
*/

//[+/-] d./.d/d.d [e[+/-]d]
class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        while(i<n&&s[i]==' ') i++;
        while(i<n&&s[n-1]==' ') n--;
        
        //[+/-]
        if(s[i]=='+') i++; 
        else if(s[i]=='-') i++;
        
        // d./.d/d.d
        bool valid = false;
        while(i<n&&s[i]>='0'&&s[i]<='9'){
            i++;
            valid = true;
        }
        if(i<n&&s[i]=='.'){
            i++;
        }
        while(i<n&&s[i]>='0'&&s[i]<='9'){
            i++;
            valid = true;
        }
        
        //[e[+/-]d]
        if(valid&&i<n&&s[i]=='e'){
            i++;
            
            if(s[i]=='+') i++;
            else if(s[i]=='-') i++;
            
            valid = false;
            while(i<n&&s[i]>='0'&&s[i]<='9'){
                i++;
                valid = true;
            }    
        }
        
        return valid&&i==n;
    }
};