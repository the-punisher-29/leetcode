class MedianFinder {
private:
    // Max heap for the lower half of the numbers
    priority_queue<int> lowerHalf;
    // Min heap for the upper half of the numbers (using negative values)
    priority_queue<int, vector<int>, greater<int>> upperHalf;
    
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // First decide which heap to push to
        if (lowerHalf.empty() || num <= lowerHalf.top()) {
            lowerHalf.push(num);
        } else {
            upperHalf.push(num);
        }
        // Balancing the heaps to maintain the median property
        // The lower half can have at most one more element than the upper half
        if (lowerHalf.size() > upperHalf.size() + 1) {
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        } 
        // The upper half can have at most the same number of elements as the lower half
        else if (upperHalf.size() > lowerHalf.size()) {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }
    
    double findMedian() {
        // If lower half has more elements, it contains the median
        if (lowerHalf.size() > upperHalf.size()) {
            return lowerHalf.top();
        }
        // Otherwise, median is the average of tops of both heaps
        else {
            return (lowerHalf.top() + upperHalf.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */