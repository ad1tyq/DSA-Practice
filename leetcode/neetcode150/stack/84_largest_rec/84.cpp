#include <iostream>
using namespace std;
#include <stack>
#include <vector>

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int area = 0, n = heights.size();
    stack<int> st;
    for (int i = 0; i <= n; i++) {
      int current_height = (i == n) ? 0 : heights[i];
      while (!st.empty() && heights[st.top()] > current_height) {
        int height = heights[st.top()];
        st.pop();
        int width;
        if (st.empty())
          width = i;
        else
          width = i - st.top() - 1;
        area = max(area, height * width);
      }
      st.push(i);
    }
    return area;
  }
};

int main() {
  int n;
  cout << "enter size: ";
  cin >> n;
  cout << "enter heights: ";
  vector<int> heights(n);
  for (int i = 0; i < n; i++)
    cin >> heights[i];
  Solution *sol = new Solution();
  int area = (*sol).largestRectangleArea(heights);
  cout << "area: " << area;
}
