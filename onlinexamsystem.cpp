//abstract base class
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Exam {
protected:
    int examID;
    string subject;
    int duration; // in minutes
public:
    Exam(int id, string sub, int dur) : examID(id), subject(sub), duration(dur) {}
    virtual double gradeExam() = 0;
    virtual void displayInfo() {
        cout << "Exam ID: " << examID << ", Subject: " << subject << ", Duration: " << duration << " minutes" << endl;
    }
    virtual ~Exam() {} 
};

//derived classes
class MultipleChoiceExam : public Exam {
    vector<string> questions;
    int correctAnswers;
public:
    MultipleChoiceExam(int id, string sub, int dur, int correct) : Exam(id, sub, dur), correctAnswers(correct) {}
    double gradeExam() override {
        return correctAnswers * 10; 
    }
    void displayInfo() override {
        Exam::displayInfo();
        cout << "Correct Answers: " << correctAnswers << endl;
    }
};

class EssayExam : public Exam {
    string topic;
public:
    EssayExam(int id, string sub, int dur, string tp) : Exam(id, sub, dur), topic(tp) {}
    double gradeExam() override {
        return 80.0; // Fixed score for simplicity
    }
    void displayInfo() override {
        Exam::displayInfo();
        cout << "Essay Topic: " << topic << endl;
    }
};

//mainfunction
int main() {
    MultipleChoiceExam mcExam(1, "Math", 60, 8);
    EssayExam essayExam(2, "Physics", 90, "The Renaissance");

    Exam* exams[] = { &mcExam, &essayExam };

    for (Exam* ex : exams) {
        ex->displayInfo();
        cout << "Grade: " << ex->gradeExam() << endl;
        cout << "-----------------------------" << endl;
    }
    return 0;
}

