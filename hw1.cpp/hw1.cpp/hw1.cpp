//  Name: Elizabeth Dayton , ead0044.
//  Partner: NONE.
//  File Name: hw1.cpp.
//  Due Date: 8/31/18.
//  Collaboration: I did not use any external sources for this assignment.
//  Problem: determine how much diet soda it is possible to drink
//           without dying as a result.

#include <iostream>
using namespace std;

const double RATIO = 0.001;
int user_weight = 0;
double lethal_kill_mouse = 0;
int mouse_weight = 0;
int number_of_sodas = 0;

int main() {
   
   cout << "What is the amount of artificial sweetner needed to kill a mouse: ";
   cin >> lethal_kill_mouse;
   cout << "\n\nWhat is the weight of the mouse: ";
   cin >> mouse_weight;
   cout << "\n\nWhat is the weight of the dieter: ";
   cin >> user_weight;
   number_of_sodas = (lethal_kill_mouse / mouse_weight) * (user_weight / RATIO);
   cout << "\n\nYou can drink "  << number_of_sodas << " diet soda without dying as a result.";
   return 0;
}
