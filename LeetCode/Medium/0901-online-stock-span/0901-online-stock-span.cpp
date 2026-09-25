class StockSpanner {
public:
    int i=0;
        stack<pair<int,int>> st;
        vector<int> ans;
    StockSpanner() {
    }
    
    int next(int price) {
        int curr=1;
        while(!st.empty() && st.top().first<=price){
            curr+=ans[st.top().second];
            st.pop();
        }
        st.push({price,i++});
        ans.push_back(curr);
        return curr;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */