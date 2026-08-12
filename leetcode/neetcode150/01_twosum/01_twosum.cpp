#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            vector<int> ans(2);
            for(int i=0; i<nums.size(); i++){
                for(int j=0; j<nums.size(); j++){
                    if( (nums[i]+nums[j]) == target && i!=j){
                        ans = {i, j};
                        return ans;
                    }
                }
            }
            return {-1, -1};
        }
};

void print(vector<int> ans){
    cout << "{";
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i];
        if (i == ans.size()-1){
            cout << "}";  return;
        }
        cout << ",";
    }
}

int main(){
    Solution soln;
    vector<int> nums = {2,7,11,15};
    cout << "enter target : ";
    int target; cin >> target;
    vector<int> ans = soln.twoSum(nums, target);
    if (ans[0] >= 0) print(ans);
    else cout << "no indexes found for the sum " << target ;
    return 0;
}
