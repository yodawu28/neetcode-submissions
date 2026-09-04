class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);

        string b_str = b.to_string();

        int l = 0;
        int r = b_str.size() - 1;

        while (l < r) {
            char tmp = b_str[l];
            b_str[l] = b_str[r];
            b_str[r] = tmp;

            l++;
            r--;
        }

        return bitset<32>(b_str).to_ulong();
    }
};
