// https://adventofcode.com/2019/day/2

#include <cassert>
#include <fstream>
#include <iterator>
//#include <numeric>
#include <vector>
#include <iostream>  // tmp

auto constexpr answer_part_1 = 77;
auto constexpr answer_part_2 = 77;

struct execution_state {
  std::vector<int> program;
  std::vector<int>::size_type instruction_idx = 0U;
};

bool finished(execution_state const & s)
{
  return s.instruction_idx == s.program.size();
}

void execute_next(execution_state& s)
{
  assert(!finished(s));
  auto op_code = s.program[s.instruction_idx];
  //switch (auto op_code
}

void run(execution_state & s)
{
  while (!finished(s))
    execute_next(s);
}


std::vector initial { 1, 0, 0, 0, 99 };
std::vector final { 2, 0, 0, 0, 99 };
execution_state s { initial, 0U };
run(s);
assert(s.progran == final);

1,0,0,0,99 becomes 2,0,0,0,99 (1 + 1 = 2).
2,3,0,3,99 becomes 2,3,0,6,99 (3 * 2 = 6).
2,4,4,5,99,0 becomes 2,4,4,5,99,9801 (99 * 99 = 9801).
1,1,1,4,99,5,6,0,99 becomes 30,1,1,4,2,5,6,0,99.

int main()
{
    std::ifstream in("input");
    std::vector<int> const masses {
            std::istream_iterator<int>(in),
	    std::istream_iterator<int>() };
}
