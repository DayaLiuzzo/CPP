
#include <limits>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string replace_str(std::string content, const std::string s1, const std::string s2)
{
    size_t pos = 0;
    size_t foundPos;

    std::string updatedContent;
    while ((foundPos = content.find(s1, pos)) != std::string::npos)
    {
        updatedContent.append(content, pos, foundPos - pos);
        updatedContent.append(s2);
        pos = foundPos + s1.length();
    }
    updatedContent.append(content, pos, std::string::npos);
    return(updatedContent);

}

int replace_in_file(const std::string filename, const std::string s1, const std::string s2)
{
    std::ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return (1);
    }
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();
    inputFile.close();
    std::string updatedContent = replace_str(content, s1, s2);
    std::string newFilename = filename +".replace";
    std::ofstream outputFile(newFilename);
    if(!outputFile.is_open())
    {
        std::cerr << "Couldn't open the file: " << newFilename << std::endl;
        return (1);
    }
    outputFile << updatedContent;
    outputFile.close();
    return(0);
}

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cout << "Wrong argument count" << std::endl;
        return(1);
    }
    if(replace_in_file(av[1], av[2], av[3])== 1)
        return(1);
    return(0);
}

