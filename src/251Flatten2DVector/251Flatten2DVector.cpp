class Vector2D {
    vector<vector<int>>::iterator it;
    vector<int>::iterator itt;
    vector<vector<int>>::iterator it_end;
public:
    Vector2D(vector<vector<int>>& v) {
        it = v.begin();
        it_end = v.end();
        while(it!=it_end){
            itt = it->begin();
            if(itt==it->end()){
                ++it;
            }else{
                break;
            }
        }
    }
    
    int next() {
        if(!hasNext()) return 0;
        
        int val = *itt;
        ++itt;
        if(itt==it->end()){
            ++it;
            while(it!=it_end){
                itt = it->begin();
                if(itt==it->end()){
                    ++it;
                }else{
                    break;
                }
            }
        }
        
        return val;
    }
    
    bool hasNext() {
        return it != it_end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

#include <iostream>
#include <vector>
using namespace std;

class Vector2D {
private:
  vector<vector<int>> vec2d;
  int i, j;

public:
  Vector2D(vector<vector<int>> &vec2d) {
    this->vec2d = vec2d;
    i = 0;
    j = 0;
  }

  int next() {
    int v = vec2d[j][i];
    i++;
    if (i >= vec2d[j].size()) {
      i = 0;
      j++;
    }
    return v;
  }

  bool hasNext() {
    while (j < vec2d.size()) {
      if (i >= vec2d[j].size()) {
        i = 0;
        j++;
      } else {
        return true;
      }
    }
    return false;
  }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
int main() { return 0; }
