class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentQueue;
        for (int student : students)
            studentQueue.push(student);

        int unableToEat = 0;
        int currentIndex = 0;
        while (!studentQueue.empty()) {
            if (studentQueue.front() == sandwiches[currentIndex]) {
                studentQueue.pop();
                currentIndex++;
                unableToEat = 0; // Reset unableToEat counter if a student was able to eat
            } else {
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                unableToEat++;
            }
            // If unableToEat equals the number of students in the queue, it means none of the students can eat
            if (unableToEat == studentQueue.size())
                break;
            // Reset currentIndex if it goes beyond the size of sandwiches
            if (currentIndex == sandwiches.size())
                currentIndex = 0;
        }
        return unableToEat;
    }
};
