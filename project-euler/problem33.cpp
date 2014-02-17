#include <algorithm>
#include <iostream>
#include <utility>

struct Fraction
{
    int n, d;
};

bool operator == (const Fraction &lhs, const Fraction &rhs);
bool isCancelling(const Fraction &lhs, const Fraction &rhs);
int calcGCF(int a, int b);
Fraction simplify(const Fraction &f);

int main()
{
    Fraction product{1, 1};

    // cd
    // --
    // ab
    for (int a = 1; a < 10; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            for (int c = 1; c < 10; c++)
            {
                // ca    c
                // -- -> -
                // ab    b
                if (isCancelling(Fraction{c * 10 + a, a * 10 + b}, Fraction{c, b}))
                {
                    product.n *= c * 10 + a;
                    product.d *= a * 10 + b;
                    product = simplify(product);
                }

                // cb    c
                // -- -> -
                // ab    a
                if (isCancelling(Fraction{c * 10 + b, a * 10 + b}, Fraction{c, a}))
                {
                    product.n *= c * 10 + b;
                    product.d *= a * 10 + b;
                    product = simplify(product);
                }
            }
        }
    }

    std::cout << simplify(product).d << '\n';
}

bool operator == (const Fraction &lhs, const Fraction &rhs)
{
    return lhs.n == rhs.n && lhs.d == rhs.d;
}

bool isCancelling(const Fraction &f1, const Fraction &f2)
{
    // must be two digits
    if (f1.n == 0 || f2.n == 0)
        return false;
    if (f1.d == 0 || f2.d == 0)
        return false;
    // must be be less than 1
    if (f1.n / f1.d >= 1)
        return false;
    if (f2.n / f2.d >= 1)
        return false;
    return simplify(f1) == simplify(f2);
}

int calcGCF(int a, int b)
{
    while (a != 0)
    {
        b %= a;
        std::swap(a, b);
    }
    return b;
}

Fraction simplify(const Fraction &f)
{
    int gcf = calcGCF(f.n, f.d);
    return Fraction{f.n / gcf, f.d / gcf};
}
