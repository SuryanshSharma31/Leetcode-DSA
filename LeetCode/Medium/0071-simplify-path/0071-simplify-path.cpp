class Solution {
public:
    string simplifyPath(string path) {
        stack<char> st;
        int i=0;
        while(i<path.size()){
           if(path[i]=='/') st.push(path[i]);
           while(i<path.size() && path[i]=='/') i++;
           string x="";
           while(i<path.size() && path[i]!='/'){
                st.push(path[i]);
                x+=path[i];
                i++;
           }
           if(x=="."){
            st.pop();
            st.pop();
            
           }
           else if(x==".."){
            st.pop();
            st.pop();
            st.pop();
            while(!st.empty() && st.top()!='/') st.pop();
            if(!st.empty()) st.pop();
           }
           
        }
        if(st.empty()) st.push('/');
        else if(st.top()=='/'){
             st.pop();
            if(st.empty()) st.push('/');
        }    
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};