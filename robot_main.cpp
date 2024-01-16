#include "robot.h"
#include <iostream>
#include <string>
using namespace std;

// Main function that takes 5 integer values for max number, robot coordinates, and treasure coordinates, 
int main(int argc, char* argv[]) 
{
    // If statement checks there is not more than 5 inputs.
    if (argc != 6) 
    {
        cout << "Invalid input! Please enter five integers!" << endl;
        return 1;
    } else 
    {
        // try and catch exceptions used to check and test the code for errors
        try
        {
            //Initializing and converting char/string into inetgers
            int maxDistance = stoi(argv[1]);
            int robotX = stoi(argv[2]);
            int robotY = stoi(argv[3]);
            int treasureX = stoi(argv[4]);
            int treasureY = stoi(argv[5]);

            // If statements check if the start and ends points are not same.
            if (robotX == treasureX && robotY == treasureY) 
            {
                cout << "The robot's starting point matches the treasure's endpoint." << endl;
                cout << endl;
                return 2;
            }
            
            // Creating a Robot object with given parameters
            cout << "Max Step in one direction: " << maxDistance << " | Robot (X, Y)-> (" << robotX << " , " << robotY << ") | Treasure (X,Y)-> (" << treasureX << " , " << treasureY << ") " << endl;
            Point startPoint(robotX, robotY);
            Point endPoint(treasureX, treasureY);
            Robot result(maxDistance, startPoint, endPoint);
            cout << result << endl;
        }
        catch(const std::exception& e)
        {
            cout << "Invalid input! Please enter five integers!" << endl;
            cout << endl;
            return 3;
        }
    }
    return 0;
}