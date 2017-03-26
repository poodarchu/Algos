/**
 * Given an array of integers, return indices of the two numbers such that
 * they add up to a specific target.
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v = {};
        for(int i = 0; i < nums.size(); ++i) {
            int m = target - nums[i];
            for (int o = 0; o < nums.size(); ++o) {
                if (m == nums[o] && o != i) {
                    v.push_back(i);
                    v.push_back(o);
                    return v;
                }
                else
                    continue;
            }
        }
    }
};
