#include <iostream>
using namespace std;
#include <stack>
#include <vector>

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    stack<int> indexes;
    vector<int> answers(n);
    for (int i = 0; i < n; i++) {
      while (!indexes.empty() &&
             temperatures[indexes.top()] < temperatures[i]) {
        answers[indexes.top()] = i - indexes.top();
        indexes.pop();
      }
      indexes.push(i);
    }
    while (!indexes.empty()) {
      answers[indexes.top()] = 0;
      indexes.pop();
    }
    return answers;
  }
};

int main() {
  int n;
  cout << "enter size: ";
  cin >> n;
  vector<int> temperatures(n);
  cout << "enter temperatures: ";
  for (int i = 0; i < n; i++)
    cin >> temperatures[i];
  Solution *sol = new Solution();
  vector<int> answers = (*sol).dailyTemperatures(temperatures);
  for (int i = 0; i < n; i++)
    cout << answers[i] << ", ";
  return 0;
}
