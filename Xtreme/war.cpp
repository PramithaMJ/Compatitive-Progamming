#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

unordered_map<char, int> dic = {{'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};

void determine_winner(vector<string> &player1, vector<string> &player2)
{
    queue<string> player1_queue(player1.begin(), player1.end());
    queue<string> player2_queue(player2.begin(), player2.end());

    while (!player1_queue.empty() && !player2_queue.empty())
    {
        if (dic[player1_queue.front()[0]] > dic[player2_queue.front()[0]])
        {
            player1_queue.push(player2_queue.front());
            player2_queue.pop();
        }
        else if (dic[player1_queue.front()[0]] < dic[player2_queue.front()[0]])
        {
            player2_queue.push(player1_queue.front());
            player1_queue.pop();
        }
        else
        {
            size_t min_size = min(player1_queue.size(), player2_queue.size());
            vector<string> temp1, temp2;
            for (size_t i = 0; i < min_size; i++)
            {
                temp1.push_back(player1_queue.front());
                temp2.push_back(player2_queue.front());
                player1_queue.pop();
                player2_queue.pop();
            }

            if (temp1 == temp2)
            {
                cout << "draw" << endl;
                return;
            }

            for (const string &card : temp1)
            {
                player1_queue.push(card);
            }
            for (const string &card : temp2)
            {
                player2_queue.push(card);
            }
        }
    }

    if (player1_queue.empty())
    {
        cout << "player 2" << endl;
    }
    else if (player2_queue.empty())
    {
        cout << "player 1" << endl;
    }
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
