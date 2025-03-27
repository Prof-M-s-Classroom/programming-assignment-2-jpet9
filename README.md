[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `James Petropulos`  
### **Student ID:** `130346707`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)
This RPG game utilizes decision tree to create a interactive story that takes the player through a journey. I created a 
decision tree where each decision leads to a different outcome and the goal is to have a good ending depending on what you want.
It provides the player with at most two options and they input the decision they want to go with for the game. The game events are
nodes and have options to go left or right. Story is loaded from 'story.txt' and is parsed to make sure the delimiter categorizes 
the line into its different roles. This includes the event number, description, left option, and right option.

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `[Describe its function]`  
- main.cpp starts the game by initializing it, setting the file, setting the delimiter, and starting the game
- **`GameDecisionTree.h`** → `[Explain what this file contains]` 
- GameDecisionTree.h consists of the constructor, loadStoryFromFile method, and playGame method. It constructs the game's "tree". First loads the text files and extracts each portion out of the lines into a vector using the delimiter.
- The code then creates the game with the correct parameters. This file, it constructs and manages the tree, reads the text file and builds the tree, and allows the player to traverse the tree.
- **`Node.h`** → `[Explain what this file contains]`  
- Nodes store a Story object which comes with pointers to the left and right child nodes. This is the decision point of the game
- **`Story.h`** → `[Explain what this file contains]`
- This defines the Story class with the description, event number, left and right choices.
- **`story.txt`** → `[Explain how the game loads story events from this file]`
- Game loads story events from this file by parsing each part of it with the delimiter to identify the event number, description, left and right choices. This file contains the storyline and is loaded into GameDecisionTree.h

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
- How are nodes linked based on left and right event numbers?  
- What happens if an event has `-1` as left or right children?  

The decision tree is built from the story.txt file as each line in story.txt follows the same template.
Eventnumber | Description | LeftEventNumber | RightEventNumber and we parse it by using the delimiter '|'
It is stored as story objects. The nodes are based on left and right event numbers which the user chooses which then progresses the story.
If an event has -1 as a left or right child, the game ends as that leaf is null.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- What happens when the player reaches a leaf node?  
- Explain the special case where multiple events lead to the same outcome.  

The player starts at the root node and chooses between 1 or 2 which correlate to the left or right node. Leaf nodes are valued as -1 and end the game.
There is a special case where multiple events lead to the same outcome in which they all have the option to lead to the same node. If a player enters an invalid choice
then they are given an error message.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

The file is read line by line. The splitstream command and delimiter,'|', parse the line into values.
stoi() converts the event number, left event number, and right event number from strings to ints. The story object is then created with this data
The nodes are properly linked because I have debugged it by printing the strings to make sure they all are correctly parsed. 
Some challenges I faced were trying to parse it correctly with the delimiter. At first, I was going through the text file by character 
but that didn't get me the full lines. I switched the getting it line by line and it worked.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)
One of the debugging challenges I had was when trying to parse the text file to create the story object.
I kept running into the problem of storing the wrong values and characters when in reality I should be storing strings.
I had to keep going and printing out what I was storing to see what I was doing wrong. Eventually I realized
that I should be looking at it line by line and splitting it whenever the delimiter was identified. This worked
and now my code is able to create the story object with the correct values.

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.
---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)
You arise from a long slumber after 100 years in a desolate cavern. Choose one of the two paths.
1.  You turn right and walk down the mountain path.
2.  You go straight forward and start to climb down from the mountain
    Enter choice:
    2

You go straight forward and start to climb down from the mountain
1.  You see a huge vulture while climbing down, should you attract its attention?
2.  Go down to the bottom ignoring the vulture
    Enter choice:
    2

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(?)` O(n) 
- **Searching for an event in the tree** → `O(?)`  O(n)
- **Game traversal efficiency** → `O(?)`  O(n)

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)
Reaching a leaf node is an edge case where I tested what would happen. When you reach a leaf node in this
game the game ends. The value is -1 for the leaf node. Another one is if the user enters something other than 1 or 2
for the options during the game. If they do type something else then the user will get an error message.

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

I did not add any extra features
---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
