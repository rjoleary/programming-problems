#include <fstream>
#include <iostream>
#include <utility>

int main()
{
    std::ifstream file("problem18.txt");
    if (!file)
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    const int height = 15;

    // Initialize the triangle structure.
    int triangle[height][height];
    for (int i = 0; i < height; i++)
        for (int j = 0; j <= i; j++)
            file >> triangle[i][j];

    // Each element is the maximum sum of the elements below it.
    for (int i = height - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            triangle[i][j] += std::max(triangle[i+1][j], triangle[i+1][j+1]);

    std::cout << triangle[0][0] << '\n';
}
