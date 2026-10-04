class Solution {
public:
    string robotWithString(string s) {
        string ans="";
        stack<char> st;
        int n=s.size();
        vector<char> mini(n);
        mini[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            mini[i]=min(mini[i+1],s[i]);
        }
        for(int i=0;i<n;i++){
            st.push(s[i]);
            while(!st.empty() && (i==n-1|| st.top()<=mini[i+1])){
                ans+=st.top();
                st.pop();
            }
        }
        return ans;
    }
};