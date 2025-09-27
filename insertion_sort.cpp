#include <bits/stdc++.h>
using namespace std;

struct Student {
    int rollNo;
    int marks;
};

// Function for Insertion Sort
void insertionSort(vector<Student> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        Student key = arr[i];
        int j = i - 1;

        // Move elements greater than key.marks to one position ahead
        while (j >= 0 && arr[j].marks > key.marks) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    ifstream inputFile("roll_marks.csv"); // Input CSV file
    ofstream outputFile("sorted_roll_marks.csv"); // Output CSV file

    if (!inputFile.is_open()) {
        cout << "Error opening input file!" << endl;
        return 1;
    }

    vector<Student> students;
    string line;

    getline(inputFile, line); // Skip header

    // Read CSV file
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string token;
        Student s;

        getline(ss, token, ',');
        s.rollNo = stoi(token);

        getline(ss, token, ',');
        s.marks = stoi(token);

        students.push_back(s);
    }

    // Sort using insertion sort
    insertionSort(students);

    // Write sorted data to new CSV
    outputFile << "RollNo,Marks\n";
    for (auto s : students) {
        outputFile << s.rollNo << "," << s.marks << "\n";
    }

    inputFile.close();
    outputFile.close();

    cout << "Sorting completed. Check sorted_roll_marks.csv\n";
    return 0;
}
