// Name: Elizabeth Dayton, ead0044.
// Partner: NONE.
// File Name: hw3.cpp
// Due Date: 9/14/2018.
// Collaboration: I did not use any external sources for this assignment.
// Problem: Determines the greatest puzzle-solver of all time!


# include <iostream>
# include <cstdlib>
# include <cassert>
# include <ctime>

using namespace std;

//const double ACCURACY_AARON = 1.0/3.0;
//const double ACCURACY_BOB = 0.5;
//const double ACCURACY_CHARLIE = 1.0;

bool at_least_two_alive(bool Aaron_alive, bool Bob_alive, bool Charlie_alive) {
    
    if (Aaron_alive && Bob_alive)
    {
        return true;
    }
    
    if (Aaron_alive && Charlie_alive)
    {
        return true;
    }
    
    if (Bob_alive && Charlie_alive)
    {
        return true;
    }
    
    return false;
}


void Aaron_shoots1(bool& target) {
    
    int shot = (rand() % 3);
    if (shot == 1) {
        
        target = false;
    }
}

void Aaron_shoots2(bool& target) {
    int shot1 = 0;
    int shot2 = (rand() % 2);
    if (shot1 == 0 && shot2 == 1) {
        
        target = false;
    }
}

void Bob_shoots(bool& target) {
    
    int shot = (rand() % 2);
    if (shot == 1) {
        
        target = false;
    }
}

void Charlie_shoots(bool& target) {
    
    target = false;
}

void test_at_least_two_alive(void) {
    
    cout << "Unit Testing 1: Function – at_least_two_alive()\n";
    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "\tCase passed ...\n";
    
    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "\tCase passed...\n";
    
    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "\tCase passed...\n";
    
    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "\tCase passed...\n";
    
}

void test_Aaron_shoots1(void) {
    
    //bool Aaron_alive = true;
    bool Bob_alive = true;
    bool Charlie_alive = true;
    
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    
    cout << "\tCase 1: Bob alive, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    
    Aaron_shoots1(Charlie_alive);
    
    if (Charlie_alive == false) {
        
        cout << "\t\tCharlie is dead.\n";
    }
    
    else {
        
        cout << "\t\tAaron misses.\n";
    }
    
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    
    Aaron_shoots1(Charlie_alive);
    
    if (!Charlie_alive) {
        
        cout << "\t\tCharlie is dead.\n";
    }
    
    else {
        
        cout << "\t\tAaron misses.\n";
    }

    cout << "\tCase 3: Bob alive, Charlie dead\n";
    cout << "\t\tAaron is shooting at Bob\n";
    
    Aaron_shoots1(Bob_alive);
    
    if (!Bob_alive) {
        
        cout << "\t\tBob is dead.\n";
    }
    
    else {
        
        cout << "\t\tAaron misses.\n";
    }
    
}

void test_Bob_shoots(void) {
    
    bool Aaron_alive = true;
    //bool Bob_alive = true;
    bool Charlie_alive = true;
    
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   
    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    
    Bob_shoots(Charlie_alive);
    
    if (!Charlie_alive) {
        
        cout << "\t\tCharlie is dead.\n";
    }
    
    else {
        
        cout << "\t\tBob misses.\n";
    }
    
    cout << "\tCase 2: Aaron dead, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    
    Bob_shoots(Charlie_alive);
    
    if (!Charlie_alive) {
        
        cout << "\t\tCharlie is dead.\n";
    }
    
    else {
        
        cout << "\t\tBob misses.\n";
    }
    
    cout << "\tCase 3: Aaron alive, Charlie dead\n";
    cout << "\t\tBob is shooting at Aaron\n";
    
    Bob_shoots(Aaron_alive);
    
    if (!Aaron_alive) {
        
        cout << "\t\tAaron is dead.\n";
    }
    
    else {
        
        cout << "\t\tBob misses.\n";
    }
    
}

void test_Charlie_shoots(void) {
    
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Charlie_alive)\n";
    
    cout << "\tCase 1: Aaron alive, Bob alive\n";
    cout << "\t\tCharlie is shooting at Bob\n";
    cout << "\t\tBob is dead.\n";
    
    cout << "\tCase 2: Aaron dead, Bob alive\n";
    cout << "\t\tCharlie is shooting at Bob\n";
    cout << "\t\tBob is dead.\n";
    
    cout << "\tCase 3: Aaron alive, Bob dead\n";
    cout << "\t\tCharlie is shooting at Aaron\n";
    cout << "\t\tAaron is dead.\n";
    
    
}

void test_Aaron_shoots2(void) //something wrong here {
    
    //bool Aaron_alive = true;
    bool Bob_alive = true;
    bool Charlie_alive = true;
    
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    
    cout << "\tCase 1: Bob alive, Charlie alive\n";
    cout << "\t\tAaron intentionally misses his first shot\n";
    cout << "\t\tBoth Bob and Charlie are alive.\n";

    cout << "\tCase 2: Bob dead, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    
    Aaron_shoots2(Charlie_alive);
    
    if (!Charlie_alive) {
        
        cout << "\t\tCharlie is dead.\n";
    }
    
    else {
        
        cout << "\t\tAaron misses.\n";
    }
    
    cout << "\tCase 3: Bob alive, Charlie dead\n";
    cout << "\t\tAaron is shooting at Bob\n";
    
    Aaron_shoots2(Bob_alive);
    
    if (!Bob_alive) {
        
        cout << "\t\tBob is dead.\n";
    }
    
    else {
        
        cout << "\t\tAaron misses.\n";
    }
}

