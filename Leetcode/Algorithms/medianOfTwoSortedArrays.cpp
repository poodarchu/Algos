// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

class Solution {
public:
    /*
    对于一个长度为n的已排序数列a，若n为奇数，中位数为a[n / 2 + 1] ,
    若n为偶数，则中位数(a[n / 2] + a[n / 2 + 1]) / 2
    如果我们可以在两个数列中求出第K小的元素，便可以解决该问题
    不妨设数列A元素个数为n，数列B元素个数为m，各自升序排序，求第k小元素
    取A[k / 2] B[k / 2] 比较，
    如果 A[k / 2] > B[k / 2] 那么，所求的元素必然不在B的前k / 2个元素中(证明反证法)
    反之，必然不在A的前k / 2个元素中，于是我们可以将A或B数列的前k / 2元素删去，求剩下两个数列的
    k - k / 2小元素，于是得到了数据规模变小的同类问题，递归解决
    如果 k / 2 大于某数列个数，所求元素必然不在另一数列的前k / 2个元素中，同上操作就好。
    */
    double findKth(vector<int>& A, vector<int>& B, int A_st, int B_st, int k) {
        // 边界情况，任一数列为空
        if (A_st >= A.size()) {
            return B[B_st + k - 1];
        }
        if (B_st >= B.size()) {
            return A[A_st + k - 1];
        }
        // k 等于 1 时表示取最小值，直接返回 min
        if (k == 1) return min(A[A_st], B[B_st]);
        int A_key = A_st + k / 2 - 1 >= A.size() ? INT_MAX : A[A_st + k / 2 - 1];
        int B_key = B_st + k / 2 - 1 >= B.size() ? INT_MAX : B[B_st + k / 2 - 1];
        if (A_key < B_key) {
            return findKth(A, B, A_st + k / 2, B_st, k - k / 2);
        } else {
            return findKth(A, B, A_st, B_st + k / 2, k - k / 2);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        double ret;
        if (sum & 1) {
            ret = findKth(nums1, nums2, 0, 0, sum / 2 + 1);
        } else {
            ret = (findKth(nums1, nums2, 0, 0, sum /2 ) + findKth(nums1, nums2, 0, 0, sum / 2 + 1)) / 2.0;
        }
        return ret;
    }
};
