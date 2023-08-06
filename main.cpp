// ToDoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct ToDo {
    char type;
    char* task;
    int month;
    int day;
    int priority;
};
const int MAX = 20;

void findSize(int& size, ifstream& fin) {
    fin.open("todo.txt");
   
    char temp = fin.get();
    if (temp != '\n') {
        while (fin.get(temp)) {
            if (temp == '\n') {
                size++;
            }
        }
    }
    
    fin.close();
}

void ReadList(ToDo list[MAX], int& size, ifstream &fin) {
    fin.open("todo.txt");

    for (int i = 0;i < size; i++) {
        fin >> list[i].type;
        fin.ignore();
        list[i].task = new char[80];
        fin.getline(list[i].task, 80, '\0');
        fin >> list[i].month;
        fin.ignore();
        fin >> list[i].day;
        fin.ignore();
        fin >> list[i].priority;
    }

    fin.close();
}

void AddTask(ToDo list[MAX], int& size, char* word) {
    cin >> list[size].type;
    list[size].task = new char[80];
    cin.ignore();
    cin.getline(list[size].task,80, '0');
    cin >> list[size].month;
    cin >> list[size].day;
    cin >> list[size].priority;
    cout << endl;
    size++;
}

bool DeleteTask(ToDo list[MAX], int& size, char* word) {
    cout << "enter the word to delete: " << endl;
    cin >> word;

    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].task, word) == 0) {
            for (; i < size; i++) {
                list[i].type = list[i + 1].type;
                list[i].task = list[i + 1].task;
                list[i].month = list[i + 1].month;
                list[i].day = list[i + 1].day;
                list[i].priority = list[i + 1].priority;
            }
            --size;
            return true;
        }
    }
    return false;
}

void DeleteLast(ToDo list[MAX], int& size) {
   
    for (int i = 0; i < size - 1; i++) {
        list[i+1].type = list[i].type;
        list[i+1].task = list[i].task;
        list[i+1].month = list[i].month;
        list[i+1].day = list[i].day;
        list[i+1].priority = list[i].priority;
    }
    --size;
}

void DeleteFirst(ToDo list[MAX], int& size) {

    for (int i = 0; i < size; i++) {
        list[i].type = list[i + 1].type;
        list[i].task = list[i + 1].task;
        list[i].month = list[i + 1].month;
        list[i].day = list[i + 1].day;
        list[i].priority = list[i + 1].priority;
            }
            --size;
}

        // called once within printall
int LongestTask(ToDo list[MAX], int size) {
    int longest = 0;
    for (int i = 0; i < size; i++) {
        longest = (strlen(list[i].task) > longest) ? strlen(list[i].task) : longest;
    }
    return longest;
}

void consistentSpacing(ToDo list[MAX], int size, int stringlength, int longest) {
    int addSpaces = stringlength;

    while (addSpaces < longest) {
        cout << ' ';
        addSpaces++;
    }
}

void PrintAll(ToDo list[MAX], int& size) {
    if (size == 0) {
        return;
   }    
    int longest = LongestTask(list, size);
    cout << "Type   " << '\t' << " Task";
    consistentSpacing(list, size, 5, longest);
    cout << "  Month" << "  " << "Day" << ' ' << "Priority" << endl;
    for (int i = 0; i < size; i++) {
                // print type
        if (list[i].type == 'p') {
            cout << "Personal ";
        }
        else if (list[i].type == 's') {
            cout << "School   ";
        }
        else {
            cout << "Other    ";
        }

                // print task
        cout << list[i].task;
        consistentSpacing(list, size, strlen(list[i].task), longest);

        cout << ' ';

                // print month
        if (list[i].month == 1) {
            cout << "January   ";
        }
        else if (list[i].month == 2) {
            cout << "February  ";
        }
        else if (list[i].month == 3) {
            cout <<"March      ";
        }
        else if (list[i].month == 4) {
            cout << "April     ";
        }
        else if (list[i].month == 5) {
            cout << "May       ";
        }
        else if (list[i].month == 6) {
            cout << "June      ";
        }
        else if (list[i].month == 7) {
            cout << "July      ";
        }
        else if (list[i].month == 8) {
            cout << "August    ";
        }
        else if (list[i].month == 9) {
            cout << "September ";
        }
        else if (list[i].month == 10) {
            cout << "October   ";
        }
        else if (list[i].month == 11) {
            cout << "November  ";
        }
        else if (list[i].month == 12) {
            cout << "December  ";
        }
        else {
            cout << "Error     ";
        }
                //print day
        cout << list[i].day;
        cout << ' ';

                //prints priority
        if (list[i].priority == 1) {
            cout << "Low         ";
        }
        else if (list[i].priority == 2) {
            cout << "Medium-Low  ";
        }
        else if (list[i].priority == 3) {
            cout << "Medium      ";
        }
        else if (list[i].priority == 4) {
            cout << "Medium-High ";
        }
        else if (list[i].priority == 5) {
            cout << "High        ";
        }
        else {
            cout << ' ';
        }
            //newline between each entry
        cout << endl;
    }
        //newline before new command
    cout << endl;
}

void WriteAll(ToDo list[MAX],int size, ofstream& fout){
    fout.open("todo.txt");

    for (int i = 0; i < size; i++) {
        if (list[i].type != 'p' && list[i].type != 's') {
            fout << 'o';
        }
        else {
            fout << list[i].type;
        }
        fout << '\t';
        fout << list[i].task;
        fout << '\0' << list[i].month;
        fout << '\t';
        fout << list[i].day;
        fout << '\t';
        fout << list[i].priority << endl;
    }
    fout.close();
}

void EraseAll(ofstream& fout) {
    fout.open("todo.txt");
    fout << '\0';
    fout.close();
}

enum choices { ADD, DELETE, DELETEFIRST, DELETELAST, PRINTALL, EXIT };

int main() {
    ToDo list[MAX];
    int choice;
    char word[80];
    int size = 0;
    ifstream fin;
    ofstream fout;
   
    findSize(size, fin);
    ReadList(list, size, fin);

    cout << "enter 0 to add, enter 1,2,3 to delete, enter 4 to print, enter 5 to exit" << endl;

    PrintAll(list, size);

    do {
        cout << "enter 0-4" << endl;
        cin >> choice;

        switch (choice) {
        case ADD:       // adds a new word
            if (size < MAX) {
                AddTask(list, size, word);
                WriteAll(list, size, fout);
            }
            else {
                cout << "List Full. Press 1 to Delete" << endl;
            }
            PrintAll(list, size);
            break;
        case DELETE:        // deletes a word
            if (size > 0) {
                if (DeleteTask(list, size, word) == false) {
                    cout << "Not Found" << endl << endl;
                }
                else {
                    WriteAll(list, size, fout);
                }
            }
            else {
                cout << "list empty" << endl;
            }
            PrintAll(list, size);
            break;
        case DELETEFIRST:
            DeleteFirst(list, size);
            PrintAll(list, size);
            WriteAll(list, size, fout);
            break;
        case DELETELAST:
            DeleteLast(list, size);
            PrintAll(list, size);
            WriteAll(list, size, fout);
            break;
        case PRINTALL:      // prints all
            PrintAll(list, size);
            break;
        }
    } while (choice < 4);  //  4 exits the program
    if (choice == 15) {
        EraseAll(fout);
    }
    return 0;
}
/*


*/
