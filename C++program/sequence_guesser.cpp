#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

const int SEQUENCE_LENGTH = 4;
const std::vector<std::string> COLORS = {"RED", "BLUE", "GREEN", "YELLOW", "ORANGE", "PURPLE", "WHITE", "BLACK"};

void generateSequence(std::vector<std::string>& sequence) {
    sequence.clear();
    for (int i = 0; i < SEQUENCE_LENGTH; ++i) {
        int randomIndex = rand() % COLORS.size();
        sequence.push_back(COLORS[randomIndex]);
    }
}

int main() {
    srand(time(NULL));

    std::vector<std::string> sequence;
    generateSequence(sequence);

    std::cout << "Guess the Sequence Game!" << std::endl;
    std::cout << "Available colors: RED, BLUE, GREEN, YELLOW, ORANGE, PURPLE, WHITE, BLACK" << std::endl;
    std::cout << "Guess the sequence of " << SEQUENCE_LENGTH << " colors (no spaces, e.g., REDBLUEGREENYELLOW):" << std::endl;

    int attempts = 0;
    while (true) {
        ++attempts;
        std::string guess;
        std::cin >> guess;

        std::transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        bool isCorrect = true;

        for (int i = 0, j = 0; i < SEQUENCE_LENGTH && j < guess.size(); i += COLORS[0].size(), j += COLORS[0].size()) {
            std::string colorGuess = guess.substr(j, COLORS[0].size());
            if (colorGuess != sequence[i]) {
                isCorrect = false;
                break;
            }
        }

        if (isCorrect) {
            std::cout << "Congratulations! You guessed the sequence in " << attempts << " attempts." << std::endl;
            break;
        } else {
            std::cout << "Incorrect. Try again:" << std::endl;
        }
    }

    return 0;
}
