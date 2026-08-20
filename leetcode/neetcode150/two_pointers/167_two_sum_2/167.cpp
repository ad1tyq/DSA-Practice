#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size(), left = 0, right = numbers.size() - 1, sum = 0;
    while (left < right) {
      sum = numbers[left] + numbers[right];
      if (sum == target)
        return {left + 1, right + 1};
      else if (sum < target)
        left++;
      else
        right--;
    }
    return {-1, -1};
  }
};

int main() {
  int n, target;
  cout << "enter target: ";
  cin >> target;
  cout << "enter size: ";
  cin >> n;
  vector<int> numbers(n);
  cout << "enter nos: ";
  for (int i = 0; i < n; i++)
    cin >> numbers[i];
  Solution *sol = new Solution();
  vector<int> twoSum = (*sol).twoSum(numbers, target);
  for (int i = 0; i < twoSum.size(); i++)
    cout << twoSum[i] << ", ";
}
