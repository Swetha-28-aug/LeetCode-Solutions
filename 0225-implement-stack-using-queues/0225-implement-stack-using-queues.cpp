class MyStack {
public:
    queue<int>que;
    queue<int>stk;
    MyStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        while(!que.empty()){
            stk.push(que.front());
            que.pop();
        }
        swap(stk,que);
    }
    
    int pop() {
        int val=que.front();
        que.pop();
        return val;
    }
    
    int top() {
       return que.front();
    }
    
    bool empty() {
        if(que.empty()) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */