#include <iostream>
#include <string>
using namespace std;

string encrypt(string input)
{
    string shiftedString = "";
    for (char c : input)
    {
        if (c != ' ')
        {
            if (c >= 'a' && c <= 'z')
            {
                c = (c - 'a' + 7) % 26 + 'a';
            }
            else if (c >= 'A' && c <= 'Z')
            {
                c = (c - 'A' + 7) % 26 + 'A';
            }
        }
        shiftedString += c;
    }
    return shiftedString;
}

string decrypt(string input)
{
    string shiftedString = "";
    for (char c : input)
    {
        if (c != ' ')
        {
            if (c >= 'a' && c <= 'z')
            {
                c = (c - 'a' - 7 + 26) % 26 + 'a';
            }
            else if (c >= 'A' && c <= 'Z')
            {
                c = (c - 'A' - 7 + 26) % 26 + 'A';
            }
        }
        shiftedString += c;
    }
    return shiftedString;
}

int main()
{
    // cout << encrypt("we accept the ieeextreme challenge") << endl;
    // cout << decrypt("qbspbz jhlzhy olsk aol vmmpjl vm wvuapmle theptbz wypvy av iljvtpun kpjahavy") << endl;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int shift;
        string message;
        cin >> shift >> ws;
        getline(cin, message);

        if (message.find("the") != string::npos)
        {
            cout << encrypt(message) << endl;
        }
        else
        {
            cout << decrypt(message) << endl;
        }
    }


    return 0;
}