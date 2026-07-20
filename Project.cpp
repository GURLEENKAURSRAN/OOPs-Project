#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 
 
class Student { 
private: 
    int rollNo; 
    string name;      
    int marks[10]; 
    int total; 
    float average; 
    char grade; 
    int n; 
 
public: 
    void inputDetails() { 
        cout << "\nEnter Roll Number: "; 
        cin >> rollNo; 
        cin.ignore(1000, '\n');   
        cout << "Enter Name : "; 
        getline(cin, name);         
 
        total = 0; 
        cout<<"Enter number of subjects: "; 
        cin>>n; 
        for (int i = 0; i < n; i++) { 
            cout << "Enter marks for subject " << i + 1 << ": "; 
            cin >> marks[i]; 
            total += marks[i]; 
        } 
        average = total / n; 
 
        if (average >= 90) grade = 'A'; 
        else if (average >= 75) grade = 'B'; 
        else if (average >= 60) grade = 'C'; 
        else if (average >= 50) grade = 'D'; 
        else grade = 'F'; 
    } 
 
    void displayDetails() { 
        cout << "\n------- STUDENT DETAILS -------\n"; 
       cout << "Name : " << name << endl; 
        cout << "Roll No : " << rollNo << endl; 
        cout << "Total Marks : " << total << endl; 
        cout << "Average : " << average << endl; 
        cout << "Grade : " << grade << endl; 
        cout << "--------------------------------\n"; 
    } 
 
    int getRollNo() { return rollNo; } 
 
   void SaveToFile(ofstream &out) { 
        out << rollNo << endl; 
        out << name << endl;           
        for (int i = 0; i < 10; i++) 
            out << marks[i] << " "; 
        out << endl; 
    } 
 
    bool readFromFile(ifstream &in) { 
        if (!(in >> rollNo))  
return false; 
        in >> name;                    
       total = 0; 
        for (int i = 0; i < 10; i++) { 
            in >> marks[i]; 
            total += marks[i]; 
        }         
average = total /  float(n); 
 
        if (average >= 90) grade = 'A'; 
        else if (average >= 75) grade = 'B'; 
        else if (average >= 60) grade = 'C'; 
        else if (average >= 50) grade = 'D'; 
        else grade = 'F'; 
        return true; 
    } 
 
    void editDetails() { 
        cout << "\nEditing Student (Roll No: " << rollNo << ")\n"; 
        cin.ignore(1000, '\n');   
        cout << "Enter new Name : "; 
        getline(cin, name); 
 
        total = 0; 
        cout<<"Enter number of subjects: "; 
        cin>>n; 
             
        for (int i = 0; i < n; i++) { 
            cout << "Enter marks for subject " << i + 1 << ": "; 
            cin >> marks[i]; 
 
            total += marks[i]; 
        } 
        average = total /  float(n); 
 
        if (average >= 90) grade = 'A'; 
        else if (average >= 75) grade = 'B'; 
        else if (average >= 60) grade = 'C'; 
        else if (average >= 50) grade = 'D'; 
        else grade = 'F'; 
 
        cout << "Record updated successfully.\n"; 
    } 
}; 
 
int main() { 
    Student s1[100]; 
    int count = 0; 
    int choice; 
    ifstream inFile("students.txt"); 
    if (inFile) { 
        Student temp; 
        while (temp.readFromFile(inFile)) { 
            s1[count++] = temp; 
            if (count >= 100) break;  
        } 
        inFile.close(); 
    } 
 
    do { 
        cout << "\n===== STUDENT GRADE MANAGEMENT SYSTEM =====\n"; 
        cout << "1. Add Student Details\n"; 
        cout << "2. Display All Student Details\n"; 
        cout << "3. Search Student by Roll Number\n"; 
        cout << "4. Edit Student Details\n"; 
        cout << "5. Save & Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        if (choice == 1) { 
            if (count < 100) { 
 
                s1[count].inputDetails(); 
                count++; 
                cout << "Student Added Successfully!\n"; 
            } else { 
                cout << "Maximum student limit reached.\n"; 
            } 
        } 
        else if (choice == 2) { 
            if (count == 0) 
                cout << "No Student Records Found!\n"; 
            else 
                for (int i = 0; i < count; i++) 
                    s1[i].displayDetails(); 
        } 
        else if (choice == 3) { 
            int r, found = 0; 
            cout << "Enter Roll Number to search: "; 
            cin >> r; 
 
            for (int i = 0; i < count; i++) { 
                if (s1[i].getRollNo() == r) { 
                    s1[i].displayDetails(); 
                    found = 1; 
                    break; 
                } 
            } 
            if (!found) 
                cout << "Student Not Found!\n"; 
      } 
        else if (choice == 4) { 
            int r, found = 0; 
            cout << "Enter Roll Number to edit: "; 
            cin >> r; 
 
            for (int i = 0; i < count; i++) { 
                if (s1[i].getRollNo() == r) { 
                    s1[i].editDetails(); 
                    found = 1; 
                    break; 
                } 
            } 
            if (!found) 
                cout << "Student Not Found!\n"; 
        } 
        else if (choice == 5) { 
            ofstream fout("students.txt"); 
            for (int i = 0; i < count; i++) 
                s1[i].SaveToFile(fout); 
            fout.close(); 
            cout << "Data Saved Successfully. Exiting...\n"; 
   } 
        else { 
            cout << "Invalid Choice! Try Again.\n"; 
        } 
 
    } while (choice != 5); 
 
    return 0; 
} 
 