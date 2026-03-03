#include <iostream>

#include "student.h"
#include "global.h"

int main () {
    student s1("Bogdan" , 7.5 , 8 ,10) ;
    student s2("Alex" , 5.5 , 10 , 6) ;

    std::cout <<"student 1  " <<'\n';
    std::cout <<"name : "<< s1.getName() <<'\n';
    std::cout <<"mathGrade : "<< s1.getMathGrade() <<'\n';
    std::cout <<"englishGrade : "<< s1.getEnglishGrade() <<'\n';
    std::cout <<"historyGrade : "<< s1.getHistoryGrade() <<'\n';
    std::cout <<"average : " << s1.average() <<'\n';
    std::cout << '\n';

    std::cout <<"student 2  " <<'\n';
    std::cout <<"name : "<< s2.getName() <<'\n';
    std::cout <<"mathGrade : "<< s2.getMathGrade() <<'\n';
    std::cout <<"englishGrade : "<< s2.getEnglishGrade() <<'\n';
    std::cout <<"historyGrade : "<< s2.getHistoryGrade() <<'\n';
    std::cout <<"average : " << s2.average() <<'\n';
    std::cout<<'\n';

    std::cout <<"comparisons "<<'\n';
    std::cout << "by Name : " << compareName(s1 , s2)<<'\n';
    std::cout << "by mathGrade : " << compareMath(s1 , s2)<<'\n';
    std::cout << "by englishGrade : " << compareEnglish(s1 , s2)<<'\n';
    std::cout << "by historyGrade : " << compareHistory(s1 , s2)<<'\n';
    std::cout << "by average : " << compareAverage(s1 , s2)<<'\n';
    std::cout << '\n' ;
    
    s1.setName ("Alex");
    s2.setName ("Bogdan");
    s1.setMathGrade (10.0) ;
    s2.setMathGrade (8.5) ;
    s1.setEnglishGrade (7.5);
    s2.setEnglishGrade (9.25);
    s1.setHistoryGrade(6.5) ;
    s2.setHistoryGrade(8.33) ;

    std::cout <<"student 1  " <<'\n';
    std::cout <<"name : "<< s1.getName() <<'\n';
    std::cout <<"mathGrade : "<< s1.getMathGrade() <<'\n';
    std::cout <<"englishGrade : "<< s1.getEnglishGrade() <<'\n';
    std::cout <<"historyGrade : "<< s1.getHistoryGrade() <<'\n';
    std::cout <<"average : " << s1.average() <<'\n';
    std::cout << '\n';

    std::cout <<"student 2  " <<'\n';
    std::cout <<"name : "<< s2.getName() <<'\n';
    std::cout <<"mathGrade : "<< s2.getMathGrade() <<'\n';
    std::cout <<"englishGrade : "<< s2.getEnglishGrade() <<'\n';
    std::cout <<"historyGrade : "<< s2.getHistoryGrade() <<'\n';
    std::cout <<"average : " << s2.average() <<'\n';
    std::cout<<'\n';

    std::cout <<"comparisons "<<'\n';
    std::cout << "by Name : " << compareName(s1 , s2)<<'\n';
    std::cout << "by mathGrade : " << compareMath(s1 , s2)<<'\n';
    std::cout << "by englishGrade : " << compareEnglish(s1 , s2)<<'\n';
    std::cout << "by historyGrade : " << compareHistory(s1 , s2)<<'\n';
    std::cout << "by average : " << compareAverage(s1 , s2)<<'\n';
    std::cout << '\n' ;

    return 0;
}