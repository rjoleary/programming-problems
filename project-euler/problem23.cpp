#include <iostream>

int main()
{
    const int length = 30000;

    // indicates which numbers are sums of abundant numbers
    bool isSumOfAbundants[length] = {0};

    // Create a list of the sum of the proper divisors.
    int divisorSums[length] = {0};
    for (int i = 1; i < length; i++)
    {
        // Add number to all future sums.
        for (int j = i * 2; j < length; j += i)
            divisorSums[j] += i;

        // number is abundant
        if (i != 1 && divisorSums[i] > i)
            for (int j = 2; j <= i; j++)
                if (divisorSums[j] > j)
                    if (i + j < length)
                        isSumOfAbundants[i+j] = true;
    }

    // 0 and 1 are not abundant
    isSumOfAbundants[0] = isSumOfAbundants[1] = false;

    // add the numbers which are not abundant
    int sum = 0;
    for (int i = 0; i < length; i++)
        if (!isSumOfAbundants[i])
            sum += i;

    std::cout << sum << '\n';
}
