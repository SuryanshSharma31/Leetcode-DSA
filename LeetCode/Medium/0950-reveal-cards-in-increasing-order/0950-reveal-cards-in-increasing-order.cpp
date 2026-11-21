class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int> ans(n,0);
        sort(deck.begin(),deck.end());
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        int x=0;
        int i=0;
        while(!q.empty()){
            if(x==0){

                ans[q.front()]=deck[i];
                q.pop();
                x=1;
                i++;
            }
            else{
                q.push(q.front());
                q.pop();
                x=0;
            }
        }
        return ans;
    }
};