#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

//
// Created by retek on 2023. 09. 10..
//

#ifndef TEXTRPGGAME_PUZZLE_H
#define TEXTRPGGAME_PUZZLE_H


class Puzzle {
private:
    std::string question;
    std::vector<std::string> answers;
    int correctAnswer;

public:
    explicit Puzzle(std::string fileName);
    std::string getAsString();

    [[nodiscard]]
    inline const int& getCorrectAnswer() const { return this->correctAnswer; }
};


#endif //TEXTRPGGAME_PUZZLE_H
