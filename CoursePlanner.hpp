#ifndef COURSEPLANNER_HPP
#define COURSEPLANNER_HPP

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

// The Course class represents a single course offering.
class Course {
public:
    // default constructor
    Course() : courseNumber(""), name("") {} 

    // Constructor initializes a course with a given number and name.
    Course(const std::string& courseNum, const std::string& courseName)
    : courseNumber(courseNum), name(courseName) {}

    // Adds a prerequisite to the course's list of prerequisites.
    void addPrerequisite(const std::string& prereq) {
        prerequisites.push_back(prereq);
    }

    // Returns the course number.
    std::string getCourseNumber() const {
        return courseNumber;
    }

    // Returns the name of the course.
    std::string getName() const {
        return name;
    }

    // Returns a list of prerequisites for the course.
    const std::vector<std::string>& getPrerequisites() const {
        return prerequisites;
    }

private:
    std::string courseNumber;              // Unique identifier for the course.
    std::string name;                      // Name of the course.
    std::vector<std::string> prerequisites; // List of prerequisite course numbers.
};

// The CoursePlanner class maintains a collection of courses and supports operations
// such as loading data from a file and printing course information.
class CoursePlanner {
public:
    // Loads course data from a file.
    void loadData(const std::string& filename);
    
    // Prints a list of all courses in the planner.
    void printCourseList() const;
    
    // Prints detailed information about a specific course.
    void printCourse(const std::string& courseNumber) const;

private:
    // A map from course numbers to Course objects. It helps in quick retrieval of courses.
    std::map<std::string, Course> courses;
};

#endif // COURSEPLANNER_HPP
