class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<int> st;
        int i=0;
        
        while(i<num.size()){
             while(!st.empty() && k>0 &&  st.top()>(num[i]-'0')){
                st.pop();
                k--;
             }
             if(st.empty() && num[i]=='0') i++;
             else st.push((num[i++]-'0'));
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans.push_back(st.top()+'0');
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans=="" ? "0": ans ;
    }
};
