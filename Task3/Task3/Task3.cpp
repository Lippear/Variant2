#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class TextProcessor {
public:
    bool checkBrackets(const string& text) {
        int roundOpen = 0, roundClose = 0;
        int squareOpen = 0, squareClose = 0;

        for (char c : text) {
            if (c == '(') roundOpen++;
            if (c == ')') roundClose++;
            if (c == '[') squareOpen++;
            if (c == ']') squareClose++;
        }

        return (roundOpen == roundClose) && (squareOpen == squareClose);
    }

    string findLongestWord(const string& text) {
        istringstream iss(text);
        string word, longestWord;
        while (iss >> word) {
            if (word.length() > longestWord.length()) {
                longestWord = word;
            }
        }
        return longestWord;
    }

    string removeLatinWords(const string& text) {
        istringstream iss(text);
        string word, result;
        while (iss >> word) {
            if (!isLatinWord(word)) {
                result += word + " ";
            }
        }
        return result;
    }

private:
    bool isLatinWord(const string& word) {
        for (char c : word) {
            if (isalpha(c) && (c < 'а' || c > 'я') && (c < 'А' || c > 'Я')) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    TextProcessor processor;

    bool bracketsMatch = processor.checkBrackets(input);
    cout << "Brackets match: " << (bracketsMatch ? "Yes" : "No") << endl;

    string longestWord = processor.findLongestWord(input);
    cout << "Longest word: " << longestWord << endl;

    string modifiedText = processor.removeLatinWords(input);
    cout << "Text without Latin words: " << modifiedText << endl;

    system("pause");
    return 0;
}
