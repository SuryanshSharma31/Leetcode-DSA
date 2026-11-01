class Solution {
public:
    string removeOccurrences(string s, string part) {
        bool x=true;
        stack<char> st;
        while(x){
            x=false;
            for(int i=0;i<s.size();i++){
                st.push(s[i]);
                if(s[i]==part[0] && !x){
                    int a=0;
                    while(i+a<s.size() && a<part.size() && s[i+a]==part[a]){
                        a++;
                    }
                    if(a==part.size()){
                        i=i+a-1;
                        st.pop();
                        x=true;
                    }
                }
              
            }
            string ans="";
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            s=ans;
        }
        return s;
    }
};