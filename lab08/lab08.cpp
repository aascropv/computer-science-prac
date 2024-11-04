#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
    vector<string> str;
    string input;
    
    while (cin >> input) {  //cin >> input
        str.push_back(input);   //把input push進vector
        if (cin.get() == '\n') break;   //遇到換行字元終止迴圈
    }
    for (int i = 0; i < str.size(); i++) {  //大小寫字母切換為0跟1
        for (int j = 0; j < str[i].size(); j++) {
            if (str[i][j] >= 'a' && str[i][j] <= 'z') {
                str[i][j] = '0';
            } else if (str[i][j] >= 'A' && str[i][j] <= 'Z') {
                str[i][j] = '1';
            }
        }
    }
    for (int i = 0; i < str.size(); i++) {  //連續重複三次的字元erase掉
        int num = 0;
        for (int j = 1; j < str[i].size(); j++) {
            // cout << str[i][j-1] << " " << str[i][j] << endl;
            if (str[i][j] == str[i][j-1]) {
                num++;
                if (num >= 2) {
                    // cout << "erase" << str[i][j] << endl;
                    str[i].erase(str[i].begin() + j - 1);
                    j--;    //因為erase掉了，所以j要往前一格
                }
            }
            else {
                num = 0;
            }
        }
    }
    for (int i = 0; i < str.size(); i++) {
        if (i == str.size() - 1) {
            cout << str[i];
        }
        else {
            cout << str[i] << " ";
        }
    }
    cout << endl;
    int dec[str.size()] = {0};
    int sum = 0;
    for (int i = 0; i < str.size(); i++) {  //01字串轉成10進位數字
        int exp = 0;
        for (int j = str[i].size() - 1; j >= 1; j--) {
            dec[i] +=  ((int)str[i][j] - 48) * pow(2, exp); //char 的 "0" 轉成 int 為 48
            exp++;
        }
        if (str[i][0] == '1') dec[i] = -dec[i]; //判斷正負
        if (i == str.size() - 1) cout << dec[i];
        else cout << dec[i] << " ";
        sum += dec[i];
    }
    cout << endl;
    cout << sum << endl;
    return 0;
}