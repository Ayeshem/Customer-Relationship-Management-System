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
    
    std::ofstream file1;
    std::ifstream file2;
    std::fstream file3;
    
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
        file1.open("/Users/mbp/Documents/Semester 5/DSA/DSA/DSA/DSA/Client Information.bin", std::ios::binary | std::ios::out);
        
       
        file2.open("/Users/mbp/Documents/Semester 5/DSA/DSA/DSA/DSA/Client Information.bin", std::ios::binary | std::ios::in);
        
        file3.open("/Users/mbp/Documents/Semester 5/DSA/DSA/DSA/DSA/Client Information.bin", std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
        
    }
    
    //gets client information
    void getInfo()
    {
        int n;
        
        if(file1.is_open())
        {
            std::cout<<"File 1 opening successful"<<std::endl;
        }
        
        
        std::cout<<"\nHow many times do you want to enter client data"<<std::endl;
        std::cin>>n;

        while(n<0)
        {
            std::cout<<"Please enter a positive value: "<<std::endl;
            std::cin>>n;
        }
        
        std::cout<<"\nEntering new client:-"<<std::endl;
        
        for(int i=0; i<n; i++)
        {
            std::cout<<"Enter your ID: "<<std::endl;
            std::cin>>clientID;
            std::cout<<"Enter your name: "<<std::endl;
            std::cin.ignore();
            std::cin.getline(name,sizeof(name));
            std::cout<<"Enter your Address: "<<std::endl;
            std::cin.ignore();
            std::cin.getline(address,sizeof(address));
            
            file1.write((char*)this, sizeof(this));
        }
    }
    
    
    
    ~ClientInfo()
    {
        file1.close();
        file2.close();
        file3.close();
    }
    
    
    //Search client information
    void searchClientInfo()
    {
        int n;
        int choice=0;
        int ID_no;
        
        int search=0;
        
        if(file2.is_open())
        {
            std::cout<<"File 2 opening successful"<<std::endl;
        }
        
        std::cout<<"\nHow many times do you want to Search client data"<<std::endl;
        std::cin>>n;

        while(n<0)
        {
            std::cout<<"Please enter a positive value: "<<std::endl;
            std::cin>>n;
        }
                
        std::cout<<"\nSearching client:-"<<std::endl;
        
        std::cout<<"Enter ID of the client whose record you want to search: "<<std::endl;
        std::cin>>ID_no;
        
        while(file2.read((char*)this, sizeof(this)))
        {
            if(clientID==ID_no)
            {
                std::cout<<"Client record FOUND"<<std::endl;
                std::cout<<"\nID"<<"\tname\tAddress\n";
                std::cout<<"------------------------------\n";
                std::cout<<name<<"\t"<<clientID<<"\t"<<address<<"\t"<<std::endl;
                search=1;
            }
                
        }
        
        if(search==0)
        {
            std::cout<<"Record not found!"<<std::endl;
        }
        
    }
    
    
    //Update client Information
    void updateClientInfo()
    {
        int n;
        int choice=0;
        int ID_no;
        int search=0;

        file3.seekg(0);
        
        if(file3.is_open())
        {
            std::cout<<"File 3 opening successful"<<std::endl;
        }
        
        
        std::cout<<"\nHow many times do you want to Update client data"<<std::endl;
        std::cin>>n;

        while(n<0)
        {
            std::cout<<"Please enter a positive value: "<<std::endl;
            std::cin>>n;
        }
                
        std::cout<<"\nUpdating client:-"<<std::endl;
        
        std::cout<<"Enter ID of the client whose record you want to update: "<<std::endl;
        std::cin>>ID_no;
        
        while(file2.read((char*)this, sizeof(this)))
        {
            if(clientID==ID_no)
            {
                std::cout<<"Client record FOUND"<<std::endl;
                std::cout<<"\nID"<<"\tname\tAddress\n";
                std::cout<<"------------------------------\n";
                std::cout<<name<<"\t"<<clientID<<"\t"<<address<<"\t"<<std::endl;
                search=1;
                
                std::cout<<"\nEnter the updated value: \n";
                std::cout<<"Enter your ID: "<<std::endl;
                std::cin>>clientID;
                std::cout<<"Enter your name: "<<std::endl;
                std::cin.ignore();                //can not input the whole string
                std::cin.getline(name,sizeof(name));     //does not run
                std::cout<<"Enter your Address: "<<std::endl;
                std::cin.ignore();                //can not input the whole string
                std::cin.getline(address,sizeof(address));
                file3.seekp(-sizeof(this), std::ios::cur);
                
                file3.write((char*)this, sizeof(this));
                
            }
                
        }
        
        if(search==0)
        {
            std::cout<<"Record not found!"<<std::endl;
        }
        
        
    }
    
    
};

class Projects
{
    
};

class customerSupport
{
    
};

class Billing
{
    
};

class Feedback
{
    
};



//add CRUD functionality


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
        
        if(num==1)
        {
            ClientInfo Client;
            Client.getInfo();
        }
        
        else if(num==2)
        {
            ClientInfo searchClient;
            searchClient.searchClientInfo();
        }
        
        
        std::cout<<"\nEnter Y/y to run the program again, Press any key to Quit:"<<std::endl;
        std::cin>>choice;
        
    }while(choice=='y' || choice=='Y');
    
    
    
    return 0;
}





 
