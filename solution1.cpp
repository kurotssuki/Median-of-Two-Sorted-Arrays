#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //merge arrays
        for (int i = 0; i < size(nums2); i++) {
            nums1.push_back(nums2[i]);
        }
        mergeSort(nums1, 0, size(nums1) - 1);

        int n = size(nums1);
        if(n % 2 == 1) {
            return (double)nums1[n / 2];
        } else {
            return (double)(nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
        }
    }
private:
        void merge(std::vector<int>& arr, int left, int mid, int right) {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            std::vector<int> L(n1), R(n2);

            
            for(int i = 0; i < n1; i++) L[i] = arr[left + i];
            for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

            int i = 0, j = 0, k = left;
            while(i < n1 && j < n2) {
                if(L[i] <= R[j]) {
                    arr[k] = L[i];
                    i++;
                } else {
                    arr[k] = R[j];
                    j++;
                }
                k++;
            }
            while (i < n1) {
                arr[k] = L[i];
                i++;
                k++;
            }

            while (j < n2) {
                arr[k] = R[j];
                j++;
                k++;
            }

        }
        void mergeSort(std::vector<int>& arr, int left, int right) {
            if (left >= right) return;
            int mid = left + (right- left) / 2;
            mergeSort(arr,left,mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
};

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
   
    Solution solver;

    double result = solver.findMedianSortedArrays(nums1, nums2);

    cout << "Merged Median: " << result << endl;

    return 0;
}
