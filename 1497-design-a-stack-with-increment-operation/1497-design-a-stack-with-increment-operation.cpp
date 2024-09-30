class CustomStack {
private:
    vector<int> stack;
    int maxSize;
    int curr_s;

public:
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
        this->curr_s=0;
    }
    
    void push(int x) {
        if(curr_s<maxSize){
            stack.push_back(x);
            curr_s++;
        }
    }
    
    int pop() {
        if(curr_s==0){
            return -1;
        }
        int te=stack.back();
        stack.pop_back();
        curr_s--;
        return te;
        
    }
    
    void increment(int k, int val) {
        int lim=min(k,curr_s);
        for(int i=0;i<lim;++i){
            stack[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */