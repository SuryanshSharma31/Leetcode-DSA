class Solution {
public:
    long long maximumSumOfHeights(vector<int>& arr) {
        int n=arr.size();
        vector<long long> left(n,0);
        vector<long long> right(n,0);
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                left[i]=left[st.top()]+1ll*(i-st.top())*arr[i];
            }
            else{
                left[i]=1ll*(i+1)*arr[i];
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                right[i]=right[st.top()]+1ll*(st.top()-i)*arr[i];
            }
            else{
                right[i]=1ll*(arr.size()-i)*arr[i];
            }
            st.push(i);
        }
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            long long x=left[i]+right[i]-arr[i];
            sum=max(x,sum);
        }
        return sum;
       
    }
};