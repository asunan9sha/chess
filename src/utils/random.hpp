#ifndef CHESS_RANDOM_HPP
#define CHESS_RANDOM_HPP

#include <random>


class random {
public:
  template<typename T>
  static T next(const T &low, const T &high);

private:
  random();

  static random &get();

private:
  std::mt19937_64 mt;

};




#endif