#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(const vector<int> &A, const vector<int> &B)
{
    int M = A.size();
    int N = B.size();
    vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[M][N];
}

int main()
{
    int M;
    cin >> M;
    vector<int> A(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> A[i];
    }

    int N;
    cin >> N;
    vector<int> B(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> B[i];
    }

    int ans = lcs(A, B);
    cout << ans << endl;

    return 0;
}
