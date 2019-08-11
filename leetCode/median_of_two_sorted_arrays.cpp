#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
/*
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		//int size_1 = nums1.size(), size_2 = nums2.size();
		//int median_1 = size_1 / 2 , medain_2 = size_2 / 2;
		nums1.insert(nums1.end(), nums2.begin(), nums2.end());
		sort(nums1.begin(),nums1.end());
		int size = nums1.size();
		if (size % 2 == 0)
			return (double)(nums1[size / 2 - 1] + nums1[size / 2]) / 2;
		else
			return nums1[size / 2];
	}
	*/
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		if (m == 0 && n == 0) return 0;
		if (m > n) return findMedianSortedArrays(nums2, nums1);

		int i, j, lo = 0, hi = m;
		while (lo <= hi) {
			i = lo + (hi - lo) / 2, j = (m + n + 1) / 2 - i;
			if (i > 0 && j < n && nums1[i - 1] > nums2[j]) {
				hi = i - 1;
			}
			else if (j > 0 && i < m && nums2[j - 1] > nums1[i]) {
				lo = i + 1;
			}
			else {
				break;
			}
		}

		int ml, mr;
		if (j == 0) ml = nums1[i - 1];
		else if (i == 0) ml = nums2[j - 1];
		else ml = max(nums2[j - 1], nums1[i - 1]);
		if ((m + n) & 1) return ml;
		if (i == m) mr = nums2[j];
		else if (j == n) mr = nums1[i];
		else mr = min(nums1[i], nums2[j]);


		return (ml + mr) / 2.0;
	}
};