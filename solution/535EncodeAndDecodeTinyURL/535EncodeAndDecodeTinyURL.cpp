#include <cstdint>
#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
private:
  unordered_map<string, uint64_t> short2id;
  vector<string> id2long;
  const string LUT =
      "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  const int LUT_SIZE = 62;

public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    uint64_t id = id2long.size();
    id2long.push_back(longUrl);
    ostringstream oss;
    uint64_t id2 = id;
    do {
      oss << LUT[id % LUT_SIZE];
      id = id / LUT_SIZE;
    } while (id);
    string shortUrl = "http://tinyurl.com/" + oss.str();
    short2id[shortUrl] = id2;
    return shortUrl;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    uint64_t id = short2id[shortUrl];
    if (id < id2long.size()) {
      return id2long[id];
    }
    return "";
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main() { return 0; }