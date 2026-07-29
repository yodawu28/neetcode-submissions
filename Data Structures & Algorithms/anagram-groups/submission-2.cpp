class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        multiset<char> mul_set;

        for (int i = 0; i < s.length(); i++)
        {
            mul_set.insert(s[i]);
        }

        for (int i = 0; i < t.length(); i++)
        {
            if (mul_set.find(t[i]) == mul_set.end())
            {
                return false;
            }
            mul_set.erase(mul_set.find(t[i]));
        }

        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        set<string> my_set;

        int tmp = 0;

        string s;

        while (tmp < strs.size())
        {
            s = strs[tmp];
            tmp++;
            if (my_set.find(s) == my_set.end())
            {
                vector<string>items;
                items.push_back(s);
                my_set.insert(s);

                for (int i = tmp; i < strs.size(); i++)
                {
                    string t = strs[i];
                    if (((my_set.find(t) == my_set.end()) || (s == t)) && isAnagram(s, t))
                    {
                        items.push_back(t);
                        my_set.insert(t);
                    }
                }

                ans.push_back(items);
            }
        }

        return ans;
    }
};
