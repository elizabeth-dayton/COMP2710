// Name: Elizabeth Dayton, ead0044.
// Partner: NONE.
// File Name: hw2.cpp
// Due Date: 7/7/2018.
// Collaboration: I did not use any external sources for this assignment.
// Problem: Calculate the monthly payments for a given loan an interest rate.

#include <iostream>
#include <iomanip>
using namespace std;

double balance = 0.0;
double yearly_interest_rate = 0.0;
double monthly_payments = 0.0;
double monthly_interest_rate = 0.0;
int month_counter = 0;
double total_interest = 0;

int main() {
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "Loan Amount: ";
    cin >> balance;
    cout << "Interest Rate (% per year): ";
    cin >> yearly_interest_rate;
    cout << "Monthly Payments: ";
    cin >> monthly_payments;
    
    monthly_interest_rate = (yearly_interest_rate / 12) / 100;
    double first_month_interest = monthly_interest_rate * balance;
    
    while (first_month_interest >= monthly_payments) {
        
        cout << "Monthly payment is not large enough to cover interest or is only enough to cover interest. Please enter a larger monthly payment: ";
        cin >> monthly_payments;
        
    }
        
    cout << "\n*******************************************************\n        Amortization Table\n*******************************************************\n";
    cout << left << setw(7) << "Month" << setw(10) << "Balance" << setw(9) << "Payment" << setw(6) << "Rate" << setw(10) << "Interest" << setw(9) << "Principal";
    cout << "\n" << left << setw(7)<< month_counter << "$" << setw(10) << balance << setw(9) << "N/A" << setw(6) << "N/A" << setw(10) << "N/A" << setw(9) << "N/A";
    
    while (balance > 0) {
        
        month_counter++;
        
        if ((balance * monthly_interest_rate) + balance < monthly_payments) {
            
            cout << "\n" << left << setw(7)<< month_counter << setw(11) << "$0" << "$" << setw(9) << (balance * monthly_interest_rate) + balance << setw(6) << monthly_interest_rate * 100 << "$" << setw(10) <<balance * monthly_interest_rate << "$" << setw(9) << balance - (balance * monthly_interest_rate);
            
            total_interest += balance * monthly_interest_rate;
            balance = 0;
           
            cout << "\n*******************************************************\n\nIt takes " << month_counter << " months to pay off the loan.\nTotal interest paid is: $" << total_interest;
            
        }
        
        else {
            
            double principal = monthly_payments - (balance * monthly_interest_rate) ;
            
        cout << "\n" << left << setw(7)<< month_counter << "$" << setw(10) << balance - principal << "$" << setw(9) <<monthly_payments << setw(6) << monthly_interest_rate * 100 <<  "$" << setw(10) << balance * monthly_interest_rate <<  "$" << setw(9) << principal;
            
            total_interest += balance * monthly_interest_rate;
            balance = balance - principal;
            
            
        }
        
    }
    
    return 0;
    
}
