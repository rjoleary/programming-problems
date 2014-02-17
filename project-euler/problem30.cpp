#include <iostream>

// Raise to the 5th power.
int pow5(int);

int main()
{
    int sum = 0;
    for (int i = 2; i < 1000000; i++)
    {
        // "abcdef" = i
        int a = pow5(i / 100000);
        int b = pow5(i / 10000  % 10);
        int c = pow5(i / 1000   % 10);
        int d = pow5(i / 100    % 10);
        int e = pow5(i / 10     % 10);
        int f = pow5(i          % 10);
        if (a + b + c + d + e + f == i)
            sum += i;
    }
    std::cout << sum << '\n';
}

int pow5(int x)
{
    return x * x * x * x * x;
}
