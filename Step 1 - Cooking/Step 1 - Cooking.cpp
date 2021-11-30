#include <string>
#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

using namespace std;
using namespace this_thread;
using namespace chrono;

void SpaceLine();
void PrepareCooking();
void Title();
void FinishCooking();
void CookDinner();
void Color(int typeColor);
void CookSteak();
void CookOmelette();
void CookMushrooms();
void TimeDelay();

int main()
{
    CookDinner();
}

void SpaceLine()
{
    cout << "---------------------------------------------------------------------------\n";
}

void Title()
{
    Color(6);
    cout << "How to cook dinner" << endl;
    Color(7);

    SpaceLine();
}

void PrepareCooking()
{
    cout << "To start you need to wash your hands. Once this is done the fun beggins." << endl;
    cout << "1st Turn heat";
    
    Color(10);
    cout << " on";
    Color(7);

    cout << ".\n2nd Heat the pan." << endl;
    cout << "3rd Put oil in." << endl;

    SpaceLine();
}

void CookSteak()
{
    string GradeSteak = "";
    bool Answer = false;

    cout << "Put beef in the pan and ask how cook the want the beef." << endl;
    
    while (Answer == false)
    {
        cout << "(";
        Color(4);
        cout << "Well done";
        Color(7);
        cout << "/";
        Color(6);
        cout << "Medium";
        Color(7);
        cout << "/";
        Color(1);
        cout << "Rare";
        Color(7);
        cout << ")\n";

        getline(cin, GradeSteak);

        if (GradeSteak == "Well done")
        {
            cout << "Cook the steak for 10 minutes.\n";
            Answer = true;
        }
        else if (GradeSteak == "Medium")
        {
            cout << "Cook the steak for 7 minutes.\n";
            Answer = true;
        }
        else if (GradeSteak == "Rare")
        {
            cout << "Cook the steak for 5 minutes.\n";
            Answer = true;
        }
        else
        {
            cout << "Make sure you type the grade correctly.\n";
            Answer = false;

            SpaceLine();
        }
    }

    SpaceLine();

}

void CookOmelette()
{
    int numEggs;

    cout << "How many eggs would you like in your omelette ?" << endl;
    cin >> numEggs;
    cout << "Put " << numEggs << " eggs in the pan" << endl;
    cout << "Wait 4 minutes" << endl;

    SpaceLine();
}

void CookMushrooms()
{
    cout << "Put mushrooms in the pan." << endl;
    cout << "Wait 5 minutes." << endl;

    SpaceLine();
}

void FinishCooking()
{
    cout << "Serve food." << endl;
    cout << "Last and very important, turn heat";
    Color(4);
    cout << " off";
    Color(7);
    cout << ".\n";

    SpaceLine();
}

void CookDinner()
{
    string WhatsForDinner;
    bool TypeCorrectly = false;

    Title();

    TimeDelay();

    PrepareCooking();

    TimeDelay();

    cout << "Now you need to decide what you would like to cook for dinner." << endl;

    while (TypeCorrectly == false)
    {
        TimeDelay();
        Color(8);
        cout << "(Steak/Omelette/Mushrooms) " << endl;
        Color(7);

        getline(cin, WhatsForDinner);

        TimeDelay();

        if (WhatsForDinner == "Steak")
        {
            SpaceLine();
            CookSteak();
            TypeCorrectly = true;
        }
        else if (WhatsForDinner == "Omelette")
        {
            SpaceLine();
            CookOmelette();
            TypeCorrectly = true;
        }
        else if (WhatsForDinner == "Mushrooms")
        {
            SpaceLine();
            CookMushrooms();
            TypeCorrectly = true;
        }
        else
        {
            SpaceLine();
            cout << "Make sure you type it like it says." << endl;
        }

    }
    TimeDelay();

    FinishCooking();
}

void Color(int typeColor)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, typeColor);
}

void TimeDelay()
{
    sleep_for(nanoseconds(100));
    sleep_until(system_clock::now() + seconds(1));
}