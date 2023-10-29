#include <iostream>
#include <vector>
#include <map>

std::map<char, int> dic;

void initializeDic()
{
    dic['1'] = 1;
    dic['2'] = 2;
    dic['3'] = 3;
    dic['4'] = 4;
    dic['5'] = 5;
    dic['6'] = 6;
    dic['7'] = 7;
    dic['8'] = 8;
    dic['9'] = 9;
    dic['T'] = 10;
    dic['J'] = 11;
    dic['Q'] = 12;
    dic['K'] = 13;
    dic['A'] = 14;
}

void determine_winner(std::vector<char> &player1, std::vector<char> &player2)
{
    while (!player1.empty() && !player2.empty())
    {
        if (dic[player1[0]] > dic[player2[0]])
        {
            player1.push_back(player2[0]);
            player1.push_back(player1[0]);
            player1.erase(player1.begin());
            player2.erase(player2.begin());
        } else if (dic[player1[0]] < dic[player2[0]])
        {
            player2.push_back(player1[0]);
            player2.push_back(player2[0]);
            player1.erase(player1.begin());
            player2.erase(player2.begin());
        }
        else
        {
            if (player1 == player2)
            {
                std::cout << "draw" << std::endl;
                return;
            }
            player1.push_back(player2[0]);
            player2.push_back(player1[0]);
            player1.erase(player1.begin());
            player2.erase(player2.begin());
        }
    }

    if (player1.empty())
    {
        std::cout << "player 2" << std::endl;
    }
    else
    {
        std::cout << "player 1" << std::endl;
    }
}

int main()
{
    initializeDic();

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string ps1, ps2;
        std::cin >> ps1 >> ps2;

        std::vector<char> player1(ps1.begin(), ps1.end());
        std::vector<char> player2(ps2.begin(), ps2.end());

        determine_winner(player1, player2);
    }

    return 0;
}
