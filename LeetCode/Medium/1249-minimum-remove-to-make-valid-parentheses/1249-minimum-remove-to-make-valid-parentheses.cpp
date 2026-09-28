class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        int i=0;
        string ans="";
        while(i<s.size()){
            if(s[i]=='(' || s[i]==')'){
                if(s[i]=='(') st.push(s[i]);
                else if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else {
                    i++;
                    continue;
                }
            }
            ans+=s[i++];
        }
        reverse(ans.begin(),ans.end());
        s=ans;
        ans="";
        stack<char> sd;
     i=0;
       
        while(i<s.size()){
            if(s[i]=='(' || s[i]==')'){
                if(s[i]==')') sd.push(s[i]);
                else if(!sd.empty() && sd.top()==')'){
                    sd.pop();
                }
                else {
                    i++;
                    continue;
                }
            }
            ans+=s[i++];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};