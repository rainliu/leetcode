159-Longest Substring With At Most Two Distinct Characters
===
Solutions:

a). Brute force to get all substrings (N^2) + Hash Set (N) for each substring (N^2): O(N^3) runtime, O(1) space

b). For at most 2 distinct chars: Invariant + two pointers
  i->invariant substring start position, 
  k->next position which is not equal to char of str[k-1], 
  j->last position which is not equal to char of str[k-1]

for example: [...]->invarint substring
 ij   k
[abaa]c


c). For at most k distinct chars: Invariant + Hash Map to count appear of char
  n->number of distinct char
  i->invariant substring start position, 
  j->next position which the count of char is zero, 
  
for example: [...]->invarint substring
 i    j
[abba]c
count['a']=2
count['b']=2
count['c']=1
