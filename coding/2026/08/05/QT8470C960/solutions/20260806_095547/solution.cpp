#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    long long minAdjacentSwaps(vector<int>& nums) {
        vector<long long> adjusted;

        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                adjusted.push_back((long long)i - adjusted.size());
            }
        }

        int k = adjusted.size();
        if (k <= 1) return 0;

        long long median = adjusted[k / 2];
        long long ans = 0;

        for (long long x : adjusted) {
            ans += llabs(x - median);
        }

        return ans;
    }
};