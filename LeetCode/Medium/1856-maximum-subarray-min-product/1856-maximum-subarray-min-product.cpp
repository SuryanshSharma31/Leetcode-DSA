class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long int maxi=0;
        int n=nums.size();
        vector<long long int> prefix(n+1,0);
        vector<int> left(n,-1);
        vector<int> right(n,n);
        stack<int> st;
        for(int i=0;i<nums.size();i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();

            if(!st.empty()) left[i]=st.top();

            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();

            if(!st.empty()) right[i]=st.top();

            st.push(i);
        }
        for(int i=0;i<nums.size();i++){
            long long sum= prefix[right[i]]-prefix[left[i]+1];
            long long product=sum*nums[i];
            maxi=max(product,maxi);
        }
        return (maxi)%1000000007;
    }
};