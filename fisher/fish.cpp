/*
todo:
    make a way to fail
*/

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <format>

void slow_cout(std::string ustr, std::string end = "\n", std::chrono::milliseconds wt = std::chrono::milliseconds(500)) {
    for (char c : ustr) {
        std::this_thread::sleep_for(wt);
        std::cout << c;
    }
    std::cout << end;
}

const std::string fishies[8] {
    "pike",         // 0
    "sturgeon",     // 1
    "catfish",      // 2
    "salmon",       // 3
    "bass",         // 4
    "trout",        // 5
    "walleye",      // 6
    "gar"           // 7
};

const int num_fishies { std::end(fishies) - std::begin(fishies) };

void wait_one() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void getinv(int* inv) {
    std::ifstream fin;

    fin.open("./fish_data.txt");

    std::string line;

    for (int i = 0; i < num_fishies; i++) {
        std::getline(fin, line);
        inv[i] = std::stoi(line);
    }

    fin.close();
}

void display(int* inv) {
    for (int i = 0; i < num_fishies; i++) {
        slow_cout(fishies[i] + ":\t", "", std::chrono::milliseconds(60));
        // std::cout << fishies[i] << ":\t"; // orig fast code
        if (fishies[i].size() < 7) {
            std::cout << '\t';
        }
        std::cout << inv[i] << '\n';
    }
    wait_one();
}

void fish(int* inv) {
    srand(time(nullptr));
    int ind { rand() % num_fishies };
    inv[ind] += 1;

    std::cout << "Casting rod"; slow_cout("... ", "");

    std::cout << "Rod cast!\n";
    std::this_thread::sleep_for(std::chrono::seconds(1 + (rand() % 2) ));

    // std::cout << "Wow! You caught a " << fishies[ind] << "!\n";

    std::string catch_msg = "Wow! You caught a " + fishies[ind] + "!";
    slow_cout(catch_msg, "\n", std::chrono::milliseconds(125));

    slow_cout("><(((", "", std::chrono::milliseconds(250));
    for (int i = 0; i < rand() % 5; i++) { // 0 to 5
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        std::cout << '(';
    }
    slow_cout("'>", "\n", std::chrono::milliseconds(250));
}

void quit(int* inv) {
    std::ofstream fout;

    fout.open("./fish_data.txt");

    for (int i = 0; i < num_fishies; i++) {
        fout << inv[i] << '\n';
    }

    fout.close();
}


int main() {
    int inv[num_fishies] {};
    getinv(inv);

    std::cout << "You are now fishing!\n";

    char cuin = '0';

    while (true) { // main game loop
        std::cout << "+----------------------------------------------+\n";
        std::cout << " \"f\" to fish | " << "\"d\" to display inv | " << "\"q\" to quit\n";
        std::cin >> cuin;

        if (cuin == 'f') { fish(inv); wait_one(); }
        else if (cuin == 'd') { display(inv); }
        else if (cuin == 'q') { quit(inv); break; }
    }

    return 0; // end of prog
}