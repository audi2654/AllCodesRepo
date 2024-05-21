//Code snippet to run a program directly on CLI

g++ '-xc++' - <<eof
#include <iostream>
#include <string>

auto main() -> int {
  std::cout << std::endl;
  std::string out{"Hello world"};
  std::cout << (out[out.size()] == '\0');
  std::cout << std::endl;
}
eof
./a.out