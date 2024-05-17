class Solution {
public:

    int myAtoi(string s) {

        int i = 0;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        long long ans = 0;
        int sign = 1;

        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {

            int digit = s[i] - '0'; 
            ans = ans * 10 + digit;

            if (ans * sign < INT_MIN) {
                return INT_MIN;
            } else if (ans * sign > INT_MAX) {
                return INT_MAX;
            }

            i++;
        }

        return ans * sign;
    }
};
