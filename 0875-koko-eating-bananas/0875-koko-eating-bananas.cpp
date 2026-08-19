 class Solution {
public:
    long long totalHours(vector<int>& piles, int speed) {
        long long hours = 0;

        for (int bananas : piles) {
            hours += (bananas + speed - 1) / speed;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (totalHours(piles, mid) <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};