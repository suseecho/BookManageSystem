#include "../include/Book.h"
Book::Book(std::string name, std::string id, double price,std::string author, bool exist,std::string reader_id)
{
   this->m_name        =   name;
   this-> m_id         =   id;   
   this->m_price       =   price;
   this->m_author      =   author;
   this->m_status      =   exist;
   this->m_reader_ids  =   reader_ids;
}
Book::~Book()
{
}

std::string Book::getName()
{
    return this->m_name;
}

std::vector<std::string> Book::getId()
{
    return this->m_id;
}

double Book::getPrice()
{
    return this->m_price;
}

std::string Book::getAuthor()
{
    return this->m_author;
}

bool Book::isExist()
{
    return this->m_status;
}

std::vector<std::string> & Book::getReaderIds()
{
    return this->m_readerids;
}

void Book::setNum(int change)
{
    if(-1*change > this->m_num){
        std::cout<<"改变图书数量失败:图书变化数量大于在库数量"<<std::endl;
        return;
    }
    this->m_num += change;
}

void Book::setStatus(int change)
{
    if(-1*change > this->m_status){
        std::cout<<"改变图书在库数量失败：图书变化数量大于在库数量"<<std::endl;
        return;
    }
    this->m_status += change;
}

unsigned int getNum()
{
    return this->m_num;
}

unsigned int getStatus()
{
    return this->m_status;
}
