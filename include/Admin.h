#ifndef ADMIN_H
#define ADMIN_H
#include "Book.h"

class Admin
{
private:
    std::string m_id;
    std::string m_passwd;

public:
    Admin(std::string id,std::string passwd);
    bool input(Book book);//TO_DO
    bool logon(Reader reader);
    bool deleteBook(std::string bookId);
    bool deleteReader(std::string readerId);
    bool retBook(std::string bookId);
    bool lendBook(std::string bookId);
};

#endif //ADMIN_H
