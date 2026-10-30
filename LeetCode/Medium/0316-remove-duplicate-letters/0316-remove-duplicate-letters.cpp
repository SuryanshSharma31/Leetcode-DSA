class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(27,-1);
        vector<bool> visit(27,false);
        stack<char> st;
        string ans="";
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
        }
        for(int i=0;i<s.size();i++){
            while(!st.empty() && !visit[s[i]-'a'] && st.top()>s[i] && i<last[st.top()-'a']){
                visit[st.top()-'a']=false;
                st.pop();
            }
            if(!visit[s[i]-'a']){
                st.push(s[i]);
                visit[s[i]-'a']=true;
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};