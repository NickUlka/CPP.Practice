// Стрельба по мишени


#include <iostream>

int main()
{
    float x, y;
    int score = 0, quant =0;
    do {
        std::cout<<"Input coordinates of x and y of your shoot: \n";
        std::cin >> x >> y;
        quant++;
        if (x * x + y * y <= 9)
            score += 10;
        else if (x * x + y * y <= 100)
            score += 5;
    } 
    while (score<40);
    std::cout << "You shot "<< quant<< " times"<<std::endl;
    if (quant == 4)
        std::cout<<"Your are SNIPER!";
    else if (quant<=8)
        std::cout << "Your are SHOOTER!";
    else
        std::cout << "Your are NEW in shooting!";
}
