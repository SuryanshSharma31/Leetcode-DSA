class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        stack<int> st;
        vector<int> ans(h.size(), 0);
        for (int i = h.size() - 1; i >= 0; i--) {
            if (!st.empty()) {

                int count = 0;
                while (!st.empty()) {
                    count++;

                    if (st.top() < h[i]) {
                        st.pop();
                    } else {

                        break;
                    }
                }
                ans[i] = count;
            }
            st.push(h[i]);
        }
        return ans;
    }
};