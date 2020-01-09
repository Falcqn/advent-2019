#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>

int main()
{
  std::cout << std::accumulate(
      std::istream_iterator<int>{std::cin},
      std::istream_iterator<int>{},
      0,
      [] (auto const total_fuel, auto const mass) { return total_fuel + std::floor(mass / 3.0) - 2; }
  ) << std::endl;
  return 0;
}
