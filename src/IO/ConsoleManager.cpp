#include "ConsoleManager.hpp"

using namespace std;
using namespace IO;


void IO::setxy(int x, int y) {
    printf("\x1b[%d;%dH", y, x);
}


void IO::print(std::string str) {
    printf("%s", str.c_str());
}

void IO::println(std::string str) {
    printf("%s\n", str.c_str());
}
