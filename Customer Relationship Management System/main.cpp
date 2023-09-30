#include <iostream>
#include <fstream>


int main()
{
    std::cout<<"\n                       ";
    std::cout<<"Welcome to Customer Relationship Management System!"<<std::endl;
    
    int num;
    char choice;
    
    do
    {
        std::cout<<"\n1. Enter Client data"<<std::endl;
        std::cout<<"2. Show client data"<<std::endl;
        std::cout<<"3. Add new Project"<<std::endl;
        std::cout<<"4. Show all projects"<<std::endl;
        std::cout<<"5. Customer Support"<<std::endl;
        std::cout<<"6. Contract Biling and Management "<<std::endl;
        std::cout<<"7. Customer Feedback"<<std::endl;
        
        std::cout<<"\nEnter choice: "<<std::endl;
        std::cin>>num;
        
        while(num<=0 || num>=8)
        {
            std::cout<<"\nInvalid input! Please enter a number between 1-7"<<std::endl;
            std::cin>>num;
        }
        
        std::cout<<"\nEnter Y/y to run the program again, Press any key to Quit:"<<std::endl;
        std::cin>>choice;
        
    }while(choice=='y' || choice=='Y');
    
    
    
    return 0;
}





