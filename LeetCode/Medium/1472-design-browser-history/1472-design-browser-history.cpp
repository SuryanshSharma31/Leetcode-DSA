class BrowserHistory {
public:
stack<string> curr;
stack<string> bk;

    BrowserHistory(string homepage) {
    curr.push(homepage);
    }
    
    void visit(string url) {
        curr.push(url);
        while(!bk.empty()){
            bk.pop();
        }
    }
    
    string back(int steps) {
        string ans="";
        while(!curr.empty() && steps>0){
        bk.push(curr.top());
        curr.pop();
        steps--;
        }
        if(curr.empty() && !bk.empty()){
            curr.push(bk.top());
            bk.pop();
            ans=curr.top();
        }
        else if(!curr.empty()){
            ans=curr.top();
        }
        return ans;
    }
    
    string forward(int steps) {
        string ans="";
        if(bk.empty() && !curr.empty()) return curr.top();
        while(!bk.empty() && steps>0){
            ans=bk.top();
            curr.push(bk.top());
            bk.pop();
            steps--;
        }
        return ans;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */