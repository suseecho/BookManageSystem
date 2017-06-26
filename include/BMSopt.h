#ifndef BMSOPT_H
#define BMSOPT_H
#include "Root.h"
/*
*对类Admin Root Reader Root的进一步包装
*使用BMSopt对象对这些类的对象及其对象的容器，储存这些类的文件进行操作
*使用单例模式，防止多个对象对文件操作
*/
class BMSopt
{
    public:
        //得到唯一的对象
        static BMSopt * Instance();
        //得到超级管理员密码
        std::string & getRootpasswd();
        //得到管理员类的map引用
        std::map<std::string,Admin> &  getAdmins();
        //得到读者类的map引用
        std::map<std::string,Reader> & getReaders();
        //得到图书类的map引用
        std::map<std::string,Book> &   getBooks();
        //管理员类读入文件
        void adminsToFile();
        //图书类读入文件
        void booksToFile();  //TODO
        //读者类读入文件
        void readersToFile(); //TODO
        //删除管理员
        void deleteAdmin(std::string admin);
        //删除图书
        void deleteBook(std::string bookId);
        //注销读者
        void deleteReader(std::string reader);
        //增加管理员
        void addAdmin(Admin admin);
        //增加图书
        void addBook(Book book);
        //注册读者
        void addReader(Reader reader);
        //设置当前操作人员
        void setOperator(std::string user);
        //得到当前操作人员
        std::string getOperator();

    private:
        //当前操作人员
        std::string                    m_operator;
        BMSopt();
        //唯一的对象的指针
        static BMSopt                  * instance_;
        //存储管路员类
        std::map<std::string,Admin>    m_admins;
        //存储超级管理员密码
        std::string                    m_Rootpasswd;
        //存储读者类
        std::map<std::string,Reader>   m_readers;
        //存储图书类
        std::map<std::string,Book>     m_books;
};

#endif // BMSOPT_H
