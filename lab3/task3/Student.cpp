#include "Student.h"
#include <numeric>
#include <sstream>

Student::Student() : Human(), scores() {}

Student::Student(const std::string& firstName, const std::string& lastName, const std::string& patronymic, const std::vector<int>& scores)
    : Human(firstName, lastName, patronymic), scores(scores) {}

void Student::addScore(int score) {
    scores.push_back(score);
}

double Student::getAverageScore() const {
    if (scores.empty()) return 0.0;
    double sum = std::accumulate(scores.begin(), scores.end(), 0.0);
    return sum / scores.size();
}

std::string Student::getShortStudentInfo() const {
    std::stringstream ss;
    ss << getSurnameAndInitials() << ": " << getAverageScore();
    return ss.str();
}

std::string Student::getFullStudentInfo() const {
    std::stringstream ss;
    ss << getFullName() << ": ";
    for (int score : scores) ss << score << " ";
    ss << "- " << getAverageScore();
    return ss.str();
}