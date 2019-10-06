/*
For at most 2 distinct chars: Invariant + two pointers
i->invariant substring start position,
k->next position which is not equal to char of str[k-1],
j->last position which is not equal to char of str[k-1],

for example: [...]->invarint substring
ij k
[abaa]c
*/
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int i = 0;
        int j = 0;
        int k = 0;
        int global = 0;
        while(k<tree.size()){
            if(k>0 && tree[k]!=tree[k-1]){
                j=k-1;
                while(j>i && tree[j]==tree[k-1]) {
                    --j;
                }
                if(tree[k]!=tree[j]&&tree[j]!=tree[k-1]){
                    global = max(global, k-i);
                    i=j+1;
                }
            }
            ++k;
        }
        return max(global, k-i);
    }
};
