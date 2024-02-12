#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>


using namespace std;

string Input, sInput;
int NumInput;

void PaliCheck(string Input) {

    transform(Input.begin(), Input.end(), Input.begin(),[](unsigned char c) {return tolower(c); });             // Convert to lowercase because (Racecar != racecaR) and (racecar == racecar)
    string RevInput = Input;
    reverse(RevInput.begin(), RevInput.end());                                                                  // Reverse character order

    if (RevInput == Input) {                                                                                    // Test if strings are identical
        cout << Input << " == " << RevInput << " Is a palindrome\n";
    }

    else {
        cout << Input << " != " << RevInput << " Is not a palindrome\n";
    }
}

void WordCheck(string Input) {
    int w = 0;                                                                                              // w = words, LastChar = Last checked character
    char LastChar = ' ';

    for (int i = 0; i < Input.size(); i++) {

        if (Input[i] != ' ' && LastChar == ' ') {                                                           // Check every character in the string against the one before it
            w++;                                                                                            // If there is a space (" ") and then a character (" a") => new word
        }

        LastChar = Input[i];                                                                                // Update latest checked character
    }

    cout << "There are:\n" << Input.length() << " characters and \n" << w << " words.\n";

}

void VowelCheck(string Input) {
    transform(Input.begin(), Input.end(), Input.begin(), [](unsigned char c) {return tolower(c); });        // Change to lowercase so we dont have to make "if" conditions for uppercase letters
    int c = 0;
    
    for (int i = 0; i < Input.size(); i++) {
        if (Input[i] == 'a' or Input[i] == 'e' or Input[i] == 'i' or Input[i] == 'o' or Input[i] == 'u' or Input[i] == 'å' or Input[i] == 'ö' or Input[i] == 'ä') {
            c++;
        }
    }

    cout << "There are " << c << " vowels in your input\n";
}

int main() {

    cout << "Give input: \n1 = Palindrome check \n2 = Word and character counter \n3 = Vowel counter \n";            // "Input" was originally taken with "cin >> Input;"                                                                                    
    getline(cin, Input);                                                                                // but for some reason this caused the "getline(cin, sInput);" to be skipped
    NumInput = stoi(Input);                                                             

    if (NumInput == 1) {
        cout << "What word or sentence would you like to check?\n";
        getline(cin, sInput);
        PaliCheck(sInput);
    }

    if (NumInput == 2) {
        cout << "Please input the string you'd like to check\n";
        getline(cin, sInput);
        WordCheck(sInput);
    }

    if (NumInput == 3) {
        cout << "Please input the string you'd like to check\n";
        getline(cin, sInput);
        VowelCheck(sInput);
    }
    
    if (NumInput < 1 or NumInput > 3) {
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
