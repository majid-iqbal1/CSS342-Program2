#include <iostream>
using namespace std;

// Calculates the Catalan number for a given input.
// The function uses a recursive approach to calculate the Catalan number.
int calculateCatalan(int n)
{
    if (n < 0){
        return -1;
    } 
    
    vector<long long> catalan(n + 1, 0);
    catalan[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }

    return catalan[n];
}

int main(int argc, char* argv[])
{

    if (argc == 2) 
    {
        int catalan_number = std::stoi(argv[1]);

        if (catalan_number >= 1 && catalan_number <= 30) 
        {
            long long result = calculateCatalan(catalan_number);
            std::cout << "Catalan(" << catalan_number << ") = " << result << std::endl;
        } 
        else 
        {
            std::cout << "Input out of range. Please input a value between 1 and 30." << std::endl;
        }
    } else 
    {
        std::cout << "Usage: " << argv[0] << " <n>" << std::endl;
    }

    return 0;
}