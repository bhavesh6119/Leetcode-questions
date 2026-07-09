class MinStack {
public:
stack<int>st1;
stack<int>st2;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st1.empty()){
            st1.push(value);
            st2.push(value);
        }else{
            st1.push(value);
            st2.push(min(value,st2.top()));
        }
    }
    
    void pop() {
        if(st1.empty()){
            return;
        }else{
            st1.pop();
            st2.pop();
        }
    }
    
    int top() {
        if(st1.empty()){
            return -1;
        }else{
           int element=st1.top();
            return element;
        }
    }
    
    int getMin() {
        if(st2.empty()){
            return -1;
        }else{
            return st2.top();
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */