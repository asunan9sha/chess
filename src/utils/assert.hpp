#ifndef CHESS_ASSERT_HPP
#define CHESS_ASSERT_HPP

#define BREAKPOINT    __debugbreak()

#define ASSERT(x) if (!(x)) { \
fprintf( stderr, "assertion failed ( %s ), %s, %i \n", #x,__FILE__,__LINE__); \
BREAKPOINT; }


#endif //CHESS_ASSERT_HPP
