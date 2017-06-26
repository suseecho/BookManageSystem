#include "../include/Admin.h"

Admin::Admin()
{
    Admin("","");
}

Admin::Admin(std::string id,std::string passwd)
{
    this->m_id          =     id;
    this->m_passwd      =     passwd;
}

void Admin::input(Book book,std::map<std::string,Book> & books)
{
    auto it = books.find(book.getId());
    if(it != books.end()){
        (it->second).setNum(book.getNum());
        (it->second).setStatus(book.getNum());
    }else{
        books[book.getId()] = book;
    }
}

void Admin::logon(Reader reader,std::map<std::string,Reader> & readers)
{
    auto it = readers.find(reader.getId());
    if(it == readers.end())
        readers[reader.getId()] = reader;
}

void Admin::deleteBook(std::string bookId,std::map<std::string,Book> & books)
{
    for(auto it = books.begin(); it != books.end(); it++){
        if(it->first == bookId){
            books.erase(it);
            return;
        }
    }
    std::cout<<"对不起，找不到这本书，删除失败！"<<std::endl;
}

void Admin::deleteReader(std::string readerId, std::map<std::string,Reader> & readers)
{
    for(auto it = readers.begin(); it != readers.end(); it++){
        if( it->first == readerId ){
            readers.erase(it);
            return;
        }
    }
    std::cout<<"对不起，找不到这位读者，删除失败！"<<std::endl;
}

void Admin::retBook(std::string bookId,std::vector<Book> & books)
{
    for(std::vector<Book>::iterator it = books.begin(); it != books.end(); it ++){
        if( it->getName() == bookId ){
            if(it->getStatus() == 0)
            {
                std::cout<<"书本库存不够，借出失败！"<<std::endl;
                return;
            }
            it->setStatus(-1);
            return;
        }
    }
}

void lendBook(std::string reader_name,std::vector<Reader> readers,std::string bookId,std::vector<Book> & books)
{
    for(std::vector<Book>::iterator it = books.begin(); it != books.end(); it++){
        if( bookId == it->getName() ){
            std::vector<std::string> temp = it->getReaderIds();
            for( std::vector<std::string>::iterator it2 = temp.begin(); it2 != temp.end(); it2++){
                if(reader_name == *it2){
                    temp.erase(it2);
                    break;
                }
            }
            break;
        }
    }
    for(std::vector<Reader>::iterator it = readers.begin(); it != readers.end(); it++){
        if(reader_name == it->getName()){
            std::vector<std::string> & temp = it->getRecord();
            for(std::vector<std::string>::iterator it2 = temp.begin(); it2 != temp.end(); it2++){
                if(*it2 == bookId){
                    temp.erase(it2);
                    return;
                }
            }
        }
    }
}

std::string Admin::getId()
{
    return this->m_id;
}

bool Admin::login(std::string passwd)
{
    bool b = true;
    if(this->m_passwd != passwd)
        b = false;
    return b;
}

std::string Admin::getPasswd()
{
    return this->m_passwd;
}
