class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int small=nums[i];
            int large=nums[i];
            for(int j=i;j<nums.size();j++){
                small=min(small,nums[j]);
                large=max(large,nums[j]);
                ans+=large-small;
            }
        }
        return ans;
    }
};