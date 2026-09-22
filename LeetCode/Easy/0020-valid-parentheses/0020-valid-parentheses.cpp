class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='('||s[i]=='{'|| s[i]=='[') st.push(s[i]);
            else if(s[i]==')' && !st.empty() && st.top()=='(') st.pop();
            else if(s[i]=='}' && !st.empty() && st.top()=='{') st.pop();
            else if(s[i]==']' && !st.empty() && st.top()=='[') st.pop();
            else return false;
            i++;
            
        }
        return st.empty() ? true:false;
    }
};