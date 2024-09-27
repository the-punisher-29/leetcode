
class MyCalendarTwo {
private:
    map<int, int> bookings;
public:
    MyCalendarTwo() {}
    bool book(int start, int end) {
        bookings[start]++;
        bookings[end]--;
        int count = 0;
        for (const auto& [time, delta] : bookings) {
            count += delta;
            if (count > 2) {
                bookings[start]--;
                bookings[end]++;
                return false;
            }
            if (time >= end) break;
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */