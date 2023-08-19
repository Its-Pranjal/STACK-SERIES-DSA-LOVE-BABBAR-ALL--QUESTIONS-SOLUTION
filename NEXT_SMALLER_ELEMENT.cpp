#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/* Function to find the index of the next smaller element */
vector<int> nextSmallerElement(vector<int> &height, int n) {
    stack<int> st;
    st.push(n); // Start with a sentinel element at the end

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        int curr = height[i];

        while (st.top() != n && height[st.top()] >= curr) { // Changed !st.top() to st.top() != n
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

int main() {
    // Example usage
    vector<int> heights = {6, 2, 5, 4, 5, 1, 6};
    int n = heights.size();

    vector<int> result = nextSmallerElement(heights, n);

    cout << "Next smaller element indices:" << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
