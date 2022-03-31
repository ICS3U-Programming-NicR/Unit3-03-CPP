// Copyright (c) 2022 Nicolas Riscalas All rights reserved.
//
// Created by: Nicolas Riscalas
// Created on: March 29 2022
// This program makes a random number game

#include <stdlib.h>
#include <iostream>
#include <random>

using std::cout;
using std::cin;
using std::string;


int main() {
  int biggestNum, usersNum, randomNum;
  cout << "Enter the largest number to be generated: ";
  cin >> biggestNum;
  std::random_device rseed;
  std::mt19937 rgen(rseed());
  std::uniform_int_distribution<int> idist(0, biggestNum);
  randomNum = idist(rgen);

  while (true) {
    cout << "Guess a number between 1 and " << biggestNum << ": ";
    cin >> usersNum;

    if (randomNum < usersNum) {
        cout << "The secret number is lower\n";
    } else if (randomNum > usersNum) {
       cout << "The secret number is higher\n";
    } else {
      cout << "You guessed the right number!\n";
      break;
    }
  }
  string tryAgain;
  cout << "would you like to try again? ";
  cin >> tryAgain;
  if (tryAgain == "y"
    || tryAgain == "Y"
    || tryAgain == "yes"
    || tryAgain == "YES") {
    main();
  } else if (tryAgain == "n"
    || tryAgain == "N"
    || tryAgain == "no"
    || tryAgain == "NO") {
    exit(1);
  }
}
