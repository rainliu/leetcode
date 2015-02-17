#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/
/*
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	if((m+n)%2){
        	return findMedian(A, m, B, n,  1+(m+n)/2);
        }else{
        	int a = findMedian(A, m, B, n,   (m+n)/2);
        	int b = findMedian(A, m, B, n, 1+(m+n)/2);
        	return double(a+b)/2.0;
        }
    }

    int findMedian(int A[], int m, int B[], int n, int k){
    	if(m>n) return findMedian(B, n, A, m, k);

    	if(m==0) return B[k-1];
    	
    	int la = 0;
    	int ha = m-1;
    	int lb = 0;
    	int hb = n-1;
    	int ma = la + (ha-la)/2;
    	int mb = lb + (hb-lb)/2;
    	if(A[ma]<B[mb]){
    		lb = binarySearch(B, mb, A[ma]);
    		if(k-(ma+1)-lb>0){
    			if(ma+1<=ha){
    				return findMedian(A+ma+1, ha-ma-1+1, B+lb, hb-lb+1, k-(ma+1)-lb);
    			}else{
    				return B[k-(ma+1)-1];
    			}
    		}
    		else{
    			return A[ma];
    		}
    	}else{
    		la = binarySearch(A, mb, B[mb]);
    		if(k-(mb+1)-la>0){
    			if(mb+1<=hb){
    				return findMedian(A+la, ha-la+1, B+mb+1, hb-mb-1+1, k-(mb+1)-la);
    			}else{
    				return A[k-(mb+1)-1];
    			}
    		}
    		else{
    			return B[mb];
    		}
    	}
    }

    int binarySearch(int C[], int hi, int val){
    	int mi;
    	int lo = 0;
    	while(lo<=hi){
    		mi = lo+(hi-lo)/2;
    		
    		if(C[mi]<val) lo = mi+1;
    		else if(C[mi]>val) hi = mi-1;
    		else return mi;
    	}
    	return mi;
    }
};
*/
int main(){
	Solution s;
	{
		int A[] = {1, 3, 5, 7, 9};
		int B[] = {2, 4, 6, 8};
		cout<<s.findMedianSortedArrays(A,5,B,4)<<endl;
	}
	{
		int A[] = {1, 2, 3, 4, 5};
		int B[] = {6, 7, 8, 9};
		cout<<s.findMedianSortedArrays(A,5,B,4)<<endl;
	}
	{
		int A[] = {1, 2, 3, 7, 9};
		int B[] = {6, 8, 10, 11};
		cout<<s.findMedianSortedArrays(A,5,B,4)<<endl;
	}
	{
		int A[] = {1};
		int B[] = {2, 3, 4};
		cout<<s.findMedianSortedArrays(A,1,B,3)<<endl;
	}
	{
		int A[] = {1};
		int B[] = {1};
		cout<<s.findMedianSortedArrays(A,1,B,1)<<endl;
	}
		{
		int A[] = {1,2,5,6};
		int B[] = {3,4};
		cout<<s.findMedianSortedArrays(A,4,B,2)<<endl;
	}
	return 0;
}