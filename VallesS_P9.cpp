//2023F_CSCI221_VB Computer Science II
//Steve Valles Quiroz
//Project 9

//include libraries
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HiScores {
private:
//private variables for public functions
    vector<string> names;
    vector<int> scores;
    vector<string> dates;
public:
    void addScore(string name, int score, string date) {
        if(score < 100 || score > 10000) {
            cout << "Wrong input. Score has be between 100 and 10,000\n";
            return;
        }
        names.push_back(name);//add name to vector
        scores.push_back(score);//add score to vector
        dates.push_back(date);//add date to vector
    }

    void listScores() {
        // Create a temporary copy of the scores
        vector<int> tempScores = scores;

        //Sort the temporary scores in descending order
        sort(tempScores.begin(), tempScores.end(), greater<int>());//greater<int>() is a comparator that compares two integers in descending order

        // Print the high scores in sorted order
        for(int tempScore : tempScores) {
            // Find the index of the tempScore in the original scores vector
            auto it = find(scores.begin(), scores.end(), tempScore);//find() is a function that searches for an element in a vector

            // If the score is found, print the corresponding name and date
            if(it != scores.end()) {
                int index = distance(scores.begin(), it);
                cout << "Name: " << names[index] << ", Score: " << scores[index] << ", Date: " << dates[index] << "\n";

                // Remove the score from the original scores vector to handle duplicate scores
                scores.erase(it);
            }
        }
    }
};

int main() {
    HiScores scores; //Create a HiScores object named scores
    int input, score; //Store user input and score
    string name, date;//Store user name and date

    while(true) {
        cout << "Welcome! Chose an option...";//Prompt user to chose from 1 to 3
      
        cout << "1) Add a Hi-Score\n";//User will be prompted to case 1
        cout << "2) List Hi-Scores\n";//User will be prompted to case 2
        cout << "3) Quit\n";//User will exit
        cin >> input;

        switch(input) {
            case 1:
                cout << "Enter Name:\n";
                cin >> name;
                cout << "Enter Score:\n";
                cin >> score;
                cout << "Enter Date:\n";
                cin >> date;
                scores.addScore(name, score, date);//Call addScore function
                break;
            case 2:
                scores.listScores();//Call listScores function
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid option. Please choose a valid option.\n";
        }
    }

    return 0;
}


