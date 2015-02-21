#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int N) {
        vector<vector<int> > matrix;
        for (int i=0; i<N; i++){
            vector<int> v(N);
            matrix.push_back(v);
        }

        vector<int> ret(N*N);

        int SM = 0;
        int SN = 0;
        int EM = N-1;
        int EN = N-1;
        int i = 0, m, n;
        do{
            for(m=SM, n=SN; SM<=EM && n<=EN; n++){
                matrix[m][n] = ++i;
                //cout<<"0:"<<i<<":"<<matrix[m][n]<<endl;
            }
            SM++;
            for(m=SM, n=EN; m<=EM && SN<=EN; m++){
                matrix[m][n] = ++i;
                //cout<<"1:"<<i<<":"<<matrix[m][n]<<endl;
            }
            EN--;
            for(m=EM, n=EN; EM>=SM && n>=SN; n--){
                matrix[m][n] = ++i;
                //cout<<"2:"<<i<<":"<<matrix[m][n]<<endl;
            }
            EM--;
            for(m=EM, n=SN; m>=SM && EN>=SN; m--){
                matrix[m][n] = ++i;
                //cout<<"3:"<<i<<":"<<matrix[m][n]<<endl;
            }
            SN++;
        }while(i<N*N);

        return matrix;        
    }
};


int main(){
	Solution s;
	int n = 5;
	auto ret = s.generateMatrix(n);

	for(int i=0; i<ret.size(); i++){
		for(int j=0; j<ret[i].size(); j++){         
            cout <<  ret[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}
