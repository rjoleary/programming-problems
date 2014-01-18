#include <iostream>

// Reverses the digits in an integer. Ex: 1234 -> 4321
int reverse(int value);

int main()
{
    // Test all possible combinations of a*b and keep the largest palindrome.
	int largestProduct = 0;
	for (int a = 999; a >= 0; a--)
	{
		for (int b = a; b >= 0; b--)
		{
			int product = a * b;
			
			// Since b iterates in reverse, a significant number of combinations
			//  do not need to be checked.
			if (product < largestProduct)
			    break;
			    
			if (reverse(product) == product)
				largestProduct = std::max(product, largestProduct);
		}
	}

	std::cout << largestProduct << '\n';
}

int reverse(int value)
{
	int reverse = 0;
	while (value > 0)
	{
	    reverse *= 10;
	    reverse += value % 10;
		value = value / 10;
	}

	return reverse;
}
