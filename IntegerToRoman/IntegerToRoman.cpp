#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string pattern[4][3] = {
            {"I", "V", "X"},
            {"X", "L", "C"},
            {"C", "D", "M"},
            {"M"}
        };
        int base[4] = {1, 10, 100, 1000};
        int value[3]= {1,  5,  10};
        int i, j, v;
        ostringstream s;

        for(j = 3; j>=0; j--){
            v = num/base[j];
            num-=v*base[j];
            if(v<=3){//I, II, III
                for(i=0; i<v; i++){
                    s << pattern[j][0];
                }
            }else if(v==4){//IV
                s << pattern[j][0] << pattern[j][1];
            }else if(v<=8){//V, VI, VII, VIII
                s << pattern[j][1];
                v-=5;
                for(i=0; i<v; i++){
                    s << pattern[j][0];
                }
            }else if(v==9){
                s << pattern[j][0] << pattern[j][2];
            }
        }

        return s.str(); 
    }
};


int main(){
	Solution s;
	int num1 = 1999;//"MCMXCIX";
    int num2 = 2420;//"MMCDXX";

	cout << s.intToRoman(num1) << endl;
    cout << s.intToRoman(num2) << endl;

	return 0;
}
