#include <cstdlib>
#include <iostream>

typedef std::int64_t Scalar;

// Uses metaprogramming to calculate the binomial coefficient.
template <Scalar X, Scalar Y>
struct FindRoutes
{
    static const Scalar value = FindRoutes<X-1,Y>::value + FindRoutes<X,Y-1>::value;
};

template <>
struct FindRoutes<0,0>
{
    static const Scalar value = 1;
};

template <Scalar Y>
struct FindRoutes<-1,Y>
{
    static const Scalar value = 0;
};

template <Scalar X>
struct FindRoutes<X,-1>
{
    static const Scalar value = 0;
};

int main()
{
    std::cout << FindRoutes<20,20>::value << '\n';
}

