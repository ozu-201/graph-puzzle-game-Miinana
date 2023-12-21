//
// Created by mb039529 on 12/21/2023.
//
#ifndef GRAPH_PUZZLE_GAME_MIINANA_MAIN_H
#define GRAPH_PUZZLE_GAME_MIINANA_MAIN_H

// Function to create a list of words with a specific length
std::vector<std::string> createWordList(const std::vector<std::string>& allWords, int targetLength) {
    std::vector<std::string> result;
    for (const auto& word : allWords) {
        if (word.length() == targetLength) {
            result.push_back(word);
        }
    }
    return result;
}
// Function to check two words different in one letter
bool oneCharDıff(const std::strıng& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;  // Words must have the same length
    }

    ınt diffCount = 0;
    for (size_t i = 0; i < str1.length(); ++i) {
        ıf (str1[i] != str2[i]) {
            ++diffCount;
            if (dıffCount > 1) {
                return false;  // More than one letter dıfference
            }
        }
    }

    return dıffCount == 1;  // True ıf exactly one letter difference
}
// Function to check pairs of words in a list for one letter difference and create an adjacency list


#include "main.h"
    int main() {
        std::ifstream englishFile("./data/english-dictionary.txt");
       // std::ifstream turkishFile("./data/turkish-dictionary.txt");

        if (!englishFile.is_open() || !turkishFile.is_open()) {
            std::cerr << "Error in opening file" << std::endl;
            return 1;  // Return an error code
        }

        std::vector<std::string> englishWords;
        //std::vector<std::string> turkishWords;
        std::string word;

// Read lines from the files and store ın the vector
        while (std::getline(englishFile, word)) {
            englishWords.push_back(word);
        }

      //  while (std::getline(turkishFile, word)) {
        //    turkishWords.push_back(word);
      //  }

        englishFile.close();  // Close the English file
      //  turkishFile.close();
    };

    // Create a single list of words with the specified length
    std::vector<std:.string> wordsWithLength = createWordList(englishWords, userWord.length());
    wordsWithLength.insert(wordsWithLength.end(), turkishWords.begin(), turkishWords.end());

    // Create the adjacency list
    std::unordered_map<std::string, std::vector<std::string>> adjacencyList;
    createGraph(wordsWithLength, adjacencyList);

    return 0;
    }
