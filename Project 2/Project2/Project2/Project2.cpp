/*
 * Author: Elizabeth Dayton, ead0044.
 * Partner: NONE.
 * File Name: Project1.cpp
 * Due Date: 12/7/18.
 * Collaboration: I did not use any external sources for this assignment.
 * Problem: Create a bank terminal.
 */

#include <iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

char username[6];
int password = 0000;
string role;
int token2;

struct Client {
    char *username;
    int password;
    string role;
    };

Client Clients[10];
int size = 1;

struct ClientInformation {
    string name;
    string address;
    int socialSecurity;
    string employer;
    int income;
};

ClientInformation Clientele[10];
int clienteleSize = 0;

struct Account {
    string name;
    int accountNumber;
    string accountType;
    int balance;
};

Account AccountDetails[10];
int accountSize = 0;

void tellerTerminalSystem();
void branchTellerTerminalSystem();
void addBranchStaff();
void branchLoginDispay();
void changePassword();
void clientTerminal();
void addAccount();

void saveInfo() {
    
    ofstream myfile1 ("client-info.txt");
    ofstream myfile2 ("account-info.txt");
    myfile1.open ("client-info.txt", ios::out | ios::app);
    
    if (myfile1.is_open()) {
        
        myfile1 << "Name: " << Clientele[0].name << endl;
        myfile1 << "Address: " << Clientele[0].address << endl;
        myfile1 << "Social: xx-xxx-xxxx" << endl;
        myfile1 << "Employer: " << Clientele[0].employer << endl;
        myfile1 << "Income: " << Clientele[0].income << endl;
        
        myfile1 << "Name: " << Clientele[1].name << endl;
        myfile1 << "Address: " << Clientele[1].address << endl;
        myfile1 << "Social: xx-xxx-xxxx" << endl;
        myfile1 << "Employer: " << Clientele[1].employer << endl;
        myfile1 << "Income: " << Clientele[1].income << endl;
        
        myfile1.close();
    }
    
    myfile2.open ("account-info.txt", ios::out | ios::app);
    
    if (myfile2.is_open()) {
        
        myfile2 << "Account Number: " << AccountDetails[0].accountNumber << endl;
        myfile2 << "Account Type: " << AccountDetails[0].accountType << endl;
        myfile2 << "Balance: " << AccountDetails[0].balance << endl;
        
        myfile2 << "Account Number: " << AccountDetails[1].accountNumber << endl;
        myfile2 << "Account Type: " << AccountDetails[1].accountType << endl;
        myfile2 << "Balance: " << AccountDetails[1].balance << endl;
        
        myfile2.close();
    }
    
    cout << "Client information has been saved in the client-info file; account information has been saved in the account-info file!\n";
    cout << "Press any key to continue...";
    cin.ignore().get();
}

void manageBalance() {
    
    int option1, deposit, withdrawal;
    
    cout << "1) Deposit\n";
    cout << "2) Withdrawal\n";
    cout << "3) Cancel\n";
    
    cin >> option1;
    
    switch(option1) {
            
        case 1:
            cout << "Deposit Amount: ";
            cin >> deposit;
            AccountDetails[token2].balance += deposit;
            cout << "Balance of account " << AccountDetails[token2].accountNumber << " is: " <<  AccountDetails[token2].balance << endl;
            manageBalance();
            
        case 2:
            cout << "Withdrawal Amount: ";
            cin >> withdrawal;
            AccountDetails[token2].balance -= withdrawal;
            cout << "Balance of account " << AccountDetails[token2].accountNumber << " is: " <<  AccountDetails[token2].balance << endl;
            manageBalance();
            
        case 3:
            clientTerminal();
    }
    
}

void manageAccount() {
    
    int token, confirm;
    int counter = 1;
    
    cout << "Which Account will be managed? \n";
    
    for (int i=1; i < clienteleSize+1; i++) {
        
        cout << counter << ": " << AccountDetails[i].name << "\n";
        counter++;
        i++;
    }
    
    cin >> token;
    token2 = token;
    
    if (token > 10) {
        
        cout << "Error that account is not in our system";
        cout << "1) Manage Account\n";
        cout << "2) Cancel";
        cin >> confirm;
        
        if (confirm == 1)
        {
            manageAccount();
        }
        
        if (confirm == 2)
        {
            clientTerminal();
        }
        
    }
    
    cout << "Manage account " << AccountDetails[token].accountNumber << " for " << AccountDetails[token].name << "...\n";
    manageBalance();
    
    
}

