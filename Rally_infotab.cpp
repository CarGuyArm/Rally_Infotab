#include <iostream>
using namespace std;

class Help {
public:
    void mainmenu();
    void infodesk(char what);
    void showmenu();
    bool isvalid(char ch);
    bool mainisvalid(char ch);
};
void Help::mainmenu() {
    cout << "1. Group B InfoTab\n";
    cout << "2. Clutch Manager\n";
    cout << "Press x for exit \n";
}

bool Help::mainisvalid(char ch) {
    //checking the inputed information
    if (ch > '1' || ch < '2' && ch != 'x')
        return true;
    else
        return false;
}

void Help::infodesk(char what) {

    switch (what) {
    case '1':
        cout << "Audi Sport Quattro S1/E2\n\n";
        cout << "Displacement - 2135cc\n";
        cout << "Type - l5,DOHC 20v,turbocharged\n";
        cout << "Compression ratio - 7.5:1\n";
        cout << "Power,torque - 400-450/450-590,~580nm\n\n";
        break;
    case '2':
        cout << "Lancia Delta S4\n\n";
        cout << "Displacement - 1759x1.4 = 2463\n";
        cout << "Type - I4,DOHC 16v,turbo + supercharger\n";
        cout << "Compression ratio - 7.1:1\n";
        cout << "Power,torque - 450-550+,~450nm\n\n";
        break;
    case '3':
        cout << "Lancia Rallye 037 E1/E2\n\n";
        cout << "Displacement - 1995cc/2111cc\n";
        cout << "Type - I4,twincam 16v,Abarth supercharger\n";
        cout << "Compression ratio - 7.5:1/9.0:1\n";
        cout << "Power,torque - 290-310hp/325-350hp,~300nm\n\n";
        break;
    case '4':
        cout << "Ford RS200 /E\n\n";
        cout << "Displacement - 1.8lx1.4 = 2524cc/2137x1.4 = 2790cc\n";
        cout << "Type - BDT,I4,DOHC 16v,turbocharged\n";
        cout << "Compression ratio - 7.2:1\n";
        cout << "Power,torque - 350-450hp/450-650,~490nm";
        break;
    case '5':
        cout << "Peugeot 205 T16 E1/E2\n\n";
        cout << "Displacement - 1775x1.4 = 2485cc\n";
        cout << "Type - XU8T,I4,DOHC 16v,turbo\n";
        cout << "Compression ratio - 7.0:1\n";
        cout << "Power,torque - 340-350hp/460-550hp,450nm/490nm\n\n";
        break;
    }
    cout << "\n";
}

void Help::showmenu() {
    cout << "Group B car list: \n";
    cout << "1. Audi Sport Quattro\n";
    cout << "2. Lancia Delta S4\n";
    cout << "3. Lancia 037\n";
    cout << "4. Ford RS200\n";
    cout << "5. Peugeot 205 T16\n";
    cout << "Choose the car or press x to exit \n\n";
}

bool Help::isvalid(char ch) {
    //checking the inputed information
    if (ch > '1' || ch <'5' && ch != 'x')
        return true;
    else
        return false;
}

//clutch Manager
class vehicle {
public:

    //constructor 
    //Default - stock Honda S2000 
    vehicle() {
        horsepower = 200;
        capacity = 2.0;
        clutch = 100;
    }
    void specific_output();//hp per capacity calculator
    void drift();//clutch warnings

    //destructor
    ~vehicle() {
        cout << "that's all";
    }

    int horsepower;//horsepower
    double capacity;//engine capacity
    int clutch;//clutch percentage

};

void vehicle::drift() {
    if (clutch >= 50)
        cout << "\nClutch it!";

    else if (clutch < 50 && clutch > 0)
        cout << "\nClutch carefully";

    else
        cout << "\nCall evacuator!!";
}

void vehicle::specific_output() {
    double output;

    output = horsepower / capacity;
    cout << "\nSpecific output is: " << output;
}

int main()
{
    char choice;
    char mainchoice;
    Help help;
    vehicle v;
    cout << "Welcome to TheCarGuy App!\n\n";
    //------------------------------------------------//

    for (;;) {
        do {
            help.mainmenu();
            cin >> mainchoice;
        } while (!help.mainisvalid(mainchoice));

        //group b
        if (mainchoice == '1')
        {
            for (;;) {
                do {
                    help.showmenu();
                    cin >> choice;
                } while (!help.isvalid(choice));

                if (choice == 'x') break;
                cout << "\n";

                help.infodesk(choice);

                cout << "\n";
            }
        }

       //clutch manager
       if (mainchoice == '2') {
                cout << "Input horsepower: ";
                cin >> v.horsepower;
                cout << "Input displacement: ";
                cin >> v.capacity;
                cout << "Input clutch percentage: ";
                cin >> v.clutch;
                v.drift();
                v.specific_output();
                cout << "\n";
            }
            
        if (mainchoice == 'x') break;
            cout << "\n";
        }
        cout <<"\n"<<"The CarGuy Production 2020\n\n";
    }