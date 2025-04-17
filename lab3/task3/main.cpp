#include <iostream>
#include <vector>
#include <fstream>
#include "Student.h"
#include "Teacher.h"

// Оператор вывода для Position
std::ostream& operator<<(std::ostream& os, const Position& pos) {
    switch(pos) {
        case Position::ASSISTANT: os << "Assistant"; break;
        case Position::SENIOR_LECTURER: os << "Senior Lecturer"; break;
        case Position::DOCENT: os << "Docent"; break;
        case Position::PROFESSOR: os << "Professor"; break;
        default: os << "Unknown";
    }
    return os;
}

void saveStudentsToFile(const std::vector<Student>& students, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing students!\n";
        return;
    }
    for (const auto& student : students) {
        file << student.getFullName() << " | Scores: ";
        for (int score : student.getScores()) {
            file << score << " ";
        }
        file << "\n";
    }
    file.close();
}

void saveTeachersToFile(const std::vector<Teacher>& teachers, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing teachers!\n";
        return;
    }
    for (const auto& teacher : teachers) {
        file << teacher.getFullName() << " | Position: " << teacher.getPosition() << " | Subjects: ";
        for (const auto& subject : teacher.getSubjects()) {
            file << subject << ", ";
        }
        file << "\n";
    }
    file.close();
}

int main() {
    std::vector<Student> students = {
        Student("John", "Doe", "Smith", {4, 5, 5}),
        Student("Jane", "Smith", "Brown", {3, 3, 4}),
    };

    std::vector<Teacher> teachers = {
        Teacher("Alice", "Johnson", "Lee", Position::DOCENT, {"OOP", "Algorithms"}),
        Teacher("Bob", "Williams", "Taylor", Position::PROFESSOR, {"Informatics", "Databases"}),
    };

    saveStudentsToFile(students, "students.txt");
    saveTeachersToFile(teachers, "teachers.txt");

    std::cout << "Students with average > 4:\n";
    for (const auto& student : students) {
        if (student.getAverageScore() > 4.0) {
            std::cout << student.getShortStudentInfo() << "\n";
        }
    }

    std::cout << "\nStudents with average < 3:\n";
    for (const auto& student : students) {
        if (student.getAverageScore() < 3.0) {
            std::cout << student.getShortStudentInfo() << "\n";
        }
    }

    size_t maxScores = 0;
    const Student* topStudent = nullptr;
    for (const auto& student : students) {
        if (student.getScores().size() > maxScores) {
            maxScores = student.getScores().size();
            topStudent = &student;
        }
    }
    if (topStudent) {
        std::cout << "\nStudent with the most scores:\n";
        std::cout << topStudent->getFullStudentInfo() << "\n";
    }

    std::cout << "\nAll Docents:\n";
    for (const auto& teacher : teachers) {
        if (teacher.getPosition() == Position::DOCENT) {
            std::cout << teacher.getShortTeacherInfo() << "\n";
        }
    }

    size_t maxSubjects = 0;
    const Teacher* topProfessor = nullptr;
    for (const auto& teacher : teachers) {
        if (teacher.getPosition() == Position::PROFESSOR && teacher.getSubjects().size() > maxSubjects) {
            maxSubjects = teacher.getSubjects().size();
            topProfessor = &teacher;
        }
    }
    if (topProfessor) {
        std::cout << "\nProfessor with the most subjects:\n";
        std::cout << topProfessor->getFullTeacherInfo() << "\n";
    }

    std::cout << "\nTeachers teaching Informatics:\n";
    for (const auto& teacher : teachers) {
        for (const auto& subject : teacher.getSubjects()) {
            if (subject == "Informatics") {
                std::cout << teacher.getFullTeacherInfo() << "\n";
                break;
            }
        }
    }

    return 0;
}