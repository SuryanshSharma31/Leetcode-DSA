class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        vector<int> ans(temp.size(),0);
        int i=temp.size()-1;
        while(i>=0){
            int j=1;
           while(!st.empty()&& st.top().first<=temp[i]){
            j+=ans[st.top().second];
            st.pop();
           }
           if(!st.empty()) ans[i]=j;
           st.push({temp[i],i});
           i--;
        }
        return ans;
    }
};