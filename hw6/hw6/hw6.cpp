//
// Name: Elizabeth Dayton, ead0044.
// Partner: NONE.
// File Name: hw6.cpp
// Due Date: 10/19/2018.
// Collaboration: I did not use any external sources for this assignment.
// Problem: create a doctor class

#include<cassert>
#include<iostream>
#include<string>
using namespace std;

class doctor_t {
private:
    
    struct exp_array_t {
        
        string* elements;
        int size;
        int max_size;
        
        exp_array_t()
        try {
            elements = new string[1];
            size = 0;
            max_size = 1;
        }
        catch(...) {
            
            cout << "Out of memory. Exiting." << endl;
            exit(1);
        }
        
        ~exp_array_t() {
            delete[] elements;
        }
        
        exp_array_t& operator=(exp_array_t& input) {
            
            delete[] elements;
            
            elements = new string[input.max_size];
            for (int i = 0; i < input.size; i++)
                elements[i] = input[i];
            
            size = input.size;
            max_size = input.max_size;
            
            return *this;
        }
        
        void flush() {
        delete[] elements;
            elements = new string[1];
            size = 0;
            max_size = 1;
        }
        
        void expand_array()
        try {
           
            max_size = max_size * 2;
            string* temp = new string[max_size];

            for (int i = 0; i < size; i++)
                temp[i] = elements[i];
            
            delete[] elements;
            elements = &temp[0];
        }
        catch(...) {
           
            cout << "Out of memory. Exiting." << endl;
            exit(1);
        }

        void push_back(string elem) {
            if (size == max_size)
                expand_array();

            elements[size] = elem;
            size++;
        }
        
        string& operator[](int i) {
            return elements[i];
        }
    };
    string name;
    exp_array_t patient_list;
public:

    doctor_t()
    try
    :name{}, patient_list{}
    {
    }
    catch(...) {
        
        cout << "Out of memory. Exiting." << endl;
        exit(1);
        }
        
        ~doctor_t() {
            
        }

        doctor_t& operator=(doctor_t& rvalue) {
            this->set_doctor_name(rvalue.name);
            patient_list = rvalue.patient_list;
            return *this;
        }

        void user_init_doctor();

        void print_doctor_t() {
            cout << "Doctor " << name
            << endl << "Patients: " << endl;

            for (int i = 0; i < get_num_patients(); i++)
                cout << '\t' << patient_list[i] << endl;
        }
        void reset_patient_load() {
            patient_list.flush();
        }

        int get_num_patients() {
            return patient_list.size;
        }

        string& get_doctor_name() {
            return name;
        }

        string& get_patient_x(int i) {
            if (i > get_num_patients() || i < 0) {
                cout << "Dr. " << name
                << " does not have a patient "
                << i << endl;
                
                return name;
            }
            
            return patient_list[i];
        }

        void add_patient(string name) {
            patient_list.push_back(name);
        }

        void set_doctor_name(string name) {
            this->name = name;
        }
        };

        void doctor_t::user_init_doctor() {
 
            reset_patient_load();
            
            cout << "User initalization of a doctor." << endl
            << "Enter name of doctor: ";
            getline(cin, name);
            cin.clear();
            
            char user_input{};
            cout << "Would you like to create patient(s) for"
            << " Doctor " << name << ". Yes/No (y/n)? ";
            cin >> user_input;
            (cin.peek() == '\r') ? cin.ignore() : cin;
            (cin.peek() == '\n') ? cin.ignore() : cin;
            
            switch(user_input) {
                case 'y':
                case 'Y':
                    string temp;
                    do {
                        cout << "Enter name of patient: ";
                        getline(cin, temp);
                        
                        patient_list.push_back(temp);
                        
                        cout << "Would you like to create more patient(s) for"
                        << " Doctor " << name << ". Yes/No (y/n)? ";
                        cin >> user_input;
                        (cin.peek() == '\r') ? cin.ignore() : cin;
                        (cin.peek() == '\n') ? cin.ignore() : cin;
                    } while(user_input != 'n' && user_input != 'N');
            }
        }
        
        
#define UNIT_TESTING
        
