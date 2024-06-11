#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void hangman();
int charcount(const char* x);
void game(const char* y);

int charcount(const char* x) {
    int count = 0;
    while (*x != '\0') {
        x++;
        count++;
    }
    return count;
}

void game(const char* y) {
    int size = charcount(y);
    char temparr[20];  // Increased size to handle larger words
    int loopcount = 0;
    int wrngcount = 0;

    for (int i = 0; i < size; i++) {
        temparr[i] = '_';
        cout << "_";
    }
    cout << endl;

    while (loopcount < size && wrngcount < 8) {
        int wrngcheck = 0;
        char guess;

        cout << "\nGuess any letter of the Country's Name: ";
        cin >> guess;

        for (int i = 0; i < size; i++) {
            if (y[i] == guess) {
                temparr[i] = guess;
                wrngcheck = 1;
            }
        }
        
        if (wrngcheck == 0) {
            wrngcount++;
        }

        // Clear the console (note: system("CLS") works on Windows; you might need "clear" for Unix)
        system("CLS");

        for (int i = 0; i < size; i++) {
            cout << temparr[i] << " ";
        }
        cout << endl;

        if (wrngcount == 8) {
            cout << "\n\n\n";
            cout << "      ('')\n";
            cout << "      ||/\n";
            cout << "     / ||\n";
            cout << "    /  \\ \n";
            cout << "==============\n\n";
            cout << " NO MORE CHANCES! YOU LOST!\n";
        } else if (wrngcount == 7) {
            cout << "\n\n\n";
            cout << "      ('')\n";
            cout << "      ||/\n";
            cout << "     / ||\n";
            cout << "    _/ \n";
            cout << "==============\n\n";
            cout << "Wrong!! 1 Chance Left! Try Again\n";
        } else if (wrngcount == 6) {
            cout << "\n\n\n";
            cout << "      ('')\n";
            cout << "      ||/\n";
            cout << "     / ||\n";
            cout << "==============\n\n";
            cout << "Wrong!! 2 Chances Left! Try Again\n";
        } else if (wrngcount == 5) {
            cout << "\n\n\n";
            cout << "       ( )\n";
            cout << "        | \n";
            cout << "     / \n";
            cout << "==============\n\n";
            cout << "Wrong!! 3 Chances Left! Try Again\n";
        } else if (wrngcount == 4) {
            cout << "\n\n\n";
            cout << "      ('')\n";
            cout << "      _||\n";
            cout << "     / \n";
            cout << "==============\n\n";
            cout << "Wrong!! 4 Chances Left! Try Again\n";
        } else if (wrngcount == 3) {
            cout << "\n\n\n";
            cout << "      ('')\n";
            cout << "      _||\n";
            cout << "     / \n";
            cout << "==============\n\n";
            cout << "Wrong!! 5 Chances Left! Try Again\n";
        } else if (wrngcount == 2) {
            cout << "\n\n\n";
            cout << "      ('')\n";
            cout << "==============\n\n";
            cout << "Wrong!! 6 Chances Left! Try Again\n";
        } else if (wrngcount == 1) {
            cout << "\n\n\n";
            cout << "      ('\n";
            cout << "==============\n\n";
            cout << "Wrong!! 7 Chances Left! Try Again\n";
        } else {
            cout << "\n\n8 Chances Left!";
        }

        loopcount = 0;
        for (int i = 0; i < size; i++) {
            if (temparr[i] == y[i]) {
                loopcount++;
            }
        }
    }

    if (loopcount == size) {
        cout << "\n\nYOU WIN\n\n";
    } else {
        cout << "\n\nYOU LOSE\n";
        cout << "Correct Answer is " << y << "\n\n";
    }

    cout << "\n\n*GAMEOVER*\n";
    
    int select = 0;
    cout << "\n\nDo you want to play again!(0 for no): ";
    cin >> select;
    if (select == 0) {
        cout << " \n\nEXITING GAME\n\n";
    } else {
        system("CLS");
        hangman();
    }
}

void hangman() {
    const char* words[] = {"watermelon", "pineapple", "orange", "blueberry"};
    srand((unsigned int) time(0));
    int n = rand() % 4;
    game(words[n]);
}

int main() {
    cout << "*WELCOME TO THE HANGMAN GAME*\n\n";
    cout << "Rules\n\n1. Use lower case letters only\n2. You have only 8 wrong choice limit\n3. One letter once used cannot be used again\n";
    hangman();
    return 0;
}
