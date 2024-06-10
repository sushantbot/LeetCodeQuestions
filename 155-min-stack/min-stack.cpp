class MinStack {
public:
    vector<pair<int, int> > v;
    MinStack() {}

    void push(int val) {
                //case-1(stack Empty)--> The value will be first and second both
        if(v.empty()){
            //then the first and second both will be val
            pair<int,int>p;
            p.first=val;
            p.second=val;
            v.push_back(p);
        }
        //but when stack is not empty 
        //we will check min from the previous one
        else{
            pair<int,int>p;
            p.first=val;
            int puranaMin=v.back().second;
            p.second=min(val,puranaMin);
            v.push_back(p);
        }
    }


    void pop() {
        v.pop_back();
    }

    int top() {
        return v.back().first;
    }

    int getMin() {
        return v.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */