#include "../include/Reader.h"

class Reader;
Reader::Reader(std::string name,bool gender,std::string id)
{
    this->m_name   =   name;
    this->m_gender =   gender;
    this->m_id     =   id;
    init();
}

bool Reader::init()
{
    bool b      =   true;
    std::ifstream    =   in(name+".dat");
    if(!in){
        return b;
    }
    m_record.clear();
    std::string book_name;
    while(in<<book_name){
        m_record.push_back(book_name);
    }
    return b;
}

bool Reader::getGender()
{
    return this->m_gender;
}

std::string Reader::getId()
{
    return this->m_id;
}

std::string Reader::getName()
{
    return this->m_name;
}
