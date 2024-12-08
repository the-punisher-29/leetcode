struct Event {
  int time;
  int value;
  bool isStart;

  Event(int t, int v, bool s) : time(t), value(v), isStart(s) {}
};

class Solution {
 public:
  int maxTwoEvents(vector<vector<int>>& events) {
    int ans = 0;
    int maxValue = 0;
    vector<Event> evts;

    // Create start and end events
    for (const vector<int>& event : events) {
      int start = event[0];
      int end = event[1];
      int value = event[2];
      evts.emplace_back(start, value, true);
      evts.emplace_back(end + 1, value, false);
    }

    // Sort events
    sort(evts.begin(), evts.end(), [](const Event& a, const Event& b) {
      return a.time == b.time ? a.isStart < b.isStart : a.time < b.time;
    });

    // Process events
    for (const Event& evt : evts) {
      if (evt.isStart) {
        // Update the answer for the start of an event
        ans = max(ans, evt.value + maxValue);
      } else {
        // Update the maximum value when an event ends
        maxValue = max(maxValue, evt.value);
      }
    }

    return ans;
  }
};