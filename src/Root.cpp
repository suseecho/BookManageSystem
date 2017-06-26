#include "../include/Root.h"


Root::Root()
{
    Root("","");
}

Root::Root(std::string id,std::string passwd):Admin(id,passwd)
{
    std::string m_id     = id;
    std::string m_passwd = passwd;
}

void Root::logon(Admin admin,std::map<std::string,Admin> & admins)
{
    admins[admin.getId()] = admin;
}

void Root::deleteAdmin(std::string adminId, std::map<std::string, Admin> admins)
{
    std::map<std::string,Admin>::iterator temp = admins.find(adminId);
    admins.erase(temp);
}
