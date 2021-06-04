#ifndef EXAM_DETAILS_H_
#define EXAM_DETAILS_H_
#include <string>
#include <ostream>

namespace mtm {
    class ExamDetails {
        private:
            int course_number;
            int month;
            int day;
            double time;
            int duration;
            std::string link;

        public:
            ExamDetails(int course_number,
                        int month,
                        int day,
                        double time,
                        int duration,
                        std::string link= "");
            ExamDetails(const ExamDetails& exam);
            ~ExamDetails() = default;
            static ExamDetails makeMatamExam();
            ExamDetails& operator=(const ExamDetails& exam);
            std::string getLink() const;
            void setLink(const std::string new_link);
            int operator-(const ExamDetails& exam) const;
            bool operator<(const ExamDetails& exam) const;
            friend std::ostream& operator<<(std::ostream& os, const ExamDetails& exam);
            class InvalidDateException {};
            class InvalidTimeException {};
            class InvalidArgsException {};
    };
};

#endif /*EXAM_DETAILS_H_*/