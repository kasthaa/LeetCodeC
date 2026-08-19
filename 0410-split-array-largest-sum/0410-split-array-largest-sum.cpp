 class Solution {
public:

    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int count = 1;
        long long sum = 0;

        for (int num : nums) {
            if (sum + num > maxSum) {
                count++;
                sum = num;
            } else {
                sum += num;
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = 0;

        for (int num : nums) {
            high += num;
        }

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return (int)low;
    }
};