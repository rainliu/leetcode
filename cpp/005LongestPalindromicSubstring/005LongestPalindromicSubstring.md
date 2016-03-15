005-Longest Palindromic Substring
===
Solutions:

a). Brute force: O(N^3) runtime, O(1) space

b). Dynamic Programming: O(N^2) runtime, O(n) space

E[i,j] = E[i+1, j-1]==true && S[i]==S[j]

E[i,i] = true

E[i,i+1] = S[i]==S[i+1]

c). ExpandAroundCenter(i, i) and ExpandAroundCenter(i, i+1): O(N^2) runtime, O(1) space
