class Solution {
public:
    string loop(string &s,int &i, int x){
        string t="";
        string ans="";
        if(s[i]=='[') i++;
        while(i<s.size() && s[i]!=']'){
            if(isdigit(s[i])){
               int z=0;
                while(isdigit(s[i])){
                    z=z*10+(s[i++]-'0');
                }
                t+=loop(s,i,z);
                
            }
            else{
                t+=s[i++];
            }
        }
        i++;
        for(int j=0;j<x;j++){
            ans+=t;
        }
        return ans;
    }
    string decodeString(string s) {
        string ans="";
        int i=0;
        while(i<s.size()){
            if(isdigit(s[i])) {
                int z=0;
                while(isdigit(s[i])){
                    z=z*10+(s[i++]-'0');
                }
                ans+=loop(s,i,z);
            }
            else{
                ans+=s[i++];
            }
        }
        return ans;
    }
};