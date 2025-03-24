//tc issue
// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//         vector<bool> hm(days+1,false);
//         for (const auto& meeting : meetings) {
//             int start = meeting[0];
//             int end = meeting[1];
//             for (int day = start; day <= end; day++) {
//                 hm[day] = true;
//             }
//         }
//         //now counting days without meetings
//         int ad= 0;
//         for (int day = 1; day <= days; day++) {
//             if (!hm[day]) {
//                 ad++;
//             }
//         }
//         return ad;
//     }
// };
//------------------------------
//learning--line sweep tech
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> timeline;
        for (const auto& meeting : meetings) {
            timeline[meeting[0]]++;     // Start of meeting
            timeline[meeting[1] + 1]--; // Day after end of meeting
        }
        int availableDays = 0;
        int activeMeetings = 0;
        int prevDay = 1;
        for (const auto& [day, change] : timeline) {
            if (activeMeetings == 0 && prevDay <= days) {
                availableDays += min(day, days + 1) - prevDay;
            }
            activeMeetings += change;
            prevDay = day;
            if (prevDay > days) {
                break;
            }
        }
        if (activeMeetings == 0 && prevDay <= days) {
            availableDays += days - prevDay + 1;
        }
        return availableDays;
    }
};