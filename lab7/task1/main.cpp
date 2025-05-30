#include "Print.h"
#include <vector>
#include <list>

int main() {
    std::vector<int> data = {1, 2, 3};
    Print(data, ", ");

    std::list<std::string> words = {"Hello", "world", "!"};
    Print(words, " ");
}