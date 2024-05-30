#include <iostream>
#include <string>
#include <vector>

#include "../lexemer.hpp"

int main() {
    // const char *str = "K@kobra!@we@mr!om\0";
    // const char str[18] = {'K', '@', 'k', 'o', 'b', 'r', 'a', '!', '@', 'w', 'e', '@', 'm', 'r', '!', 'o', 'm', '\0'};
    const std::string str = "K@kobra!@we@mr!om";
    
    // const char *delimeters = " @!rm\0";
    // const char delimeters[6] = {' ', '@', '!', 'r', 'm', '\0'};
    const std::string delimeters = " @!rm";

    std::vector<std::string> result = lexemer(str, delimeters);
    
    std::cout << result.size() << std::endl;
    
    for (const auto &item : result)
        std::cout << item << std::endl;

    return 0;
}