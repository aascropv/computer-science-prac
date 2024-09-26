#include <iostream>
using namespace std;

int main() {
    char mode;
    int height, width;
    cout << "Enter the shape: ";
    while (cin >> mode) {
        int letter = 65;
        switch (mode) {
            case 'T':
            case 't':
                cout << "Enter the height: ";
                cin >> height;
                width = height * 2 - 1;
                for (int i = 0; i < height; i++) {
                    for (int j = 0; j < (width / 2 - i); j++) cout << "*";
                    for (int j = 0; j < (i * 2 + 1); j++) {
                        cout << (char)(letter++);
                        if (letter > 90) letter = 65;
                    }
                    for (int j = 0; j < (width / 2 - i); j++) cout << "*";
                    cout << endl;         
                }
                cout << "Enter the shape: ";
                break;
            case 'D':
            case 'd':
                cout << "Enter the height: ";
                cin >> height;
                width = height;
                for (int i = 0; i < (height / 2); i++) {
                    for (int j = 0; j < (width / 2 - i); j++) cout << "*";
                    for (int j = 0; j < (i * 2 + 1); j++) {
                        cout << (char)(letter++);
                        if (letter > 90) letter = 65;
                    }
                    for (int j = 0; j < (width / 2 - i); j++) cout << "*";
                    cout << endl;
                }
                for (int i = (height / 2); i >= 0; i--) {
                    for (int j = 0; j < (width / 2 - i); j++) cout << "*";
                    for (int j = 0; j < (i * 2 + 1); j++) {
                        cout << (char)(letter++);
                        if (letter > 90) letter = 65;
                    }
                    for (int j = 0; j < (width / 2 - i); j++) cout << "*";
                    cout << endl;
                }
                cout << "Enter the shape: ";
                break;
            case 'I':
            case 'i':
                cout << "Enter the height: ";
                cin >> height;
                width = height;
                for (int i = 0; i < height; i++) {
                    if (i % 2 == 0) {
                        for (int j = 0; j < width; j++) {
                            if (j % 2 == 0) {
                                cout << (char)(letter++);
                                if (letter > 90) letter = 65;
                            }
                            else
                                cout << "*";
                        }
                    }
                    else {
                        for (int j = 0; j < width; j++) {
                            if (j % 2 == 0) {
                                cout << "*";
                            }
                            else {
                                cout << (char)(letter++);
                                if (letter > 90) letter = 65;
                            }
                        }
                    }
                    cout << endl;
                }
                cout << "Enter the shape: ";
                break;
            case 'E':
            case 'e':
                return 0;
            default:
                cout << "Reenter the shape: ";
                break;
        }
    }
    return 0;
}