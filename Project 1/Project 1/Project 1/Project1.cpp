//
// Name: Elizabeth Dayton, ead0044.
// Partner: NONE.
// File Name: hw6.cpp
// Due Date: 11/09/2018.
// Collaboration: I did not use any external sources for this assignment.
// Problem: create a text-based adventure game

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Player {
    
    public : string name;
    int intelligence;
    int time;
    double money;
    int stepsLeft;
    int score;
    
    public : Player (int intelligenceIn, int timeIn, double moneyIn) {
        
        intelligence = intelligenceIn;
        time = timeIn;
        money = moneyIn;
        stepsLeft = 20;
        
    }
    
    int getIntelligence() { return intelligence; }
    int getTime() { return time; }
    int getMoney() { return money; }
    int getStepsLeft() { return stepsLeft; }
    int getScore() { return intelligence*time*money; }
    string getName() { return name; }
    void setIntelligence(int intelligenceIn) { intelligence = intelligenceIn; }
    void setTime(int timeIn) { time = timeIn; }
    void setMoney(double moneyIn) { money = moneyIn; }
    void setStepsLeft(int stepsLeftIn) { stepsLeft = stepsLeftIn; }
    
};


class Encounters {
    
    Player* player;
    
    public : void playerMoves(Player* player) {
        
        srand((int)time(NULL));
        int num = rand() % 100 + 1;
        int timeLost = rand() % 3 + 1;

        player = player;
        
        player->setTime(player->getTime() - 1);
        player->setStepsLeft(player->getStepsLeft() - 1);
        
        cout << "\nYou move forward one step, and ...\n";
        
        if (num <= 25) { cout <<"\n Nothing happens!\n"; }
        
        if ( num > 25 && num <=55) { encounterPuzzle(player); }
        
        if ( num > 55 && num <= 65) {
            
            cout << "\nYou've encountered a professor!\n";
            cout << "\nYou've lost an additional " << timeLost << " time!\n";
            
            player->setTime(player->getTime() - timeLost);
            
            int gainIntelligence = rand() % 100 + 1;
            if (gainIntelligence <= 50) {
                
                player->setIntelligence(player->getIntelligence() + 3);
                cout << "\nYou've also gained an additional 3 intelligence!\n";
                
            }
            
        }
        
        if (num > 65 && num <= 75) {
            
            cout << "\nYou've encountered a fellow graduate student and they want to stop for a chat!\n";
            cout << "\nYou've lost an additional " << timeLost << " time!\n";
            
            player->setTime(player->getTime() - timeLost);
            
        }
        
        if (num > 75 && num <= 90) {
            
            cout << "\nYou've been attacked by grunt work!\n";
            cout << "\nYou've lost both time and intelligence!\n";
            
            player->setIntelligence(player->getIntelligence() - 2);
            player->setTime(player->getTime() - 2);
            
        }
        
        if (num > 90 && num <= 100) {
            
            cout << "\nYou have to grade some papers!\n";
            cout << "\nYou've lost some additional time, but you've also gained some money!\n";
            
            player->setTime(player->getTime() - 3);
            player->setMoney(player->getMoney() + 3);
            
        }
        
}
    
    void encounterPuzzle(Player* player) {
        
        srand((int)time(NULL));
        player = player;

        cout << "\nYou've encountered a puzzle! Answer correctly and you shall be rewarded, but answer incorrectly and you shall be punished.(Answer with 1, 2, or 3)\n";
        
        int answer;
        int number = rand() % 4 + 1;
        
        if ( number == 1) {
            
            cout << "\nNever resting, never still; moving silently from hill to hill; it does not walk, run, or trot; all is cool where it is not.\n\n1. The wind\n2. The sun\n3. The rain\n";
            cout << "\nAnswer: ";
            
            cin >> answer;
            
            if (answer != 2) {
                
                player->setIntelligence(player->getIntelligence() - 3);
                cout << "\nYou've answered incorrectly! You've lost 3 intelligence!\n";
                
            }
            else {
                
                player->setIntelligence(player->getIntelligence() + 3);
                cout << "\nYou've answered correctly! You've gained 3 intelligence!\n";
                
            }
            }
        
        if (number == 2) {
         
            cout << "\nWhat can bring back the dead; make you cry, make you laugh, make you young; is born in an instant, yet lasts a lifetime?\n\n1. A memory\n2. A name\n3. A joke\n";
            cout << "\nAnswer: ";
            
            cin >> answer;
            
            if (answer != 1) {
                
                player->setIntelligence(player->getIntelligence() - 3);
                cout << "\nYou've answered incorrectly! You've lost 3 intelligence!\n";
                
            }
            else {
                
                player->setIntelligence(player->getIntelligence() + 3);
                cout << "\nYou've answered correctly! You've gained 3 intelligence!\n";
                
            }
            
        }
        
        if (number == 3){
            
            cout << "\nWhat can run, but never walks; has a mouth, but never talks; has a head, but never weeps; has a bed, but never sleeps?\n\n1. A chariot\n2. A child\n3. A river\n";
            cout << "\nAnswer: ";
            
            cin >> answer;
            
            if (answer != 3) {
                
                player->setIntelligence(player->getIntelligence() - 3);
                cout << "\nYou've answered incorrectly! You've lost 3 intelligence!\n";
                
            }
            else {
                
                player->setIntelligence(player->getIntelligence() + 3);
                cout << "\nYou've answered correctly! You've gained 3 intelligence!\n";
                
            }
            
        }
        
        if (number == 4) {
            
            cout << "\nThis thing all things devour: birds, beasts, tress, flowers; gnaws iron, bites steel; grinds hard stones to meal; slays kings, ruins towns; and beats high mountains down!\n\n1. Armies\n2. Time\n3. Nature\n";
            cout << "\nAnswer: ";
            
            cin >> answer;
            
            if (answer != 2) {
                player->setIntelligence(player->getIntelligence() - 3);
                cout << "\nYou've answered incorrectly! You've lost 3 intelligence!\n";
                
            }
            else {
                
                player->setIntelligence(player->getIntelligence() + 3);
                cout << "\nYou've answered correctly! You've gained 3 intelligence!\n";
            }
            
        }
        
    }
    
};

