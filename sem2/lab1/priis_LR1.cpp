#include "segtree.hpp"
#include <iostream>
using namespace std;

int main()
{
    vector<int> arr;
    int c, n, ans = -1, m, l, r;

    while (true) {
        cout << "Enter the size of array: ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter a natural number.\n";
        }
        else break;
    }

    cout << "Enter the elements of array (natural numbers): ";
    for (int i = 0; i < n; ++i) {
        while (true) {
            cin >> c;
            if (cin.fail() || c < 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a natural number.\n";
            }
            else break;
        }
        arr.push_back(c);
    }

    SegmentTree tree(arr);

    cout << "The tree is created.\n";
    do {
        cout << "Choose operation:\n"
            << "1) Find number count on segment.\n"
            << "2) Change numbers on segment.\n"
            << "0) Close the program.\n"
            << "Your answer: ";

        while (true) {
            cin >> ans;
            if (cin.fail() || (ans != 0 && ans != 1 && ans != 2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a correct answer (0, 1, or 2).\n";
            }
            else break;
        }

        switch (ans) {
        case 0:
            return 0;
        case 1:
            cout << "Enter left and right border and number: ";
            while (true) {
                cin >> l >> r >> m;
                if (cin.fail() || l < 0 || r >= n || l > r) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter correct numbers.\n";
                }
                else break;
            }
            tree.rebuildTree(m);
            cout << "Result: " << tree.findCount(l, r) << endl;
            break;
        case 2:
            cout << "Enter left and right border and number: ";
            while (true) {
                cin >> l >> r >> m;
                if (cin.fail() || l < 0 || r >= n || l > r) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Enter correct numbers.\n";
                }
                else break;
            }
            for (int i = l; i <= r; ++i) arr[i] = m;
            tree.rebuildTree(arr);
            cout << "Result: ";
            for (int i = 0; i < n; ++i) cout << arr[i] << " ";
            cout << endl;
            break;
        }
    } while (ans != 0);

    return 0;
}

