#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
		int bits[32];
		int ret;

		for (int j=0; j<32; j++){
			bits[j] = 0;
		}

    	for (int i=0; i<n; i++){
    		for(int j=0; j<32; j++){
    			bits[j]+=(A[i]>>j)&0x1;
    		}
    	}

    	ret = 0;
		for (int j=0; j<32; j++){
			ret |= ((bits[j]%3)!=0)<<j;
		}    	

		return ret;        
    }
};


int main(){
	int A[16] = {0, 2, 1, 5, 0, 4, 0, 5, 3, 2, 1, 4, 4, 1, 2, 5};
	int B[8]  = {3, 5, 4, 3, 5, 4, 5, 4};
	int C[1]  = {3};
	int D[10]  = {2, 1, 0, 2, 1, 0, 0, 1, 2, 3};

	Solution s;

	cout <<  s.singleNumber(A,16) << endl;
	cout <<  s.singleNumber(B, 8) << endl;
	cout <<  s.singleNumber(C, 1) << endl;
	cout <<  s.singleNumber(D, 10) << endl;

	return 0;
}
