#include <iostream>
#include <span>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

bool is_delimeter(const std::span<const char> delimeters, const char symbol) {
    return std::find(delimeters.begin(), delimeters.end(), symbol) != delimeters.end();
}

auto lexemer(const std::span<const char> input_str, const std::span<const char> delimeters) {
    std::vector<std::string> result;
    
    if (input_str.empty() || delimeters.empty()) {
        std::cout << "Input string or delimeters are empty\n";
        return result;
    }
    
    auto it_holder = input_str.begin(), it_runner = input_str.begin();
    
    while (it_holder < input_str.end()) {
        if (is_delimeter(delimeters, *it_holder))
            it_holder++;
        else if (is_delimeter(delimeters, *it_runner) || it_runner == input_str.end()) {
            result.emplace_back(it_holder, it_runner);
            it_holder = it_runner + 1;
        }
        
        ++it_runner;
    }
    
    return result;
}

auto lexemer(const char *input_str, const std::span<const char> delimeters) {
    return lexemer(std::span<const char>(input_str, std::strlen(input_str)), delimeters);
}

auto lexemer(const std::span<const char> input_str, const char *delimeters) {
    return lexemer(input_str, std::span<const char>(delimeters, std::strlen(delimeters)));
}

auto lexemer(const char *input_str, const char *delimeters) {
    return lexemer(std::span<const char>(input_str, std::strlen(input_str)), std::span<const char>(delimeters, std::strlen(delimeters)));
}