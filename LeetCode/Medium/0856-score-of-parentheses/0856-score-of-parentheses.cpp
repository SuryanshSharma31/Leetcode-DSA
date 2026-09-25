class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
st.push(0);

for(char c : s) {
    if(c == '(') {
        st.push(0);
    }
    else {
        int current = st.top();
        st.pop();

        int value;

        if(current == 0)
            value = 1;
        else
            value = 2 * current;

        st.top() += value;
    }
}

return st.top();
    }
};