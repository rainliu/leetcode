#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
		int ret=A[0];
    	for (int i=1; i<n; i++){
    		ret ^=A[i];
    	}
		return ret;        
    }
};


int main(){
	int A[11] = {0, 2, 1, 5, 0, 4, 3, 2, 4, 1, 5};
	int B[5]  = {3, 5, 4, 5, 4};
	int C[1]  = {3};
	int D[7]  = {2, 0, 2, 1, 0, 1, 3};

	Solution s;

	cout <<  s.singleNumber(A,11) << endl;
	cout <<  s.singleNumber(B, 5) << endl;
	cout <<  s.singleNumber(C, 1) << endl;
	cout <<  s.singleNumber(D, 7) << endl;

	return 0;
}
