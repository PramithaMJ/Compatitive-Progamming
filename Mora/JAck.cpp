#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Function to calculate the probability of Jack building the boat
double calculateProbability(int m, const vector<string>& boxes, const string& target) {
            int countItems = 0; // Changed variable name to countItems
    int n = boxes.size();
    int waysToGetTarget = 0;
    int totalWays = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string combined = boxes[i] + boxes[j];
            
            for (char item : target) {
                countItems += count(combined.begin(), combined.end(), item);
            }
            
            if (countItems >= m) {
                waysToGetTarget++;
            }
            
            totalWays++;
        }
    }
    
    return double(waysToGetTarget) / double(totalWays);
}

int main() {
    int n, m;
    cin >> n;
    vector<string> boxes(n);
    
    for (int i = 0; i < n; i++) {
        cin >> boxes[i];
    }
    
    cin >> m;
    
    string target;
    cin >> target;
    
    double probability = calculateProbability(m, boxes, target);
    
    cout << fixed;
    cout.precision(2);
    cout << probability << endl;
    
    return 0;
}
