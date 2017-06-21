#ifndef BOOK_H
#define BOOK_H
#include "Reader.h"


class Book
{
public:
    Book(std::string name , std::string id, double price , std::string author , bool exist , std::string reader_id);
    std::string getName();
    std::string getId();
    double getPrice();
    std::string getAuthor();
    bool isExist();
    std::string getReaderId();
    void setNum();
    unsigned getNum();
    friend operator<<(const std::ostream & out,const Book &book);
//    friend operator>>(const std::istream & in,Book &book);
private:
    std::string m_name;
    std::string m_id;
    double m_price; //注意小数位数
    std::string m_author;
    short int   m_status;
    std::string m_readerid;
    unsigned  m_num;
};

#endif // BOOK_H