void editInfo() {
    
    int token, confirm;
    int counter = 1;
    
    cout << "Choose a Client: \n";
    
    for (int i=1; i < clienteleSize+1; i++) {
        
        cout << counter << ": " << Clientele[i].name << "\n";
        counter++;
        i++;
    }
    
    cin >> token;
    
    if (token > 10) {
        
        cout << "Error, that option does not make sense. Please try again.";
        addAccount();
    }
    
    cout << "Displaying " << Clientele[token].name << "'s information: \n";
    cout << "Address: " << Clientele[token].address << "\n";
    cout << "Social Security: " << Clientele[token].socialSecurity << "\n";
    cout << "Employer: " << Clientele[token].employer << "\n";
    cout << "Annual Income: " << Clientele[token].income << "\n";
    
    cout << "Client " << Clientele[token].name << "'s information will be updated...\n";
    cout << "1) Confirm\n";
    cout << "2) Cancel\n";
    cin >> confirm;
    
    if (confirm == 1) {
        
        string updatedAddress, updatedEmployer;
        int updatedSocialSecurity, updatedIncome;
        
        cout << "Address: ";
        cin.ignore();
        getline(cin, updatedAddress);
        cout << "Social Security: ";
        cin >> updatedSocialSecurity;
        cout << "Employer: ";
        cin >> updatedEmployer;
        cout << "Income: ";
        cin >> updatedIncome;
        
        Clientele[token].address = updatedAddress;
        Clientele[token].socialSecurity = updatedSocialSecurity;
        Clientele[token].employer = updatedEmployer;
        Clientele[token].income = updatedIncome;
        
        cout << "Client " << Clientele[token].name << "'s information was updated!\n";
        cout << "Press any key to continue...";
        cin.ignore().get();
        clientTerminal();
    }
    
    if (confirm == 2) {
        
        cout << "Process cancelled...\n";
        clientTerminal();
    }
}

