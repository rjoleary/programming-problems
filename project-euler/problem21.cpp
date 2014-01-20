#include <iostream>

int main()
{
    // Create a list of the sum of the proper divisors.
    const int length = 10000;
    int divisorSums[length] = {0};
    for (int i = 1; i < length / 2; i++)
        for (int j = i * 2; j < length; j += i)
            divisorSums[j] += i;

    // Search for matches.
    int amicableSum = 0;
    for (int i = 1; i < length; i++)
        if (divisorSums[i] != 0 && divisorSums[i] < length)
            if (i == divisorSums[divisorSums[i]] && i != divisorSums[i])
                amicableSum += i; // i and divisorSums[i] are amicable

    std::cout << amicableSum << '\n';
}
