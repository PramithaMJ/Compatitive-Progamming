#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>

using namespace std;

map<char, int> cardValues;
template <typename T>

bool compareQueues(queue<T> q1, queue<T> q2)
{
    // if (q1.size() != q2.size())
    // {
    //     return false;
    // }

    while (!q1.empty())
    {
        if (q1.front() != q2.front())
        {
            return false;
        }
        q1.pop();
        q2.pop();
    }

    return true;
}

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
    const int MAX_TURNS = 1000000;

    while (!deck1.empty() && !deck2.empty() && turns < MAX_TURNS)
    {
        char card1 = deck1.front();
        deck1.pop();

        char card2 = deck2.front();
        deck2.pop();

        int value1 = cardValues[card1];
        int value2 = cardValues[card2];

        if (value1 > value2)
        {
            deck1.push(card1);
           // deck1.push(card2);
        }
        else if (value2 > value1)
        {
            deck2.push(card2);
           // deck2.push(card1);
        }
        else
        {
            deck1.push(card1);
            deck2.push(card2);
        }

        turns++;
    }

    if (turns >= MAX_TURNS)
    {
        return "draw";
    }
    else if ((deck1.empty() && deck2.empty()) || compareQueues(deck1, deck2))
    {
        return "draw";
    }
    else if (deck1.empty())
    {
        return "player 1";
    }
    else
    {
        return "player 2";
    }
}

int main()
{
    cardValues['2'] = 2;
    cardValues['3'] = 3;
    cardValues['4'] = 4;
    cardValues['5'] = 5;
    cardValues['6'] = 6;
    cardValues['7'] = 7;
    cardValues['8'] = 8;
    cardValues['9'] = 9;
    cardValues['T'] = 10;
    cardValues['J'] = 11;
    cardValues['Q'] = 12;
    cardValues['K'] = 13;
    cardValues['A'] = 14;

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        vector<char> player1, player2;

        string cards1, cards2;
        getline(cin, cards1);
        getline(cin, cards2);

        stringstream ss1(cards1);
        stringstream ss2(cards2);

        char card;
        while (ss1 >> card)
        {
            player1.push_back(card);
        }

        while (ss2 >> card)
        {
            player2.push_back(card);
        }

        string result = determineWinner(player1, player2);
        cout << result << endl;
    }

    return 0;
}