void addAccount() {
    
    int counter = 1;
    int token, newAccountNumber, newBalance;
    string newAccountType;
    
    cout << "Choose a Client: \n";
    
    for (int i=1; i < clienteleSize+1; i++) {
        
        cout << counter << ": " << Clientele[i].name << "\n";
        counter++;
        i++;
    }
    
    cin >> token;
    switch(token) {
            
        case 1:
            cout << "A new account will be created for " << Clientele[1].name << "...\n";
            cout << "Account Number: ";
            cin >> newAccountNumber;
            cout << "Account Type: ";
            cin >> newAccountType;
            cout << "Account Balance: ";
            cin >> newBalance;
            AccountDetails[1].name = Clientele[1].name;
            AccountDetails[1].accountNumber = newAccountNumber;
            AccountDetails[1].accountType = newAccountType;
            AccountDetails[1].balance = newBalance;
            break;
            
        case 2:
            cout << "A new account will be created for " << Clientele[2].name << "...\n";
            cout << "Account Number: ";
            cin >> newAccountNumber;
            cout << "Account Type: ";
            cin >> newAccountType;
            cout << "Account Balance: ";
            cin >> newBalance;
            AccountDetails[2].name = Clientele[2].name;
            AccountDetails[2].accountNumber = newAccountNumber;
            AccountDetails[2].accountType = newAccountType;
            AccountDetails[2].balance = newBalance;
            break;
            
        case 3:
            cout << "A new account will be created for " << Clientele[3].name << "...\n";
            cout << "Account Number: ";
            cin >> newAccountNumber;
            cout << "Account Type: ";
            cin >> newAccountType;
            cout << "Account Balance: ";
            cin >> newBalance;
            AccountDetails[3].name = Clientele[3].name;
            AccountDetails[3].accountNumber = newAccountNumber;
            AccountDetails[3].accountType = newAccountType;
            AccountDetails[3].balance = newBalance;
            break;
            
        case 4:
            cout << "A new account will be created for " << Clientele[4].name << "...\n";
            cout << "Account Number: ";
            cin >> newAccountNumber;
            cout << "Account Type: ";
            cin >> newAccountType;
            cout << "Account Balance: ";
            cin >> newBalance;
            AccountDetails[4].name = Clientele[4].name;
            AccountDetails[4].accountNumber = newAccountNumber;
            AccountDetails[4].accountType = newAccountType;
            AccountDetails[4].balance = newBalance;
            break;
            
        case 5:
            cout << "A new account will be created for " << Clientele[5].name << "...\n";
            cout << "Account Number: ";
            cin >> newAccountNumber;
            cout << "Account Type: ";
            cin >> newAccountType;
            cout << "Account Balance: ";
            cin >> newBalance;
            AccountDetails[5].name = Clientele[5].name;
            AccountDetails[5].accountNumber = newAccountNumber;
            AccountDetails[5].accountType = newAccountType;
            AccountDetails[5].balance = newBalance;
            break;
            
        case 6:
            cout << "A new account will be created for " << Clientele[6].name << "...\n";
            cout << "Account Number: ";
            cin >> newAccountNumber;
            cout << "Account Type: ";
            cin >> newAccountType;
            cout << "Account Balance: ";
            cin >> newBalance;
            AccountDetails[6].name = Clientele[6].name;
            AccountDetails[6].accountNumber = newAccountNumber;
            AccountDetails[6].accountType = newAccountType;
            AccountDetails[6].balance = newBalance;
            break;
            
        case 7:
            cout << "A new account will be created for " << Clientele[7].name << "...\n";
            cout << "Account Number: ";
            cin >> newAccountNumber;
            cout << "Account Type: ";
            cin >> newAccountType;
            cout << "Account Balance: ";
            cin >> newBalance;
            AccountDetails[7].name = Clientele[7].name;
            AccountDetails[7].accountNumber = newAccountNumber;
            AccountDetails[7].accountType = newAccountType;
            AccountDetails[7].balance = newBalance;
            break;
            
        case 8:
            cout << "A new account will be created for " << Clientele[8].name << "...\n";
            cout << "Account Number: ";
            cin >> newAccountNumber;
            cout << "Account Type: ";
            cin >> newAccountType;
            cout << "Account Balance: ";
            cin >> newBalance;
            AccountDetails[8].name = Clientele[8].name;
            AccountDetails[8].accountNumber = newAccountNumber;
            AccountDetails[8].accountType = newAccountType;
            AccountDetails[8].balance = newBalance;
            break;
            
        case 9:
            cout << "A new account will be created for " << Clientele[9].name << "...\n";
            cout << "Account Number: ";
            cin >> newAccountNumber;
            cout << "Account Type: ";
            cin >> newAccountType;
            cout << "Account Balance: ";
            cin >> newBalance;
            AccountDetails[9].name = Clientele[9].name;
            AccountDetails[9].accountNumber = newAccountNumber;
            AccountDetails[9].accountType = newAccountType;
            AccountDetails[9].balance = newBalance;
            break;
            
        case 10:
            cout << "A new account will be created for " << Clientele[10].name << "...\n";
            cout << "Account Number: ";
            cin >> newAccountNumber;
            cout << "Account Type: ";
            cin >> newAccountType;
            cout << "Account Balance: ";
            cin >> newBalance;
            AccountDetails[10].name = Clientele[10].name;
            AccountDetails[10].accountNumber = newAccountNumber;
            AccountDetails[10].accountType = newAccountType;
            AccountDetails[10].balance = newBalance;
            break;
    }
    
    if (token > 10) {
        
        cout << "Error – The client is not in the system!";
        addAccount();
    }
    
    cout << "A new account was created!\n";
    cout << "Press any key to continue...";
    cin.ignore().get();
    clientTerminal();
    
}

void addClient() {
    
    string newName, newAddress, newEmployer;
    int newSocial, newIncome;
    clienteleSize += 1;
    
    cout << "A new Client will be added:";
    
    cout << "\nClient Name: ";
    cin.ignore();
    getline(cin, newName);
    cout << "Address: ";
    cin.ignore();
    getline(cin, newAddress);
    cout << "Social Security number: ";
    cin >> newSocial;
    cout << "Employer: ";
    cin.ignore();
    getline(cin, newEmployer);
    cout << "Annual Income: ";
    cin >> newIncome;
    
    Clientele[clienteleSize].name = newName;
    Clientele[clienteleSize].address = newAddress;
    Clientele[clienteleSize].socialSecurity = newSocial;
    Clientele[clienteleSize].employer = newEmployer;
    Clientele[clienteleSize].income = newIncome;
    
    cout << "\n";
    cout << "A new client was added!\n";
    cout << "Press any key to continue...";
    cin.ignore().get();
    clientTerminal();
    
}