#ifdef UNIT_TESTING

        void test_constructor();
        void test_equ_operator();
        void test_user_init();
        void test_print();
        void test_reset();
        
        int main() {
            cout << "*** Unit testing for the doctor_t class ***"
            << endl << "***    Author: Elizabeth Dayton     ***"
            << endl << "***   Email: ead0044@auburn.edu   ***"
            << endl;
            
            test_constructor();
            test_user_init();
            test_equ_operator();
            test_print();
            test_reset();
            
            cout << "*** End of unit testing for doctor_t class ***" << endl;
        }
        
        void test_constructor() {
            cout << "-> Testing doctor_t constructor:" << endl;
            doctor_t chad{};
            assert(chad.get_num_patients() == 0);
            assert(chad.get_doctor_name() == string{});
            cout << "\t+ Passed..." << endl;
        }
        
        void test_user_init() {
            cout << "-> Testing user initalization. Please do the following:" << endl
            << "\t- Enter no doctor name" << endl
            << "\t- Enter no patients" << endl;
            
            doctor_t chad{};
            chad.user_init_doctor();
            
            assert(chad.get_doctor_name() == string{});
            assert(chad.get_num_patients() == 0);
            
            cout << "-> Testing user initalization. Please do the following:" << endl
            << "\t- Enter a doctor name (Chad Oval)" << endl
            << "\t- Enter no patients" << endl;
            
            chad.user_init_doctor();

            assert(chad.get_doctor_name() == "Chad Oval");
            assert(chad.get_num_patients() == 0);
            
            cout << "-> Testing user initalization. Please do the following:" << endl
            << "\t- Enter a doctor name (Chad Oval)" << endl
            << "\t- Enter one patient (Fyodor Rominov)" << endl;
            
            chad.user_init_doctor();

            assert(chad.get_doctor_name() == "Chad Oval");
            assert(chad.get_num_patients() == 1);
            assert(chad.get_patient_x(0) == "Fyodor Rominov");
            
            cout << "-> Testing user initalization. Please do the following:" << endl
            << "\t- Enter a doctor name (Chad Oval)" << endl
            << "\t- Enter multiple patients" << endl
            << "\t-Varify them with a console printed list" << endl;
            
            chad.user_init_doctor();

            assert(chad.get_doctor_name() == "Chad Oval");
            
            cout  << endl;
            chad.print_doctor_t();
            cout << endl;
            
            cout << "\t+ Passed..." << endl;
        }
        
        void test_equ_operator() {
            cout << "-> Testing doctor_t =operator" << endl;
            
            doctor_t chad{};
            chad.set_doctor_name("chad");
            chad.add_patient("test");
            chad.add_patient("testing");
            chad.add_patient("last test");
            
            doctor_t copy{};
            copy = chad;

            assert(chad.get_num_patients() == copy.get_num_patients());
            assert(chad.get_doctor_name() == copy.get_doctor_name());
            assert(chad.get_patient_x(0) == copy.get_patient_x(0));
            assert(chad.get_patient_x(1) == copy.get_patient_x(1));
            assert(chad.get_patient_x(2) == copy.get_patient_x(2));
            
            chad.reset_patient_load();
            chad.set_doctor_name("");
            
            copy = chad;

            assert(chad.get_num_patients() == copy.get_num_patients());
            assert(chad.get_doctor_name() == copy.get_doctor_name());
            
            cout << "\t-Tester should check that error message appears:" << endl;
            chad.get_patient_x(1);
            
            cout << "\t+ Passed..." << endl;
        }
        
        void test_print() {
            cout << "-> Testing doctor_t print" << endl;
            cout << "\t- Tester should verify that the proper"
            << " doctor name and list prints" << endl
            << "\t- Doctor: chad Patient List: 'test' 'testing' 'last test'"
            << endl << endl;
            
            doctor_t chad{};
            chad.set_doctor_name("chad");
            chad.add_patient("test");
            chad.add_patient("testing");
            chad.add_patient("last test");
            
            chad.print_doctor_t();
            cout << endl;
            
            cout << "\t+ Passed..." << endl;
        }
        
        void test_reset() {
            cout << "-> Testing doctor_t reset" << endl;
            
            doctor_t chad{};
            chad.set_doctor_name("chad");
            chad.add_patient("test");
            chad.add_patient("testing");
            chad.add_patient("last test");
            
            chad.reset_patient_load();

            assert(chad.get_doctor_name() == "chad");
            assert(chad.get_num_patients() == 0);
            
            cout << "\t+ Passed..." << endl;
        }
#endif
