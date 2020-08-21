#include <iostream>
#include <cmath>
#include <ctime>
void PrintIntroduction()
{
    std::cout << R"(____    __    ____  _______  __        ______   ______   .___  ___.  _______ 
\   \  /  \  /   / |   ____||  |      /      | /  __  \  |   \/   | |   ____|
 \   \/    \/   /  |  |__   |  |     |  ,----'|  |  |  | |  \  /  | |  |__   
  \            /   |   __|  |  |     |  |     |  |  |  | |  |\/|  | |   __|  
   \    /\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____ 
    \__/  \__/     |_______||_______| \______| \______/  |__|  |__| |_______|
                                                                             )" << '\n'<< std::endl;
    

    std::cout << "You are in a game show that requires you to unlock briefcases." << std::endl;
    std::cout << "You need to enter the correct code to unlock a briefcase" << std::endl;
    std::cout << "The more you unlock, the more money you win!\n" << std::endl;
}
bool PlayGame(int Difficulty)
{
                        /* need money implementation */
    int CodeA = rand()%Difficulty + Difficulty;
    int CodeB = rand()%Difficulty + Difficulty;
    int CodeC = rand()%Difficulty + Difficulty;
    int Sum = CodeA + CodeB + CodeC;
    int Product = CodeA * CodeB * CodeC;

    // Printing the Problem 
    std::cout << "\n Briefcase #" << Difficulty << std::endl;
    std::cout << "There are 3 numbers in the code" << std::endl;
    std::cout << "The codes add up to: " << Sum << std::endl;
    std::cout << "The codes multiply to give: " << Product << std::endl;

    // Player's answers
    int GuessA, GuessB, GuessC, GuessSum, GuessProduct;
    std::cin >> GuessA >> GuessB >> GuessC;

    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    // Checks if guess is correct
    if (GuessSum == Sum && GuessProduct == Product)
    {
        std::cout << "\nGood Job! Keep going!" << std::endl; //Winning statement
        return true;
    }
    else
    {                   
        std::cout << "\nAww, that was wrong. " << std::endl;
        return false;
    } 
        
}

int main()
{ 
    srand(time(NULL));
    int LevelDifficulty = 1;
    int MaxDifficulty = 7;
    int Money = 0;
    PrintIntroduction();    // Intro screen

    while (LevelDifficulty <= MaxDifficulty) // Loops till all Briefcases are open or user leaves
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();   // Clears errors
        std::cin.ignore();  // Discards buffer

        if (bLevelComplete)
        {
            Money+= 100 * LevelDifficulty;
            ++LevelDifficulty;
        }
        
    }
        
    std::cout << "\nCongratulations! You won all the money!" << std::endl; //Winning statement
    
    
    
    /*  Some code for a later functionality 
     *
     *  else
     *      std::cout << "\nAww, that was wrong. At least you get to walk away with " << std::endl;
     * 
     */ 
   

    return 0;
}