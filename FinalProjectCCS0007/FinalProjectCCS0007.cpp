#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

//values for the user interface design
char corner1 = 201, corner2 = 187, corner3 = 200, corner4 = 188, line = 205, side = 186, bullet = 254, arrow1 = 175, arrow2 = 174;


/*
class Node
- Contains student information members
- Holds the address for the next and previous records
*/

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
        idNumber = 0;
        address = "";
        gender = "";
        dProgram = "";
        fName = "";
        next = nullptr;
        previous = nullptr;
    }
};


/*
class Student Record
- Contains the functions to manipulate the records and operations.
- Organizes the structure of the node.
*/

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


    //checks whether a student id already exists.
    Node* nodeExists(double k)
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

    //checks whether a student name already exists.
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


    //adds a student in the structure.
    void appendNode(Node* n) {
        if (nodeExists(n->getID()) != nullptr)
        {
            cout << setfill(' ') << setw(37) << "Student ID: " << fixed << setprecision(0) << n->getID() << " , Already exists please try again." << endl;
        }
        else {
            if (head == nullptr)
            {
                head = n;
                cout << endl << setfill(' ') << setw(37) << arrow1 << "First student record is successfully added" << arrow2 << endl;
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
                cout << setfill(' ') << setw(37) << arrow1 << "Student record is successfully added" << arrow2 << endl;
            }
        }
    }

    //deletes a node based on its student id number. 
    void deleteNodeByKey(double k)
    {
        Node* ptr = nodeExists(k);

        if (ptr == nullptr)
        {
            cout << "Student ID with this number: " << fixed << setprecision(0) << k << " doesn't exist, please try again" << endl;
        }
        else
        {

            if (head->getID() == k)
            {
                    if (head->next == nullptr)
                    {
                        head = nullptr;
                        cout << "Student ID with number: " << fixed << setprecision(0) << k << " is officially deleted" << endl;
                    }
                    else
                    {
                        head = head->next;
                        head->previous = nullptr;
                        cout << "Student ID with number: " << fixed << setprecision(0) << k << " is officially deleted" << endl;
                    }
             }
             else 
             {
                    Node* nextNode = ptr->next;
                    Node* prevNode = ptr->previous;

                    if (nextNode == nullptr)
                    {
                        prevNode->next = nullptr;
                        cout << "Student ID with number: " << fixed << setprecision(0) << k << " is officially deleted" << endl;
                    }
                    else
                    {
                        prevNode->next = nextNode;
                        nextNode->previous = prevNode;
                        cout << "Student ID with number: " << fixed << setprecision(0) << k << " is officially deleted" << endl;

                    }
             }
        }
    };

    //Prints all of the data in each node.
    void printList()
    {
        Node* temp = head;
        if (temp == nullptr)
        {
            cout << setfill(' ') << setw(30) << arrow1 << "NO EXISTING STUDENT RECORD AVAILABLE" << arrow2 << endl;
        }
        else {

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



    //Calculates the total nodes in the stucture.
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




    /*Traverses through all of the nodes in the structureand collecting the datas and stores them to an int array,
    then returns the array based on the users input. */
    int* collectRecord_int(string name)
    {
        int size = listCount();
        int* year_lvl = new int[size];
        Node* temp = head;
        int i = 0;
        while (temp != nullptr && i < size)
        {
            year_lvl[i] = temp->yLevel;
            i++;
            temp = temp->next;
        }

        return year_lvl;
    };


    /*Traverses through all of the nodes in the structureand collecting the datasand stores them to a string array,
    then returns the array based on the users input. */
    string* collectRecord(string name)
    {
        int size = listCount();
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
            int i = 0;
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

        if (name == "NAME") {
            return fname;
        }
        else if (name == "ADDRESS") {
            return address;
        }
        else if (name == "GENDER") {
            return gender;
        }
        else if (name == "DEGREE PROGRAM") {
            return degprog;
        }
        else {
            return nullptr;
        }

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

        if (name == "NAME" || name == "GENDER" || name == "ADDRESS" || name == "DEGREE PROGRAM")
        {
            string* values;
            values = collectRecord(name);

            cout << setw(20) << setfill(' ') << corner1 << setfill(line) << setw(20) << corner2 << setfill(line) << setw(50) << corner2 << endl;
            cout << setfill(' ') << setw(20) << side << "\t ID NUMBER:" << setw(5) << side << setw(22) << arrow1 << name << arrow2 << setw(27 - name.length()) << side << endl;

            int i = 0;
            while (temp != nullptr)
            {
                cout << setfill(' ') << setw(20) << side << setw(14) << fixed << setprecision(0) << temp->getID() << setw(6) << side << setw(5) << arrow1 << " " << values[i] << setw(44 - values[i].length()) << side << endl;
                i++;
                temp = temp->next;
            }
            cout << setw(20) << setfill(' ') << corner3 << setfill(line) << setw(20) << corner4 << setfill(line) << setw(50) << corner4 << endl;

        }
        else if (name == "YEAR LEVEL")
        {
            int* values;
            values = collectRecord_int(name);

            cout << setw(20) << setfill(' ') << corner1 << setfill(line) << setw(20) << corner2 << setfill(line) << setw(50) << corner2 << endl;
            cout << setfill(' ') << setw(20) << side << "\t ID NUMBER:" << setw(5) << side << setw(22) << arrow1 << name << arrow2 << setw(27 - name.length()) << side << endl;

            int i = 0;
            string year_lvl[4] = { "st Year", "nd Year", "rd Year", "th Year" };
            while (temp != nullptr)
            {
                string temp_str;
                switch (temp->yLevel) {
                case 1:
                    temp_str = year_lvl[0];
                    break;
                case 2:
                    temp_str = year_lvl[1];
                    break;
                case 3:
                    temp_str = year_lvl[2];
                    break;
                case 4:
                    temp_str = year_lvl[3];
                    break;
                }
                cout << setfill(' ') << setw(20) << side << setw(14) << fixed << setprecision(0) << temp->getID() << setw(6) << side << setw(5) << arrow1 << " " << values[i] << temp_str << setw(36) << side << endl;
                i++;
                temp = temp->next;
            }
            cout << setw(20) << setfill(' ') << corner3 << setfill(line) << setw(20) << corner4 << setfill(line) << setw(50) << corner4 << endl;
        }
        else {
            cout << setw(20) << setfill(' ') << corner1 << setfill(line) << setw(20) << corner2 << setfill(line) << setw(50) << corner2 << endl;
            cout << setfill(' ') << setw(20) << side << "\t ID NUMBER:" << setw(5) << side << setw(22) << arrow1 << "BIRTHDAY" << arrow2 << setw(19) << side << endl;

            while (temp != nullptr)
            {
                string bday;
                bday = to_string(temp->dd) + to_string(temp->mm) + to_string(temp->yy);
                int size = bday.length() + 2; int size2;
                if (size == 8) { size2 = 36; }
                else if (size == 9) { size2 = 35; }
                else { size2 = 34; }

                cout << setfill(' ') << setw(20) << side << setw(14) << fixed << setprecision(0) << temp->getID() << setw(6) << side << setw(5) << arrow1 << " " << temp->dd << '/' << temp->mm << '/' << temp->yy << setw(size2) << side << endl;
                temp = temp->next;
            }
            cout << setw(20) << setfill(' ') << corner3 << setfill(line) << setw(20) << corner4 << setfill(line) << setw(50) << corner4 << endl;
        }

    };


    void saveRecord(string name, ofstream& file) {
        Node* temp = head;
        if (name == " ") {
            return;
        }

        file.open(name, ios::app);

        while (temp != nullptr) {
            file << "Student ID Number: " << fixed << setprecision(0) << temp->getID() << endl;
            file << "Full Name: " << temp->fName << endl;
            file << "Birthday: " << temp->dd << '/' << temp->mm << '/' << temp->yy << endl;
            file << "Address: " << temp->address << endl;
            file << "Gender: " << temp->gender << endl;
            file << "Degree Program: " << temp->dProgram << endl;
            file << "Year Level: " << temp->yLevel;
            file << endl << endl;

            temp = temp->next;
        }
        file.close();
        return;
    }

};

//Function : makeStudent - getting and setting the data and key of the nodes, also used for validating inputs.

Node* makeStudent(Node* n1);

/*
Functions for operation :
searchRecord - contains two functions, used for searching a specific ID Number or Student Name, then returns it record.
deleteRecord - delinks the node from the structure.
displayAllRecords - traverses to all of the node in the structure, then displays all of the data.
displaySpecificRecord - traverses a specific data of the inputted data to be searched, then displays all of it.
*/

void searchRecord(StudentRecord obj);
void deleteRecord(StudentRecord obj);
void displayAllRecords(StudentRecord obj);
void displaySpecificRecord(StudentRecord obj);

//Function : pause - acts like _getch(), used for displaying the output, until the user enters a key. 
void pause();

//Function : "check" - used for checking the data if it is valid or not, returns true or false.

bool checkID(double num);
bool checkBDAY(int dd, int mm, int yy);
bool checkGENDER(string gender);
bool checkYRLVL(int yrlvl);

//Function : saveprogress - used for saving the records into a text format. 
string saveProgress();

// Function : members - displaying the members of the group.
void members();



int main() {

    ofstream fout;
    StudentRecord obj;
    int option;
    do {
        system("cls"); system("Color 0E");
        cout << endl;
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
            pause();
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
            obj.saveRecord(saveProgress(), fout);
            members();
            exit(EXIT_SUCCESS);
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
};


string saveProgress() {
    string placeholder; char option;
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << setw(20) << corner1 << setfill(line) << setw(80) << setw(72) << corner2 << endl;
    cout << setfill(' ') << setw(20) << side << setw(72) << side << endl;
    cout << setw(20) << side << setw(16) << arrow1 << "Would you like to save progress? (Y/N)" << arrow2 << setfill(' ') << setw(17) << side << endl;
    cout << setfill(' ') << setw(20) << side << setw(72) << side << endl;
    cout << setfill(' ') << setw(20) << corner3 << setfill(line) << setw(72) << corner4 << endl;
    cout << setfill(' ') << setw(51) << arrow1 << "CHOICE: ";
    cin >> option;

    if (tolower(option) == 'y') {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n";
        cout << setw(20) << corner1 << setfill(line) << setw(80) << setw(72) << corner2 << endl;
        cout << setfill(' ') << setw(20) << side << setw(72) << side << endl;
        cout << setw(20) << side << setw(27) << arrow1 << "ENTER FILE NAME: " << arrow2 << setfill(' ') << setw(27) << side << endl;
        cout << setw(20) << side << setw(16) << arrow1 << "(Add \".txt\" at the end of the file name)" << arrow2 << setfill(' ') << setw(15) << side << endl;
        cout << setfill(' ') << setw(20) << side << setw(72) << side << endl;
        cout << setfill(' ') << setw(20) << corner3 << setfill(line) << setw(72) << corner4 << endl;
        cout << setfill(' ') << setw(41) << arrow1 << "FILE NAME: ";
        while (true) {
            cin >> placeholder;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << endl << setfill(' ') << setw(41) << arrow1 << "INVALID INPUT\n";
                cout << setfill(' ') << setw(41) << arrow1 << "RE-ENTER - FILE NAME:";
            }
            else if (placeholder.substr(placeholder.find_last_of(".") + 1) != "txt") {
                cout << endl << setfill(' ') << setw(41) << arrow1 << "INVALID FORMAT\n";
                cout << setfill(' ') << setw(41) << arrow1 << "RE-ENTER - FILE NAME:";
            }
            else {
                break;
            }
        }

        return placeholder;
    }
    else {
        return "  ";
    }
}


void members() {
    system("cls");
    cout << "\n\n\n\n\n\n";
    cout << setw(20) << corner1 << setfill(line) << setw(80) << setw(58) << corner2 << endl;
    cout << setfill(' ') << setw(20) << side << setw(58) << side << endl;
    cout << setw(20) << side << setw(25) << arrow1 << "MEMBERS" << arrow2 << setfill(' ') << setw(25) << side << endl;
    cout << setw(20) << side << setw(14) << arrow1 << "[1] RHODE DANNIEL L. REYES" << setw(18) << side << endl;
    cout << setw(20) << side << setw(14) << arrow1 << "[2] KIRSTEN HAILEY D. ESCUETA" << setw(15) << side << endl;
    cout << setw(20) << side << setw(14) << arrow1 << "[3] RAMI YOUSEF S. ABUARQOUB" << setw(16) << side << endl;
    cout << setw(20) << side << setw(14) << arrow1 << "[4] MARVIN MARVIN DIZON" << setw(21) << side << endl;
    cout << setfill(' ') << setw(20) << side << setw(58) << side << endl;
    cout << setfill(' ') << setw(20) << corner3 << setfill(line) << setw(58) << corner4 << endl;
    cout << "\n\n\n\n\n";
}



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
        obj.specificRecord("NAME");
        pause();
        break;
    case 2:
        obj.specificRecord("BIRTHDAY");
        pause();
        break;
    case 3:
        obj.specificRecord("GENDER");
        pause();
        break;
    case 4:
        obj.specificRecord("ADDRESS");
        pause();
        break;
    case 5:
        obj.specificRecord("DEGREE PROGRAM");
        pause();
        break;
    case 6:
        obj.specificRecord("YEAR LEVEL");
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
    cout << "\n\n\n\n\n\n";
    cout << setw(20) << corner1 << setfill(line) << setw(80) << setw(58) << corner2 << endl;
    cout << setfill(' ') << setw(20) << side << setw(58) << side << endl;
    cout << setw(20) << side << "\t\t\t" << arrow1 << "SEARCH RECORD" << arrow2 << setfill(' ') << setw(23) << side << endl;
    cout << setw(20) << side << "\t\t      [0] Go Back " << setw(28) << side << endl;
    cout << setw(20) << side << "\t\t      [1] Student ID number " << setw(18) << side << endl;
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

    switch (user_option) {

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
        cin.ignore();
        cin.clear();
        getline(cin, name);

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

        cout << "\n\n\n\n\n\n\n";
        cout << setw(20) << corner1 << setfill(line) << setw(100) << setw(66) << corner2 << endl;
        cout << setfill(' ') << setw(20) << side << setw(66) << side << endl;
        cout << setw(20) << side << "\t\t   DELETE NODE BY STUDENT ID NUMBER" << setw(19) << side << endl;
        cout << setw(20) << side << "\t\tENTER THE STUDENT ID NUMBER TO BE DELETED : " << setw(10) << side << endl;
        cout << setw(20) << side << "\t\t\t     [0] go back" << setw(30) << side << endl;
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
        cout << "\t\t   " << side << "\t\t   ENTER STUDENT DATA TO BE RECORDED\t\t   " << side << endl;
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

    cout << endl << setw(37) << arrow1 << "Enter Birthday: " << arrow2 << endl;
    cout << setfill(' ') << setw(37) << arrow1 << "(EX. DD: 03/MM: 04/YYYY: 2000)\n";

    while (true) {

        cout << endl << setfill(' ') << setw(37) << arrow1 << "DD: ";
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
                cout << "\t\t\t\t    ----------------\n\n";
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
        cout << endl << setw(37) << arrow1 << "Enter Gender: " << arrow2 << endl;
        cout << setfill(' ') << setw(53) << "(EX. Male/Female)" << endl << endl;
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
    cout << endl << setw(37) << arrow1 << "Enter Degree Program: " << arrow2 << endl;
    cout << setfill(' ') << setw(37) << arrow1 << "DEGREE: ";
    getline(cin, dProgram);
    cout << "\t\t\t\t    ----------------\n\n";

    while (true) {
        cout << endl << setw(37) << arrow1 << "Enter Year Level: " << arrow2 << endl;
        cout << setfill(' ') << setw(37) << arrow1 << "YEAR LVL: ";
        cin >> yLevel;
        if (checkYRLVL(yLevel) == false) {
            cout << "Invalid Input, please try again";
            pause();
        }
        else {
            cout << "\t\t\t\t    ----------------\n\n";
            break;
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

    return n1;
}

bool checkID(double num) {
    string id;
    stringstream ss;
    ss << num;
    ss >> id;
    int size = id.length();
    if (size == 7) {
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

    if ((day.length() >= 1 && day.length() <= 2) && (month.length() >= 1 && month.length() <= 2) && (year.length() == 4) && (yy < 2023) && (mm > 0 && mm <= 12) && (dd > 0 && dd <= 31)) {
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
