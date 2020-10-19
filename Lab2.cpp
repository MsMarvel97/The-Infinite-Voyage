// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

float height, weight;

int main()
{
    float bmi;

    cout << "Enter your height in centimeters: ";
    cin >> height;

    cout << "\nEnter your weight: ";
    cin >> weight;

    bmi = weight / ((height / 100) * (height / 100));

    cout << "\nYour BMI is " << bmi << ", ";

    if (bmi <= 18.5)
    {
        cout << "You are Underweight.";

    }

    else if ((bmi > 18.5) && (bmi <= 24.9))
    {
        cout << "You have normal weight.";
    }

    else if ((bmi > 24.9) && (bmi <= 29.9))
    {
        cout << "You are overweight.";
    }

    else
    {
        cout << "You are obese.";
    }


    



    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
