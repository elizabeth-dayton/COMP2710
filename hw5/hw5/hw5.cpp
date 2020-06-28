//
// Name: Elizabeth Dayton, ead0044.
// Partner: NONE.
// File Name: hw5.cpp
// Due Date: 10/5/2018.
// Collaboration: I did not use any external sources for this assignment.
// Problem: creates a trivia game

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//#define UNIT_TESTING

struct TriviaNode {
 
    TriviaNode* next_question;
    string question;
    string answer;
    int value;

};


int number_of_questions;

TriviaNode* initialize_trivia_game();
TriviaNode* add_trivia_question(TriviaNode*);
void quiz_user(TriviaNode*,  int&, int);
#ifdef UNIT_TESTING

void initialize_trivia_game_test();
void add_trivia_question_test();
void quiz_user_test();

int main() {
    cout << "*** This is a debugging version ***\n";
    
    TriviaNode* quiz = initialize_trivia_game();
    int score{0};
    
    cout << "Unit Test Case 1: Ask no question. The program"
    << " should give a warning message.\n";
    quiz_user(quiz, score, 0);
    
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list."
    << " The tester enters an incorrect answer.\n";
    quiz_user(quiz, score, 1);
    assert(score == 0);
    
    cout << "Unit Test Case 2.2: Ask 1 question in the linked list."
    << " The tester enters a correct answer.\n";
    quiz_user(quiz, score, 1);
    assert(score != 0);
    
    cout << "Unit Test Case 3: Ask all the questions of the last"
    << " trivia in the linked list. The tester should check that"
    << " three questions are asked.\n";
    quiz_user(quiz, score, number_of_questions);
    
    cout << "Unit Test Case 4: Ask five questions in the linked list."
    << " The program should give a warning message because"
    << " their are not five questions in the testing list.\n";
    quiz_user(quiz, score, 5);
    
    cout << "*** End of the Debugging Version ***\n";
}

#else
    
int main() {
    
    cout << "*** Welcome to Elizabeth Dayton's Trivia Quiz Game ***\n";
    
    TriviaNode* list = nullptr;
    string user_input;
    
    do {
        
        list = initialize_trivia_game();
        list = add_trivia_question(list);
        cout << "Continue? (Yes/No): ";
        getline(cin, user_input);
        }
    while(user_input != "No" && user_input != "no" && user_input != "n");
    
    int score{};
    quiz_user(list, score, number_of_questions);
    
    cout << "\nYou scored " << score
    << " points.\n";
    cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***";
    

    return 0;
}

#endif

TriviaNode* initialize_trivia_game() {
    
    TriviaNode* question = new TriviaNode();
    question->question = "How long was the shortest war on record? (Hint: how many minutes)";
    question->answer = "38";
    question->value = 100;
    question->next_question = nullptr;
    number_of_questions++;
    
    TriviaNode* prev = question;
    question = new TriviaNode();
    question->question = "What was Bank of America's original name?"
    "(Hint: Bank of Italy or Bank of Germany)?";
    question->answer = "Bank of Italy";
    question->value = 50;
    question->next_question = prev;
    number_of_questions++;
    
    prev = question;
    question = new TriviaNode();
    question->question = "What is the best-selling video game of all"
    " time? (Hint: Call of Duty or Wii Sports)?";
    question->answer = "Wii Sports";
    question->value = 50;
    question->next_question = prev;
    number_of_questions++;
    
    return question;
}

TriviaNode* add_trivia_question(TriviaNode* list) {
    TriviaNode* question = new TriviaNode();
    
    cout << "Enter a question: ";
    getline(cin, question->question);
    
    cout << "Enter an answer: ";
    getline(cin, question->answer);
    
    cout << "Enter award points: ";
    string temp_value;
    getline(cin, temp_value);
    question->value = stoi(temp_value);
    
    TriviaNode* prev = list;
    TriviaNode* current = list;
    
    while(current) {
        prev = current;
        current = current->next_question;
    }
    
    if (prev) {
        
        prev->next_question = question;
    }
    
    else {
        
        list = question;
    }
    
    number_of_questions++;
    
    return list;
}

void quiz_user(TriviaNode* question, int& score, int num_questions) {
    string user_ans;
    
    if (num_questions < 1) {
        cerr << "Warning - The number of trivia to be asked"
        << " must equal to or larger than 1.\n";
        return;
    }
    
    if (num_questions > number_of_questions) {
        cerr << "Warning - There are only three trivia in the list.\n";
        return;
    }
    
    for (int i = 0; i < num_questions && question; i++) {
        
        cout << "Question: " << question->question
        << endl;
        
        cout << "Answer: ";\
        getline(cin, user_ans);
        
        if (question->answer == user_ans) {
            cout << "Your answer is correct. You"
            << " recieve " << question->value << " points.\n";
            score += question->value;
            question = question->next_question;
        }
        
        else {
            cout << "Your answer is incorrect. The correct answer is: "
            << question->answer << endl;
            
            question = question->next_question;
        }
    }
}
