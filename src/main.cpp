#include "filehandler.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: fcleaner <directories separated by space>" << std::endl;
        return 1;
    }

    std::vector<std::string> should_be_removed;
    for (int i = 1; i < argc; i++) {
        should_be_removed.push_back(argv[i]);
    }

    FileHandler file_handler(should_be_removed);

    fs::path current = fs::current_path();
    file_handler.browser_directory(current);
}
