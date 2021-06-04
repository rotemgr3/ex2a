#ifndef EXAM_DETAILS_H_
#define EXAM_DETAILS_H_
#include <string>

namespace mtm {
    class ExamDetails {
        private:
            int course_number;
            int month;
            int day;
            int time;
            int duration;
            std::String link;

        public:
            ExamDetails(int course_number,
                        int month,
                        int day,
                        int time,
                        int duration,
                        std::String link= "");
            ExamDetails(const ExamDetails& exam);
            ~ExamDetails();
            ExamDetails static makeMatamExam();
            ExamDetails& operator=(const ExamDetails& exam);
            std::String getLink() const;
            std::String setLink(const std::String new_link);
            int operator-(const ExamDetails& exam) const;
            bool operator<(const ExamDetails& exam) const;
            friend ostream& operator<<(ostream& os, const ExamDetails& exam);
            class ExamDetails::InvalidDateException {};
            class ExamDetails::InvalidTimeException {};
            class ExamDetails::InvalidArgsException {};
    }
}

#endif /*EXAM_DETAILS_H_*/