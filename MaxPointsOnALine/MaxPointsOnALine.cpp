#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 (ax-cx)*(by-cy) == (bx-cx)*(ay-cy) 
*/

 /**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int size = points.size();
        for(int i=0; i<size; i++){
        	for(int j=i+1; j<size; j++){
        		
        	}
        }
    }
};

int main(){
	Solution s;

	return 0;
}