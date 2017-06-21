#ifdef READER_H
#define READER_H
#include <string>
#include <iostream>
class Reader
{
private:
    std::string    m_name;
    bool           m_gender;
    std::string    m_id;
    std::vector<std::string>  m_record;
public:
    Reader(std::string name,bool gender,std::string id);
    bool init();
    std::string getName();
    bool getGender();
    std::string getId();
    friend operator<< (const std::ostream &out, const Reader & reader);
    friend operator>> (const std::istream &in, Reader);
};

#endif // READER_H
