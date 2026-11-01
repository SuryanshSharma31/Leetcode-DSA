class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        vector<int> right(h.size(),1);
        vector<int> left(h.size(),1);
        stack<int> st;
        for(int i=0;i<h.size();i++){
            while(!st.empty() && h[st.top()]>=h[i]){
                left[i]+=left[st.top()];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=h.size()-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i]){
                right[i]+=right[st.top()];
                st.pop();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<h.size();i++){
            ans=max(ans,(left[i]+right[i]-1)*h[i]);
        }
        return ans;
    }
};