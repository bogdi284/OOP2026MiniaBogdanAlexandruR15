#pragma once

class student {
    private:
        char* name;
        float mathGrade;
        float englishGrade;
        float historyGrade;
    public:
        student();
        student (char* name , float math , float english , float history) ;

        void setName(char* name);
        char* getName();

        void setMathGrade (float grade);
        float getMathGrade();

        void setEnglishGrade (float grade);
        float getEnglishGrade();

        void setHistoryGrade (float grade);
        float getHistoryGrade();

        float average();

};