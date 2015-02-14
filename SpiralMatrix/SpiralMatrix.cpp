#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        const int M = matrix.size();
        //cout<<"M:"<<M<<endl;
        if(M==0){
        	vector<int> v;
        	return v;
        }
        const int N = matrix[0].size();
        //cout<<"N:"<<N<<endl;
        if(N==0){
        	vector<int> v;
        	return v;
        }

		vector<int> ret(M*N);

    	int SM = 0;
    	int SN = 0;
    	int EM = M-1;
    	int EN = N-1;
    	int i = 0, m, n;
    	do{
    		for(m=SM, n=SN; SM<=EM && n<=EN; n++){
    			ret[i++] = matrix[m][n];
    			//cout<<"0:"<<i<<":"<<matrix[m][n]<<endl;
    		}
    		SM++;
    		for(m=SM, n=EN; m<=EM && SN<=EN; m++){
    			ret[i++] = matrix[m][n];
    			//cout<<"1:"<<i<<":"<<matrix[m][n]<<endl;
    		}
    		EN--;
    		for(m=EM, n=EN; EM>=SM && n>=SN; n--){
    			ret[i++] = matrix[m][n];
    			//cout<<"2:"<<i<<":"<<matrix[m][n]<<endl;
    		}
    		EM--;
    		for(m=EM, n=SN; m>=SM && EN>=SN; m--){
    			ret[i++] = matrix[m][n];
    			//cout<<"3:"<<i<<":"<<matrix[m][n]<<endl;
    		}
    		SN++;
    	}while(i<M*N);

    	return ret;
    }
};


int main(){
	vector<vector<int> >matrix = {{7}, {9}, {6}};
	/*{
	{1,2,3,4,5,6,7,8,9,10},
	{11,12,13,14,15,16,17,18,19,20},
	{21,22,23,24,25,26,27,28,29,30},
	{31,32,33,34,35,36,37,38,39,40},
	{41,42,43,44,45,46,47,48,49,50},
	{51,52,53,54,55,56,57,58,59,60},
	{61,62,63,64,65,66,67,68,69,70},
	{71,72,73,74,75,76,77,78,79,80},
	{81,82,83,84,85,86,87,88,89,90},
	{91,92,93,94,95,96,97,98,99,100}};*/
	//{{1, 2, 3}};//{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	Solution s;
	
	auto ret = s.spiralOrder(matrix);

	for(int i=0; i<ret.size(); i++)
		cout <<  ret[i] << " ";
	cout << endl;

	return 0;
}
