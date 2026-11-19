class MyQueue {
public:
stack<int> st;
stack<int> bk;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(!st.empty()){
            bk.push(st.top());
            st.pop();
        }
        int a=NULL;
        if(!bk.empty()) a=bk.top();
        
        bk.pop();
        while(!bk.empty()){
            st.push(bk.top());
            bk.pop();
        }
        return a;
    }
    
    int peek() {
        while(!st.empty()){
            bk.push(st.top());
            st.pop();
        }
        
        int a=NULL;
        if(!bk.empty()) a=bk.top();
        
        while(!bk.empty()){
            st.push(bk.top());
            bk.pop();
        }
        return a;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */