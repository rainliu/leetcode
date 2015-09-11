#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	char pattern[4][3] = {
    		{'I', 'V', 'X'},
    		{'X', 'L', 'C'},
    		{'C', 'D', 'M'},
    		{'M'}
    	};
    	int base[4] = {1, 10, 100, 1000};
    	int value[3]= {1,  5,  10};
    	int sum = 0;

    	int i, j;
    	for (j=0, i=s.size()-1; i>=0; i--){
    		if(s[i]==pattern[j][0]){//I, II, III
    			sum+=base[j]*value[0];
    		}else if(s[i]==pattern[j][1]){
    			if(i-1>=0 && s[i-1]==pattern[j][0]){//IV
    				sum+=base[j]*(value[1]-value[0]);
    				i--;
    			}else{//V
    				sum+=base[j]*value[1];
    			}
    			j++;
    		}else if(s[i]==pattern[j][2]){
    			if(i-1>=0 && s[i-1]==pattern[j][0]){//IX
    				sum+=base[j]*(value[2]-value[0]);
    				i--;
    			}else{//X
    				sum+=base[j]*value[2];
    			}
    			j++;
    		}else{
    			j++;
    			i++;
    		}
    	}

    	return sum;  
    }
};


int main(){
	Solution s;
	string str = "MCMXCIX";//"MMCDXX";

	cout << s.romanToInt(str) << endl;

	return 0;
}
