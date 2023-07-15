#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int M = A.size();
    int N = B.size();
    int O = C.size();

    vector<vector<vector<int>>> dp(M + 1, vector<vector<int>>(N + 1, vector<int>(O + 1, 0)));

    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            for (int k = 1; k <= O; ++k)
            {
                if (A[i - 1] == B[j - 1] && A[i - 1] == C[k - 1])
                {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                }
                else
                {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }
    return dp[M][N][O];
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

    int O;
    cin >> O;
    vector<int> C(O);
    for (int i = 0; i < O; ++i)
    {
        cin >> C[i];
    }

    int ans = lcs(A, B, C);
    cout << ans << endl;

    return 0;
}
