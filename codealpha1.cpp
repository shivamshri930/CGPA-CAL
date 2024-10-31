#include <iostream>
#include <vector>
using namespace std;

struct Course {
    string courseName;
    double grade;   // Grade on a 4.0 scale
    int credits;
};

double calculateGPA(const vector<Course>& courses) {
    double totalGradePoints = 0;
    int totalCredits = 0;

    for (const auto& course : courses) {
        totalGradePoints += course.grade * course.credits;
        totalCredits += course.credits;
    }

    return (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;
}

void displayGrades(const vector<Course>& courses) {
    cout << "\nCourse Grades:\n";
    for (const auto& course : courses) {
        cout << course.courseName << ": " << course.grade << " (" << course.credits << " credits)" << endl;
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<Course> courses(numCourses);

    // Input course details
    for (int i = 0; i < numCourses; ++i) {
        cout << "\nEnter details for course " << i + 1 << ":\n";
        cout << "Course Name: ";
        cin >> courses[i].courseName;
        cout << "Grade (on a 4.0 scale): ";
        cin >> courses[i].grade;
        cout << "Credits: ";
        cin >> courses[i].credits;
    }

    // Display each course's grade
    displayGrades(courses);

    // Calculate and display GPA for the semester
    double semesterGPA = calculateGPA(courses);
    cout << "\nSemester GPA: " << semesterGPA << endl;

    // If the CGPA is calculated from multiple semesters, assume more details for CGPA calculation
    int numSemesters;
    cout << "\nEnter the number of semesters for CGPA calculation: ";
    cin >> numSemesters;

    double cumulativeGPA = 0;
    int cumulativeCredits = 0;

    for (int i = 0; i < numSemesters; ++i) {
        int semesterCredits;
        double semesterGPA;
        cout << "\nEnter total credits for semester " << i + 1 << ": ";
        cin >> semesterCredits;
        cout << "Enter GPA for semester " << i + 1 << ": ";
        cin >> semesterGPA;

        cumulativeGPA += semesterGPA * semesterCredits;
        cumulativeCredits += semesterCredits;
    }

    double CGPA = (cumulativeCredits > 0) ? (cumulativeGPA / cumulativeCredits) : 0.0;
    cout << "\nCumulative GPA (CGPA): " << CGPA << endl;

    return 0;
}