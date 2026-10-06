class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& posi, vector<int>& heal, string direct) {
        unordered_map<int,int> mp;
        for(int i=0;i<posi.size();i++){
            mp[posi[i]]=i;
        }
        sort(posi.begin(),posi.end());
        stack<int> st;
        int i=0;
        while(i<posi.size()){
            int id=mp[posi[i]];
            if(direct[id]=='L'){
                
                while(!st.empty() && st.top()>0){
                    int idx=mp[st.top()];
                    if(heal[id]>heal[idx]){
                        heal[idx]=0;
                        heal[id]-=1;
                        st.pop();
                       
                    }
                    else if(heal[id]<heal[idx]){
                        heal[id]=0;
                        heal[idx]-=1;
                        break;
                    }
                    else{
                        heal[id]=0;
                        heal[idx]=0;
                        st.pop();
                        break;
                    }
                }
                if(heal[id]>0) st.push(-posi[i]);
                
                
                
            }
            else{
                st.push(posi[i]);
            }
            i++;
        }
        vector<int> ans;
        while(!st.empty()){
            int x=mp[abs(st.top())];
            ans.push_back(x);
            st.pop();
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(heal[ans[i]]>0)
            ans[i]=heal[ans[i]];
        }
        return ans;
    }
};