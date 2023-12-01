#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("./input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    std::string line;
    int sum = 0;

    while (std::getline(inputFile, line)) {
        // Process each line of the input file here
        // For each line get the first digit and the last digit
        // then combine them to obtain a number and add it to a sum
        // Example: 1122 -> 1  2 = 12
        // Example: 1111 -> 1 1 = 11
        size_t firstDigitPos = line.find_first_of("0123456789");
        size_t lastDigitPos = line.find_last_of("0123456789");
        if (firstDigitPos != std::string::npos && lastDigitPos != std::string::npos) {
            // Extract the first and last digits
            char firstDigit = line[firstDigitPos];
            char lastDigit = line[lastDigitPos];

            // Combine them to obtain a number
            int combinedNumber = (firstDigit - '0') * 10 + (lastDigit - '0');

            // Add it to the sum
            sum += combinedNumber;
        }


        // Example: Print each line
        // std::cout << line << std::endl;
    }
    std::cout << "Sum: " << sum << std::endl;

    inputFile.close();

    return 0;
}
