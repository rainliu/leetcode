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

class MinStack2 {
public:
    MinStack2(){
        capacity = 1;
        size = 0;
        mainstack = new int[capacity];
        ministack = new int[capacity];
    }
    ~MinStack2(){
        delete []mainstack;
        delete []ministack;
    }
public:
    void push(int x) {
        if(capacity<size+1){
            int *mainstack2 = new int[size*2];
            int *ministack2 = new int[size*2];
            memcpy(mainstack2, mainstack, sizeof(int)*size);
            memcpy(ministack2, ministack, sizeof(int)*size);
            delete []mainstack;
            delete []ministack;
            mainstack = mainstack2;
            ministack = ministack2;
        }

        mainstack[size] = x;
        if(size==0){
            ministack[size] = size;
        }else{
            if(x<mainstack[ministack[size-1]]){
                ministack[size] = size;        
            }else{
                ministack[size] = ministack[size-1];
            }
        }
        ++size;
    }

    void pop() {
        --size;
    }

    int top() {
        return mainstack[size-1];
    }

    int getMin() {
        return mainstack[ministack[size-1]];
    }

private:
    int capacity;
    int size;
    int *mainstack;
    int *ministack;
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
