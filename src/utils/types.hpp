#ifndef CHESS_TYPES_HPP
#define CHESS_TYPES_HPP

#include <SFML/System/Vector2.hpp>
#include "SFML/Graphics/Color.hpp"

typedef sf::Vector2f vec2;
typedef sf::Vector2i vec2i;

struct vec4 {
  float x;
  float y;
  float z;
  float w;

  vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }
  vec4(): x(0), y(0), z(0), w(0) { }
  vec4(float x) : x(x), y(x), z(x), w(x) { }
};

inline vec4 operator-(const vec4 &left, const vec4 &right) {
  return vec4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
}

inline vec4 operator+(const vec4 &left, const vec4 &right) {
  return vec4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
}

static sf::Color encode(const vec4 &color) {
  const sf::Uint8 r1 = static_cast<sf::Uint8>(color.x * 255);
  const sf::Uint8 g1 = static_cast<sf::Uint8>(color.y * 255);
  const sf::Uint8 b1 = static_cast<sf::Uint8>(color.z * 255);
  const sf::Uint8 a1 = static_cast<sf::Uint8>(color.w * 255);

  return sf::Color(r1, g1, b1, a1);
}



#endif
