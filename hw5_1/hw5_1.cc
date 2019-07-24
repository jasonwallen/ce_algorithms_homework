#include <iostream>

int main(int argc, char *argv[])
{
    int key = 9;
    std::cout << key << "\n";
    int x = (key + 5) * (key + 5);
    x = x / 16;
    x = x + key;
    x = x % 11;
    std::cout << x << "\n";

    return 0;
}