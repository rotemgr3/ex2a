#include <iostream>
#include <string>
#include "examDetails.h"
#include <cmath>

namespace mtm {
    const int mtmExam_course_number = 234124;
    const int mtmExam_month = 7;
    const int mtmExam_day = 28;
    const double mtmExam_time = 13;
    const int mtmExam_duration = 3;
    const std::string mtmExam_link = "https://tinyurl.com/59hzps6m";
    const int days_in_month = 30;
    const double epsilon = 10e-6;
    const std::string course_number_string = "Course Number: ";
    const std::string time_string = "Time: ";
    const char dot_char = '.';
    const std::string at_string = " at "; 
    const std::string half_hour_string = ":30";
    const std::string rounded_hour_string = ":00";
    const std::string duration_string = "Duration: ";
    const std::string zoom_link_string = "Zoom Link: ";



    ExamDetails::ExamDetails(int course_number, int month, int day, double time, int duration, std::string link)
    {
        ExamDetails::checkArgs(month, day, time, duration);
        this->course_number = course_number;
        this->month = month;
        this->day = day;
        this->time = time;
        this->duration = duration;
        this->link = link;
    }

    void ExamDetails::checkArgs(int month, int day, double time, int duration)
    {
        /* No need to check course number */
        if(month <= 0 || month > 13) {
            throw ExamDetails::InvalidDateException();
        }
        if(day < 1 || day > 30){
            throw ExamDetails::InvalidDateException();
        }
        if(time < -epsilon || time >= 24 + epsilon) {
            throw ExamDetails::InvalidTimeException();
        }
        double intpart;
        double fract_part = std::modf(time, &intpart);
        if((fract_part < 0.5 - epsilon || fract_part > 0.5 + epsilon)
            && (fract_part < -epsilon || fract_part > epsilon)) {
            throw ExamDetails::InvalidTimeException();
        }
        if(duration <= 0) { 
            throw ExamDetails::InvalidArgsException();
        }
    }

    ExamDetails::ExamDetails(const ExamDetails& exam) : 
        course_number(exam.course_number) ,
        month(exam.month) , 
        day(exam.day) ,
        time(exam.time) ,
        duration(exam.duration) ,
        link(exam.link){}

    ExamDetails ExamDetails::makeMatamExam()
    {
        return ExamDetails(mtmExam_course_number,
                        mtmExam_month,
                        mtmExam_day,
                        mtmExam_time,
                        mtmExam_duration,
                        mtmExam_link);
    }
    ExamDetails& ExamDetails::operator=(const ExamDetails& exam)
    {
        course_number = exam.course_number;
        month = exam.month;
        day = exam.day;
        time = exam.time;
        duration = exam.duration;
        link = exam.link;
        return *this;
    }
    std::string ExamDetails::getLink() const
    {
        return link;
    }
    void ExamDetails::setLink(const std::string new_link)
    {
        link = new_link;
    }
    int ExamDetails::operator-(const ExamDetails& exam) const
    {
        return (month - exam.month)*days_in_month + (day - exam.day);
    }
    bool ExamDetails::operator<(const ExamDetails& exam) const
    {
        int delta = *this - exam;
        if(delta > 0){
            return false;
        }
        if(delta < 0){
            return true;
        }
        if(time + duration < exam.time){
            return true;
        }
        return false;
    }
    std::ostream& operator<<(std::ostream& os, const ExamDetails& exam)
    {
        double intpart;
        double fract_part = std::modf(exam.time, &intpart);
        os << course_number_string << exam.course_number << std::endl;
        os << time_string << exam.day << dot_char << exam.month << at_string;
        if(fract_part == 0.5)
        {
            os << intpart << half_hour_string << std::endl;
        }
        else{
            os << intpart << rounded_hour_string << std::endl;
        }
        os << duration_string << exam.duration << rounded_hour_string << std::endl;
        os << zoom_link_string << exam.link << std::endl;
        return os;
    }
}
