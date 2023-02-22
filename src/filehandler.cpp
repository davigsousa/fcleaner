#include "filehandler.h"


FileHandler::FileHandler(std::vector<std::string> should_be_removed) {
    this->should_be_removed = should_be_removed;
}

FileHandler::~FileHandler() {
    should_be_removed.clear();
}

void FileHandler::browser_directory(const fs::path& path) {
    for (const fs::directory_entry& dir_entry : fs::directory_iterator(path)) {
        std::string current = dir_entry.path().filename();
        
        if (!dir_entry.is_directory()) {
            continue;
        }

        if (folder_should_be_removed(current)) {
            fs::remove_all(dir_entry.path());
            std::cout << "Removed: " << dir_entry.path() << std::endl;
            continue;
        }

        browser_directory(dir_entry.path());
    }
}

bool FileHandler::folder_should_be_removed(std::string str) {
    for (std::string s : should_be_removed) {
        if (s == str) {
            return true;
        }
    }
    return false;
}