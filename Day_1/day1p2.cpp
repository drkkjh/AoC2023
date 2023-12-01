#include <iostream>
#include <string>

struct DigitTuple {
    std::string digit;
    std::string number;
};

int main() {
    DigitTuple digits[] = {
        { "zero", "zero0zero" },
        { "one", "one1one" },
        { "two", "two2two" },
        { "three", "three3three" },
        { "four", "four4four" },
        { "five", "five5five" },
        { "six", "six6six" },
        { "seven", "seven7seven" },
        { "eight", "eight8eight" },
        { "nine", "nine9nine" },
    };

    int sum = 0;
    std::string line;

    while (std::getline(std::cin, line)) {
        // Replace spelled-out numbers first
        for (std::size_t i = 0; i < sizeof(digits) / sizeof(digits[0]); ++i) {
            const std::string& digit = digits[i].digit;
            const std::string& number = digits[i].number;

            std::size_t idx = 0;
            while ((idx = line.find(digit, idx)) != std::string::npos) {
                line.replace(idx, digit.size(), number);
                idx += number.size();
            }
        }

        // Reuse P1 code
        std::size_t firstDigitPos = line.find_first_of("0123456789");
        std::size_t lastDigitPos = line.find_last_of("0123456789");
        if (firstDigitPos != std::string::npos && lastDigitPos != std::string::npos) {
            // Extract the first and last digits
            char firstDigit = line[firstDigitPos];
            char lastDigit = line[lastDigitPos];

            // Combine them to obtain a number
            int combinedNumber = (firstDigit - '0') * 10 + (lastDigit - '0');

            // Add it to the sum
            sum += combinedNumber;
        }
    }

    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
