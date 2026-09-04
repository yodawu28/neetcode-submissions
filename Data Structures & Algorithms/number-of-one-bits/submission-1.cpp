class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<31>(n).count();
    }
};
