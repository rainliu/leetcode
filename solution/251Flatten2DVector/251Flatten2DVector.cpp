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