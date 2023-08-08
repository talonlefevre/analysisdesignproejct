#include "CoursePlanner.hpp"

// Loads course data from a file.
void CoursePlanner::loadData(const std::string& filename) {
    std::ifstream file(filename);

    // Check if the file is open.
    if (!file.is_open()) {
        std::cerr << "Failed to open the file " << filename << std::endl;
        return;
    }

    std::string line;
    // Read each line from the file.
    while (getline(file, line)) {
        size_t pos = line.find(',');
        
        // Extract course number and rest of the line.
        std::string courseNumber = line.substr(0, pos);
        std::string rest = line.substr(pos + 1);
        
        // Extract course name and update the rest of the string.
        pos = rest.find(',');
        std::string name = rest.substr(0, pos);
        rest = rest.substr(pos + 1);

        // Create a new Course object.
        Course course(courseNumber, name);

        // Read prerequisites and add them to the Course object.
        while ((pos = rest.find(',')) != std::string::npos) {
            std::string prereq = rest.substr(0, pos);
            course.addPrerequisite(prereq);
            rest = rest.substr(pos + 1);
        }

        // If there's still data in the 'rest' string, it's a prerequisite.
        if (!rest.empty()) {
            course.addPrerequisite(rest);
        }

        // Store the Course object in the 'courses' map.
        courses[courseNumber] = course;
    }

    file.close();
}

// Print all the courses in the 'courses' map.
void CoursePlanner::printCourseList() const {
    for (const auto& pair : courses) {
        const Course& course = pair.second;
        std::cout << course.getCourseNumber() << ", " << course.getName() << std::endl;
    }
}

// Print details of a specific course, given its course number.
void CoursePlanner::printCourse(const std::string& courseNumber) const {
    // Check if the course exists in the 'courses' map.
    if (courses.find(courseNumber) == courses.end()) {
        std::cerr << "Course not found." << std::endl;
        return;
    }

    const Course& course = courses.at(courseNumber);
    std::cout << course.getCourseNumber() << ", " << course.getName() << std::endl;

    // Print prerequisites if they exist.
    const auto& prerequisites = course.getPrerequisites();
    if (!prerequisites.empty()) {
        std::cout << "Prerequisites: ";
        for (size_t i = 0; i < prerequisites.size(); i++) {
            std::cout << prerequisites[i];
            if (i != prerequisites.size() - 1) { // If it's not the last prerequisite.
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}
