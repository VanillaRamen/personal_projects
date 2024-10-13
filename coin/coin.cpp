#include <iostream>
#include <string>
#include <fstream>

#include "coin.hpp"

int main() {
    using std::cout, std::cin, std::string;

    srand(time(nullptr));

    string answer = "y";
    int score;

    score = flipstreak(answer, score);

    cout << "final score: " << score << '\n';

    if (score) {
        win_score(score);
    }

    cout << "\nscores are in ./top.txt.\ntype \"./coin\" to play again!\n";
}