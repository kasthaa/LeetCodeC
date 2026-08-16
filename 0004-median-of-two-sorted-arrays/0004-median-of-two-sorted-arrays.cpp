 class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr3;

        int i = 0, j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                arr3.push_back(nums1[i]);
                i++;
            }
            else {
                arr3.push_back(nums2[j]);
                j++;
            }
        }

        while (i < n1) {
            arr3.push_back(nums1[i]);
            i++;
        }

        while (j < n2) {
            arr3.push_back(nums2[j]);
            j++;
        }

        int n = arr3.size();

        if (n % 2 == 1) {
            return arr3[n / 2];
        }

        return (arr3[n / 2 - 1] + arr3[n / 2]) / 2.0;
    }
};