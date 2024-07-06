class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        vector<int> sortedSeats = seats;
        vector<int> sortedStudents = students;
        sort(sortedSeats.begin(), sortedSeats.end());
        sort(sortedStudents.begin(), sortedStudents.end());
        int totalMoves = 0;
        // Iterate through both vectors simultaneously
        for (int i = 0; i < n; i++) {
            // Calculate the minimum number of moves required to match the student with the seat
            totalMoves += abs(sortedSeats[i] - sortedStudents[i]);
        }
        return totalMoves;
    }
};