#include "parent.hpp"

int main() {
    const char *pathChild1 = getenv("pathChild1");
    const char *pathChild2 = getenv("pathChild2");
    Parent(pathChild1, pathChild2);
    return 0;
}
  