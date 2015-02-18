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
/*
class Solution {
public:
    int maxSubArray(int A[], int n) {
    	int b = 0;
    	int e = n-1;
     	return findSubArray(A, b, e);   
    }

    int findSubArray(int A[], int& b, int& e){
    	if(b==e){
    		return A[b];
    	}
    	int b1 = b;
    	int e1 = (e+b)/2;
    	int b2 = e1+1;
    	int e2 = e;
    	int left = findSubArray(A, b1, e1); cout<<"left:"<<left<<endl;
    	int right= findSubArray(A, b2, e2); cout<<"right:"<<right<<endl;
    	
    	int mixed = left+right;
		if(mixed>=left && mixed>=right){
			b = b1;
			e = e2;
			return mixed;
		}else if(left>=mixed && left>=right){
			b = b1;
			e = e1;
			return left;
		}else{
			b = b2;
			e = e2;
			return right;
		}
    	
    }
};
*/
int main(){
	Solution s;
	
	int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout<<s.maxSubArray(A, 9)<<endl;

	return 0;
}