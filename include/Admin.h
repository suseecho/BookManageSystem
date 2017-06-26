#ifndef ADMIN_H
#define ADMIN_H
#include "Book.h"

class Admin
{
private:
    //管理员用户名
    std::string m_id;
    //管理员密码
    std::string m_passwd;

public:
    Admin();
    Admin(std::string id,std::string passwd);
    //加入书籍
    void input(Book book,std::map<std::string,Book> & books);//TO_DO
    //注册读者
    void logon(Reader reader,std::map<std::string,Reader> &  readers);
    //删除书籍
    void deleteBook(std::string bookId, std::map<std::string,Book> & books);
    //注销读者信息
    void deleteReader(std::string readerId, std::map<std::string, Reader> &readers);
    //办理读者借书手续
    void retBook(std::string bookId,std::vector<Book> & books);
    //办理读者还书手续
    void lendBook(std::string bookId,std::vector<Book> & books);
    std::string getId();
    bool login(std::string passwd);
    std::string getPasswd();
};

#endif //ADMIN_H