void clientTerminal() {
    
    int option;
    
    cout << "==============================================================================\n";
    cout << "|             Teller Terminal System - Client & Account Management            |\n";
    cout << "==============================================================================\n";
    
    cout << "1) Add a Client \n";
    cout << "2) Add an Account \n";
    cout << "3) Edit Client Information \n";
    cout << "4) Manage an Account \n";
    cout << "5) Save Client and Account Information \n";
    cout << "6) Exit \n";
    cout << "\t Please choose an option: ";
    cin >> option;
    
    switch(option) {
            
        case 1:
            addClient();
            break;
        case 2:
            addAccount();
            break;
        case 3:
            editInfo();
            break;
        case 4:
            manageAccount();
            break;
        case 5:
            saveInfo();
            break;
        case 6:
            break;
    }
    
}
void branchTellerTerminalSystem() {
    
    int option;
    
    cout << "==============================================================================\n";
    cout << "|               Teller Terminal System - Branch Administration               |\n";
    cout << "==============================================================================\n";
    
    cout << "1) Client and Account Management \n";
    cout << "2) Change Password \n";
    cout << "3) Exit \n";
    cout << "\t Please choose an option: ";
    cin >> option;
    
    switch(option)
    {
        case 1:
            clientTerminal();
            break;
        case 2:
            changePassword();
            break;
        case 3:
            break;
    }
}

void changePassword() {
    
    int newPassword, token;
    int counter = 1;
    
    cout << "New Password: ";
    cin >> newPassword;
    
    if (password == newPassword) {
        
        cout << "Your new password must be different from the old one!\n";
        changePassword();
    }
    
    cout << "Which user's password would you like to change? \n";
    
    for (int i=0; i < size+1; i++) {
        
        cout << counter << ": " << Clients[i].username << "\n";
        counter++;
        i++;
    }
    cin >> token;
    switch(token) {
            
        case 1:
            Clients[1].password = newPassword;
            break;
            
        case 2:
            Clients[2].password = newPassword;
            break;
            
        case 3:
            Clients[3].password = newPassword;
            break;
            
        case 4:
            Clients[4].password = newPassword;
            break;
            
        case 5:
            Clients[5].password = newPassword;
            break;
            
        case 6:
            Clients[6].password = newPassword;
            break;
            
        case 7:
            Clients[7].password = newPassword;
            break;
            
        case 8:
            Clients[8].password = newPassword;
            break;
            
        case 9:
            Clients[9].password = newPassword;
            break;
            
        case 10:
            Clients[10].password = newPassword;
            break;
    }
    cout << "Password was changed!\n";
    cout << "Press any key to continue...";
    cin.ignore().get();
    tellerTerminalSystem();
}

void deleteClient() {
    
    int confirm, token;
    int counter = 1;
    
    cout << "Delete a user. Which user would you like to delete? \n";
    
    for (int i=0; i < size+1; i++) {
        
        cout << counter << ": " << Clients[i].username << "\n";
        counter++;
        i++;
    }
    
    cin >> token;
    
    cout << "1) Confirm\n";
    cout << "2) Cancel\n";
    cin >> confirm;
    
    if (confirm == 1) {
        
        switch(token)
        {
            case 1:
                Clients[1].username = NULL;
                Clients[1].password = 0000;
                Clients[1].role = "";
                break;
                
            case 2:
                Clients[2].username = NULL;
                Clients[2].password = 0000;
                Clients[2].role = "";
                break;
                
            case 3:
                Clients[3].username = NULL;
                Clients[3].password = 0000;
                Clients[3].role = "";
                break;
                
            case 4:
                Clients[4].username = NULL;
                Clients[4].password = 0000;
                Clients[4].role = "";
                break;
                
            case 5:
                Clients[5].username = NULL;
                Clients[5].password = 0000;
                Clients[5].role = "";
                break;
                
            case 6:
                Clients[6].username = NULL;
                Clients[6].password = 0000;
                Clients[6].role = "";
                break;
                
            case 7:
                Clients[7].username = NULL;
                Clients[7].password = 0000;
                Clients[7].role = "";
                break;
                
            case 8:
                Clients[8].username = NULL;
                Clients[8].password = 0000;
                Clients[8].role = "";
                break;
                
            case 9:
                Clients[9].username = NULL;
                Clients[9].password = 0000;
                Clients[9].role = "";
                break;
                
            case 10:
                Clients[10].username = NULL;
                Clients[10].password = 0000;
                Clients[10].role = "";
                break;
                
                
        }
        size--;
        cout << "Press any key to continue...";
        cin.ignore().get();
        tellerTerminalSystem();
        
    }
    
    
    if (confirm == 2) {
        
        cout << "Progress Cancelled.\n";
        tellerTerminalSystem();
    }
    
    if (confirm == 0 || confirm > 2) {
        
        cout << "You entered an unknown option number. Please choose again.\n\n";
        addBranchStaff();
    }
}


