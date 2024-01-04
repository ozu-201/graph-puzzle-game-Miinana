//
// Created by mb039529 on 12/21/2023.
//
//#ifndef GRAPH_PUZZLE_GAME_MIINANA_MAIN_H
//#define GRAPH_PUZZLE_GAME_MIINANA_MAIN_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Array/Graph/Graph.h"

// Function to create a list of words with a specific length
std::vector<std::string> createWordList(const std::vector<std::string> &allWords, int targetLength) {
    std::vector<std::string> result;
    for (const auto &word: allWords) {
        if (word.length() == targetLength) {
            result.push_back(word);
        }
    }
    return result;
}

// Function to check two words different in one letter
bool oneCharDiff(const std::string &str1, const std::string &str2) {
    if (str1.length() != str2.length()) {
        return false;  // Words must have the same length
    }

    int diffCount = 0;
    for (size_t i = 0; i < str1.length(); ++i) {
        if (str1[i] != str2[i]) {
            ++diffCount;
            if (diffCount > 1) {
                return false;  // More than one letter dıfference
            }
        }
    }

    return diffCount == 1;  // True ıf exactly one letter difference
}
// Function to check pairs of words in a list for one letter difference and create an adjacency list


int main() {
    std::ifstream englishFile("../data/english-dictionary.txt");
    std::ifstream turkishFile("../data/turkish-dictionary.txt");

    if (!englishFile.is_open() || !turkishFile.is_open()) {
        std::cerr << "Error in opening file" << std::endl;
        return 1;  // Return an error code
    }

    std::vector<std::string> englishWords;
    std::vector<std::string> turkishWords;
    std::string word;

// Read lines from the files and store ın the vector
    while (std::getline(englishFile, word)) {
        englishWords.push_back(word);
    }

    while (std::getline(turkishFile, word)) {
        turkishWords.push_back(word);
    }

    englishFile.close();  // Close the English file
    turkishFile.close();

    //get inputs:
    int targetLength;
    std::cout << "Enter the Target Length";
    std::cin >> targetLength;

    //Get the first word
    std::string startWord;
    std::cout << "Enter the first word";
    std::cin >> startWord;

    //Get the target word
    std::string endWord;
    std::cout << "Enter the first word";
    std::cin >> endWord;

    //creat a vector
    std::vector<std::string> wholewords;
    wholewords.insert(wholewords.end(), englishWords.begin(), englishWords.end());
    wholewords.insert(wholewords.end(), turkishWords.begin(), turkishWords.end());

    std::vector<std::string> wordWithTargetLength;
    createWordList(wholewords, targetLength);

    //how many words are in the vector?
    int numberOfWords = wordWithTargetLength.size();

    array::Graph mygraph(numberOfWords);

    for (int i = 0; i<numberOfWords; i++) {
        for (int j = 0; j<numberOfWords; j++) {
            if (i != j) {
                if(oneCharDiff(wordWithTargetLength[i], wordWithTargetLength[j]))
                {
                    mygraph.addEdge(i, j);
                }
            }
        }
    }
    return 0;
}

//};