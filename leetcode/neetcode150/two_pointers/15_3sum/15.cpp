#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> threesum;
    for (int i = 0; i < n - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int l = i + 1, r = n - 1;
      while (l < r) {
        if (nums[i] + nums[l] + nums[r] == 0) {
          threesum.push_back({nums[i], nums[l], nums[r]});
          l++;
          r--;
          while (l < r && nums[l] == nums[l - 1])
            l++;
          while (l < r && r != n - 1 && nums[r] == nums[r + 1])
            r++;
        }
        if (nums[l] + nums[r] + nums[i] < 0)
          l++;
        else if (nums[l] + nums[r] + nums[i] > 0)
          r--;
      }
    }
    return threesum;
  }
};

/*set<vector<int>> uniqueTriplets;
for (int i = 0; i < n - 2; i++) {
  for (int j = i + 1; j < n - 1; j++) {
    for (int k = j + 1; k < n; k++) {
      if (nums[i] + nums[j] + nums[k] == 0) {
        vector<int> triplet = {nums[i], nums[j], nums[k]};
        sort(triplet.begin(), triplet.end());
        uniqueTriplets.insert(triplet);
      }
    }
  }
}
return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());*/

int main() {
  int n;
  cout << "enter size: ";
  cin >> n;
  vector<int> nums(n);
  cout << "enter elements: ";
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  Solution *sol = new Solution();
  vector<vector<int>> three_sum = (*sol).threeSum(nums);
  for (int i = 0; i < three_sum.size(); i++) {
    for (int j = 0; j < three_sum[i].size(); j++)
      cout << three_sum[i][j] << ", ";
    cout << endl;
  }
  return 0;
}
