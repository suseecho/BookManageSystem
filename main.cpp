#include "./include/BMSopt.h"
#include<unistd.h>
#define BRK()  do { ; getchar(); } while (0)
char getch();
void menu();
void input();
void mydelete();
void query();
void logon();
void borrow();
void restore();
int main()
{
    BMSopt * ptr = BMSopt::Instance();
    std::map<std::string,Admin> & mapAdmin =  ptr->getAdmins();
    std::string user,pwd;
    system("clear");
    std::cout << "login, please" << std::endl;
    std::cout << "user: ";
    std::cin >> user;
    std::cout << "password: ";
    getchar();
//    std::cin >> pwd;
    int i = 0;
    char ch;
    char chPwd[20];
    for(i=0;i<20;i++)
    {
     ch=getch();
     if(ch=='\n')
     {
         chPwd[i]='\0';
         break;
     }
     putchar('*');
     chPwd[i]=ch;
    }
    pwd = std::string(chPwd);
    std::cout << pwd << std::endl;



        
    auto it = mapAdmin.begin();
    while(it!=mapAdmin.end())
    {
        if(it->first == user)
        {
            if(pwd == it->second.getPasswd())
            {
                menu();
            }
            else
            {
                std::cerr << "login failed" << std::endl;
                break;
            }
        }
        else
        {
            it++;
            continue;
        }
    }
    std::cout << "Permisson denied" << std::endl;

    return 0;
}



void menu()
{
    system("clear");
    std::cout << "                            ************************************************************************" << std::endl;
    std::cout << "                            ************************************************************************" << std::endl;
    std::cout << "                            **                                                                    **" << std::endl;
    std::cout << "                            **                                                                    **" << std::endl;
    std::cout << "                            **                  Welcome to Book Manage System                     **" << std::endl;
    std::cout << "                            **                                                                    **" << std::endl;
    std::cout << "                            **                                                                    **" << std::endl;
    std::cout << "                            **                                                                    **" << std::endl;
    std::cout << "                            **    1.输入                                                          **" << std::endl;
    std::cout << "                            **    2.查询                                                          **" << std::endl;
    std::cout << "                            **    3.删除                                                          **" << std::endl;
    std::cout << "                            **    4.注册                                                          **" << std::endl;
    std::cout << "                            **    5.借书                                                          **" << std::endl;
    std::cout << "                            **    6.还书                                                          **" << std::endl;
    std::cout << "                            **    7.退出                                                          **" << std::endl;
    std::cout << "                            **                                                                    **" << std::endl;
    std::cout << "                            **                                                                    **" << std::endl;
    std::cout << "                            **                                                                    **" << std::endl;
    std::cout << "                            **                                                                    **" << std::endl;
    std::cout << "                            ************************************************************************" << std::endl;
    std::cout << "                            ************************************************************************" << std::endl;
    char ch ;
    std::cout << "你想要干什么: ";
    std::cin >> ch;
    std::cout <<  ch <<  std::endl;
    switch(ch)
    {
        case '1':
            input();
            break;
        case '2':
            query();
            break;
        case '3':
            mydelete();
            break;
        case '4':
            logon();
            break;
        case '5':
            borrow();
            break;
        case '6':
            restore();
            break;
        case '7':
            exit(2);
    }
}
void input()
{
    std::string name , id , author;
    double price;
    unsigned int num , status;
    std::cout << "输入图书信息(书名,图书编号,价格,作者,书总量,书在库量)" << std::endl;
    std::cout << "书名:";
    std::cin >> name;
    std::cout << "编号:";
    std::cin >> id;
    std::cout << "价格:";
    std::cin >> price;
    std::cout << "作者:";
    std::cin >> author;
    std::cout << "总量:";
    std::cin >> num;
    std::cout << "在库量:";
    std::cin >> status;
    if(status > num)
    {
        std::cout << "输入信息有误" << std::endl;
        BRK();
        BRK();
    }
    else
    {
        Book book(name,id,price,author,num,status);
        BMSopt * ptr = BMSopt::Instance();
        ptr->addBook(book);
        std::cout <<"信息输入成功" <<std::endl;
        BRK();
        BRK();
    }
    
}


void query()
{
    std::cout <<"请输入图书编号:";
    std::string id;
    std::cin >> id;
    BMSopt * ptr = BMSopt::Instance();
    std::map<std::string,Book> &mapBook = ptr->getBooks();
    auto it = mapBook.begin();

    int flag = 0;
    while(it!=mapBook.end())
    {
        if(it->second.getId() == id)
        {
            std::cout << "图书名称: ";
            std::cout << it->second.getName() << std::endl;
            std::cout << "图书编号: ";
            std::cout << it->second.getId() << std::endl;
            std::cout << "图书价格: ";
            std::cout << it->second.getPrice() << std::endl;
            std::cout << "图书作者: ";
            std::cout << it->second.getAuthor() << std::endl;
            std::cout << "库存量: ";
            std::cout << it->second.getNum() << std::endl;
            flag = 1;
            BRK();
            break;
        }
        it++;
    }             
    if(flag == 0)
    {
        std::cout << "未找到相关书籍" << std::endl;
        BRK();
    }
    BRK();
}

void mydelete()
{
    int flag = 0;
    std::cout << "输入要删除图书的编号:";
    std::string t_id;
    std::cin >> t_id;
    BMSopt * ptr = BMSopt::Instance();
    std::map<std::string,Book> &mapBook = ptr->getBooks();
    auto it = mapBook.begin();
    while(it!=mapBook.end())
    {
        if(it->second.getId() == t_id)
        {
            ptr->deleteBook(t_id);
            flag = 1;
            BRK();
            break;
        }
        it++;
    }
    if(flag == 0)
    {
        std::cout << "未找到想要删除的书籍" << std::endl;
        BRK();
    }
}


void logon()
{
    std::string name , id;
    bool gender; 
    std::cout << "请输入读者信息" << std::endl;
    std::cout << "姓名:";
    std::cin >> name;
    std::cout << "性别(0-女,1-男):";
    std::cin >> gender;
    std::cout << "编号:" ;
    std::cin >> id;
    Reader reader(name,gender,id);
    BMSopt * ptr = BMSopt::Instance();
    ptr->addReader(reader);
    std::cout << "注册成功" << std::endl;
    BRK();
    BRK();
    
}

void borrow()
{
/*
    std::cout << "请输入读者编号: " << std::endl;
    std::string readerId;
    std::cin >> readerId;
    BMSopt * ptr = BMSopt::Instance();
    std::map<std::string,Reader> mapReader = ptr->getReader();
    auto itReader = mapReader.begin();
    int flagReader  = 0 ;
    int flagBook =  0;
    while(itReader != mapReader.end())
    {
        if(itReader->seconde.getId() == readerId)
        {
            flagReader = 1;
            std::cout << "请输入所借图书的编号" << std::endl;
            std::string bookId;
            std::cin >> bookId;
            std::map<std::string,Book> mapBook = ptr->getBook();
            auto itBook = mapBook.begin();
            while(itBook != mapBook.end())
            {
                if(itBook->second.getId() == bookId)
                {
                    flagBook = 1;
                    Admin admin;
                    admin.lendBook(
                    
*/
            




        
}

void restore()
{
    std::cout << "restore" << std::endl;
}
char getch()
{    
    char c;
    system("stty -echo");
    system("stty -icanon");
    c=getchar();
    system("stty icanon");
    system("stty echo");
    return c;
}    
