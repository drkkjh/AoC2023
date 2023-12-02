#include <iostream>
#include <sstream>

auto solve()
{
    std::string line;
    auto answer = std::make_pair(0, 0);

    while (std::getline(std::cin, line))
    {
        std::istringstream is(line);
        std::string game, color;
        auto gameNumber = 0, n = 0, red = 0, green = 0, blue = 0;
        auto colon = ':';
        bool possibleRed = true;
        bool possibleGreen = true;
        bool possibleBlue = true;

        is >> game >> gameNumber >> colon;

        while (is >> n >> color)    
        {
            auto last = color[color.length() - 1];
            if (last == ',' || last == ';')
                color.pop_back();

            if (color == "red")
            {
                if (n > 12) { 
                    possibleRed = false;
                }
                red = std::max(red, n);
            }
            else if (color == "green")
            {
                if (n > 13) {
                    possibleGreen = false;
                }
                green = std::max(green, n);
            }
            else if (color == "blue")
            {
                if (n > 14) {
                    possibleBlue = false;
                }
                blue = std::max(blue, n);
            }
        }

        if (possibleRed && possibleGreen && possibleBlue) {
            answer.first += gameNumber;
        }

        answer.second += red * green * blue;
    }

    return answer;
}


int main()
{
    auto answer = solve();
    std::cout << "Part 1 answer: " << answer.first << std::endl;
    std::cout << "Part 2 answer: " << answer.second << std::endl;

    return 0;
}
