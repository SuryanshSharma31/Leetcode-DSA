class Solution {
public:
    int minSwaps(string s) {
        int ans=0;
       stack<char> st;
       for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                if(st.empty()){
                    ans++;
                    st.push('[');
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
       }
       return ans;
    }
};