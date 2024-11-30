#ifndef FUZZYMATCHER_H
#define FUZZYMATCHER_H

/* Program Name: FuzzyMatcher.h
*  Author: Generated by ChatGPT through prompts from Kyle Ingersoll
*  Date last updated: 11/30/2024
*  Purpose: To create the class prototype for the FuzzyMatcher class
*/

#include <string>
#include <vector>
#include <unordered_map>

class FuzzyMatcher {
private:
    // The inverted index to be used for matching
    std::unordered_map<std::string, std::vector<int>> index;

    // Helper method to calculate Levenshtein Distance
    static int levenshteinDistance(const std::string& s1, const std::string& s2);

public:
    // Constructor to initialize the FuzzyMatcher with an index
    explicit FuzzyMatcher(const std::unordered_map<std::string, std::vector<int>>& index);

    // Method to perform fuzzy matching
    std::vector<std::string> match(const std::string& query, int maxDistance) const;
};

#endif // FUZZYMATCHER_H

