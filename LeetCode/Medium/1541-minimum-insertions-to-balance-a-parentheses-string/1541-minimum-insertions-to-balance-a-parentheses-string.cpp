class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int i=0;
        int count=0;
        while(i<s.size()){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                i++;
                if(i<s.size() && s[i]==')'){
                    if(st.empty()) count++;
                    else st.pop();
                }
                else{
                    i--;
                    if(st.empty()) count+=2;
                    else {
                        count++;
                        st.pop();
                    }
                }
            }
            i++;
        }
        while(!st.empty()){
            st.pop();
            count+=2;
        }
        return count;
    }
};