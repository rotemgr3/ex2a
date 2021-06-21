#ifndef EXAM_DETAILS_H_
#define EXAM_DETAILS_H_
#include <string>
#include <iostream>

namespace mtm {
    class ExamDetails {
        public:
            /**
            * ExamDetails(constructor): create an ExamDetails object. 
            * @param this - pointer to the ExamDetails object we create.
            * @param course_number - the number of the course.
            * @param month - a number between 1 to 12 that represent a month.
            * @param day - a number between 1 to 30 that represent a day in month.
            * @param time - the hour that the exam starts.
            * @param duration - the duration of the exam
            * @param link - a zoom link to the exam. empty string if we dont get a link.
            * 
            * @throw InvalidDateException - if the month isn't between 1 to 12,
            * or the day isn't between 1 to 30.
            *        InvalidTimeException - if the hour isn't between 0 to 24.
            * or if the hour doesn't look like: XX:30 or XX:00.
            *        InvalidArgsException - if the duration isn't a positive number.       
            */
            ExamDetails(int course_number,
                        int month,
                        int day,
                        double time,
                        int duration,
                        std::string link = "");
            /**
            * ExamDetails(copy constructor): copies an ExamDetails object. 
            * @param this - pointer to the ExamDetails object we copy into.
            * @param exam - the exam we want to copy.   
            */
            ExamDetails(const ExamDetails& exam);
            
            //We dont allow the user to create an empty ExamDetails object
            ExamDetails() = delete;
            
            /**
            * ~ExamDetails(destructor): destructs an ExamDetails object. 
            * default because we dont need to explicitly free something. 
            * @param this - pointer to the ExamDetails object we destruct.
            */
            ~ExamDetails() = default;
            
            /**
            * makeMatamExam:a static function that creates an ExamDetails object with specified fields. 
            * @return A new ExamDetails object with matam course details as fields.
            */
            static ExamDetails makeMatamExam();
            
            /**
            * operator=(assignment operator): copies exam into *this. 
            * @param this - pointer to the ExamDetails object we assign into.
            * @param exam - the exam we want to assign.
            * 
            * @return A refrence to *this after the assignment.
            */
            ExamDetails& operator=(const ExamDetails& exam);
            
            /**
            * getLink: returns the link to the exam. 
            * @param this - pointer to the ExamDetails object that we want its link.
            * @return A new link to the exam.
            */
            std::string getLink() const;
            
            /**
            * setLink: sets a new link to the exam. 
            * @param this - pointer to the ExamDetails object that we want to change its link.
            * @param new_link - the new link we'll set.
            */
            void setLink(const std::string new_link);
            
            /**
            * operator-: returns the difference between the days of two exams. 
            * @param this - pointer to the the first ExamDetails object.
            * @param exam - the second exam.
            * 
            * @return An int which represents the difference.
            */
            int operator-(const ExamDetails& exam) const;
            
            /**
            * operator<: checking if one exam is taking place before the other. 
            * @param this - pointer to the first ExamDetails object.
            * @param exam - the second exam.
            * 
            * @return True - if *this is starting before exam.
            * False - otherwise.
            */
            bool operator<(const ExamDetails& exam) const;
            
            /**
            * operator<<: allows us to print the ExamDetails object properly. 
            * @param exam - the exam we want to print.
            * @param os - the place we want to print into.
            * 
            * @return A refrence to std::ostream& with the new information inside.
            */
            friend std::ostream& operator<<(std::ostream& os, const ExamDetails& exam);
            
            //An exception class that we throw when we get an invalid date.
            class InvalidDateException {};
            
            //An exception class that we throw when we get an invalid time.
            class InvalidTimeException {};
            
            //An exception class that we throw when we get an invalid arguments that are not date or time. 
            class InvalidArgsException {};
            
        private:
            int course_number;
            int month;
            int day;
            double time;
            int duration;
            std::string link;
            /* A private static function that will check if the arguments are valid.
               if not, the function will throw an exception.
               
               Function gets as arguments:
               int course_number - the course number.
               int month - the month.
               int day - the day.
               double time - the time.
               int duration - the duration. 
            */
            /**
            * checkArgs: A private static function that will check if the arguments are valid.
            * if not, the function will throw an exception. 
            * @param month - a number. Will check if its between 1 to 12.
            * @param day - a number. Will check if its between 1 to 30.
            * @param time - the hour that the exam starts. Will check if its a valid hour
            * @param duration - the duration of the exam. Will check if its a valid duration
            
            * @throw InvalidDateException - if the month isn't between 1 to 12,
            * or the day isn't between 1 to 30.
            *        InvalidTimeException - if the hour isn't between 0 to 24.
            * or if the hour doesn't look like: XX:30 or XX:00.
            *        InvalidArgsException - if the duration isn't a positive number.       
            */
            static void checkArgs(int month, int day, double time, int duration);
            
    };
}

#endif /*EXAM_DETAILS_H_*/