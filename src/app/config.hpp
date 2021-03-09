#ifndef CHESS_CONFIG_HPP
#define CHESS_CONFIG_HPP

struct Config {
  const char *title = "chess";
  unsigned width = 800;
  unsigned height = 800;
  unsigned frameLimit = 60;
  bool isFullScreen = false;
  bool vSync = true;
  unsigned tps = 120;
};


#endif //CHESS_CONFIG_HPP
