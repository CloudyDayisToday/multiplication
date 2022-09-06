#include <tuple>
#include <math.h>
#include <string>
#include "../include/multiplication.h"

static std::tuple<int64_t, int64_t> seperate (int64_t x, int64_t m)
{
    return std::make_tuple(x/std::pow(10.0, m), x % static_cast<int64_t>(std::pow(10.0, m)));
}

int64_t MultiAlgor::karatsuba_algorithm(int64_t x, int64_t y)
{
    if ((x < 10) || (y < 10))
    {
        return x * y;
    }

    int64_t high1, low1, high2, low2, z0, z1, z2;
    int64_t min_digits = std::min(floor(log10(x)+1), floor(log10(y)+1));
    int64_t m = floor(min_digits/2);

    std::tie(high1, low1) = seperate(x, m);
    std::tie(high2, low2) = seperate(y, m);

    z0 = karatsuba_algorithm(low1, low2);
    z2 = karatsuba_algorithm(high1, high2);
    z1 = karatsuba_algorithm(high1 + low1, high2 + low2);

    return z2 * (pow(10, 2*m)) + ((z1 - z2 - z0) * pow(10, m)) + z0;

}

int64_t MultiAlgor::peasant_algorithm(int64_t x, int64_t y)
{
    if (x == 1) return y;
    return ((x % 2) != 0) ? y + peasant_algorithm(floor(x/2), y*2) : peasant_algorithm(floor(x/2), y*2);
}

int64_t MultiAlgor::quarter_square_algorithm(int64_t x, int64_t y)
{
    return floor(pow(x+y, 2)/4) - floor(pow(x-y, 2)/4);
}

