#include <iostream>
#include <vector>
using namespace std;

void knapsack(int num, vector<int>& val, vector<int>& weight, int capacity) {
    vector<vector<int>> v(num + 1, vector<int>(capacity + 1, 0));
    vector<vector<int>> keep(num + 1, vector<int>(capacity + 1, 0));

    // Building the DP table (v) and the keep table
    for (int i = 1; i <= num; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                if ((val[i - 1] + v[i - 1][w - weight[i - 1]]) > v[i - 1][w]) {
                    v[i][w] = val[i - 1] + v[i - 1][w - weight[i - 1]];
                    keep[i][w] = 1; // Item is included
                } else {
                    v[i][w] = v[i - 1][w];
                    keep[i][w] = 0; // Item is not included
                }
            } else {
                v[i][w] = v[i - 1][w];
                keep[i][w] = 0; // Item is not included
            }
        }
    }

    // Print the DP table (v matrix)
    cout << "\nDynamic Programming Table (v):\n";
    for (int i = 0; i <= num; i++) {
        for (int w = 0; w <= capacity; w++) {
            cout << v[i][w] << " ";
        }
        cout << endl;
    }

    // Print the keep table (solution matrix)
    cout << "\nKeep Table (solution matrix):\n";
    for (int i = 0; i <= num; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (keep[i][w] == 1)
                cout << "R ";  // Item is included
            else
                cout << "X ";  // Item is not included
        }
        cout << endl;
    }

    // The total profit (max value that can be obtained)
    cout << "\nTotal Profit (Maximum value): " << v[num][capacity] << endl;

    // Reconstruct the solution (which items are included)
    cout << "\nItems included in the knapsack:\n";
    int i = num, w = capacity;
    while (i > 0 && w > 0) {
        if (keep[i][w] == 1) {
            cout << "Item " << i << " (Value: " << val[i - 1] << ", Weight: " << weight[i - 1] << ")" << endl;
            w = w - weight[i - 1]; // Reduce weight
        }
        i--;
    }
}

int main() {
    int num, capacity;
    cout << "Enter number of items: ";
    cin >> num;
    vector<int> val(num), weight(num);

    cout << "Enter values of items: ";
    for (int i = 0; i < num; i++) {
        cin >> val[i];
    }

    cout << "Enter weights of items: ";
    for (int i = 0; i < num; i++) {
        cin >> weight[i];
    }

    cout << "Enter capacity or max-weight: ";
    cin >> capacity;

    // Call the knapsack function
    knapsack(num, val, weight, capacity);

    return 0;
}
