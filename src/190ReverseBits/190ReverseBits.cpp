class Solution {
    uint8_t lut[256];
public:
    Solution(){
        for(int i=0; i<256; ++i){
            uint8_t r = 0;
            for(int j=0; j<8; ++j){
                r |= ((i>>j)&0x1)<<(7-j);
            }
            lut[i]= r;
        }
    }
    uint32_t reverseBits(uint32_t n) {
        uint8_t* ptr = (uint8_t*)&n;
        uint32_t result = 0;
        for(int i=0; i<4; ++i){
            result |= lut[*ptr++]<<(3-i)*8;    
        }
        return result;
    }
};


#include <iostream>
using namespace std;

class Solution {
private:
  uint8_t LUT[256];

private:
  uint8_t resverse(uint8_t b) {
    uint8_t r = 0;
    for (int i = 0; i < 8; i++) {
      r |= ((b >> (7 - i)) & 0x1) << i;
    }
    return r;
  }

public:
  Solution() {
    for (int i = 0; i < 256; i++) {
      LUT[i] = resverse(i);
    }
  }
  uint32_t reverseBits(uint32_t n) {
    uint8_t *b = (uint8_t *)(&n);
    uint8_t t = LUT[b[0]];
    b[0] = LUT[b[3]];
    b[3] = t;

    t = LUT[b[1]];
    b[1] = LUT[b[2]];
    b[2] = t;
    return n;
  }
};

int main() {
  Solution s;
  cout << s.reverseBits(43261596) << endl;
}
