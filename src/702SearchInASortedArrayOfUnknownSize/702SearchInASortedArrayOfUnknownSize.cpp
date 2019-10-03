// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int lo = 0;
        int mi = 1;
        while(true){
            int value = reader.get(mi);
            if (value == target) {
                return mi;
            }else if (value > target) {
                return binarySearch(reader, target, lo, mi-1);
            }else {
                mi *= 2;
            }
        }
        return -1;
    }
    
    int binarySearch(const ArrayReader& reader, int target, int lo, int hi) {
        while (lo <= hi) {
            int mi = lo + (hi-lo)/2;
            int value = reader.get(mi);
            if (value == target) return mi;
            else if (value > target) hi = mi-1;
            else lo = mi+1;
        }
        return -1;
    }
    
};
