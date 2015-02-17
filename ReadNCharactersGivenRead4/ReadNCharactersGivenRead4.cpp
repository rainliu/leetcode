#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

/*
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, 
it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) 
that reads n characters from the file.

Note:
The read function will only be called once for each test case.
*/

// Forward declaration of the read4 API.
char b[] = "hGBfyEfMOCxdLIIBeHCScmXupglxlLPLWDkAxxOHPSzBzibLqypQRIiNgCzWsqATwvXYdwZnrqvsTjMnyvYmCoukwgOHHcWfAUvbRbWZnlhnmmIIulLrepgUXzaUHyAbmoBBZKIdKlTAoriOjwjUSsiJAiCwiKkodimbihRoNrGJeITllNYfmzfZljFhpBqjJeQQWJFvdkaULBNgKgVeQWXNxLROhfcTZqaqlngNYfHRjlldiHRBnMSZbiZBAzVaXOisJpItWWFiMUNndAThbfQUcLRoFPFfDwADDOKJcWTavTTOHwQNKPmjxNrpHuJyscxEsGVZYJdjlNnNJQGtrJtJYLVnzDouhhIrFRmUwNCaDQvuyTfjnlDLMvdUacWzzeeTrtNYHQqvwNwsIeNHfdlvXHziCroXHMeDZfKIoAulkYQYdwJTivzEveTNUCKnOVLiMPjecvZzvHGvfugnjIzaWXhqbMVGzvEzNkwoIPLUiwNhetnz";
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
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if(buf==NULL||n==0) return 0;
        
        int nn    = 0;
        int size  = 4;
        int times = n/4;
        int left  = n%4;
        while(times>0&&size==4){
        	size = read4(buf);
        	buf+=size; 
        	nn+=size;
        	times--;
        }
        if(left>0&&size==4){
	        char buffer[4];
        	size = read4(buffer);
        	nn += (size>left?left:size);
        	memcpy(buf, buffer, (size>left?left:size));
	    }
	    return nn;
    }
};

int main(){
	Solution s;

	p = 0;
	n = strlen(b);

	char buffer[1000];
	cout<<n<<" "<<s.read(buffer, 507)<<endl;
	
	return 0;
}
