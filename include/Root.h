#ifndef ROOT_H
#define ROOT_H
#include "Admin.h"

class Root::public Admin
{
private:
    std::string m_id;
    std::string m_passwd;
public:
    Root(std::string id,std::string passwd);
    void logon(Admin admin);
    void deleteAdmin(std::string adminId);
};

#endif //ROOT_A
