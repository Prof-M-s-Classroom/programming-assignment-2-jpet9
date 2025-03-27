#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <filesystem>

#include "Node.h"
#include "Story.h"

using namespace std;
template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter) {
        ifstream myFile(filename);

        if (!myFile.is_open()) {
            cout << "File " << filename << " does not exist." << endl;
            return;
        }

        string line;
        vector<Node<T>*> vectorStrings;

        while (getline(myFile, line)) {
            istringstream ss(line);
            string description, eventNumber, rightNumber, leftNumber;

            getline(ss, eventNumber, delimiter);
             int eventNum = stoi(eventNumber);

            getline(ss, description, delimiter);

            getline(ss, leftNumber, delimiter);
            getline(ss, rightNumber, delimiter);
            int leftNum = stoi(leftNumber);
            int rightNum = stoi(rightNumber);

            Story story(description, eventNum, leftNum, rightNum);
            Node<T>* newNode = new Node<T>(story);

            vectorStrings.push_back(newNode);

            if (root == nullptr) {
                root = newNode;
            }
        }

        for (int i = 0; i < vectorStrings.size(); i++) {
            Node<T>* currentNode = vectorStrings[i];
            for (int j = 0; j < vectorStrings.size(); j++) {
                if (vectorStrings[j]->data.eventNumber == currentNode-> data.leftEventNumber) {
                    currentNode -> left = vectorStrings[j];
                }
                if (vectorStrings[j]->data.eventNumber == currentNode-> data.rightEventNumber) {
                    currentNode->right = vectorStrings[j];
                }
            }

        }
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {

        if (!root) {
            cout << "Story has not been loaded" << endl;
        }

        Node<T>* currentNode = root;

        while (currentNode) {
            cout << currentNode->data.description << endl;

            if (currentNode->data.leftEventNumber == -1 && currentNode->data.rightEventNumber == -1) {
                cout << "You Died. Should of chose the better option. End of game. Thanks for playing!"<< endl;
                break;
            }
            string leftPrompt;
            string rightPrompt;

            if (currentNode->left) {
                leftPrompt = currentNode->left->data.description;
            }else {
                leftPrompt = "No data";
            }

            if (currentNode->right) {
                rightPrompt = currentNode->right->data.description;
            }else {
                rightPrompt = "No data";
            }

            cout << "1. " << leftPrompt <<endl;
            cout << "2. " << rightPrompt <<endl;
            cout << "Enter choice: " << endl;

            int choice;
            cin >> choice;

            if (choice == 1) {
                if (currentNode->left != nullptr) {
                    currentNode = currentNode->left;
                }else {
                    cout<<"Game Over. Thanks for playing!"<<endl;
                }
            }
            else if (choice == 2) {
                currentNode = currentNode -> right;
            }
            else {
                cout << "Invalid choice. Options are 1 or 2" << endl;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H