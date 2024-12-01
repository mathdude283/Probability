#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>



int main() 
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    int successes;
    unsigned int trials;
    float x;
    float y;

    // Creates a text file to store output and adds general info to top
    std::ofstream OutputFile("data.txt");
    OutputFile << "Expected Area: 7/9 or 0.7777778 approximately\n";
    OutputFile << "General shape area is being found of inscribed in a 1x1 square\n";
    OutputFile << "/‾\\\n";
    OutputFile << "| |\n";
    OutputFile << "\\_/\n";
    OutputFile << "# of trials | Estimated Area\n";
    OutputFile.close();


    // Does estimation with number of trials set to all powers of ten from one to one billion
    for (int i = 0; i < 10; i++)
    {
        // Sets number of trial to 10^i
        trials = std::pow(10, i);
        successes = 0;

        // Runs a set of trials
        for (int j = 0; j < trials; j++)
        {
            // Generates a number from 0 to 1 for x and for y
            x = (double) std::rand() / RAND_MAX;
            y = (double) std::rand() / RAND_MAX;

            // Checks if the coordinate falls within the octagon, and increments successes if it does
            if (y < x + (double)2/3 && y < (double)5/3 - x && y > x - (double)2/3 && y > (double)1/3 - x)
            {
                successes++;
            }
        }

        // Adds data to file
        std::string data = std::to_string(trials);
        data.append(12 - data.length(),' ');
        data = data + "| " + std::to_string((double) successes/trials) + "\n";
        std::ofstream OutputFile("data.txt", std::ios_base::app);
        OutputFile << data;
        OutputFile.close();

    }
}