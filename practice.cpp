#include <iostream>
#include <vector>
using namespace std;

int main() {
    int capacity = 3;
    vector<int> cache;
    vector<int> pages = {1, 2, 3, 2, 4, 1};

    int hits = 0, misses = 0;

    cout << "Access Sequence: ";
    for (int p : pages) cout << p << " ";
    cout << "\n\n";

    for (int page : pages) {
        cout << "Accessing page: " << page << " => ";

        // Check if page is in cache (hit)
        bool hit = false;
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i] == page) {
                hit = true;
                // Move this page to the front (most recently used)
                cache.erase(cache.begin() + i);
                cache.insert(cache.begin(), page);
                break;
            }
        }

        if (hit) {
            hits++;
            cout << "HIT";
        } else {
            misses++;
            cout << "MISS";
            if (cache.size() == capacity) {
                cout << " (Evicting: " << cache.back() << ")";
                cache.pop_back();
            }
            cache.insert(cache.begin(), page);
        }

        // Print current cache state
        cout << " | Cache: ";
        for (int val : cache) cout << val << " ";
        cout << endl;
    }

    cout << "\nFinal Cache State: ";
    for (int val : cache) cout << val << " ";
    cout << "\nHits: " << hits << ", Misses: " << misses << endl;
    cout << "Hit Ratio: " << (double)hits / (hits + misses) << endl;

    return 0;
}
