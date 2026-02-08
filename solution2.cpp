#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int total = m + n;

        int medianIndex = total / 2;

        int curVal = 0;
        int prevVal = 0;
        int i = 0;
        int j = 0;
        for(int step = 0; step <= medianIndex; step++) {
            prevVal = curVal;
            if(i < m && (j >= n || nums1[i] < nums2[j])) {
                curVal = nums1[i];
                i++;
            } else {
                curVal = nums2[j];
                j++;
            }
        }

        if(total % 2 == 1) {
            return(double)curVal;
        } else {
            return(double)(prevVal + curVal) / 2.0;
        }
    }
};


int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 7};
    Solution solver;
    double result = solver.findMedianSortedArrays(nums1, nums2);
    cout << "Calculated Median: " << result << endl;
}
