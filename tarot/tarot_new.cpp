#include <iostream>
#include <string>
#include <vector>

// big deck
std::string deck[78] = {"The Fool", "The Magician", "The High Priestess",
                "The Empress",      "The Emperor",      "The Hierophant",
                "The Lovers",       "The Chariot",      "Strength",
                "The Hermit",       "Wheel of Fortune", "Justice",
                "The Hanged Man",   "Death",            "Temperance",
                "The Devil",        "The Tower",        "The Star",
                "The Moon",         "The Sun",          "Judgement",        "The World", 
                "one of swords", "two of swords", "three of swords", "four of swords",
                "five of swords", "six of swords", "seven of swords", "eight of swords",
                "nine of swords", "ten of swords", "page of swords", "knight of swords",
                "queen of swords", "king of swords",
                "one of wands", "two of wands", "three of wands", "four of wands",
                "five of wands", "six of wands", "seven of wands", "eight of wands",
                "nine of wands", "ten of wands", "page of wands", "knight of wands",
                "queen of wands", "king of wands",
                "one of coins", "two of coins", "three of coins", "four of coins",
                "five of coins", "six of coins", "seven of coins", "eight of coins",
                "nine of coins", "ten of coins", "page of coins", "knight of coins",
                "queen of coins", "king of coins",
                "one of pentacles", "two of pentacles", "three of pentacles",
                "four of pentacles", "five of pentacles", "six of pentacles",
                "seven of pentacles", "eight of pentacles", "nine of pentacles",
                "ten of pentacles", "page of pentacles", "knight of pentacles",
                "queen of pentacles", "king of pentacles"};

// if val is in vec, returns true; else, false
bool includes(std::vector<int> vec, int val) {
    if (vec.size() > 0) {
        for (int i = 0; i < sizeof(vec); i++) {
            if (vec[i] == val) {
                return 1;
            }
        }
    }
    return 0;
}

// main logic
void draw(int count) {
    if (count <= 0) {
        std::cout << "input must be greater than 0!\n";
        return;
    } else if (count > 78) {
        std::cout << "input cannot exceed 78!\n";
        return;
    }
    srand(time(nullptr));
    std::vector<int> drawndex = {};
    std::vector<std::string> cards = {};

    for (int i = 0; i < count; i++) {
        int dex = rand() % 78;

        if (includes(drawndex, dex) == 0) {
            drawndex.push_back(dex);
            cards.push_back(deck[dex]);
        }
    }
    
    std::cout << "< ";
    for (int i = 0; i < cards.size() - 1; i++) {
        std::cout << cards[i] << ", ";
    }
    std::cout << cards.back() << " >\n";
}


int main() {
    std::cout << "Draw how many? (Up to 78)\n";

    int count;
    std::cin >> count;

    draw(count);

    std::cout << "Again? (y/n)\n";

    char user_in;
    std::cin >> user_in;
    if (tolower(user_in) == 'y') {
        main();
    }
}