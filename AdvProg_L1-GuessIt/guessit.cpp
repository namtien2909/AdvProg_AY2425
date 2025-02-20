#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


int generateRandomNumber() {
    return rand() % 100 + 1;
}

int getPlayerGuess() {
    int guess;
    cout << "Enter your guess: ";
    cin >> guess;
    return guess;
}

string getAnswer(int number, int randomNumber) {
    if (number > randomNumber) return "Your number is higher.";
    if (number < randomNumber) return "Your number is lower.";
    return "Congratulation! You win.";
}

bool checkSuccess(string answer) {
    return answer == "Congratulation! You win.";
}

char getPlayerOpinion() {
    char opinion;
    cout << "Do you want to play again? (y/n): ";
    cin >> opinion;
    return opinion;
}

bool checkContinuePlaying(char opinion) {
    return (opinion == 'y' || opinion == 'Y');
}

void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;

    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}

