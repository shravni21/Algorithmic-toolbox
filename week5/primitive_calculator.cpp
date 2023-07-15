#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOpsBottomUp(int N)
{
    vector<int> dp(N + 1, numeric_limits<int>::max());
    dp[1] = 0;
    for (int i = 2; i <= N; ++i)
    {
        if (i % 3 == 0)
        {
            dp[i] = min(dp[i], 1 + dp[i / 3]);
        }
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i], 1 + dp[i / 2]);
        }
        dp[i] = min(dp[i], 1 + dp[i - 1]);
    }
    return dp[N];
}

vector<int> reconstruct(int N)
{
    vector<int> A;
    while (N > 0)
    {
        A.push_back(N);
        if (N % 3 == 0)
        {
            N /= 3;
        }
        else if (N % 2 == 0)
        {
            N /= 2;
        }
        else
        {
            N -= 1;
        }
    }
    reverse(A.begin(), A.end());
    return A;
}

int main()
{
    int N;
    cin >> N;

    int dp_ans = minOpsBottomUp(N);
    vector<int> A = reconstruct(N);

    cout << A.size() - 1 << endl;
    for (int num : A)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
