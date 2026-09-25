class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;
        vector<int> ans;
        int i=0;
        while(i<ast.size()){
            if(!st.empty() && st.top()>0 && ast[i]<0){
                // if(st.top()==abs(ast[i])) st.pop();
                while(!st.empty()  && st.top()>0 && abs(ast[i])>st.top()) st.pop();
                if(!st.empty() && st.top()==abs(ast[i])) st.pop();
                else if(!st.empty() && st.top()<0) continue;
                else if(st.empty()) st.push(ast[i]);
            }
            else{
                st.push(ast[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};