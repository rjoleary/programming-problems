#include <iostream>

int main()
{
    int sumOfSquares = 0;
    for (int i = 1; i <= 100; ++i)
        sumOfSquares += i * i;

    int squareOfSums = 0;
    for (int i = 1; i <= 100; ++i)
        squareOfSums += i;
    squareOfSums *= squareOfSums;

    std::cout << squareOfSums - sumOfSquares << '\n';
}
