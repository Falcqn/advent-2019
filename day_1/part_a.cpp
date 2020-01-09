#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>

auto fuel_for_mass(int const mass)
{
  return static_cast<int>(std::floor(mass / 3.0)) - 2;
}

int main()
{
  auto const accumulate_fn = [] (auto const total_fuel, auto const module_mass) {
    return total_fuel + fuel_for_mass(module_mass);
  };

  auto const input_iter = std::istream_iterator<int>{std::cin};
  auto const input_end  = std::istream_iterator<int>{};
  auto const total_fuel = std::accumulate(input_iter, input_end, 0, accumulate_fn);

  std::cout << total_fuel << std::endl;
  return 0;
}
