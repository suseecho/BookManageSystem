#include "../include/BMSopt.h"

BMSopt* BMSopt::instance_ = 0;

BMSopt::BMSopt()
{
    //ctor
}

BMSopt * BMSopt::Instance()
{
    if(instance_ == NULL){
        instance_ = new BMSopt();
    }
    return instance_;
}

std::string & BMSopt::getRootpasswd()
{
    if(this->m_Rootpasswd != "")
        return this->m_Rootpasswd;
    std::ifstream in("Admin/Root.dat",std::ios_base::binary);
    if(!in){
        std::cout<<"Root.dat文件打开失败"<<std::endl;
        in.close();
        exit(0);
    }
    in>>this->m_Rootpasswd;
    in.close();
    return this->m_Rootpasswd;
}

std::map<std::string,Admin> & BMSopt::getAdmins()
{
    if(((this->m_admins).empty())){
        std::string id,passwd;
        std::ifstream in("Admin/Admin.dat",std::ios_base::binary);
        while(in>>id>>passwd){
            Admin temp(id,passwd);
            this->m_admins[id] = temp;
        }
    }
    return this->m_admins;
}

std::map<std::string,Reader> & BMSopt::getReaders()
{
    if((this->m_readers).empty()){
        std::ifstream in("Readers/Readers.dat",std::ios_base::binary);
        if(!in){
            std::cout<<"Readers.dat文件打开失败！！"<<std::endl;
            in.close();
            exit(0);
        }
        std::string name, id;
        bool gender;
        while(in>>name>>gender>>id){
            this->m_readers.emplace(std::make_pair(id,Reader(name,gender,id)));
        }
    }
    return this->m_readers;
}

std::map<std::string,Book> & BMSopt::getBooks()
{
     if((this->m_books).empty()){
        std::ifstream in("Books/Books.dat",std::ios_base::binary);
        if(!in){
            std::cout<<"Books.dat文件打开失败！！"<<std::endl;
            in.close();
            exit(0);
        }
        std::string name, id,author;
        double price;
        unsigned int num,status;
        while(in>>name>>id>>price>>author>>num>>status){
            this->m_books.emplace(std::make_pair(id,Book(name,id,price,author,num,status)));
        }
    }
     return this->m_books;
}

void BMSopt::adminsToFile()
{
    std::string filename = "Admin/Admin.dat";
    std::ofstream out(filename,std::ios_base::binary|std::ios_base::out);
    if(!out){
        std::cout<<"打开文件Admin/Admin.dat失败"<<std::endl;
        out.close();
        exit(0);
    }
    auto temp = this->getAdmins();
    for(auto it = temp.begin(); it != temp.end(); it++){
        out<<it->first<<" "<<it->second.getPasswd()<<std::endl;
    }
    out.close();
}

void BMSopt::booksToFile()
{
    std::string filename = "Books/Books.dat";
    std::ofstream out(filename,std::ios_base::binary|std::ios_base::out);
    if(!out){
        std::cout<<"打开文件Books/Books.dat失败"<<std::endl;
        out.close();
        exit(0);
    }
    auto temp = this->getBooks();
    for(auto it = temp.begin(); it != temp.end(); it++){
        Book & book = it->second;
        out<<book.getName()<<" "<<book.getId()<<" "
           <<book.getPrice()<<" "<<book.getAuthor()<<" "
           <<book.getNum()<<" "<<book.getStatus()<<std::endl;
    }
    out.close();
}

void BMSopt::readersToFile()
{
    std::string filename = "Readers/Readers.dat";
    std::ofstream out(filename,std::ios_base::binary|std::ios_base::out);
    if(!out){
        std::cout<<"打开文件Readers/Readers.dat失败"<<std::endl;
        out.close();
        exit(0);
    }
    auto temp = this->getReaders();
    for(auto it = temp.begin(); it != temp.end(); it++){
        Reader &  reader = it->second;
        out<<reader.getName()<<" "<<reader.getGender()<<" "
           <<reader.getId()<<std::endl;
    }
    out.close();
}

void BMSopt::deleteAdmin(std::string adminId)
{
    Root *temp = new Root();
    temp->deleteAdmin(adminId,this->getAdmins());
    delete temp;
    this->adminsToFile();
}

void BMSopt::deleteBook(std::string bookId)
{
    Admin *temp = new Admin();
    temp->deleteBook(bookId,this->getBooks());
    delete temp;
    this->booksToFile();
}

void BMSopt::deleteReader(std::string reader)
{
    Admin * temp = new Admin();
    temp->deleteReader(reader,this->getReaders());
    delete temp;
    this->readersToFile();
}

void BMSopt::addAdmin(Admin admin)
{
    Root *temp = new Root();
    temp->logon(admin,this->getAdmins());
    delete temp;
    this->adminsToFile();
}

void BMSopt::addBook(Book book)
{
    Admin *temp = new Admin();
    temp->input(book,this->getBooks());
    delete temp;
    this->booksToFile();
}

void BMSopt::addReader(Reader reader)
{
    Admin *temp = new Admin();
    temp->logon(reader,this->getReaders());
    delete temp;
    this->readersToFile();
}

