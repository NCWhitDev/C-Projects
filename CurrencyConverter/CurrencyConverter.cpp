#include <iostream>

int main()
{
    int converter;
    int converted;
    double currency;
    double USD;
    double Yuan;
    double Ruble;
    std::cout << "Please enter currency origin to be converted: \n";
    std::cout << "1. America" << std::endl << "2. China" << std::endl << "3. Russia" << std::endl;
    std::cin >> converter;

    std::cout << "Please enter the amount you would like to transfer: ";
    std::cin >> currency;

    std::cout << "Please enter currency to be converted to: \n";
    std::cout << "1. America" << std::endl << "2. China" << std::endl << "3. Russia" << std::endl;
    std::cin >> converted;
    
    // As of 8/3/2025
    // American dollar (1.00) is Chinese Yuan (7.20)
    // American dollar (1.00) is Russian Ruble (79.89)
    // Chinese Yuan (1) is Russian Ruble (11.08)
    // Chinese Yuan (1) is American dollar (0.14)
    // Russian Ruble (1) is Chinese Yuan (0.09)
    // Russian Ruble (1) is American dollar (0.013)


    
    if(converter == 1 && converted == 2)
    {
        Yuan = 7.20;
        //American dollar to Chinese yuan
        currency = currency * Yuan;
    }
    else if(converter == 1 && converted == 3)
    {
        Ruble = 79.89;
        //American dollar to Russian Ruble
        currency = currency * Ruble;
    }
    else if(converter == 2 && converted == 1)
    {
        USD = 0.14;
        //Chinese yuan to American dollar
        currency = currency * USD;
    }
    else if(converter == 2 && converted == 3)
    {
        Ruble = 11.08;
        //Chinese yuan to Russian Ruble
        currency = currency * Ruble;
    }
    else if(converter == 3 && converted == 1)
    {
        USD = 0.013;
        //Russian Ruble to American dollar
        currency = currency * USD;
    }
    else if(converter == 3 && converted == 2)
    {
        Yuan = 0.09;
        //Russian Ruble to Chinese yuan
        currency = currency * Yuan;
    }
    else{
        std::cout << "Money is already converted.";
        return 0;
    }
    printf("%.2f", currency);
    return currency;
}
