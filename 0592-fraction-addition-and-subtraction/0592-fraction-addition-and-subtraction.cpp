class Solution {
public:
    string fractionAddition(string expression) {
        istringstream iss(expression);
        int A = 0, B = 1, a, b;
        char c;
        
        while (iss >> a >> c >> b) {
            A = A * b + a * B;
            B *= b;
            int g = abs(__gcd(A, B));
            A /= g;
            B /= g;
        }
        
        return to_string(A) + "/" + to_string(B);
    }
    
private:
    int __gcd(int a, int b) {
        return b == 0 ? a : __gcd(b, a % b);
    }
};