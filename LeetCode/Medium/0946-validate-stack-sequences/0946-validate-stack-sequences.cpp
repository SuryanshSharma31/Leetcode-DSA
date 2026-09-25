class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        int j=0;
        stack<int> st;
        while(i<pushed.size()){
            while(i<pushed.size() && pushed[i]==popped[j]) {
                i++;
                j++;
            }
            if(i>=pushed.size()) break;
            if(!st.empty() && st.top()==popped[j]){
                while(!st.empty() && st.top()==popped[j]){
                    st.pop();
                    j++;
                }
            }
            else{
                st.push(pushed[i++]);
            }
        }
        while(j<popped.size() && !st.empty() && st.top()==popped[j]){
            st.pop();
            j++;
        }
        bool ans=false;
        if(st.empty()) ans=true;
        return ans;
    }
};