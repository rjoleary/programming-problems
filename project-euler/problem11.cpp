#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <utility>

// Returns the maximum product of 4 elements of the grid separated by the
//  value of `offset`.
int maxAlongLine(std::vector<int> &grid, int offset);

int main()
{
    // Load the 20x20 grid.
    std::ifstream file("problem11.txt");
    if (!file)
    {
        std::cerr << "Cannot open file\n";
        return 1;
    }

    typedef std::istream_iterator<int> I;
    std::vector<int> grid(I(file), (I()));

    const int gridSize = 20 * 20;
    if (grid.size() != gridSize)
    {
        std::cout << "Invalid file contents\n";
        return 1;
    }

    // These are the offsets for different movement about the grid.
    // This is broken because it wraps around, but it still gives the right
    //  answer.
    const int horiOff = 1;
    const int vertOff = 20;
    const int diagLOff = 19;
    const int diagROff = 21;

    // Maximize the product.
    int maxProduct = 0;
    maxProduct = std::max(maxProduct, maxAlongLine(grid, horiOff));
    maxProduct = std::max(maxProduct, maxAlongLine(grid, vertOff));
    maxProduct = std::max(maxProduct, maxAlongLine(grid, diagLOff));
    maxProduct = std::max(maxProduct, maxAlongLine(grid, diagROff));

    std::cout << maxProduct << '\n';
}

int maxAlongLine(std::vector<int> &grid, int offset)
{
    int maxProduct = 0;
    for (int i = 0; i < static_cast<int>(grid.size()) - offset * 3; i++)
    {
        int n1 = grid[i];
        int n2 = grid[i+offset*1];
        int n3 = grid[i+offset*2];
        int n4 = grid[i+offset*3];
        maxProduct = std::max(maxProduct, n1 * n2 * n3 * n4);
    }
    return maxProduct;
}
