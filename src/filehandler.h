#include <string>
#include <vector>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

class FileHandler {
    public:
        FileHandler(std::vector<std::string> should_be_removed);
        ~FileHandler();
        std::vector<std::string> should_be_removed;
        void browser_directory(const fs::path& path);
    private:
        bool folder_should_be_removed(std::string str);
};
