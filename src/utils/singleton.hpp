#ifndef CHESS_SINGLETON_HPP
#define CHESS_SINGLETON_HPP

class Singleton {
public:
  Singleton(Singleton &other) = delete;
  Singleton(Singleton &&other) = delete;

  Singleton &operator=(Singleton &other) = delete;
  Singleton &operator=(Singleton &&other) = delete;

protected:
  Singleton() = default;
  virtual ~Singleton() = default;
};


#endif //CHESS_SINGLETON_HPP
