#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
class MinStack4 {
public:
    void push(int x) {
        mainstack.push_back(x);
        if(ministack.size()==0){
            ministack.push_back(x);
        }else{
            if(x<ministack.back()){
                ministack.push_back(x);        
            }else{
                ministack.push_back(ministack.back());
            }
        }
    }

    void pop() {
        mainstack.pop_back();
        ministack.pop_back();
    }

    int top() {
        return mainstack.back();
    }

    int getMin() {
        return ministack.back();
    }

private:
    list<int> mainstack;
    list<int> ministack;
};

class MinStack3 {
public:    
    MinStack3(){
        m_top = -1;
        m_capacity = 0;
    }
public:
    void push(int x) {
        if(m_top+1<m_capacity){
            mainstack[m_top+1]=x;
            if(x<ministack[m_top+1]){
                ministack[m_top+1]=x;        
            }else{
                ministack[m_top+1]=ministack[m_top];
            }
        }else{
            mainstack.push_back(x);
            if(m_top==-1){
                ministack.push_back(x);
            }else{
                if(x<ministack[m_top]){
                    ministack.push_back(x);        
                }else{
                    ministack.push_back(ministack[m_top]);
                }
            }
            ++m_capacity;
        }
        ++m_top;
    }

    void pop() {
        --m_top;
    }

    int top() {
        return mainstack[m_top];
    }

    int getMin() {
        return ministack[m_top];
    }

private:
    int m_top;
    int m_capacity;
    vector<int> mainstack;
    vector<int> ministack;
};

class MinStack {  
public:  
    void push(int x) {  
        S.push(x);  
        if(MinS.empty() || x<=MinS.top()){ 
            MinS.push(x);  
        }
    }  
  
    void pop(){  
        int temp=S.top();  
        S.pop();  
        if(temp == MinS.top()){
            MinS.pop();  
        }
    }  
  
    int top(){  
        return S.top();  
    }  

    int getMin(){  
        return MinS.top();  
    }  

private:  
    stack<int> S;
    stack<int> MinS;  
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
