#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    bool knows(vector<vector<int>>& M, int a, int b) {
        return M[a][b] == 1;
    }

public:
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;

        // Push all elements into the stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Compare pairs of elements and eliminate the one who is known
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (knows(M, a, b)) {
                s.push(b);
            } else {
                s.push(a);
            }
        }

        int potentialCelebrity = s.top();

        // Verify if the potential celebrity is valid
        for (int i = 0; i < n; i++) {
            if (i != potentialCelebrity && (knows(M, potentialCelebrity, i) || !knows(M, i, potentialCelebrity))) {
                return -1;
            }
        }

        return potentialCelebrity;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        int result = ob.celebrity(M, n);
        cout << result << endl;
    }

    return 0;
}
