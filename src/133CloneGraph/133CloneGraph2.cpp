#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/**
 * Definition for undirected graph.
 */ 
 struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
};
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node==nullptr){
            return nullptr;
        }
        UndirectedGraphNode *r=nullptr, *p, *y;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        unordered_map<UndirectedGraphNode *, bool> visited;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            auto n = q.front(); q.pop();
            if (m.find(n)==m.end()){
                p=new UndirectedGraphNode(n->label);
                m[n]=p;
                if (r==nullptr){
                    r = p;
                }
            }else{
                p = m[n];
            }
            for (auto x: n->neighbors) {
                if (m.find(x)==m.end()){
                    y=new UndirectedGraphNode(x->label);
                    m[x]=y;
                    
                }else{
                    y=m[x];
                }
                p->neighbors.push_back(y);
                if (!visited[x]){
                    q.push(x);
                    visited[x]=true;
                }
            }
        }
        return r;
    }
};

int main(){
    auto node = new UndirectedGraphNode(0);
    node->neighbors.push_back(node);
    node->neighbors.push_back(node);
    Solution s;
    auto r = s.cloneGraph(node);
    cout<<r->label<<endl;
    for (auto x:r->neighbors){
        cout<<x->label<<" ";    
    }
    return 0;
}