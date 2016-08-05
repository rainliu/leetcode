#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

 struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
 };
 
class Solution {
private:
    unordered_map<int, UndirectedGraphNode *> node_map;

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL){
            return NULL;
        }
        
        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
        for(int i=0; i<node->neighbors.size(); i++){
            if(node->neighbors[i]==node){
                root->neighbors.push_back(root);
            }else if(node->neighbors[i]!=NULL){
                auto p = node_map.find(node->neighbors[i]->label);
                if(p==node_map.end()){
                    root->neighbors.push_back(cloneGraph(node->neighbors[i]));
                }else{
                    root->neighbors.push_back(p->second);
                }
            }else{
                root->neighbors.push_back(NULL);
            }
        }

        node_map[root->label]=root;

        return root;
        
    }
};


int main(){
    UndirectedGraphNode *node = new UndirectedGraphNode(0);
    node->neighbors.push_back(node);
    node->neighbors.push_back(node);
    
	Solution s;

    auto root = s.cloneGraph(node);

    printf("%d ", node->label);
    for(int i=0; i<node->neighbors.size(); i++){
        printf("%d ", node->neighbors[i]->label);
    }
    printf("\n");

    printf("%d ", root->label);
    for(int i=0; i<root->neighbors.size(); i++){
        printf("%d ", root->neighbors[i]->label);
    }
    printf("\n");

	return 0;
}
