class Solution {
public:
    void recursion(vector<int> nums, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(nums);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            recursion(nums, i+1, j, res);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> >res;
        recursion(nums, 0, nums.size(), res);
        return res;
    }
};