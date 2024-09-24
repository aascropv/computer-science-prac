#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int operators, operand1, operand2, result;
    string output_str[100], result_str;
    int i = 0;
    while(cin >> operators) {
        if (operators == 0) {   // operator is done
            output_str[i++] = "Done";
            break;
        }
        else if (operators < 0 || operators > 4)  { // operator is not valid
            output_str[i++] = "I don't know how!";
            continue;
        }
        cin >> operand1;
        cin >> operand2;
        if (operators == 1) result = operand1 + operand2;   // operator is +-*/
        else if (operators == 2) result = operand1 - operand2;
        else if (operators == 3) result = operand1 * operand2;
        else if (operators == 4) {
            if (operand2 == 0) {    //operand2 is zero
                output_str[i++] = "Divide by zero, be careful!";
                continue;
            }
            result = operand1 / operand2;
        }
        if (result < 0 || result >= 1000) { //result is out of range
            output_str[i++] ="Boom!";
            break;
        }
        else {  //result is in range
            result_str = to_string(result);
            output_str[i++] = "Result = " + result_str;
        }
    }
    for (int j = 0; j < i; j++) cout << output_str[j] << endl;  // print the output
    return 0;
}