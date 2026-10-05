class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } 
            else {
                int inner = st.top();
                st.pop();

                int score;

                if (inner == 0) {
                    score = 1;          // ()
                } else {
                    score = 2 * inner;  // (A)
                }

                st.top() += score;
            }
        }

        return st.top();
    }
};
