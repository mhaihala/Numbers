#include <iostream>
#include <iomanip>


using namespace std;

double Pi = atan(1) * 4;          // = 3.14159.... (48 decimals)

void PiFunction(int Input) {
    int Decimal = Input + 1;                    // + 1 Due to wanting to control decimals ==> setprecision(1) = integer

    if (0 < Decimal < 48) {
        cout << setprecision(Decimal);          // Set precision of output to user defined decimal amount
        cout << Pi;
    }

    else {
        cout << "*ERROR* Faulty input\n";
    }
}

void FiboFunction(int Input) {              // Fibonacci sequence => Fx = F(x-1) + F(x-2)
    int a = 0;                              // F1
    int b = 1;                              // F2

    for (int i = 0; i < Input; i++) {

        if (Input < 1 or Input > 47) {
            cout << "*ERROR* Faulty input\n";
            return;                                     // The numbers get too big and the function starts giving negative values at 48
        }

        if (i % 2 == 0 and i > 0) {                      // Print current value of even number and update its value
            cout << b;
            cout << " ";
            b = b + a;                                  // Fx = F(x-1) + F(x-2)

            if (i % 10 == 0) {                          // Change rows every 10 numbers for visual clarity
                cout << "\n";
            }
        }

        else {                                          // Print current value of odd number and update its value
            cout << a;
            cout << " ";
            a = b + a;
        }
    }
    cout << "\n";
}

void PrimeFunction(int Input) {
    int Prime = 2;                                      // Start at smallest prime number
    int Counter = Input;                                // Number used to represent how much of the input has not been divded

    if (Input < 2) {                                    // Variable is negative or doesnt contain any prime numbers
        cout << "*ERROR* Faulty input\n";
        return;
    }

    while (Prime < Counter) {                           // This function checks if the input is divisible by the current prime number ==> If (Prime = Counter) then the prime number cant be increased

        if (Counter % Prime == 0) {                     // Smallest possible number to divide the  evenly has been found
            cout << Prime;                              // Output current prime number
            cout << "*";                                // Add "*" for visual clarity
            Counter /= Prime;                           // Divide Variable with used prime number and continue looking for factors
        }

        else {                                          // If current number produces no results + 1 and try again
            Prime++;
        }
    }

    cout << Counter;                                    // Output whats left of after all divisions to get the final variable
    cout << " = ";
    cout << Input;                                      // Output original input
    cout << "\n";
}

void AreaCost() {
    int H, W, C;

    cout << "Give the width of the area (m) if the surface area (m^2) is already known input 0\n";
    cin >> W;

    if (W < 0) {
        cout << "*ERROR* Faulty input\n";
        return;
    }

    if (W == 0) {
        cout << "Give the area (m^2)\n";
        cin >> W;
        cout << "Give cost of material (eur/m^2)\n";
        cin >> C;
        cout << "Surface area = " << W << " (m^2). " << "Cost = " << W * C << " eur\n";
    }

    else {
        cout << "Give height of area (m)\n";
        cin >> H;
        cout << "Give cost of material (eur/m^2)\n";
        cin >> C;
        cout << "Surface area = " << W * H << " (m^2). " << "Cost = " << W * H * C << " eur\n";
    }
}

int main()
{
    int Input, Input2 = 0;              // Reset input variables

    cout << "Give input: \n1 = Pi \n2 = Fibonacci \n3 = Prime Factorization \n4 = Area Cost\n";
    cin >> Input;

    if (Input == 1) {
        cout << "How many decimals of Pi would you like to display? (1 - 48)\n";
        cin >> Input2;
        PiFunction(Input2);
    }

    if (Input == 2) {
        cout << "How many numbers of the Fibonacci sequence would you like to display? (1-47)\n";
        cin >> Input2;
        FiboFunction(Input2);
    }

    if (Input == 3) {
        cout << "What number would you like to factorize? (x > 2)\n";
        cin >> Input2;
        PrimeFunction(Input2);
    }

    if (Input == 4) {
        AreaCost();
    }

    if (Input < 1 or Input > 4) {
        cout << "*ERROR* Faulty input\n";
    }
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
