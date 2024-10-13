#include <iostream>
#include <string>

std::string outputs[] = {"Certainly!",
                    "Absolutely not!",
                    "Why would you consider that...",
                    "Go for it!",
                    "What would Jesus do?",
                    "What... What even...",
                    "What was the thought process here?",
                    "Dude.",
                    "YES YES OMG YES!!!",
                    "I think this is the greatest idea you've ever come up with.",
                    "What would your parents think?",
                    "What would your best friend think?",
                    "You miss every shot you don't take.",
                    "Do it.",
                    "Do it because you can.",
                    "Do it if it feels good. If not, don't.",
                    "Think about it for a bit longer, and the answer should come to you naturally.",
                    "I can't endorse this...",
                    "I fully endorse this.",
                    "Okay, this is epic.",
                    "Was there ever a doubt?"};

int indexnum = 0;

void newindex() {
    srand(time(nullptr));
    indexnum = rand() % std::size(outputs);
}

void makeline(int num = (std::size(outputs[indexnum])), char character = '-') {
    std::cout << '+';
    for (int i = 0; i < num - 1; i++) {
        std::cout << character;
    }
    std::cout << '+' << '\n';
}

int main() {
    // std::cout << std::size(outputs); // check size (debug)
    newindex();

    std::cout << '\n';
    makeline();
    std::cout << outputs[indexnum] << '\n';
    makeline();
    std::cout << '\n';
}