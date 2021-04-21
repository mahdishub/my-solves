class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> tmp;
    
    void findAns ( vector<int>& candidates, int idx, int target ) {
        if ( target == 0 ) {
            ans.push_back(tmp);
            return;
        }
        if ( target < 0 ) {
            return;
        }
        if ( idx == candidates.size() ) {
            return;
        }
        
        
        for ( int i = idx; i < candidates.size(); i++ ) {
            if ( i > idx && candidates[i-1] == candidates[i] ) continue;
            tmp.push_back(candidates[i]);
            findAns(candidates,i+1,target-candidates[i]);
            tmp.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cnt(51);
        if ( candidates.size() == 0 ) return ans;
        for ( int c: candidates ) {
            cnt[c]++;
        }
        int j = 0;
        for ( int i = 1; i <= 50; i++ ) {
            while ( cnt[i]-- ) {
                candidates[j] = i;
                j++;
            }
        }

        
        
        findAns(candidates,0,target);
        return ans;
    }
};
