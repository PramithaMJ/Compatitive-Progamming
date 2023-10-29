#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <map>

using namespace std;

map<char, int> cardValuesPlayer1;
map<char, int> cardValuesPlayer2;

template <typename T>
bool compareQueues(queue<T> q1, queue<T> q2)
{
    if (q1.size() != q2.size())
    {
        return false;
    }

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

        int value1 = cardValuesPlayer1[card1];
        int value2 = cardValuesPlayer2[card2];

        if (value1 > value2)
        {
            deck1.push(card1);
            deck1.push(card2);
        }
        else if (value2 > value1)
        {
            deck2.push(card2);
            deck2.push(card1);
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
    cardValuesPlayer1['2'] = 2;
    cardValuesPlayer1['3'] = 3;
    cardValuesPlayer1['4'] = 4;
    cardValuesPlayer1['5'] = 5;
    cardValuesPlayer1['6'] = 6;
    cardValuesPlayer1['7'] = 7;
    cardValuesPlayer1['8'] = 8;
    cardValuesPlayer1['9'] = 9;
    cardValuesPlayer1['T'] = 10; // Value for 'T' for player 1
    cardValuesPlayer1['J'] = 11;
    cardValuesPlayer1['Q'] = 12;
    cardValuesPlayer1['K'] = 13;
    cardValuesPlayer1['A'] = 14;

    cardValuesPlayer2['2'] = 2;
    cardValuesPlayer2['3'] = 3;
    cardValuesPlayer2['4'] = 4;
    cardValuesPlayer2['5'] = 5;
    cardValuesPlayer2['6'] = 6;
    cardValuesPlayer2['7'] = 7;
    cardValuesPlayer2['8'] = 8;
    cardValuesPlayer2['9'] = 9;
    cardValuesPlayer2['T'] = 7; // Value for 'T' for player 2
    cardValuesPlayer2['J'] = 11;
    cardValuesPlayer2['Q'] = 12;
    cardValuesPlayer2['K'] = 13;
    cardValuesPlayer2['A'] = 14;

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
