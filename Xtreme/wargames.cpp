#include <iostream>
#include <vector>
#include <queue>

using namespace std;

string determineWinner(vector<char> &player1, vector<char> &player2)
{
    queue<char> deck1, deck2;

    for (char card : player1)
    {
        deck1.push(card);
    }

    for (char card : player2)
    {
        deck2.push(card);
    }

    int turns = 0;

    while (!deck1.empty() && !deck2.empty() && turns < 1000000)
    {
        char card1 = deck1.front();
        deck1.pop();

        char card2 = deck2.front();
        deck2.pop();

        if (card1 > card2)
        {
            deck1.push(card2);
          //  deck1.push(card1);
        }
        else if (card2 > card1)
        {
            deck2.push(card1);
          //  deck2.push(card2);
        }
        else
        {
            deck1.push(card1);
            deck2.push(card2);
        }

        turns++;
    }


    if (deck1.empty() && deck2.empty()  )
    {
        return "draw";
    }
    else if (deck1.empty())
    {
        return "player 2";
    }
    else
    {
        return "player 1";
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<char> player1, player2;

        string cards1, cards2;
        cin >> cards1 >> cards2;

        for (char card : cards1)
        {
            player1.push_back(card);

        }

        for (char card : cards2)
        {
            player2.push_back(card);
        }

        string result = determineWinner(player1, player2);
        cout << result << endl;
    }

    return 0;
}