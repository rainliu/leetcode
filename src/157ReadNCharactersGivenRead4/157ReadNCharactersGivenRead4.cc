// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if(n<=0){
            return 0;
        }
        int actualRead = 0;
        for (int i=0; i<(n+3)/4; i++){
            int m = read4(buf+actualRead);
            actualRead+=m;
            if(m!=4){
                break;
            }
        }
        if(actualRead>n){
            buf[n]='\0';
            return n;
        }else{
            buf[actualRead]='\0';  
            return actualRead;
        }
    }
};
