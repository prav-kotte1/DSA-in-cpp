class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if (num == 0)
            return "0";
        string s;

        long n = labs(num);
        long d = labs(den);
        if (num < 0 ^ den < 0)
            s += "-";
        s += to_string(n / d);


        if (n % d == 0)
            return s;

        s += ".";
        unordered_map<int, int> seen;
        for (long r = n % d; r; r %= d) {
            if (const auto it = seen.find(r); it != seen.cend()) {
                s.insert(it->second, 1, '(');
                s += ')';
                break;
            }
            seen[r] = s.size();
            r *= 10;
            s += to_string(r / d);
        }
        return s;
    }
};