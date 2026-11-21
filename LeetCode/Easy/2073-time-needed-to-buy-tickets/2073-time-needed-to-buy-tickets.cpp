class Solution {
public:
    int timeRequiredToBuy(vector<int>& tick, int k) {
        int ans=0;
        int cnt=0;
        
        queue<int> q;
        for(int i=0;i<tick.size();i++){
            if(tick[i]<tick[k]) cnt++;
            else if(tick[i]==tick[k] && i<=k) cnt++;
            q.push(tick[i]);
        }
        int i=0;
        while(i<cnt){
            if(q.front()-1==0){
                q.pop();
                i++;
            }
            else{
                q.push(q.front()-1);
                q.pop();
            }
            ans++;
        }
        return ans;
    }
};