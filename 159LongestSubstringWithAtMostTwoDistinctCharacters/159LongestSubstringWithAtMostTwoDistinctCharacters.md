159-Longest Substring With At Most Two Distinct Characters
===
Solutions:

a). Brute force to get all substrings (N^2) + Hash Set (N) for each substring (N^2): O(N^3) runtime, O(1) space

b). For at most 2 distinct chars: Invariant + two pointers<br>
  i->invariant substring start position, <br>
  k->next position which is not equal to char of str[k-1], <br>
  j->last position which is not equal to char of str[k-1], <br>

for example: [...]->invarint substring<br>
 ij   k<br>
[abaa]c<br>

c). For at most k distinct chars: Invariant + Hash Map to count appear of char<br>
  n->number of distinct char<br>
  i->invariant substring start position, <br>
  j->next position which the count of char is zero, <br>
  
for example: [...]->invarint substring<br>
 i    j<br>
[abba]c<br>
count['a']=2<br>
count['b']=2<br>
count['c']=1<br>
