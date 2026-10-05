class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            while(!st.empty() &&(st.top()=='A'|| st.top()=='C')){
                if(i<s.size()-1 && st.top()=='A'&& s[i+1]=='B'){
                    i++;
                    st.pop();
                }
                else if(i<s.size()-1 && st.top()=='C'&& s[i+1]=='D'){ st.pop();
                i++;
                }
                else break;
            }

        }
        int count=0;
        while(!st.empty()){
            st.pop();
            count++;
        }
        return count;
    }
};