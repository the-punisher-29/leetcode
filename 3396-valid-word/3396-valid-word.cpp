class Solution {
 public:
  bool isValid(string word) {
    //C++20-flex
    //range
    return word.length() >= 3 &&
           ranges::all_of(word, [](char c) { return isalnum(c); }) 
           &&
           ranges::any_of(word, isVowel) 
           && 
           ranges::any_of(word, isConsonant);
  }
 private:
  static bool isVowel(char c) {
    static constexpr string_view kVowels = "aeiouAEIOU";
    //learnt this string_view(non owning useful in function parameters,copying is cheap(aka mem effi))
    return kVowels.find(c) != string_view::npos;
  }
  static bool isConsonant(char c) {
    return isalpha(c) && !isVowel(c);
  }
};