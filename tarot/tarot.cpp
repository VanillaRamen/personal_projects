#include <iostream>
#include <string>
#include <vector>

// amateur work of vanillaramen

std::string major_arcana[22] = {"The Fool", "The Magician", "The High Priestess",
                "The Empress",      "The Emperor",      "The Hierophant",
                "The Lovers",       "The Chariot",      "Strength",
                "The Hermit",       "Wheel of Fortune", "Justice",
                "The Hanged Man",   "Death",            "Temperance",
                "The Devil",        "The Tower",        "The Star",
                "The Moon",         "The Sun",          "Judgement",        "The World"};

std::string swords[14] = {"one of swords", "two of swords", "three of swords", "four of swords",
                        "five of swords", "six of swords", "seven of swords", "eight of swords",
                        "nine of swords", "ten of swords",
                        "page of swords", "knight of swords", "queen of swords", "king of swords"};

std::string wands[14] = {"one of wands", "two of wands", "three of wands", "four of wands",
                        "five of wands", "six of wands", "seven of wands", "eight of wands",
                        "nine of wands", "ten of wands",
                        "page of wands", "knight of wands", "queen of wands", "king of wands"};

std::string coins[14] = {"one of coins", "two of coins", "three of coins", "four of coins",
                        "five of coins", "six of coins", "seven of coins", "eight of coins",
                        "nine of coins", "ten of coins",
                        "page of coins", "knight of coins", "queen of coins", "king of coins"};

std::string pentacles[14] = {"one of pentacles", "two of pentacles", "three of pentacles",
                        "four of pentacles", "five of pentacles", "six of pentacles",
                        "seven of pentacles", "eight of pentacles", "nine of pentacles",
                        "ten of pentacles", "page of pentacles", "knight of pentacles",
                        "queen of pentacles", "king of pentacles"};



void reset_deck() { // yeah i know this solution is messy and there's probably a better one but i mean come on
    std::string major_arcana_copy[22] = {"The Fool", "The Magician", "The High Priestess",
                    "The Empress",      "The Emperor",      "The Hierophant",
                    "The Lovers",       "The Chariot",      "Strength",
                    "The Hermit",       "Wheel of Fortune", "Justice",
                    "The Hanged Man",   "Death",            "Temperance",
                    "The Devil",        "The Tower",        "The Star",
                    "The Moon",         "The Sun",          "Judgement",        "The World"};

    std::string swords_copy[14] = {"one of swords", "two of swords", "three of swords",
                            "four of swords", "five of swords", "six of swords", "seven of swords",
                            "eight of swords", "nine of swords", "ten of swords", "page of swords",
                            "knight of swords", "queen of swords", "king of swords"};

    std::string wands_copy[14] = {"one of wands", "two of wands", "three of wands", "four of wands",
                            "five of wands", "six of wands", "seven of wands", "eight of wands",
                            "nine of wands", "ten of wands", "page of wands", "knight of wands",
                            "queen of wands", "king of wands"};

    std::string coins_copy[14] = {"one of coins", "two of coins", "three of coins", "four of coins",
                            "five of coins", "six of coins", "seven of coins", "eight of coins",
                            "nine of coins", "ten of coins", "page of coins", "knight of coins",
                            "queen of coins", "king of coins"};

    std::string pentacles_copy[14] = {"one of pentacles", "two of pentacles", "three of pentacles",
                            "four of pentacles", "five of pentacles", "six of pentacles",
                            "seven of pentacles", "eight of pentacles", "nine of pentacles",
                            "ten of pentacles", "page of pentacles", "knight of pentacles",
                            "queen of pentacles", "king of pentacles"};

    for (int i = 0; i < 22; i++) {
        major_arcana[i] = major_arcana_copy[i];
    }

    for (int i = 0; i < 14; i++) {
        swords[i] = swords_copy[i];
        wands[i] = wands_copy[i];
        coins[i] = coins_copy[i];
        pentacles[i] = pentacles_copy[i];
    }
}

std::string drawsuit(std::string *arr) {
    int dex;

    do {
        srand(time(nullptr));
        dex = rand() % sizeof(arr);
    } while (arr[dex] == "reroll");

    std::string hold = arr[dex];

    arr[dex] = "reroll";

    return hold;
}

void swish(int sel = rand() % 5) {
    switch (sel) {
            case 0:
                std::cout << drawsuit(major_arcana);
                break;
            case 1:
                std::cout << drawsuit(swords);
                break;
            case 2:
                std::cout << drawsuit(wands);
                break;
            case 3:
                std::cout << drawsuit(coins);
                break;
            case 4:
                std::cout << drawsuit(pentacles);
                break;
            default:
                std::cout << "An error has occurred in function swish()." << '\n';
    }
}

std::string reversal() {
    if (rand() % 2 == 0) {
        return ", reversal";
    } else {
        return "";
    }
}

void draw(int drawcount = 3) {
    srand(time(nullptr));

    std::cout << "< ";

    for (int i = 0; i < drawcount - 1; i ++) {
        swish();
        std::cout << reversal() << "; ";
    }
    swish();
    std::cout << reversal();

    std::cout << " >";

    std::cout << '\n';
}

int main() {
    std::cout << "Draw how many? (up to 14)\n";

    int count;
    std::cin >> count;

    std::cout << "Drawing " << count << "!\n";

    draw(count);

    std::cout << "again? (y/n)\n";

    char user_in;
    std::cin >> user_in;
    if (std::tolower(user_in) == 'y') {
        reset_deck();
        main();
    }
}