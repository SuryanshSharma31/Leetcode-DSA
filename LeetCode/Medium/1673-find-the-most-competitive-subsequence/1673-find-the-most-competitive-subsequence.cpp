class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int i=0;
        int count=0;
        while(i<nums.size()){
            while(!st.empty() && st.top()>nums[i] && k-count<=nums.size()-i-1 ){
                    st.pop();
                    count--;
                
            }
            if(count<k){
            st.push(nums[i]);
            count++;
            }
            i++;
        }
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            ans[i]=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};