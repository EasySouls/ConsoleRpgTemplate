//
// Created by retek on 2023. 09. 10..
//

#include "Puzzle.h"

Puzzle::Puzzle(const std::string& fileName) {
    this->correctAnswer = 0;

    std::ifstream inFile(fileName);

    int nrOfAnswers = 0;
    std::string answer;

    if (inFile.is_open()) {
        std::getline(inFile, this->question);
        inFile >> nrOfAnswers;
        inFile.ignore();
        for (size_t i = 0; i < nrOfAnswers; i++) {
            std::getline(inFile, answer);
            this->answers.push_back(answer);
        }
        inFile >> this->correctAnswer;
    }
    else throw ("Error opening the puzzle file!");
    inFile.close();
}

std::string Puzzle::getAsString() {
    std::string _answers;
    for (size_t i = 0; i < this->answers.size(); i++) {
        _answers += std::to_string(i) + ": " + this->answers[i] + "\n";
    }

    return this->question + "\n" + _answers + "\n";
}
