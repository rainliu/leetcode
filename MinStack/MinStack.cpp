#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(int x) {
        mainstack.push(x);
        if(ministack.size()==0){
            ministack.push(x);
        }else{
            if(x<ministack.top()){
                ministack.push(x);        
            }else{
                ministack.push(ministack.top());
            }
        }
    }

    void pop() {
        mainstack.pop();
        ministack.pop();
    }

    int top() {
        return mainstack.top();
    }

    int getMin() {
        return ministack.top();
    }

private:
    stack<int> mainstack;
    stack<int> ministack;
};

int main(){
	MinStack s;
	
    s.push(1); cout<<s.getMin()<<"\n";
    s.push(4); cout<<s.getMin()<<"\n";
    s.push(3); cout<<s.getMin()<<"\n";
    s.push(0); cout<<s.getMin()<<"\n";
    s.push(3); cout<<s.getMin()<<"\n";
    s.pop();   cout<<s.getMin()<<"\n";
    s.pop();   cout<<s.getMin()<<"\n";
    s.pop();   cout<<s.getMin()<<"\n";
	return 0;
}