class System {
    
    int num1 = rand() % 17 + 8;
    int num2 = rand() % 5 + 40;
    int num3 = rand() % 17 + 8;
    Player* player = new Player(num1, num2, num3);
    Encounters* encounter = new Encounters();
    
    public : void importScore(string nameIn, int scoreIn)
    
    {
        ofstream outStream;
        outStream.open("HighScores.txt", ios::app);
        outStream << nameIn << " " << scoreIn << "\n" << endl;
        outStream.close();
    }
    
    public : void menu() {
        
        int answer;
        string name;
        
        cout << "\nWhat is your name?";
        cin >> name;
        player->name = name;
        cout << "\n\n==================================================\n";
        cout << "|                Welcome " << name << "!                |\n";
        cout << "==================================================\n";
        
        cout << "\n1) Start a new game of Shelby Center and Dragons!";
        cout << "\n2) View top 10 high scores";
        cout << "\n3) Quit\n";
        cout << "\nPlease choose an option: ";
        cin >> answer;
        
        if (answer == 1) { startNewGame(); }
        if (answer == 2) {
            
            ifstream outStream;
            outStream.open("HighScores.txt");
            char ch;
            cout << "\n The High Scores are: \n";
            if(outStream.is_open())
            {
                while (!outStream.eof())
                {
                    
                    outStream >> ch;
                    cout << ch;
                }
            }
            else
            {
                cout << "No High Scores";
            }
            outStream.close();

            menu();
        }
        if (answer == 3) {
            cout << "\n\nQuitting game...";
            exit(1);
        }
    }
    
    void startNewGame() {
    
        int answer;
        
        cout << "\n\nEntering the game...\n";
        cout << "\nYou have: \n";
        cout << "\nIntelligence: " << player->getIntelligence();
        cout << "\nTime: " << player->getTime();
        cout << "\nMoney: $" << player->getMoney() << ".00";
        cout << "\n\nThe goal of the game is to reach the end of the 20-step long hall without any of your attributes reaching 0. Good luck!";
        
        
        while (player->getMoney() > 0 && player->getIntelligence() > 0 && player->getTime() > 0 && player->getStepsLeft() > 0) {
            
            cout << "\n\nYou are " << player->getStepsLeft() << " steps from the goal.   Time left: " << player->getTime() << "\n";
            cout << "\n1) Move forward (takes one unit of time, could be risky...)";
            cout << "\n2) Read techincal papers (boost intelligence, takes time)";
            cout << "\n3) Search for loose change (boost money, takes time)";
            cout << "\n4) View character";
            cout << "\n5) Quit the game\n";
            cout << "\nPlease choose an action: ";
            cin >> answer;
            if (answer == 1) { encounter->playerMoves(player); }
            if (answer == 2) { readTechnicalPapers(); }
            if (answer == 3) { searchForLooseChange(); }
            if (answer == 4) { viewCharacter(); }
            if (answer == 5){
                
                cout << "\n\nQuitting the game...";
                exit(1);
                
            }
        }
        
        if (player->getTime() <= 0) {
          
            cout << "\nYou've run out of time! You lose!";
            exit(1);
        }
        
        if (player->getIntelligence() <= 0) {
            
            cout << "\nYou've run out of intelligence! You lose!";
            exit(1);
        }
        if (player->getMoney() <= 0) {
            
            cout << "\nYou've run out of money! You lose!";
            exit(1);
        }
        else {
            
            System* menu = new System();
            
            cout << "\nYou've won the game! Congratualations! You scored " << player->getScore() << " points!";
            menu->importScore(player->getName(), player->getScore());
            exit(1);
        }
        
    }
    
    
    void readTechnicalPapers() {
        
        srand((int)time(NULL));
        int randNum = rand() % 3 + 1;
        
        cout << "\nYou read through some technical papers. You gain intelligence, but lose 2 units of time.";
        player->setIntelligence(player->getIntelligence() + randNum);
        player->setTime(player->getTime() - 2);
        
    }
    void searchForLooseChange() {
        
        srand((int)time(NULL));
        int randNum = rand() % 3 + 1;
        
        cout << "\nYou search for some loose change. You gain some money, but lose 2 units of time.";
        player->setMoney(player->getMoney() + randNum);
        player->setTime(player->getTime() - 2);
        
    }
    void viewCharacter(){
        
        cout << "\n\nYou have: \n";
        cout << "\nIntelligence: " << player->getIntelligence();
        cout << "\nTime: " << player->getTime();
        cout << "\nMoney: $" << player->getMoney() << ".00";
        
    }
    
    
};



int main() {
    
    srand((int)time(NULL));
    
    System* system = new System();
    system->menu();
    
}
