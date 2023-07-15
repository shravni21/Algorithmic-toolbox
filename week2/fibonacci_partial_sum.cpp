#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the Nth Fibonacci number using top-down (recursive with memoization) approach
int fibonacciTopDown(int N, vector<int> &memo)
{
    if (memo[N] != -1)
        return memo[N];
    if (N < 2)
        return memo[N] = N;
    return memo[N] = fibonacciTopDown(N - 2, memo) + fibonacciTopDown(N - 1, memo);
}

// Function to calculate the Nth Fibonacci number using bottom-up (iterative) approach
int fibonacciBottomUp(int N)
{
    if (N < 2)
        return N;
    vector<int> dp(N + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; ++i)
        dp[i] = dp[i - 2] + dp[i - 1];
    return dp[N];
}

int main()
{
    int N;
    cin >> N;

    // Calculate the Nth Fibonacci number using top-down approach
    vector<int> memo(N + 1, -1);
    int ansTopDown = fibonacciTopDown(N, memo);

    // Calculate the Nth Fibonacci number using bottom-up approach
    int ansBottomUp = fibonacciBottomUp(N);

    // Assert the correctness of both methods
    if (ansTopDown != ansBottomUp)
    {
        cout << "Error: Top-down and Bottom-up methods give different results." << endl;
        return 1;
    }

    cout << ansTopDown << endl;
    return 0;
}
