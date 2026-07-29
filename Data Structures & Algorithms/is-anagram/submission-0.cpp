class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
            multiset<char> mul_set;

            for (int i = 0; i < s.length(); i++) {
                mul_set.insert(s[i]);
            }

            for (int i = 0; i < t.length(); i++) {
                if (mul_set.find(t[i]) == mul_set.end()) {
                return false;
                }
                mul_set.erase(mul_set.find(t[i]));
            }

            return true;
    }
};
