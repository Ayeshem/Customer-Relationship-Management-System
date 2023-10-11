#include <iostream>
#include <fstream>
#include <string>

int maxSize=40;

class ClientInfo
{
    int clientID;
    char name[40];
    char address[40];
    char projectsLits[40];
    
    std::ifstream file1;
    
public:
    
    
    int getclientID() const
    {
        return clientID;
    }
    
    int getName() const
    {
        return name[40];
    }
    
    int getAddress() const
    {
        return address[40];
    }
    
    int getProjectLists() const
    {
        return projectsLits[40];
    }
    
    ClientInfo()
    {
        file1.open("/Users/mbp/Documents/Semester 5/DSA/DSA/DSA/DSA/Client Information.bin", std::ios::binary | std::ios::in);
    }
    

    
    ~ClientInfo()
    {
        file1.close();
    }
    
    
    //Search client information
    void showClientInfo()
    {
        int n;
        
        if(file1.is_open())
        {
            std::cout<<"File 1 opening successful"<<std::endl;
        }
        

        while(n<0)
        {
            std::cout<<"Please enter a positive value: "<<std::endl;
            std::cin>>n;
        }
                
        std::cout<<"\nShowing ALL clients:-"<<std::endl;
        
        std::cout<<"\nID"<<"\tname\tAddress\n";
        std::cout<<"------------------------------\n";
        
        while(file1.read((char*)this, sizeof(this)))
        {

            std::cout<<name<<"\t"<<clientID<<"\t"<<address<<"\t"<<std::endl;
        }
    
        
    }
    
    
   
};


int main()
{
    std::cout<<"\n                       ";
    std::cout<<"Welcome to Customer Relationship Management System!"<<std::endl;
    
    int num;
    char choice;
    
    do
    {
        std::cout<<"\n\n1. Enter new Client"<<std::endl;
        std::cout<<"2. Search Client"<<std::endl;
        std::cout<<"3. Update Client"<<std::endl;
        std::cout<<"4. Delete Client"<<std::endl;
        std::cout<<"5. Show all Clients"<<std::endl;
        std::cout<<"6. Enter Projects"<<std::endl;
        std::cout<<"7. Search Project"<<std::endl;
        std::cout<<"8. Update Project"<<std::endl;
        std::cout<<"9. Delete Project"<<std::endl;
        std::cout<<"10. Show all Projects"<<std::endl;
        std::cout<<"11. Customer Support"<<std::endl;
        std::cout<<"12. Contract Biling and Management "<<std::endl;
        std::cout<<"13. Customer Feedback"<<std::endl;
        
        std::cout<<"\nEnter choice: "<<std::endl;
        std::cin>>num;
        
        while(num<=0 || num>=13)
        {
            std::cout<<"\nInvalid input! Please enter a number between 1-13"<<std::endl;
            std::cin>>num;
        }
        
        if(num==5)
        {
            ClientInfo Client;
            Client.showClientInfo();
        }
    
        std::cout<<"\nEnter Y/y to run the program again, Press any key to Quit:"<<std::endl;
        std::cin>>choice;
        
    }while(choice=='y' || choice=='Y');
    
    
    
    return 0;
}


