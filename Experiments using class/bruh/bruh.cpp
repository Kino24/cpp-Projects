#include <iostream>
#include <fstream>

int main()
{
    {
        std::ofstream file("data");
        file << "text1 text2" << std::endl;
        file << "text3 text4" << std::endl;
    }
    std::ifstream file("data");
    while (file.good())
    {
        std::string text1;
        std::string text2;
        file >> text1 >> text2;
        if (file.good())
            std::cout << text1 << "|" << text2 << std::endl;
    }
    return 0;
}