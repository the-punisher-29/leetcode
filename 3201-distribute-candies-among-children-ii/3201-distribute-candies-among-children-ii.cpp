// class Solution {
// public:
//     int distributeCandies(int n, int limit) {
//         // Function to count non-negative integer solutions to x1 + x2 + x3 = total
//         // using stars and bars: C(total + 2, 2) = (total + 2) * (total + 1) / 2
//         auto countSolutions = [](long long total) -> long long {
//             if (total < 0) return 0;
//             // C(total + 2, 2) = (total + 2) * (total + 1) / 2
//             return (total + 2) * (total + 1) / 2;
//         };
        
//         // Inclusion-Exclusion Principle:
//         // Total = All solutions - (violate 1 constraint) + (violate 2 constraints) - (violate 3 constraints)
        
//         long long total = countSolutions(n);
        
//         // Subtract cases where at least one child gets more than limit candies
//         // If child i gets > limit, give them (limit + 1) first, then distribute remaining
//         long long violate1 = 3LL * countSolutions(n - (long long)(limit + 1));
        
//         // Add back cases where at least two children get more than limit
//         long long violate2 = 3LL * countSolutions(n - 2LL * (limit + 1));
        
//         // Subtract cases where all three children get more than limit
//         long long violate3 = countSolutions(n - 3LL * (limit + 1));
        
//         return (int)(total - violate1 + violate2 - violate3);
//     }
// };

class Solution {
 public:
  // Same as 2927. Distribute Candies Among Children III
  long long distributeCandies(int n, int limit) {
    const int limitPlusOne = limit + 1;
    const long oneChildExceedsLimit = ways(n - limitPlusOne);
    const long twoChildrenExceedLimit = ways(n - 2 * limitPlusOne);
    const long threeChildrenExceedLimit = ways(n - 3 * limitPlusOne);
    // Principle of Inclusion-Exclusion (PIE)
    return ways(n) - 3 * oneChildExceedsLimit + 3 * twoChildrenExceedLimit -
           threeChildrenExceedLimit;
  }

 private:
  // Returns the number of ways to distribute n candies to 3 children.
  long ways(int n) {
    if (n < 0)
      return 0;
    // Stars and bars method:
    // e.g. '**|**|*' means to distribute 5 candies to 3 children, where
    // stars (*) := candies and bars (|) := dividers between children.
    return nCk(n + 2, 2);
  }

  long nCk(int n, int k) {
    long res = 1;
    for (int i = 1; i <= k; ++i)
      res = res * (n - i + 1) / i;
    return res;
  }
};