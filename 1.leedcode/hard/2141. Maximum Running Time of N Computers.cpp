#include <vector>
#include <algorithm>

class Solution {
public:
    bool check(std::vector<int>& batteries, long long mid, long long n) {
        long long target_min = mid * n;
        for (int i = 0; i < batteries.size(); i++) {
            target_min -= std::min(1LL * batteries[i], mid); // Ensure comparison with long long
            if (target_min <= 0) {
                return true;
            }
        }
        return false;
    }

    long long maxRunTime(int n, std::vector<int>& batteries) {
        long long sum = 0;
        for (auto& i : batteries) {
            sum += i;
        }

        long long start = 0; // Change to 0
        long long end = sum / n;

        long long result = 0;
        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (check(batteries, mid, n)) {
                result = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return result;
    }
};
