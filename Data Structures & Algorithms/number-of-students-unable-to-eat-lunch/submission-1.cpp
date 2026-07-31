class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> st;
        queue<int> q;
        queue<int> q2;
        
        for (int i = sandwiches.size() - 1; i > -1; i--)
        {
            st.push(sandwiches[i]);
        }
        
        for (int i = 0; i < students.size(); i++)
        {
            q.push(students[i]);
        }
        
        while (!q.empty())
        {
            if (st.top() == q.front())
            {
                st.pop();
                q.pop();
            }
            else 
            {
                if (!q2.empty() && q2.front() == st.top())
                {
                    st.pop();
                    q2.pop();
                }
                else
                {
                    int front = q.front();
                    q.pop();
                    q2.push(front);
                }
            }
        }
        
        while (!q2.empty())
        {
            if (q2.front() != st.top())
            {
                break;
            }
            q2.pop();
            st.pop();
        }

        return q2.size();
    }
};