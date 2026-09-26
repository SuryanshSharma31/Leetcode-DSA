class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<pair<int,int>> sl;
        stack<pair<int,int>> sr;
        for(int i=0;i<n;i++){
            int curl=1;
        
                while(!sl.empty() && sl.top().first>arr[i]){
                    curl+=left[sl.top().second];
                    sl.pop();
                }
            left[i]=curl;
            sl.push({arr[i],i});
                
            int curr=1;
            while(!sr.empty() && sr.top().first>=arr[n-i-1] ){
                curr+=right[sr.top().second];
                sr.pop();
            }
            right[n-i-1]=curr;
            sr.push({arr[n-i-1],n-i-1});
            
        }
        long long int ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+1LL*arr[i]*left[i]*right[i])%1000000007;
        }
        return ans;
    }       
};