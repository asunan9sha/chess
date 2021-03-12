#include <utils/random.hpp>
#include <ctime>

random::random()
    : mt(static_cast<unsigned long long>(time(nullptr))) { }

random &random::get() {
  static random r;
  return r;
}

template<>
int random::next(const int &low, const int &high) {
  auto bounds = std::uniform_int_distribution<int>(low, high);
  return bounds(get().mt);
}

