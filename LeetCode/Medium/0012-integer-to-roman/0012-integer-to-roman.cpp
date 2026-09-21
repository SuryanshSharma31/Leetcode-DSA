class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mp;
        mp[1]="I";
        mp[5]="V";
        mp[10]="X";
        mp[50]="L";
        mp[100]="C";
        mp[500]="D";
        mp[1000]="M";
        mp[4]= "VI";
        mp[9]="XI";
        mp[40]="LX";
        mp[90]="CX";
        mp[400]="DC";
        mp[900]="MC";
        string ans="";
        int i=1;
        while(num>0){
            int x=i*(num%10);
            if(x==i*4 || x==i*9 || x==i*5 || x==i*1){
                ans += mp[x];
            }
            else{ 
                if(x>5*i){
                int z=(x-i*5)/i;
                while(z>0){
                    ans+=mp[i];
                    z--;
                }
                ans+=mp[5*i];
                }
                else {
                    int z=x/i;
                    while(z>0){
                        ans+=mp[i];
                        z--;
                    }
                }
            }
           num=num/10;
           i=i*10; 
        }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};