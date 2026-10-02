class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {

        int n = cars.size();
        vector<double> ans(n, -1.0);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty()) {

                int j = st.top();

                // Car i is not faster than car j
                // so it can never catch j.
                if (cars[i][1] <= cars[j][1]) {
                    st.pop();
                    continue;
                }

                // Time for i to reach j
                double t = (double)(cars[j][0] - cars[i][0])
                         / (cars[i][1] - cars[j][1]);

                // j never collides OR i reaches j before j collides
                if (ans[j] == -1 || t <= ans[j]) {
                    ans[i] = t;
                    break;
                }

                // j collides before i can reach it.
                // So i should consider the next car.
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};