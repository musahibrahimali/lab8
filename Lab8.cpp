#include <iostream>
#include <iomanip> 
#include<string>

using namespace std;

class Student {
    private:
        int NumGrades = 0;
        float Average = 0;
        float* Grades = new float[NumGrades];

    public:

        // get the average of the student
        float GetAverage() {
            return Average;
        }

        // set the average of the student
        void SetAverage(float average) {
            Average = average;
        }

        // get the number of grades a student has
        int GetNumGrades() {
            return NumGrades;
        }

        // set the number of grades a student has
        void SetNumGrades(int numGrades) {
            NumGrades = numGrades;
        }

        // format and print the array of grades to the console
        void GetGrades() {
            SortGrades();
            cout << "The grades are = [ ";
            for (int i = 0; i < NumGrades; i++) {
                cout << Grades[i] << " ";
            }
            cout << "]";
        }

        // assign the values to the array by their index
        void SetGrades(int index, float value) {
            Grades[index] = value;
        }

        // take the grades from the user based on the number of grades the student has
        void GetGradesFromUser() {
            for (int i = 0; i < NumGrades; i++) {
                float temp = 0;
                cout << "Input grade " << i + 1 << " : ";
                cin >> temp;
                if (temp > 0 && temp < 100) {
                    SetGrades(i, temp);
                }
                else {
                    cout << "Invalid input, Grade must be between 0 - 100." << endl;
                    cout << "Input grade " << i + 1 << " : ";
                    cin >> temp;
                }
            }
        }

        // calculate the average of the student
        void CalculateAverage() {
            float average = 0;
            for (int i = 0; i < sizeof(Grades); i++) {
                average += Grades[i];
            };
            SetAverage(average / (float)NumGrades); // set the average to the average variable 
           
            cout << "The Student's Average is " << setprecision(2) << Average << endl;
        }

        void SortGrades() {
            for (int j = 0; j < NumGrades; j++)
            {
                for (int k = j + 1; k < NumGrades; k++)
                {
                    if (Grades[j] > Grades[k])
                    {
                        float temp = Grades[j];
                        Grades[j] = Grades[k];
                        Grades[k] = temp;
                    }
                }
            }
        }  

        void GetMinAndMax() {
            SortGrades(); // sort grades to arrange them in ascending order
            float max = Grades[NumGrades - 1]; // get the last value of the array
            float min = Grades[0]; // get the first value of the array
            cout << "The minimun grade is " << min << "." << endl;
            cout << "The maximum grade is " << max << "." << endl;
        }
};


int main(){
    const int students = 3;
    string student = "student";
    for (int i = 0; i < students; i++) {
        int temp; // temporary value to hold user input for validation
        cout << endl; // just for formating purposes
        cout << "How many grades do you have : ";
        cin >> temp;
        cout << endl; // just for formating purposes
        //string newStudent = student+to_string(i+1);
        Student student; // an instance of the student class
        student.SetNumGrades(temp); // set the number of grades student has
        student.GetGradesFromUser(); // take grades from the user based on the number of grades
        cout << endl; // just for formating purposes
        student.CalculateAverage(); // calculate the average of the student
        student.GetGrades(); // get all grades provided by user
        cout << endl; // just for formating purposes (a '\n' can be used for the same effects
        student.GetMinAndMax(); // get minimum and maximum grade
    }
    return 0;
}