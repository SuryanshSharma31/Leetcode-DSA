class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int i=prices.size()-1;
        vector<int> ans(prices.size());
        while(i>=0){
                while(!st.empty() && st.top()>prices[i]) st.pop();
                
            if(!st.empty()){
                ans[i]=(prices[i]-st.top());
            }
            else {
                ans[i]=prices[i];
            }
            st.push(prices[i--]);
            
        }
        return ans;
    }
};