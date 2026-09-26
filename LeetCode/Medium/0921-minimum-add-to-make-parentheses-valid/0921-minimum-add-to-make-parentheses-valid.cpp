class Solution {
public:
    int minAddToMakeValid(string s) {
        int i=0;
        stack<char> st;
        while(i<s.size()){
            if(s[i]=='(') st.push(s[i]);
            else{
                if(!st.empty() && st.top()=='(') st.pop();
                else st.push(s[i]);
            }
            i++;
        }
        int ans=0;
        while(!st.empty()){
            st.pop();
            ans++;
        }
        return ans;
    }
};