class Solution {
public:
    int evalRPN(vector<string>& tok) {
      stack<int> st;
      int i=0;
      while(i<tok.size()){
        if(tok[i]=="+"){
            int one=st.top();
            st.pop();
            int two=st.top();
            st.pop();
            st.push(one+two);
        }
        else if(tok[i]=="*"){
            int one=st.top();
            st.pop();
            int two=st.top();
            st.pop();
            st.push(one*two);
        }
        else if(tok[i]=="-"){
            int one=st.top();
            st.pop();
            int two=st.top();
            st.pop();
            st.push(two-one);
        }
        else if(tok[i]=="/"){
            int one=st.top();
            st.pop();
            int two=st.top();
            st.pop();
            st.push(two/one);
        }
        else st.push(stoi(tok[i]));
        i++;
      }  
      return st.top();
    }
};