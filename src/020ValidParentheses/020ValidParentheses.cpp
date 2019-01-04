#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
    	if(s.size()%2==1){
    		return false;
    	}
    	
    	stack<char> parenthese;
    	
        for(auto p = s.begin(); p!= s.end(); ++p){
        	if(*p==')'){
        		if(parenthese.size()==0 || parenthese.top()!='('){
        			return false;
        		}
        		parenthese.pop();
        	}else if(*p=='}'){
        		if(parenthese.size()==0 || parenthese.top()!='{'){
        			return false;
        		}
        		parenthese.pop();
        	}else if(*p==']'){
        		if(parenthese.size()==0 || parenthese.top()!='['){
        			return false;
        		}
        		parenthese.pop();
        	}else{
        		parenthese.push(*p);
        	}
        }

        return parenthese.size()==0;
    }
};

int main(){
	Solution s;

	cout<<"()[]{}"<<" is " <<s.isValid("()[]{}")<<endl;
	cout<<"([{}])"<<" is " <<s.isValid("([{}])")<<endl;
	cout<<"([)]"<<" is " <<s.isValid("([)]")<<endl;
	cout<<"]"<<" is " <<s.isValid("]")<<endl;	
	return 0;
} 