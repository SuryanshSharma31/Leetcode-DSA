class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        int i=0;
        string str="";
        while(i<s.size()){
            while(i<s.size()  && s[i]!='(' &&  s[i]!=')'){
                str+=s[i++];
            }
            if(s[i]=='('){
                st.push(str);
                str="";
            }
            else if(s[i]==')'){
                reverse(str.begin(),str.end());
                string x=str;
                if(!st.empty()) {
                    str=st.top()+x;
                st.pop();
                }
                else str=x;
            }
            i++;
            
        }
        return str;
    }
};