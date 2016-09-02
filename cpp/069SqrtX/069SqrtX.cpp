#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int sqrt(int x) {
    	if(x==0||x==1) return x;

    	int lo = 0;
    	int hi = x;
    	long long mi;
    	while(lo<=hi){
    		mi = lo+(hi-lo)/2;
    		long long m2 = mi*mi;
    		if(m2<x) lo = mi+1;
    		else if(m2>x) hi = mi-1;
    		else return mi; 
    	}    
    	
    	return hi;
    }
};

int main(){
	Solution s;

	cout<<"sqrt(2)="<<s.sqrt(2)<<endl;

	cout<<"sqrt(99)="<<s.sqrt(99)<<endl;

	cout<<"sqrt(2147483647)="<<s.sqrt(2147483647)<<endl;

	return 0;
}