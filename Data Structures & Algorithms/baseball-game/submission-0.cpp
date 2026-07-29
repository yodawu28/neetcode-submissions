class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        int n = operations.size();

        for (int i = 0; i < n; i++)
        {
            string item = operations[i];

            if (item == "C")
            {
                st.pop();
            }
            else if (item == "D")
            {
                int last_score = st.top();
                last_score *= 2;
                st.push(last_score);
            }
            else if (item == "+")
            {
                int score_1 = st.top();
                st.pop();
                int score_2 = st.top();
                st.push(score_1);

                int score = score_1 + score_2;
                st.push(score);
            }
            else
            {
                int score = stoi(item);
                st.push(score);
            }
        }

        int sum = 0;
        while (!st.empty())
        {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};