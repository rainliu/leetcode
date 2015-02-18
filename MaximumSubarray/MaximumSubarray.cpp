#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
       int b = 0;
       int e = n-1;
       return findSubArray(A, b, e);   
    }

    int findSubArray(int A[], int b, int e){
       if(b==e){
           return A[b];
       }
       int b1 = b;
       int e1 = (e+b)/2;
       int b2 = e1+1;
       int e2 = e;
       int left = findSubArray(A, b1, e1); 
       int right= findSubArray(A, b2, e2); 
       
       int lmax = numeric_limits<int>::min();
       int rmax = numeric_limits<int>::min();
       int sum;
       sum = 0;
       for(int i=e1; i>=b1; --i){
            sum+=A[i];
            if(sum>lmax)
                lmax = sum;
       }
       sum = 0;
       for(int i=b2; i<=e2; i++){
            sum+=A[i];
            if(sum>rmax)
                rmax = sum;
       }
       int mixed = lmax+rmax;

       if(mixed>=left && mixed>=right){
           return mixed;
       }else if(left>=mixed && left>=right){
           return left;
       }else{
           return right;
       }
    }
};

class Solution2 {
public:
    int maxSubArray(int A[], int n) {
        if(n==0) return 0;
        if(n==1) return A[0];

        int result = numeric_limits<int>::min();
        int E = 0;
        for(int j=0; j<n; j++){
            E += A[j];
            if(E>result){
                result = E;
            }
            if(E<0){
                E = 0;
            }
        }
        
        return result;
    }
};


int main(){
	Solution s;
	
    {
	   int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	   cout<<s.maxSubArray(A, 9)<<endl;
    }
    {
       int A[] = {-2, 1};
       cout<<s.maxSubArray(A, 2)<<endl;
    }
	return 0;
}