int main()
{
    cout << "*** Welcome to Puzzlevania's Duel Simulator ***\n";
    
    test_at_least_two_alive();
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    test_Aaron_shoots1();
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    test_Bob_shoots();
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    test_Charlie_shoots();
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    test_Aaron_shoots2();
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    cout << "Ready to test strategy 1 (run 10000 times):\n";
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    srand((int)time(0));
    
    int AaronWin = 0, BobWin = 0, CharlieWin = 0;
    
    for (int i = 0; i < 10000; i++) {
        
        bool Aaron_alive = true, Bob_alive = true, Charlie_alive = true;
        
        while ((Aaron_alive && Bob_alive) || (Aaron_alive && Charlie_alive) || (Bob_alive && Charlie_alive)) {
            
            if (Charlie_alive) {
                
                Aaron_shoots1(Charlie_alive);
                
                if (!(Bob_alive || Charlie_alive)) {
                    
                    AaronWin++;
                }
            }
            
            else {
                
                Aaron_shoots1(Bob_alive);
                
                if (!(Bob_alive || Charlie_alive)) {
                    
                    AaronWin++;
                }
            }
            
            if (Bob_alive && Charlie_alive) {
                
                Bob_shoots(Charlie_alive);
                
                if (Charlie_alive) {
                    
                    Charlie_shoots(Bob_alive);
                }
            }
            
            else if (!Bob_alive && !Charlie_alive) {
                
            }
            
            else if (!Bob_alive && Aaron_alive) {
                
                Charlie_shoots(Aaron_alive);
                CharlieWin++;
            }
            
            else {
                
                Bob_shoots(Aaron_alive);
                
                if (!Aaron_alive)
                    BobWin++;
            }
        }
    }
    
    double AaronPercent = (AaronWin * .01);
    double BobPercent = (BobWin * .01);
    double CharliePercent = (CharlieWin * .01);
    
    std::cout << "Aaron's wins: " << AaronWin << "/10000 duels or " << AaronPercent << "%.\n";
    std::cout << "Bob's wins: " << BobWin << "/10000 duels or " << BobPercent << "%.\n";
    std::cout << "Charlie's wins: " << CharlieWin << "/10000 duels or " << CharliePercent << "%.\n\n";
    
    cout << "Ready to test strategy 2 (run 10000 times):\n";
    cout << "Press any key to continue...";
    cin.ignore().get();
    
    srand((int)time(0));
    
    int AaronWin2 = 0, BobWin2 = 0, CharlieWin2 = 0;
    
    for (int i = 0; i < 10000; i++) {
        
        bool Aaron_alive = true, Bob_alive = true, Charlie_alive = true;
        
        while ((Aaron_alive && Bob_alive) || (Aaron_alive && Charlie_alive) || (Bob_alive && Charlie_alive)) {
            
            if (Charlie_alive) {
                
                Aaron_shoots2(Charlie_alive);
                
                if (!(Bob_alive || Charlie_alive)) {
                    
                    AaronWin2++;
                }
            }
            
            else {
                
                Aaron_shoots2(Bob_alive);
                
                if (!(Bob_alive || Charlie_alive)) {
                    
                    AaronWin2++;
                }
            }
            
            if (Bob_alive && Charlie_alive) {
                
                Bob_shoots(Charlie_alive);
                
                if (Charlie_alive) {
                    
                    Charlie_shoots(Bob_alive);
                }
            }
            
            else if (!Bob_alive && !Charlie_alive) {
                
            }
            
            else if (!Bob_alive && Aaron_alive) {
                
                Charlie_shoots(Aaron_alive);
                CharlieWin2++;
            }
            
            else {
                
                Bob_shoots(Aaron_alive);
                if (!Aaron_alive)
                    BobWin2++;
            }
        }
    }
    
    double AaronPercent2 = (AaronWin2 * .01);
    double BobPercent2 = (BobWin2 * .01);
    double CharliePercent2 = (CharlieWin2 * .01);
    
    std::cout << "Aaron's wins: " << AaronWin2 << "/10000 duels or " << AaronPercent2 << "%.\n";
    std::cout << "Bob's wins: " << BobWin2 << "/10000 duels or " << BobPercent2 << "%.\n";
    std::cout << "Charlie's wins: " << CharlieWin2 << "/10000 duels or " << CharliePercent2 << "%.\n\n";
    
    if (AaronPercent > AaronPercent2) {
        
        cout << "Strategy 1 is better than Strategy 2.";
    }
    
    else {
        
        cout << "Strategy 2 is better than Strategy 1.";
    }
    
    return 0;
}

