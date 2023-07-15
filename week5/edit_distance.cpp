#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int editDistance(const string &A, const string &B)
    {
        int M = A.size();
        int N = B.size();
        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

        for (int i = 1; i <= M; ++i)
            dp[i][0] = i;
        for (int j = 1; j <= N; ++j)
            dp[0][j] = j;
        for (int i = 1; i <= M; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                dp[i][j] = min({dp[i - 1][j - 1] + ((A[i - 1] == B[j - 1]) ? 0 : 1),
                                dp[i - 1][j] + 1,
                                dp[i][j - 1] + 1});
            }
        }
        return dp[M][N];
    }
};

int main()
{
    Solution solution;
    string A, B;
    cin >> A >> B;
    int ans = solution.editDistance(A, B);
    cout << ans << endl;
    return 0;
}
