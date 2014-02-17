#include <iostream>

int p(int c, int k)
{
    if (k == 0)
        return 0;
    if (c == 0)
        return 1;

    // memoization table
    static int memo[201][9];
    if (memo[c][k])
        return memo[c][k];

    // Find the sum of using this coin or a coin of smaller value.
    int sum = 0;
    const int K[] = {1, 2, 5, 10, 20, 50, 100, 200};
    if (K[k-1] > c)
        sum = p(c, k - 1);
    else
        sum = p(c - K[k-1], k) + p(c, k - 1);
    return memo[c][k] = sum;
}

int main()
{
    std::cout << p(200, 8) << '\n';
}
