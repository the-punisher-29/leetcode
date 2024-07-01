class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0;
        int l= 0;
        int r= people.size()-1;
        while (l<= r) {
            if (people[l] + people[r] <= limit) {
                // If both people can fit in the boat, move both pointers
                l++;
                r--;
            } else {
                // If only the heavier person can fit, move the pointer of the heavier person
                r--;
            }
            boats++; // Increment boats count for each iteration
        }
        return boats;
    }
};