#include "app/application.hpp"

int main(){

  Config config;
  Application app(config);
  app.run();

  return 0;
}