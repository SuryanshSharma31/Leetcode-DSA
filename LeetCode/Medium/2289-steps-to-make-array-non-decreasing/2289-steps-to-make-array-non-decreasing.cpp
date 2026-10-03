class Solution {
public:
    int totalSteps(vector<int>& nums) {

        int maxi = 0;
        stack<pair<int,int>> st;

        for (int i = 0; i < nums.size(); i++) {

            int count = 0;

            while (!st.empty() && st.top().first <= nums[i]) {
                count = max(count, st.top().second);
                st.pop();
            }

            if (!st.empty()) {
                count++;
            }

            maxi = max(maxi, count);

            st.push({nums[i], count});
        }

        return maxi;
    }
};