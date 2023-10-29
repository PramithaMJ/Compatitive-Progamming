#include <iostream>
#include <string>
using namespace std;

// Function to find the requested recipe
char findRecipe(const string &message)
{
    for (char letter : message)
    {
        if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F' || letter == 'G')
        {
            return letter;
        }
    }
    return ' '; // If no valid recipe letter is found
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // Clear the newline character from the input buffer

    for (int i = 0; i < n; i++)
    {
        string message;
        getline(cin, message); // Read the secret message

        char recipe = findRecipe(message);
        cout << recipe << endl;
    }

    return 0;
}
