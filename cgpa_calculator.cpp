#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main()
{
    int numCourses;
    double grade, credits;
    double totalGradePoints = 0.0;
    double totalCredits = 0.0;
    double gpa = 0.0;
    
    vector<pair<double, double>> courses; // Store grade and credits
    
    cout << "\n========== CGPA CALCULATOR ==========" << endl;
    cout << "\nEnter the number of courses: ";
    cin >> numCourses;
    
    if(numCourses <= 0)
    {
        cout << "\nInvalid number of courses! Please enter a positive number." << endl;
        return 1;
    }
    
    cout << "\n--- Enter Course Details ---" << endl;
    
    // Input grades and credit hours for each course
    for(int i = 1; i <= numCourses; i++)
    {
        cout << "\nCourse " << i << ":" << endl;
        
        cout << "  Enter Grade (0.0 - 4.0): ";
        cin >> grade;
        
        if(grade < 0 || grade > 4.0)
        {
            cout << "  Invalid grade! Grade must be between 0.0 and 4.0" << endl;
            i--;
            continue;
        }
        
        cout << "  Enter Credit Hours: ";
        cin >> credits;
        
        if(credits <= 0)
        {
            cout << "  Invalid credit hours! Please enter a positive number" << endl;
            i--;
            continue;
        }
        
        courses.push_back({grade, credits});
        totalGradePoints += (grade * credits);
        totalCredits += credits;
    }
    
    // Calculate GPA/CGPA
    if(totalCredits > 0)
    {
        gpa = totalGradePoints / totalCredits;
    }
    
    // Display Results
    cout << "\n\n========== RESULTS ==========" << endl;
    
    cout << "\n--- Individual Course Grades ---" << endl;
    cout << setw(10) << "Course" << setw(15) << "Grade" << setw(15) << "Credits" << setw(20) << "Grade Points" << endl;
    cout << "-----------------------------------------------------------" << endl;
    
    for(int i = 0; i < courses.size(); i++)
    {
        cout << setw(10) << i+1 
             << setw(15) << fixed << setprecision(2) << courses[i].first
             << setw(15) << fixed << setprecision(2) << courses[i].second
             << setw(20) << fixed << setprecision(2) << (courses[i].first * courses[i].second)
             << endl;
    }
    
    cout << "-----------------------------------------------------------" << endl;
    
    // Display Summary
    cout << "\n--- Summary ---" << endl;
    cout << "Total Credit Hours: " << fixed << setprecision(2) << totalCredits << endl;
    cout << "Total Grade Points: " << fixed << setprecision(2) << totalGradePoints << endl;
    cout << "\n*** OVERALL CGPA: " << fixed << setprecision(2) << gpa << " ***" << endl;
    
    // GPA Grading Scale Interpretation
    cout << "\n--- Grade Interpretation ---" << endl;
    if(gpa >= 3.5)
        cout << "Excellent!" << endl;
    else if(gpa >= 3.0)
        cout << "Very Good!" << endl;
    else if(gpa >= 2.5)
        cout << "Good!" << endl;
    else if(gpa >= 2.0)
        cout << "Satisfactory!" << endl;
    else if(gpa >= 1.5)
        cout << "Pass!" << endl;
    else
        cout << "Below Average" << endl;
    
    cout << "\n========================================\n" << endl;
    
    return 0;
}
