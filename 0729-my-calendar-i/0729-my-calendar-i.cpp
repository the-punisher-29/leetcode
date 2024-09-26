class MyCalendar {
private:
    set<pair<int, int>> bookings;

public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = bookings.lower_bound({start, end});
        
        if (it != bookings.end() && it->first < end) {
            return false;
        }
        
        if (it != bookings.begin()) {
            --it;
            if (it->second > start) {
                return false;
            }
        }
        
        bookings.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */