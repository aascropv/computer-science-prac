#include <iostream>
using namespace std;

void print_exit()
{
    cout << "Done" << endl;
}

void print_invalid()
{
    cout << "I don't know how!" << endl;
}

int addition(int a, int b)// +
{
    return a + b;
}

int subtraction(int a, int b)// -
{
    return a - b;
}

int multiplication(int a, int b)// *
{
    return a * b;
}

int division(int a, int b)// /
{
    return a / b;
}

bool is_prime(int num) // if num is prime number return true, else retrun false
{
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void print_wave(int n) //prime magic
{
    bool is_prime = true;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            is_prime = false;
            break;
        }
    }
    if (is_prime) {
        cout << "Result = " << n << " (Prime magic!)" << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++)
                cout << "P";
            cout << endl;
        }
        for (int i = n - 1; i >= 1; i--) {
            for (int j = 1; j <= i; j++)
                cout << "P";
            cout << endl;
        }
    }
    else {
        cout << "Result = " << n << endl;
    }

}

int main() 
{
    int choice;
    int num1 = 0, num2 = 0, result = 0;
    while (cin >> choice) 
    {
        
        if (choice == 0) //function "print_exit"
        {
            print_exit();
            break;
        }
        if (choice < 1 || choice > 4) //if choice != 0,1,2,3,4 //function "print_invalid"
        {
            print_invalid();
            continue;
        }
        
        cin >> num1 >> num2;
        if (choice == 1) 
        {
            result = addition(num1, num2);//addition //example
        } 
        else if (choice == 2) 
        {
            //subtraction
            result = subtraction(num1, num2);
        }
        else if (choice == 3) 
        {
            //multiplication
            result = multiplication(num1, num2);
        }
        else if (choice == 4)
        { 
            //devision
            if (num2 == 0) {
                cout << "Divide by zero, be careful!" << endl;
                continue;
            }
            result = division(num1, num2);
        }

        if(result < 0 || result >= 1000) // <0 or >1000, Boom
        {
            cout << "Boom!" << endl;
            break;
        }
        else //print Result, use "is_prime" function to check result is prime number or not, if result is prime number, "print_wave"
        {
            print_wave(result);
        }
    }
    return 0;
}