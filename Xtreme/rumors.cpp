#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string, vector<string> > sources;
map<string, bool> visited;

void addSource(string p1, string p2)
{
    sources[p1].push_back(p2);
}

void dfs(string person, string source, set<string> &possibleSources)
{
    visited[person] = true;
    for (const string &nextPerson : sources[person])
    {
        if (nextPerson != source)
        {
            if (!visited[nextPerson])
            {
                dfs(nextPerson, source, possibleSources);
            }
        }
    }
    possibleSources.insert(person);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string p1, arrow, p2;
        cin >> p1 >> arrow >> p2;

        if (arrow == "->")
        {
            addSource(p1, p2);
        }
        else if (arrow == "??")
        {
            addSource(p1, p2);
            addSource(p2, p1);
        }
    }

    set<string> possibleSources;

    for (const auto &entry : sources)
    {
        const string &person = entry.first;
        visited.clear();
        dfs(person, person, possibleSources);
    }

    for (const string &source : possibleSources)
    {
        cout << source << endl;
    }

    return 0;
}