void addBranchStaff() {
    
    char newUsername[6];
    int newPassword, role, confirm;
    string userRole;
    
    cout << "User Name: ";
    cin >> newUsername;
    cout << "Password: ";
    cin >> newPassword;
    
    cout << "Role (1 – Administrator; 2 – Branch Staff): ";
    cin >> role;
    
    if (role == 1) {
        
        userRole = "System Administrator";
    }
    
    if (role == 2) {
        
        userRole = "Branch Staff";
    }
    
    if (role == 0 || role > 2) {
        
        cout << "You entered an unknown option number. Please choose again.\n\n";
        addBranchStaff();
    }
    
    cout << "1) Confirm\n";
    cout << "2) Cancel\n";
    cin >> confirm;
    
    if (confirm == 1) {
        
        size+=1;
        Clients[size].username = newUsername;
        Clients[size].password = newPassword;
        Clients[size].role = userRole;
        
        cout << "A new branch staff was added!\n";
        cout << "User Name: " << newUsername << "\tRole: " << userRole << endl;
        cout << "Press any key to continue...";
        cin.ignore().get();
        
        tellerTerminalSystem();
    }
    
    if (confirm == 2) {
        
        size--;
        cout << "Progress Cancelled.\n";
        tellerTerminalSystem();
    }
    
    if (confirm == 0 || confirm > 2) {
        
        cout << "You entered an unknown option number. Please choose again.\n\n";
        addBranchStaff();
    }
    
    
}

void branchLoginDispay() {
    
    char newUsername[6];
    int newPassword;
    
    cout << "==============================================================================\n";
    cout << "|                Login to Access the Teller Terminal System                   |\n";
    cout << "==============================================================================\n";
    
    cout << "User Name: ";
    cin >> newUsername;
    cout << "Password: ";
    cin >> newPassword;
    
    if (newPassword == Clients[2].password || newPassword == Clients[3].password || newPassword == Clients[4].password) {
        
        branchTellerTerminalSystem();
    }
    else {
        
        cout << "It seems you've entered the wrong username or password. Please try again.\n";
        branchLoginDispay();
    }
    
}

void displayBranchStaff() {
    
    size++;
    for (int i=0; i < size+1; i++) {
        
        cout << "User Name: " << Clients[i].username << "\tPassword: " << Clients[i].password << "\tRole: " << Clients[i].role << "\n";
        i++;
    }
    
    cout << "Press any key to continue...";
    cin.ignore().get();
    tellerTerminalSystem();
}

void tellerTerminalSystem() {
    
    int option;
    
    cout << "==============================================================================\n";
    cout << "|               Teller Terminal System - System Administration                |\n";
    cout << "==============================================================================\n";
    
    cout << "1) Client and Account Management \n";
    cout << "2) Add a Branch Staff Member \n";
    cout << "3) Delete a Branch Staff Member \n";
    cout << "4) Display Branch Staff \n";
    cout << "5) Change Password \n";
    cout << "6) Exit \n";
    cout << "\t Please choose an option: ";
    cin >> option;
    
    switch(option) {
            
        case 1:
            branchLoginDispay();
            break;
        case 2:
            addBranchStaff();
            break;
        case 3:
            deleteClient();
            break;
        case 4:
            displayBranchStaff();
            break;
        case 5:
            changePassword();
            break;
        case 6:
            break;
    }
}

void loginDispay() {
    
    cout << "==============================================================================\n";
    cout << "|                Login to Access the Teller Terminal System                   |\n";
    cout << "==============================================================================\n";
    
    cout << "User Name: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    
    if (strcmp(username, "admin") && (password != 0000)) {
        
        cout << "The username or password is incorrect. Please try again.\n";
        loginDispay();
    }
    else {
        
        tellerTerminalSystem();
    }
    
    
}

void loginMenu() {
    
    int loginTrigger;
    
    cout << "==============================================================================\n";
    cout << "|                Welcome to the Auburn Branch of Tiger Bank                  |\n";
    cout << "==============================================================================\n";
    
    cout << "1) Login\n";
    cout << "2) Quit\n";
    cout << "\t Please choose an option: ";
    cin >> loginTrigger;
    
    if (loginTrigger > 2) {
        
        cout << "You entered an unknown option number. Please choose again.\n\n";
        loginMenu();
    }
    
    switch(loginTrigger) {
            
        case 1:
            loginDispay();
            break;
            
        case 2:
            exit(1);
            break;
    }
}

int main() {
    
    Clients[0].username = (char*) "admin";
    Clients[0].password = 0000;
    Clients[0].role = "System Administrator";
    
    /*
     * Tests commented out for program flow, outputs recorded on Project2_tests.txt file
     * test_addBranch();
     * test_addClient();
     * test_deleteBranch();
     * test_deletelClient();
     * test_changePassword();
     * test_editInfo();
     * test_manageAccount
     */
    loginMenu();
}
