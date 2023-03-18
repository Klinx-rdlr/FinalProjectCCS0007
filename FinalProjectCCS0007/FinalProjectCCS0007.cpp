#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
char corner1 = 201, corner2 = 187, corner3 = 200, corner4 = 188, line = 205, side = 186, bullet = 254, arrow1 = 175, arrow2 = 174;

class Node {
public:
private:
    double idNumber;
public:

    double getID()
    {
        return idNumber;
    }

    void setID(int num)
    {
        idNumber = num;
    }

    string fName;
    string address;
    string gender;
    string dProgram;
    Node* next;
    Node* previous;
    int mm;
    int dd;
    int yy;
    int yLevel;

    Node() {
        mm = 0;
        dd = 0;
        yy = 0;
        yLevel = 0;
        address = "";
        gender = "";
        dProgram = "";
        fName = "";
        next = nullptr;
        previous = nullptr;
    }
};

class StudentRecord
{

public:
    Node* head;

    StudentRecord()
    {
        head = nullptr;
    }
    StudentRecord(Node* n)
    {
        head = n;
    }

    // 1. CHeck if node exists using key value

    Node* nodeExists(int k)
    {
        Node* temp = nullptr;
        Node* ptr = head;

        while (ptr != nullptr)
        {
            if (ptr->getID() == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }

        return temp;
    }

    Node* nodeExists_name(string k)
    {
        Node* temp = nullptr;
        Node* ptr = head;

        while (ptr != nullptr)
        {
            if (ptr->fName == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }

        return temp;
    }

    void appendNode(Node* n) {
        if (nodeExists(n->getID()) != nullptr)
        {
            cout << "Node Already exists with key value : " << n->getID() << ". Append another node with different Key value" << endl;
        }
        else {
            if (head == nullptr)
            {
                head = n;
                cout << "Node Appended as Head Node" << endl;
            }
            else
            {
                Node* ptr = head;
                while (ptr->next != nullptr)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
                cout << "Node Appended" << endl;
            }
        }
    }

    void deleteNodeByKey(double k)
    {
        Node* ptr = nodeExists(k);
        if (ptr == nullptr)
        {
            cout << "Student ID with this number: " << k << " doesn't exist, please try again" << endl;
        }
        else {

            if (head->getID() == k)
            {
                head = head->next;
                cout << "Student ID with number: " << k << " is officially deleted" << endl;
            }
            else {
                Node* nextNode = ptr->next;
                Node* prevNode = ptr->previous;

                if (nextNode == nullptr)
                {
                    prevNode->next = nullptr;
                    cout << "Student ID with number: " << k << " is officially deleted" << endl;
                }
                else
                {
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                    cout << "Student ID with number: " << k << " is officially deleted" << endl;

                }
            }
        }
    };

    void updateNodeByKey(int k, int d)
    {

        Node* ptr = nodeExists(k);
        if (ptr != NULL)
        {

            cout << "Node Data Updated Successfully" << endl;
        }
        else
        {
            cout << "Node Doesn't exist with key value : " << k << endl;
        }

    }

    // 7th printing
    void printList()
    {
        if (head == nullptr)
        {
            cout << "No Nodes in Doubly Linked List";
        }
        else {
            Node* temp = head;

            cout << setw(20) << corner1 << setfill(line) << setw(80) << setw(58) << corner2 << endl;
            cout << "\t\t   " << side << "\t\t\t\t\t\t\t" << "     " << side << endl;
            cout << "\t\t   " << side << "\t\t   LIST OF ALL STUDENT RECORDS\t\t" << "     " << side << endl;
            cout << "\t\t   " << side << "\t\t\t\t\t\t\t" << "     " << side << endl;
            cout << setfill(' ') << setw(20) << corner3 << setfill(line) << setw(58) << corner4 << endl;

            while (temp != nullptr)
            {
                cout << setw(80) << setfill(line) << endl;
                cout << "\nSTUDENT ID NUMBER:" << "\t" << fixed << setprecision(0) << temp->getID() << endl;
                cout << "FULL NAME:" << "\t\t" << temp->fName << endl;
                cout << "BIRTHDAY:" << "\t\t" << temp->dd << '/' << temp->mm << '/' << temp->yy << endl;
                cout << "ADDRESS:" << "\t\t" << temp->address << endl;
                cout << "GENDER:" << "\t\t\t" << temp->gender << endl;
                cout << "DEGREE PROGRAM:" << "\t\t" << temp->dProgram << endl;
                cout << "YEAR LEVEL: " << "\t\t" << temp->yLevel << endl;
                cout << setw(80) << setfill(line) << endl;

                temp = temp->next;
            }
        }

    };


    int listCount()
    {
        int count = 0;
        if (head == nullptr)
        {
            return 0;
        }
        else {
            Node* temp = head;

            while (temp != nullptr)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    };

    int* collectRecord_int(string name)
    {
        int size = listCount(); int i = 0;
        int* year_lvl = new int[size];
        Node* temp = head;

        while (temp != nullptr)
        {
            year_lvl[i] = temp->yLevel;

            i++;
            temp = temp->next;
        }

        return year_lvl;
    };



    string* collectRecord(string name)
    {
        int size = listCount(); int i = 0;
        Node* temp = head;

        string* fname = new string[size];
        string* address = new string[size];
        string* gender = new string[size];
        string* degprog = new string[size];

        if (temp == nullptr)
        {
            return nullptr;
        }
        else
        {
            while (temp != nullptr)
            {
                fname[i] = temp->fName;
                address[i] = temp->address;
                gender[i] = temp->gender;
                degprog[i] = temp->dProgram;

                i++;
                temp = temp->next;
            }
        };

        if (name == "Name") { return fname; }
        else if (name == "Address") { return address; }
        else if (name == "Gender") { return gender; }
        else if (name == "Degree Program") { return degprog; }
        else { return nullptr; }

    };

    void searchRecord(int id)
    {
        Node* temp = nodeExists(id);

        if (temp != nullptr)
        {
            cout << setw(80) << setfill(line) << endl;
            cout << "\nSTUDENT ID NUMBER:" << "\t" << fixed << setprecision(0) << temp->getID() << endl;
            cout << "FULL NAME:" << "\t\t" << temp->fName << endl;
            cout << "BIRTHDAY:" << "\t\t" << temp->dd << '/' << temp->mm << '/' << temp->yy << endl;
            cout << "ADDRESS:" << "\t\t" << temp->address << endl;
            cout << "GENDER:" << "\t\t\t" << temp->gender << endl;
            cout << "DEGREE PROGRAM:" << "\t\t" << temp->dProgram << endl;
            cout << "YEAR LEVEL: " << "\t\t" << temp->yLevel << endl;
            cout << setw(80) << setfill(line) << endl;
        }
        else
        {
            cout << "Student ID number: " << id << " doesn't exist\n";
        }
    };

    void searchRecord(string name)
    {
        Node* temp = nodeExists_name(name);

        if (temp != nullptr)
        {
            cout << setw(80) << setfill(line) << endl;
            cout << "\nSTUDENT ID NUMBER:" << "\t" << fixed << setprecision(0) << temp->getID() << endl;
            cout << "FULL NAME:" << "\t\t" << temp->fName << endl;
            cout << "BIRTHDAY:" << "\t\t" << temp->dd << '/' << temp->mm << '/' << temp->yy << endl;
            cout << "ADDRESS:" << "\t\t" << temp->address << endl;
            cout << "GENDER:" << "\t\t\t" << temp->gender << endl;
            cout << "DEGREE PROGRAM:" << "\t\t" << temp->dProgram << endl;
            cout << "YEAR LEVEL: " << "\t\t" << temp->yLevel << endl;
            cout << setw(80) << setfill(line) << endl;
        }
        else
        {
            cout << "Student Name: " << name << " doesn't exist\n";
        }
    };

    void specificRecord(string name)
    {
        system("cls");
        Node* temp = head;

        if (name == "Name" || name == "Gender" || name == "Address" || name == "Degree Program")
        {
            string* values;
            values = collectRecord(name);

            cout << "ID Number: \t\t\t" << name << ":\n";

            int i = 0;
            while (temp != nullptr)
            {
                cout << temp->getID() << '\t' << values[i] << endl;
                i++;
                temp = temp->next;
            }

        }
        else if (name == "Year Level")
        {
            int* values;
            values = collectRecord_int(name);

            cout << "ID Number: \t\t\t" << "Year Level:\n";

            int i = 0;
            while (temp != nullptr)
            {
                cout << temp->getID() << '\t' << values[i] << endl;
                i++;
                temp = temp->next;
            }
        }
        else {
            cout << "ID Number: \t\t\t" << "Birthday:\n";

            while (temp != nullptr)
            {
                cout << temp->getID() << '\t' << temp->dd << '/' << temp->mm << '/' << temp->yy << endl;
                temp = temp->next;
            }
        }

    };
};

Node* makeStudent(Node* n1);
void searchRecord(StudentRecord obj);
void deleteRecord(StudentRecord obj);
void displayAllRecords(StudentRecord obj);
void displaySpecificRecord(StudentRecord obj);
void pause();
bool checkID(double num);
bool checkBDAY(int dd, int mm, int yy);
bool checkGENDER(string gender);
bool checkYRLVL(int yrlvl);

int main() {

    StudentRecord obj;
    int option;
    do {
        system("cls"); system("Color 0E");
        cout << setfill(' ') << setw(20) << corner1 << setfill(line) << setw(32) << arrow1 << "HOME" << arrow2 << setw(35) << corner2;
        cout << endl << setfill(' ') << setw(20) << side << "   \t\t\t\t\t\t\t\t\t" << "   " << side << endl;
        cout << setfill(' ') << setw(20) << side << "\t\t    WELCOME TO GROUP XYZ STUDENT INFORMATION SYSTEM\t" << "   " << side << endl;
        cout << setfill(' ') << setw(20) << side << "\t\t\t\t\t\t\t\t\t" << "   " << side << endl;
        cout << setfill(' ') << setw(20) << corner3 << setfill(line) << setw(72) << corner4 << endl;
        cout << setfill(' ');
        cout << endl << setfill(' ') << setw(33) << "\t\t" << arrow1 << " - What do you want to do ? -" << arrow2 << endl << endl;
        cout << setfill(' ') << setw(20) << line << setw(72) << setfill(line) << line << endl << endl;
        cout << setfill(' ');
        cout << setw(41) << arrow1 << "-[1] Add New Record.-" << arrow2 << endl;
        cout << setw(41) << arrow1 << "-[2] Search Record.-" << arrow2 << endl;
        cout << setw(41) << arrow1 << "-[3] Display ALl Records.-" << arrow2 << endl;
        cout << setw(41) << arrow1 << "-[4] Display Specific Record.-" << arrow2 << endl;
        cout << setw(41) << arrow1 << "-[5] Delete Record.-" << arrow2 << endl;
        cout << setw(41) << arrow1 << "-[6] Exit.-" << arrow2 << endl << endl;
        cout << setfill(' ') << setw(41) << arrow1 << "CHOICE: ";
        cin >> option;
        Node* n1 = new Node();
        //Node n1;
        while (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Not a valid option. Please re-enter: ";
            cin >> option;
        }

        switch (option) {
        case 0:
            break;
        case 1:
            obj.appendNode(makeStudent(n1));
            break;

        case 2:
            searchRecord(obj);
            break;

        case 3:
            displayAllRecords(obj);
            break;
        case 4:
            displaySpecificRecord(obj);
            break;
        case 5:
            deleteRecord(obj);
            break;
        case 6:
            exit(EXIT_SUCCESS);
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
};


void displaySpecificRecord(StudentRecord obj) {
    system("cls");
    int option;
    system("cls"); system("Color 0E");
    cout << setw(20) << corner1 << setfill(line) << setw(100) << setw(66) << corner2 << endl;
    cout << setfill(' ') << setw(20) << side << setw(66) << side << endl;
    cout << setw(20) << side << "\t\t   CHOOSE WHAT RECORD TO SEARCH" << setw(23) << side << endl;
    cout << setw(20) << side << setw(21) << arrow1 << "-[0] Go Back-" << arrow2 << setw(31) << side << endl;
    cout << setw(20) << side << setw(21) << arrow1 << "-[1] Name-" << arrow2 << setw(34) << side << endl;
    cout << setw(20) << side << setw(21) << arrow1 << "-[2] Birthday-" << arrow2 << setw(30) << side << endl;
    cout << setw(20) << side << setw(21) << arrow1 << "-[3] Gender-" << arrow2 << setw(32) << side << endl;
    cout << setw(20) << side << setw(21) << arrow1 << "-[4] Address -" << arrow2 << setw(30) << side << endl;
    cout << setw(20) << side << setw(21) << arrow1 << "-[5] Degree Program-" << arrow2 << setw(24) << side << endl;
    cout << setw(20) << side << setw(21) << arrow1 << "-[6] Year Level-" << arrow2 << setw(28) << side << endl;
    cout << setw(20) << side << setw(66) << side << endl;
    cout << setfill(' ') << setw(20) << corner3 << setfill(line) << setw(66) << corner4 << endl;
    cout << setfill(' ') << setw(41) << arrow1 << "CHOICE: ";

    while (true) {
        cin >> option;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << setfill(' ') << setw(41) << arrow1 << "INVALID INPUT\n";
            cout << setfill(' ') << setw(41) << arrow1 << "RE-ENTER - CHOICE: ";
        }
        else {
            break;
        }
    }
   
    switch (option) {
    case 0:
        return;
    case 1:
        obj.specificRecord("Name");
        pause();
        break;
    case 2:
        obj.specificRecord("Birthday");
        pause();
        break;
    case 3:
        obj.specificRecord("Gender");
        pause();
        break;
    case 4:
        obj.specificRecord("Address");
        pause();
        break;
    case 5:
        obj.specificRecord("Degree Program");
        pause();
        break;
    case 6:
        obj.specificRecord("Year Level");
        pause();
        break;
    default:
        cout << "Invalid input";
    }
};



void displayAllRecords(StudentRecord obj) {
    system("cls");
    obj.printList();
    pause();
    return;
};

void searchRecord(StudentRecord obj) {

    system("cls");
    int user_option; string name; double idNumber;

    cout << setw(20) << corner1 << setfill(line) << setw(80) << setw(58) << corner2 << endl;
    cout << setfill(' ') << setw(20) << side << setw(58) << side << endl;
    cout << setw(20) << side << "\t\t\t" << arrow1 << "SEARCH RECORD" << arrow2 << setfill(' ') << setw(23) << side << endl;
    cout << setw(20) << side << "\t\t      [0] Go Back "  << setw(28) << side << endl;
    cout << setw(20) << side << "\t\t      [1] Student ID number " <<  setw(18) << side << endl;
    cout << setw(20) << side << "\t\t      [2] Student Name" << setw(24) << side << endl;
    cout << setfill(' ') << setw(20) << side << setw(58) << side << endl;
    cout << setfill(' ') << setw(20) << corner3 << setfill(line) << setw(58) << corner4 << endl;

    cout << setfill(' ') << setw(41) << arrow1 << "CHOICE: ";
    while (true) {

        cin >> user_option;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << setfill(' ') << setw(41) << arrow1 << "INVALID INPUT\n";
            cout << setfill(' ') << setw(41) << arrow1 << "RE-ENTER - CHOICE: ";
        }
        else {
            break;
        }
    };

    switch(user_option){

    case 0: 
        return;
    case 1:
        cout << setfill(' ') << setw(41) << arrow1 << "ENTER STUDENT ID: ";
        while (true) {
         
            cin >> idNumber;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << setfill(' ') << setw(41) << arrow1 << "INVALID INPUT\n";
                cout << setfill(' ') << setw(41) << arrow1 << "RE - ENTER STUDENT ID: ";
            }
            else if ((checkID(idNumber) == false)) {
                cout << setfill(' ') << setw(41) << arrow1 << "INVALID INPUT, ID NUMBER MUST BE 7 DIGITS\n";
                cout << setfill(' ') << setw(41) << arrow1 << "RE - ENTER STUDENT ID: ";
            }
            else {
                break;
            }
        };



        obj.searchRecord(idNumber);
        break;
    
    case 2:
        cout << setfill(' ') << setw(41) << arrow1 << "ENTER STUDENT NAME: ";
        while (true) {

            cin >> name;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << setfill(' ') << setw(41) << arrow1 << "INVALID INPUT\n";
                cout << setfill(' ') << setw(41) << arrow1 << "RE - ENTER STUDENT NAME: ";

            }
            else {
                break;
            };
        };

        obj.searchRecord(name);
        break;

    default:
        cout << setfill(' ') << setw(41) << arrow1 << "INVALID INPUT";
        pause();
        return;
    }

    pause();
    return;
};

void deleteRecord(StudentRecord obj) {
    double idNumber;

    while (true) {
        system("cls"); system("Color 0E");
        cout << setw(20) << corner1 << setfill(line) << setw(100) << setw(66) << corner2 << endl;
        cout << setfill(' ') << setw(20) << side << setw(66) << side << endl;
        cout << setw(20) << side << "\t\t   Delete Node By Student id number" << setw(19) << side << endl;
        cout << setw(20) << side << "\t\tEnter the student id number to be deleted : " << setw(10) << side << endl;
        cout << setw(20) << side << "\t\t\t   Enter 0 to go back" << setw(25) << side << endl;
        cout << setw(20) << side << setw(66) << side << endl;
        cout << setfill(' ') << setw(20) << corner3 << setfill(line) << setw(66) << corner4 << endl;
        cout << setfill(' ');
        cout << setw(52) << "ID NUMBER: ";
        cin >> idNumber;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            idNumber = 0;
            cout << setfill(' ') << setw(42) << arrow1 << "INVALID INPUT";
            pause();
        }
        else if (idNumber == 0) {
            return;
        }
        else {
            break;
        }
    }

