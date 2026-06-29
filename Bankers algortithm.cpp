#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resource types: ";
    cin >> m;

    int alloc[n][m], maxm[n][m], need[n][m];
    int avail[m];

    // Allocation Matrix
    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    // Maximum Matrix
    cout << "\nEnter Maximum Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maxm[i][j];

    // Available Resources
    cout << "\nEnter Available Resources:\n";
    for (int i = 0; i < m; i++)
        cin >> avail[i];

    // Calculate Need Matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    bool finish[n] = {false};
    int safeSeq[n];
    int work[m];

    // Copy available resources to work array
    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    int count = 0;

    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {

                bool possible = true;

                // Check if all needed resources are available
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    // Release allocated resources
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "\nSystem is NOT in a safe state.\n";
            return 0;
        }
    }

    cout << "\nSystem is in a SAFE state.\n";
    cout << "Safe Sequence: ";

    for (int i = 0; i < n; i++) {
        cout << "P" << safeSeq[i];
        if (i != n - 1)
            cout << " -> ";
    }

    cout << endl;

    return 0;
}







