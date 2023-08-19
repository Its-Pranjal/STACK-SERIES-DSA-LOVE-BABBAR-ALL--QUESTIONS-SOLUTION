#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
    vector<int> prevSmallerElement(vector<int> &height, int n) {
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int curr = height[i];

            while (st.top() != -1 && height[st.top()] >= curr) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> nextSmallerElement(vector<int> &height, int n) {
        stack<int> st;
        st.push(n);

        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = height[i];

            while (st.top() != n && height[st.top()] >= curr) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size();

        vector<int> next;
        next = nextSmallerElement(height, n);

        vector<int> prev;
        prev = prevSmallerElement(height, n);

        int area = 0;

        for (int i = 0; i < n; i++) {
            int l = height[i];

            int r = next[i];
            int p = prev[i];

            int b = r - p - 1;

            int newArea = l * b;

            area = max(area, newArea);
        }

        return area;
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    int result = sol.largestRectangleArea(heights);
    cout << "Largest rectangle area: " << result << endl;

    return 0;
}