    obj.deleteNodeByKey(idNumber);
    pause();
    return;
};

Node* makeStudent(Node* n1) {
    double idNumber;
    string fname, address, gender, dProgram;
    int mm, dd, yy, yLevel;


    while (true) {
        system("cls");
        cout << setw(20) << corner1 << setfill(line) << setw(100) << setw(64) << corner2 << endl;
        cout << "\t\t   " << side << "\t\t\t\t\t\t\t\t   " << side << endl;
        cout << "\t\t   " << side << "\t\t   Enter Student Data to be recorded\t\t   " << side << endl;
        cout << "\t\t   " << side << "\t\t\t\t\t\t\t\t   " << side << endl;
        cout << setfill(' ') << setw(20) << corner3 << setfill(line) << setw(64) << corner4 << endl;
        cout << setfill(' ') << setw(37) << arrow1 << "Enter Student ID Number: " << arrow2 << endl;
        cout << setfill(' ') << setw(57) << "(EX. 202210482)" << endl << endl;
        cout << setfill(' ') << setw(37) << arrow1 << "ID NUMBER: ";
        cin >> idNumber;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            idNumber = 0;
            cout << setfill(' ') << setw(37) << arrow1 << "INVALID INPUT";
            pause();
        }
        else if (checkID(idNumber) == false) {
            idNumber = 0;
            cout << setfill(' ') << setw(37) << arrow1 << "INVALID INPUT";
            pause();
        }
        else {
            cout << "\t\t\t\t    _____________________________\n\n";
            break;
        }

    }

    cin.ignore();
    cout << endl << setw(37) << arrow1 << "Enter Full Name: " << arrow2 << endl;
    cout << setfill(' ') << setw(37) << arrow1 << "FULL NAME: ";
    getline(cin, fname);
    cout << "\t\t\t\t    _____________________________\n\n";

    cout << endl << setw(37) << arrow1 << "Enter Address: " << arrow2 << endl;
    cout << setfill(' ') << setw(37) << arrow1 << "ADDRESS: ";
    getline(cin, address);
    cout << "\t\t\t\t    _________________________________________________________\n\n";

    while (true) {

        cout << setw(37) << arrow1 << "Enter Birthday: " << arrow2 << endl;
        cout << setfill(' ') << setw(52) << "(EX. 03/04/2000)" << endl << endl;

        cout << setfill(' ') << setw(37) << arrow1 << "DD: ";
        while (true)
        {
            cin >> dd;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << setfill(' ') << setw(37) << arrow1 << "INVALID INPUT\n";
                cout << setfill(' ') << setw(37) << arrow1 << "RE-ENTER - DD: ";
            }
            else {
                cout << "\t\t\t\t    ----------------";
                break;
            }
        };

        cout << endl << setfill(' ') << setw(37) << arrow1 << "MM: ";

        while (true) {
            cin >> mm;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << setfill(' ') << setw(37) << arrow1 << "INVALID INPUT\n";
                cout << endl << setfill(' ') << setw(37) << arrow1 << "RE-ENTER - MM: ";
            }
            else {
                cout << "\t\t\t\t    ----------------";
                break;
            }
        };

        cout << endl << setfill(' ') << setw(37) << arrow1 << "YYYY: ";
        while (true) {
            cin >> yy;

            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << setfill(' ') << setw(37) << arrow1 << "INVALID INPUT\n";
                cout << endl << setfill(' ') << setw(37) << arrow1 << "RE-ENTER - YYYY: ";
            }
            else {
                cout << "\t\t\t\t    ----------------\n";
                break;
            }
        }

        if (checkBDAY(dd, mm, yy) == false) {
            cout << "Invalid Birthday format, use dd/mm/yyyy, please try again\n";
            pause();
        }
        else {
            break;
        }
    }

    while (true) {
        cin.ignore();
        cout << setw(37) << arrow1 << "Enter Gender: " << arrow2 << endl;
        cout << setfill(' ') << setw(54) << "(EX. Male/Female)" << endl << endl;
        cout << setfill(' ') << setw(37) << arrow1 << "GENDER: ";
        getline(cin, gender);
        if (checkGENDER(gender) == false) {
            cout << "Invalid Input, please try again";
            pause();
        }
        else {
            cout << "\t\t\t\t    ----------------\n\n";
            break;
        }
    }
    cout << setw(37) << arrow1 << "Enter Degree Program: " << arrow2 << endl;
    cout << setfill(' ') << setw(37) << arrow1 << "DEGREE: ";
    getline(cin, dProgram);
    cout << "\t\t\t\t    ----------------\n\n";

    while (true) {
        cout << setw(37) << arrow1 << "Enter Year Level: " << arrow2 << endl;
        cout << setfill(' ') << setw(37) << arrow1 << "YEAR LVL: ";
        cin >> yLevel;
        if (checkYRLVL(yLevel) == false) {
            cout << "Invalid Input, please try again";
            pause();
        }
        else {
            break;
            cout << "\t\t\t\t    ----------------\n\n";
        }
    }

    n1->setID(idNumber);
    n1->fName = fname;
    n1->address = address;
    n1->dd = dd;
    n1->mm = mm;
    n1->gender = gender;
    n1->yLevel = yLevel;
    n1->yy = yy;
    n1->dProgram = dProgram;

    pause();
    return n1;
}

bool checkID(double num) {
    string id;
    stringstream ss;
    ss << num;
    ss >> id;
    int size = id.length();
    if (size < 7) {
        return false;
    }
    else {
        return true;
    }
};

bool checkBDAY(int dd, int mm, int yy) {
    string day, month, year;
    stringstream ss;
    ss << dd;
    ss >> day;
    ss.clear();
    ss << mm;
    ss >> month;
    ss.clear();
    ss << yy;
    ss >> year;

    if ((day.length() >= 1 && day.length() <= 2) && (month.length() >= 1 && month.length() <= 2) && (year.length() == 4) && (yy < 2023)) {
        return true;
    }
    else {
        return false;
    }

};

bool checkGENDER(string gender) {
    if (gender == "Male" || gender == "Female") {
        return true;
    }
    else {
        return false;
    }
}

bool checkYRLVL(int yrlvl) {
    if (yrlvl >= 1 && yrlvl <= 4) {
        return true;
    }
    else {
        return false;
    }
}

void pause() {
    char trash;
    cout << "\nEnter any key to continue..." << flush;
    cin >> trash;
    return;
};
