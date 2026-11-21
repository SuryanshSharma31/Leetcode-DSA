class Solution {
public:
    int countStudents(vector<int>& stud, vector<int>& sand) {
        queue<int> q;
        queue<int> s;
        for(int i=0;i<stud.size();i++){
            q.push(stud[i]);
            s.push(sand[i]);
        }
        int x=0;
        while(!s.empty()){
            
                for(int i=0;i<sand.size();i++){
                    if(s.front()==q.front()){
                        s.pop();
                        q.pop();
                        x=1;
                        break;
                    }
                    else{
                        q.push(q.front());
                        q.pop();

                    }
                }
            if(x==0) return q.size();
            else x=0;
        }
        return q.size();
    }
};