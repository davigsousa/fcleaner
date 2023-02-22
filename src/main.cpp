#include <iostream>
#include <filesystem>
using namespace std::filesystem;

int main(int argc, char *argv[])
{
    std::error_code ec;

    if (is_empty(path("/Users/davi/"), ec)) {
        std::cout << "The directory is empty" << std::endl;
    } else if (ec) {
        std::cout << "error on open file" << std::endl;
        ec.clear();
    } else {
        std::cout << "The directory is not empty" << std::endl;
    }
}
