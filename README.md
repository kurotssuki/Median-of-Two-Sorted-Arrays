# LeetCode 4 Median of Two Sorted Arrays

## Description:
Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays.

**Input Example:**
```cpp
nums1 = [1, 3], nums2 = [2]
// Output: 2.00000
```
## Solutions:
This repository contains two approaches to solve this problem.

### Approach 1: Merge Sort (Brute Force)
File: solution1.cpp

In this approach, I merge both arrays into a single container and then sort the result using the Merge Sort algorithm. Finally, I calculate the median based on the combined array size.

Pros: Easy to understand, good for visualizing Merge Sort logic.

Cons: Uses extra space for the merged array and is slower due to full sorting.

### Approach 2: Two Pointers (Linear Optimization)
File: solution2.cpp

Instead of fully merging and sorting, I use two pointers to iterate through both arrays simultaneously. Since the input arrays are already sorted, I can simply count up to the median index ((m+n)/2) without storing all elements.

Pros: Significantly faster and more memory efficient.

Cons: Slightly more complex logic to handle edge cases.

### Time Complexity:
1. Merge Sort: O((N+M)log(N+M))
2. Two Pointers: O(N+M)
