#include <iostream>
#include <string>
#include <fstream>

int flip() {
    srand(time(nullptr));
    return rand() % 4;
}

void win_score(int score) {
    using std::cout, std::cin, std::string;
    string answer;
    cout << "submit score? ";

        cin >> answer;
        std::fstream File("top.txt");
        if (answer == "y" || answer == "Y") {
            File.seekp(0, std::fstream::end);

            string username;

            cout << "name? ";
            cin >> username;

            cout << username << '\n' << score << '\n';

            File << username << '\n' << score << '\n' << '\n';

            cout << "score submitted!\n";
        }

        File.seekp(0, std::fstream::beg);
        File.close();
}

int flipstreak(std::string answer, int score = 0) {
    using std::string, std::cout, std::cin;
    int coin;
    while (answer == "y" || answer == "Y") {
        coin = flip();

        if (score == 0) {
            coin = 1;
        }

        if (coin > 0) {
            score++;
            cout << "heads";
            for (int i = 0; i < score; i++) {
                cout << '!';
            }
            cout << " (" << score << ')' << '\n';
        } else if (!(coin > 0)) {
            cout << "tails!\ncrashed!!!\n\n";
            cout << "score halved... better luck next time.\n";
            score /= 2;
            break;
        }

        cout << "flip again? (y/n) ";
        cin >> answer;
    }

    return score;
}