// https://adventofcode.com/2019/day/1

#include <cassert>
#include <fstream>
#include <iterator>
#include <numeric>
#include <vector>

auto constexpr answer_part_1 = 3365459;
auto constexpr answer_part_2 = 5045301;

constexpr int fuel_requirement(int mass)
{
    return (mass / 3) - 2;  
}

static_assert(fuel_requirement(12) == 2);
static_assert(fuel_requirement(14) == 2);
static_assert(fuel_requirement(1969) == 654);
static_assert(fuel_requirement(100756) == 33583);

int total_fuel_requirement(std::vector<int> const & masses)
{
  return std::accumulate(masses.begin(), masses.end(), 0, [] (auto acc, auto v) { return acc + fuel_requirement(v); });
}

constexpr int fuel_requirement_inclusive(int mass)
{
    auto total = 0;
    while (true) {
        mass = fuel_requirement(mass);
        if (mass <= 0)
	    break;
        total += mass;
    }
    return total;
}

static_assert(fuel_requirement_inclusive(14) == 2);
static_assert(fuel_requirement_inclusive(1969) == 966);
static_assert(fuel_requirement_inclusive(100756) == 50346);

int total_fuel_requirement_inclusive(std::vector<int> const & masses)
{
    return std::accumulate(masses.begin(), masses.end(), 0, [] (auto acc, auto v) { return acc + fuel_requirement_inclusive(v); });
}

int main()
{
    std::ifstream in("input");
    std::vector<int> const masses {
            std::istream_iterator<int>(in),
	    std::istream_iterator<int>() };
    assert(total_fuel_requirement(masses) == answer_part_1);
    assert(total_fuel_requirement_inclusive(masses) == answer_part_2);
}
