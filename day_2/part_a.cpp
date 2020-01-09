#include <iostream>
#include <iterator>
#include <vector>

auto read_state(std::istream& is)
{
  auto begin = std::istream_iterator<int>{is};
  auto end   = std::istream_iterator<int>{};
  auto out   = std::vector<int>{};

  std::copy(begin, end, std::back_inserter(out));
  return out;
}

void dump_state(std::vector<int> const& state, char sep)
{
  for (auto i = state.cbegin(); i != state.cend(); i ++)
  {
    std::cout << *i;

    if (i + 1 != state.cend())
      std::cout << sep;
  }

  std::cout << '\n';
}

void run(std::vector<int>& state)
{
  auto current_pos = state.begin();

  while (current_pos != state.end())
  {
    switch (*current_pos)
    {
      case 1:
      {
        int a = state[*++current_pos];
        int b = state[*++current_pos];
        state[*++current_pos] = a + b;
        break;
      }

      case 2:
      {
        int a = state[*++current_pos];
        int b = state[*++current_pos];
        state[*++current_pos] = a * b;
        break;
      }

      case 99:
      {
        return;
      }

      default:
      {
        throw std::logic_error{"unexpected opcode"};
      }
    }

    ++current_pos;
  }
}

int main()
{
  auto state = read_state(std::cin);
  run(state);
  dump_state(state, ',');

  return 0;
}
