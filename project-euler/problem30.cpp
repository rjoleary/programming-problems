#include <iostream>

int expo5(int);

int main()
{
    int sum = 0;
    for (int i = 2; i < 1000000; i++)
    {
        // "abcdef" = i
        int a = expo5(i / 100000);
        int b = expo5(i / 10000  % 10);
        int c = expo5(i / 1000   % 10);
        int d = expo5(i / 100    % 10);
        int e = expo5(i / 10     % 10);
        int f = expo5(i          % 10);
        if (a + b + c + d + e + f == i)
            sum += i;
    }
    std::cout << sum << '\n';
}

int expo5(int x)
{
    return x * x * x * x * x;
}
