#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify 
repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that 
occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    	vector<string> result;
    	unordered_map<long long, int> tenlettermap;
    	for(int i=0; i<=int(s.size())-10; i++){
    		auto substr = s.substr(i, 10);
    		auto hval = convert(substr);
    		if(tenlettermap.find(hval)!=tenlettermap.end()){
    			tenlettermap[hval]++;
    		}else{
    			tenlettermap[hval] = 1;
    		}
    	}
    	for(auto p=tenlettermap.begin(); p!=tenlettermap.end(); ++p){
    		if(p->second>1){
    			result.push_back(convertBack(p->first));
    		}
    	}
    	return result;
    }

    long long convert(string substr){
    	long long result = 0;
    	long long bits;
    	for(int i=0; i<10; i++){
    		if(substr[i]=='A'){
    			bits = 0;
    		}else if(substr[i]=='C'){
    			bits = 1;
    		}else if(substr[i]=='G'){
    			bits = 2;
    		}else{
    			bits = 3;
    		}
    		result |= bits<<(2*i); 
    	}
    	return result;
    }
    string convertBack(long long hval){
    	ostringstream oss;
    	for(int i=0; i<10; i++){
    		int bits = hval&0x3;
    		if(bits==0){
    			oss<<'A';
    		}else if(bits==1){
    			oss<<'C';
    		}else if(bits==2){
    			oss<<'G';
    		}else{
    			oss<<'T';
    		}
    		hval >>= 2; 
    	}
    	return oss.str();
    }
};


class Solution2 {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    	vector<string> result;
    	unordered_map<string, int> tenlettermap;
    	for(int i=0; i<int(s.size())-10; i++){
    		auto substr = s.substr(i, 10);
    		if(tenlettermap.find(substr)!=tenlettermap.end()){
    			tenlettermap[substr]++;
    		}else{
    			tenlettermap[substr] = 1;
    		}
    	}
    	for(auto p=tenlettermap.begin(); p!=tenlettermap.end(); ++p){
    		if(p->second>1){
    			result.push_back(p->first);
    		}
    	}
    	return result;
    }
};

int main(){
	Solution s;

	{
		string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

		auto output = s.findRepeatedDnaSequences(str);
		for(const auto &p : output){
			cout<<p<<endl;
		}
	}
	{
		string str = "";

		auto output = s.findRepeatedDnaSequences(str);
		for(const auto &p : output){
			cout<<p<<endl;
		}
	}
	{
		string str = "AAAAAAAAAAA";

		auto output = s.findRepeatedDnaSequences(str);
		for(const auto &p : output){
			cout<<p<<endl;
		}
	}
	return 0;
}