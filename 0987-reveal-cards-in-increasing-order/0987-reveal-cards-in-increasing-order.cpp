class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> result;
        result.push_front(deck.back());
        deck.pop_back();

        while (!deck.empty()) {
            int tmp = result.back();
            result.pop_back();
            result.push_front(tmp);
            result.push_front(deck.back());
            deck.pop_back();
        }

        return vector<int>(result.begin(), result.end());
    }
};