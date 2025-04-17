#include "Teacher.h"
#include <sstream>
#include <map>

const std::map<Position, std::string> POSITION_NAMES = {
    {Position::ASSISTANT, "Assistant"},
    {Position::SENIOR_LECTURER, "Senior Lecturer"},
    {Position::DOCENT, "Docent"},
    {Position::PROFESSOR, "Professor"},
    {Position::UNKNOWN, "Unknown"}
};

Teacher::Teacher() : Human(), position(Position::UNKNOWN), subjects() {}

Teacher::Teacher(const std::string& firstName, const std::string& lastName, const std::string& patronymic, Position position, const std::vector<std::string>& subjects)
    : Human(firstName, lastName, patronymic), position(position), subjects(subjects) {}

void Teacher::addSubject(const std::string& subject) {
    subjects.push_back(subject);
}

std::string Teacher::getShortTeacherInfo() const {
    std::stringstream ss;
    ss << getSurnameAndInitials() << " " << POSITION_NAMES.at(position) << ": " << subjects.size() << " subjects";
    return ss.str();
}

std::string Teacher::getFullTeacherInfo() const {
    std::stringstream ss;
    ss << getFullName() << " " << POSITION_NAMES.at(position) << ": ";
    for (size_t i = 0; i < subjects.size(); ++i) {
        if (i != 0) ss << ", ";
        ss << subjects[i];
    }
    return ss.str();
}