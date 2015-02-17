#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <string.h>

using namespace std;

/*
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function may be called multiple times.
*/

// Forward declaration of the read4 API.
char b[] = "abc";
int n, p;
int read4(char *buf){
	if(n-p>=4){
		memcpy(buf, b+p, 4);
		p+=4;
		return 4;
	}else{
		int np = n-p;
		memcpy(buf, b+p, np);
		p+=np;
		return np;
	}
}

class Solution {
public:
	Solution(){
		bytesLeft = 0;
		bytesPos  = 0;
	}
	~Solution(){

	}
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if(buf==NULL||n==0) return 0;
        
        int nn = 0;
        //cout<<bytesLeft<<" "<<bytesPos<<endl;
        if(bytesLeft){
        	if(n>bytesLeft){
        		nn = bytesLeft;
        		n -= bytesLeft;
        		bytesLeft = 0;        		
        	}else{
        		nn = n;
        		bytesLeft -= n;
        		n = 0;
        	}
        	//cout<<" "<<bytesPos<<" "<<bytesLeft<<" "<<nn<<" "<<bytesBuff[bytesPos]<<"#"<<endl;
        	memcpy(buf, bytesBuff+bytesPos, nn);
        	buf+=nn; 
        	if(bytesLeft==0){
        		bytesPos = 0;
        	}else{
        		bytesPos = (bytesPos+nn)%4;
        	}
        	//cout<<bytesLeft<<" "<<bytesPos<<endl<<endl;        	
        }

        int size  = 4;
        int times = n/4;
        int left  = n%4;
        char buffer[4];
        while(times>0&&size==4){
        	size = read4(buffer);
        	memcpy(buf, buffer, size);
        	buf+=size; 
        	nn+=size;
        	times--;
        }
        if(left>0&&size==4){	        
        	size = read4(buffer);
        	//cout<<" "<<size<<endl;
        	if(size>left){
        		nn += left;
        		memcpy(buf, buffer, left);
        		bytesLeft = size-left;
        		//cout<<" "<<bytesPos<<" "<<bytesLeft<<" "<<left<<" "<<buffer[left]<<buffer[left+1]<<"#"<<endl;
        		memcpy(bytesBuff+bytesPos, buffer+left, bytesLeft);        		  	
        	}else{
        		nn += size;
        		memcpy(buf, buffer, size);
        	}
	    }
	    return nn;
    }
private:
	int bytesLeft; 
	int bytesPos;
	char bytesBuff[4];
};

int main(){
	Solution s;
	p = 0;
	n = strlen(b);

	char buffer[1];
	
	cout<<s.read(buffer, 1);
	cout<<buffer[0]<<endl;
	cout<<s.read(buffer, 1);
	cout<<buffer[0]<<endl;
	cout<<s.read(buffer, 1);
	cout<<buffer[0]<<endl;
	cout<<s.read(buffer, 1);
	cout<<buffer[0]<<endl;

	return 0;
}