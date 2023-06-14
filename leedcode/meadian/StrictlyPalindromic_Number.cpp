class Solution {
public:

    long long  number(int n, int base) {
        long long  num = 0;
        if (n == 0) {
            return 0;
        }
        while (n > 0) {
            int rem = n % base;
            num = num * 10 + rem;
            n = n / base;
        }
        return num;
    }

    bool ispailindronic(int n) {
        long long  num = 0;
        int temp = n;  // Store the original value of n
        while (n > 0) {
            int rem = n % 10;
            num = num * 10 + rem;
            n = n / 10;
        }
        if (num == temp) {
            return true;
        }
        return false;
    }

    bool solve(int n) {
        for (int i = 2; i <= n - 2; i++) {
            long long  num = number(n, i);
            if (ispailindronic(num) || ispailindronic(i)) {
                return false;
            }
        }
        return true;
    }

    bool isStrictlyPalindromic(int n) {
        return solve(n);
    }
};
