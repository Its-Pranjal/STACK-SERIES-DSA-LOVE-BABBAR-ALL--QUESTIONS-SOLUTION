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

            while (!st.empty() && height[st.top()] >= curr) { // Changed !st.top() to !st.empty()
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

            while (!st.empty() && height[st.top()] >= curr) { // Changed !st.top() to !st.empty()
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int> &height) {
        int n = height.size();

        vector<int> next = nextSmallerElement(height, n); // Added type specification
        vector<int> prev = prevSmallerElement(height, n); // Added type specification

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

public:
    int maxArea(vector<vector<int>>& M, int n, int m) {
        int area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] != 0) {
                    M[i][j] += M[i - 1][j]; // Fixed index i-1 instead of i-1 and j-1
                } else {
                    M[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            area = max(area, largestRectangleArea(M[i])); // Changed M[i][m] to M[i]
        }

        return area;
    }
};

int main() {
    // Example usage
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };
    int n = matrix.size();
    int m = matrix[0].size();

    int result = sol.maxArea(matrix, n, m);
    cout << "Maximum rectangle area: " << result << endl;

    return 0;
}
