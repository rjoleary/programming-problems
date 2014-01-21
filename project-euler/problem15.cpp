#include <cstdint>
#include <iostream>

typedef std::int64_t Scalar;

// Calculate the binomial coefficient using recursion and memoization.
Scalar findRoutes(int x, int y)
{
    static Scalar memo[21][21];

    if (x == 0 && y == 0)
        return 1;

    if (x < 0 || y < 0)
        return 0;

    if (memo[x][y] != 0)
        return memo[x][y];
    else
        return memo[x][y] = findRoutes(x - 1, y) +
                            findRoutes(x, y - 1);
}

int main()
{
    std::cout << findRoutes(20, 20) << '\n';
}

