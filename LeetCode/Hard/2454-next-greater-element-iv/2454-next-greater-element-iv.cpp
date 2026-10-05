class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> st1;
        stack<int> st2;

        for (int i = 0; i < n; i++) {

            // Elements waiting for their second greater
            vector<int> temp;

            while (!st2.empty() && nums[st2.top()] < nums[i]) {
                ans[st2.top()] = nums[i];
                st2.pop();
            }

            // Elements getting their first greater
            while (!st1.empty() && nums[st1.top()] < nums[i]) {
                temp.push_back(st1.top());
                st1.pop();
            }

            // Move them to second-greater stack
            while (!temp.empty()) {
                st2.push(temp.back());
                temp.pop_back();
            }

            st1.push(i);
        }

        return ans;
    }
};