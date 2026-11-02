class Solution{
public:
    int maximalRectangle(vector<vector<char>>& mat){
        int n=mat[0].size();
        vector<int> arr(n,0);
        stack<int> st;
        int ma=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]=='1') arr[j]++;
                else arr[j]=0;
            }
            for(int j=0;j<arr.size();j++){
                while(!st.empty() && arr[st.top()]>=arr[j]){
                    int h=arr[st.top()];
                    st.pop();
                    if(!st.empty()){
                    ma=max(ma,h*(j-st.top()-1));
                    }
                    else{
                        ma=max(ma,h*j);
                    }
                }
                st.push(j);
            }
            while(!st.empty()){
                int h=arr[st.top()];
                st.pop();
                if(!st.empty()){
                    ma=max(ma,h*(n-st.top()-1));
                }
                else{
                    ma=max(ma,h*n);
                }
            }
        }
        return ma;
    }
};