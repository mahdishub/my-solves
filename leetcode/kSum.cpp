class Solution {
public:
    vector<vector<int>> twoSum (vector<int>&nums, int start, int target) {
        vector<vector<int> > ans;
        map<pair<int,int>,bool> exist;
        for ( int i = start; i < nums.size(); i++ ) {
            bool found = binary_search(nums.begin()+(i+1),nums.end(),target-nums[i]);
            if ( found && !exist[{nums[i],target-nums[i]}] && !exist[{target-nums[i],nums[i]}] ) {
                exist[{nums[i],target-nums[i]}] = 1;
                ans.push_back({nums[i],target-nums[i]});
            }
        }
        return ans;
    }

    vector<vector<int>> kSum ( vector<int>&nums,int k ,int start, int target ) {

        vector< vector<int> > ans;
        if ( k == 2 ) return twoSum(nums,start,target);
        for ( int i = start; i < nums.size(); i++ ) {
            if ( i == start || nums[i-1] != nums[i] ) {
                vector< vector<int> > tmp2 = kSum(nums,k-1,i+1,target-nums[i]);

                for ( int j = 0; j < tmp2.size(); j++ ) {
                    vector<int> tmp{nums[i]};
                    tmp.insert(tmp.end(),tmp2[j].begin(),tmp2[j].end());
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kSum(nums,4,0,target);
    }
};
