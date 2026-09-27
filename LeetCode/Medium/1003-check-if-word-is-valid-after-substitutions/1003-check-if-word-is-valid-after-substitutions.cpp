class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i<s.size()){
            if(s[i]=='c'){
                if(!st.empty() && st.top()=='b') st.pop();
                else return false;
                if(!st.empty() && st.top()=='a') st.pop();
                else return false;
            }
            else{
                st.push(s[i]);
            }
            i++;
        }
        return st.empty();
    }
};