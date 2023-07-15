#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxKnapsack(const vector<int> &A, int T)
{
    int N = A.size();
    vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= T; ++j)
        {
            if (j >= A[i - 1])
            {
                dp[i][j] = max(A[i - 1] + dp[i - 1][j - A[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[N][T];
}

int main()
{
    int T;
    cin >> T; 

    int N;
    cin >> N; 

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int ans = maxKnapsack(A, T);
    cout << ans << endl;

    return 0;
}
