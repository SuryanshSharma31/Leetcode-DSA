class Solution {
public:
    int countCollisions(string car) {
        int ans=0;
        stack<char> st;
        for(int i=0;i<car.size();i++){
            if(car[i]=='L' && !st.empty()){
                if(st.top()=='R'){
                    if(!st.empty() && st.top()=='R'){
                        st.pop();
                        ans+=2;
                    }
                    while(!st.empty() && st.top()=='R'){
                    st.pop();
                    ans+=1;
                }
                    st.push('X');
                }
                else if(st.top()=='S'){
                    ans+=1;
                }
                else if(st.top()=='X'){
                    ans+=1;
                }
                
            }
            else if(car[i]=='S' && !st.empty()){
                while(!st.empty() && st.top()=='R'){
                    st.pop();
                    ans+=1;
                }
                st.push(car[i]);
            }
            else{
                st.push(car[i]);
            }
        }
        return ans;
    }
};