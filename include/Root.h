#ifndef ROOT_H
#define ROOT_H
#include "Admin.h"

class Root:public Admin
{
public:
    Root();
    Root(std::string id,std::string passwd);
    void logon(Admin admin,std::map<std::string,Admin> & admins);
    void deleteAdmin(std::string adminId,std::map<std::string,Admin>  admins);
};

#endif //ROOT_A
