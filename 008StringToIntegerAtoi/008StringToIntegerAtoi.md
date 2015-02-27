008-String To Integer (Atoi)
===
Solutions

a). One pass with correctly handling '+'/'-'/MAX_INT/MIN_INT: O(N) runtime, O(1) space

if (num > MAX_INT/10 || num == MAX_INT/10 && digit >= 8) {
  return sign == 1 ? MAX_INT : MIN_INT;
}
