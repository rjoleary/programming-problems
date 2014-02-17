#include <iostream>

// Calculate the nth factorial.
int fact(int n);

int main()
{
    const int digits[] = {
        fact(0), fact(1), fact(2), fact(3),
        fact(4), fact(5), fact(6), fact(7),
        fact(8), fact(9)
    };

    int sum = 0;
    for (int i = 3; i < 50000; i++)
    {
        int digitSum = 0;
        for (int j = i; j > 0; j /= 10)
            digitSum += digits[j%10];
        if (digitSum == i)
            sum += i;
    }
    std::cout << sum << '\n';
}

int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}
