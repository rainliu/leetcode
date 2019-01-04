#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
private:
  bool dfs(vector<vector<int>> &graph, vector<bool> &visited,
           vector<bool> &onStack, int i) {
    visited[i] = true;
    onStack[i] = true;
    bool loop = false;
    for (int j = 0; j < graph[i].size(); j++) {
      if (!visited[graph[i][j]]) {
        loop = loop || dfs(graph, visited, onStack, graph[i][j]);
      } else if (onStack[graph[i][j]]) {
        return true;
      }
    }
    onStack[i] = false;
    return loop;
  }

  void dfs2(vector<vector<int>> &graph, vector<bool> &visited,
            stack<int> &reversePost, int i) {
    visited[i] = true;
    for (int j = 0; j < graph[i].size(); j++) {
      if (!visited[graph[i][j]]) {
        dfs2(graph, visited, reversePost, graph[i][j]);
      }
    }
    reversePost.push(i);
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &graph) {
    vector<bool> visited(numCourses, false);
    vector<bool> onStack(numCourses, false);
    for (int i = 0; i < numCourses; i++) {
      if (!visited[i]) {
        bool loop = dfs(graph, visited, onStack, i);
        if (loop) {
          return false;
        }
      }
    }
    return true;
  }

  vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto &p : prerequisites) {
      graph[p.second].push_back(p.first);
    }

    vector<int> result;
    if (canFinish(numCourses, graph)) {
      vector<bool> visited(numCourses, false);
      stack<int> reversePost;
      for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
          dfs2(graph, visited, reversePost, i);
        }
      }
      while (!reversePost.empty()) {
        result.push_back(reversePost.top());
        reversePost.pop();
      }
    }
    return result;
  }
};

int main() { return 0; }