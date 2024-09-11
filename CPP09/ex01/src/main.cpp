#include "RPN.hpp"


bool isValidChar(char c)
{
    if (isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/'|| c == ' ')
        return true;
    return false;
}

bool check_arguments(int ac, char **av)
{
    if (ac != ARGUMENTS)
    {
        std::cerr << "Usage: " << av[0] << " <filename>" << std::endl;
        return false;
    }
    std::string expression = av[1];
    for(size_t i = 0; i < expression.length(); i++)
    {
        if(!isValidChar(expression[i]))
            return false;
    }
    return true;
}

int RPN(const std::string& expression) 
{
    std::stack<int, std::list<int> > s;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) 
    {
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1 && isdigit(token[1]))) 
        {
            s.push(atoi(token.c_str()));
        } 
        else 
        {
            if (s.size() < 2) 
            {
                std::cerr << "Error: Not enough operands for operator " << token << std::endl;
                return 0;
            }
            int right = s.top(); s.pop();
            int left = s.top(); s.pop();
            
            switch (token[0]) 
            {
                case '+': s.push(left + right); break;
                case '-': s.push(left - right); break;
                case '*': s.push(left * right); break;
                case '/': 
                    if (right == 0) 
                    {
                        std::cerr << "Error: Division by zero" << std::endl;
                        return 0;
                    }
                    s.push(left / right); 
                    break;
                default: 
                    std::cerr << "Unknown operator: " << token << std::endl; 
                    return 0;
            }
        }
    }

    if (s.size() != 1) 
    {
        std::cerr << "Error: The RPN expression is invalid or incomplete." << std::endl;
        return 0;
    }
    std::cout << s.top() << std::endl;
    return 1;
}

bool error_msg(const std::string &line)
{
    std::cerr << RED_COLOR << "Error: " << line << RESET_COLOR << std::endl;
    return false;
}

int main(int ac, char **av)
{
    if(!check_arguments(ac, av))
        return(error_msg("check_arguments"));
    RPN(av[1]);
    return 1;
    


}