#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
#include <vector>

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> most_freq;
    int n = nums.size();
    vector<int> checked(n, 0);
    vector<int> frequency(n, 0);

    for (int i = 0; i < n; i++) {
      if (checked[i] == 1) {
        continue;
      }
      frequency[i]++;
      checked[i] = 1;
      for (int j = 0; j < n; j++) {
        if (checked[j] == 0) {
          if (nums[i] == nums[j]) {
            frequency[i]++;
            checked[j]++;
          }
        }
      }
    }

    vector<pair<int, pair<int, int>>> candidates;
    // stores frequency and index
    for (int i = 0; i < n; i++) {
      if (frequency[i] > 0) {
        candidates.push_back({frequency[i], {i + 1, nums[i]}});
      }
    }
    // sort by frequency in desec order
    sort(candidates.begin(), candidates.end(),
         [](const pair<int, pair<int, int>> &a,
            const pair<int, pair<int, int>> &b) { return a.first > b.first; });

    for (int i = 0; i < k; i++) {
      most_freq.push_back(candidates[i].second.second);
    }
    return most_freq;
  }
};

int main() {
  int n, k;
  cout << "enter size: ";
  cin >> n;
  vector<int> nums(n);
  cout << "enter elements: ";
  for (int i = 0; i < nums.size(); i++) {
    cin >> nums[i];
  }
  cout << "enter how many most frequent elements do you need: ";
  cin >> k;

  Solution sol;
  vector<int> most_freq;
  most_freq = sol.topKFrequent(nums, k);
  cout << k << " most frequent elements: ";
  for (int i = 0; i < most_freq.size(); i++) {
    cout << most_freq[i] << ", ";
  }
  return 0;
}
