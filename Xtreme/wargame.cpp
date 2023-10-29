#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<char, int> dic = {{'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};

void determine_winner(vector<string> &player1, vector<string> &player2)
{
    if (dic[player1[0][0]] > dic[player2[0][0]])
    {
        player1.erase(player1.begin());
        player1.push_back(player2[0]);
        player2.erase(player2.begin());
    }
    else if (dic[player1[0][0]] < dic[player2[0][0]])
    {
        player2.erase(player2.begin());
        player2.push_back(player1[0]);
        player1.erase(player1.begin());
    }
    else
    {
        if (player1 == player2)
        {
            cout << "draw" << endl;
            return;
        }
        player1.push_back(player2[0]);
        player2.push_back(player1[0]);
        player1.erase(player1.begin());
        player2.erase(player2.begin());
    }
    if (player1.empty())
    {
        cout << "player 2" << endl;
        return;
    }
    if (player2.empty())
    {
        cout << "player 1" << endl;
        return;
    }
    determine_winner(player1, player2);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string ps1, ps2;
        getline(cin, ps1);
        getline(cin, ps2);
        vector<string> player1;
        vector<string> player2;
        size_t pos1 = 0;
        size_t pos2 = 0;
        while ((pos1 = ps1.find(' ')) != string::npos)
        {
            string token1 = ps1.substr(0, pos1);
            player1.push_back(token1);
            ps1.erase(0, pos1 + 1);
        }
        player1.push_back(ps1);

        while ((pos2 = ps2.find(' ')) != string::npos)
        {
            string token2 = ps2.substr(0, pos2);
            player2.push_back(token2);
            ps2.erase(0, pos2 + 1);
        }
        player2.push_back(ps2);
        determine_winner(player1, player2);
    }
    return 0;
}
