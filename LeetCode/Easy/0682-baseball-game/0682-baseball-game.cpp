class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int i=0;
        while(i<operations.size()){
            if(operations[i]=="C") s.pop();
            else if (operations[i]=="D") s.push(2*s.top());
            else if(operations[i]=="+"){
                int one=s.top();
                s.pop();
                int ans=one+s.top();
                s.push(one);
                s.push(ans);
            }
            else s.push(stoi(operations[i]));
            i++;
        }
        int ans=0;
        while(!s.empty()) {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};