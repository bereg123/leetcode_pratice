#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                ans = std::min(ans, i + 1 - left);
                sum -= nums[left++];
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }

};

int main() {
    using namespace std;
    Solution solution;
    vector<int> inputVector = {2,3,1,2,4,3};
    int sum = 7;
    int ret = solution.minSubArrayLen(sum, inputVector);
    std::cout << "[Ret]:" << ret << std::endl;
    return 0;
}