class MinStack {
public:
    //we are creating an array of pairs
    vector<pair<int,int>>arr;
    MinStack() {
        
    }
    
    void push(int val) {
        //since we are pushing into vector,
        //there will be no OVERFLOW Condition 
        
        //Here two case arises, if the array is empty or not
        if(arr.empty()){
            //in this case our val will be first and second
            //creating pair
            pair<int,int>p=make_pair(val,val);
            //pushing this pair into our array of pairs
            arr.push_back(p);
        }
        else{
            //if the array is not empty 
            //here we need to check if the val is mininmum or the prev pair
            pair<int,int>p;
            p.first=val;
            int OldMin=arr.back().second;
            p.second=min(val,OldMin);
            arr.push_back(p);
        }
    }
    
    void pop() {
        //Here we need to check if the array is empty or not
        //just to avoid UNDERFLOW Condition
        if(arr.empty()){
            return; 
        }
        else{
            //when the array is not empty,
            //we will pop the last element
            arr.pop_back();
        }
    }
    
    int top() {
        //The top element will be our rightmost pair
        pair<int,int>rightMostPair=arr.back();
        //now the first element of righmost pair will be our top element
        return rightMostPair.first;
        
    }
    
    int getMin() {
        
        //The top element will be our rightmost pair
        //and the rightmost pair's second will have the min till this index

        pair<int,int>rightMostPair=arr.back();
        //now the second element of righmost pair will be our minimum till here
        return rightMostPair.second;
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