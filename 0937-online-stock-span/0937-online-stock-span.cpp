class StockSpanner {
private:
    // Stack to store pairs of {price, span}
    stack<pair<int, int>> priceSpanStack;
    
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;
        while (!priceSpanStack.empty() && price >= priceSpanStack.top().first) {
            span += priceSpanStack.top().second;
            priceSpanStack.pop();
        }
        priceSpanStack.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */