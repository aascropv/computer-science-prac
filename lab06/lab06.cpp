#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int array2d[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    int mode, op, len;
    cin >> mode;
    if (mode == 1) {
        for (int i = 0; i < 3; i++) {
            cin >> op;
            if (op == 1) {
                for (int j = 0; j < 3; j++)
                    for (int k = 0; k < 3; k++)
                        array2d[j][k] ++;
            }
            else if (op == 2) {
                for (int j = 0; j < 3; j++)
                    array2d[1][j] = 3;
            }
            else if (op == 3) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++)
                        array2d[j][k] %= 3;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << array2d[i][j];
            cout << endl;
        }
        return 0;
    }
    else if (mode == 2) {
        cin >> len;
        vector<vector<int>> v;
        int input;
        for (int i = 0; i < len; i++) {
            vector<int> row;
            for (int j = 0; j < len; j++) {
                cin >> input;
                row.push_back(input);
            }
            v.push_back(row);
        }
        for (int i = 0; i < len; i++) {
            cin >> op;
            if (op == 1) {
                vector<int> tmp(len, 0);
                tmp = v[0];
                for (int j = 0; j < len - 1; j++) v[j] = v[j+1];
                v[len-1] = tmp;
            }
            else if (op == 2) {
                vector<int> tmp(v[len-1].begin(), v[len-1].end());
                // cout << "test" << endl;
                for (int j = len - 1; j > 0; j--) v[j] = v[j-1];
                v[0] = tmp;
            }
            else if (op == 3) {
                int tmp;
                for (int j = 0; j < len; j++) {
                    tmp = v[j][0];
                    for (int k = 0; k < len - 1; k++) v[j][k] = v[j][k+1];
                    v[j][len-1] = tmp;
                }
            }
            else if (op == 4) {
                int tmp;
                for (int j = 0; j < len; j++) {
                    tmp = v[j][len-1];
                    // cout << tmp << endl;
                    for (int k = len - 1; k > 0; k--) v[j][k] = v[j][k-1];
                    v[j][0] = tmp;
                }
            }
        }
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < len; k++) cout << v[j][k];
            cout << endl;
        }
        return 0;
    }
}