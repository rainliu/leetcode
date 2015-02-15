#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
    	int result = 0;
        for(auto p = tokens.begin(); p!= tokens.end(); ++p){
        	if(*p=="+" || *p=="-" || *p=="*" || *p=="/"){
        		int op2 = atoi(notation.top().c_str());	notation.pop();
        		int op1 = atoi(notation.top().c_str()); notation.pop();
        		if(*p=="+"){
        			result = op1+op2;
        		}else if(*p=="-"){
        			result = op1-op2;
        		}else if(*p=="*"){
        			result = op1*op2;
        		}else{//"/"
        			result = op1/op2;
        		}
        		//cout<<" "<<result<<"\n";
				notation.push(to_string(result));
        	}else{
        		notation.push(*p);
        	}
        }

        return atoi(notation.top().c_str());
    }

private:
	stack<string> notation;
};

int main(){
	Solution s;

	vector<string> notation1 = {"2", "1", "+", "3", "*"};
	vector<string> notation2 = {"4", "13", "5", "/", "+"};

	cout<<s.evalRPN(notation1)<<"\n";
	cout<<s.evalRPN(notation2)<<"\n";

	return 0;
}  