159-Longest Substring With At Most Two Distinct Characters
===
Solutions:

a). Brute force to get all substrings (N^2) + Hash Set (N) for each substring (N^2): O(N^3) runtime, O(1) space

b). Invariant:  
  i->invariant substring start position, 
  k->next position which is not equal to char of str[k-1], 
  j->last position which is not equal to char of str[k-1]

for example: [...]->invarint substring
 ij   k
[abaa]c
