//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cstring> // Include this for string manipulation
//
//class ClientInfo {
//    int clientID;
//    char name[40];
//    char address[40];
//    char projectsList[40]; // Corrected the field name
//
//    std::fstream file;
//
//public:
//    ClientInfo() {
//        file.open("/Users/mbp/Documents/Semester 5/DSA/DSA proj/Customer Relationship Management System/Customer Relationship Management System/ClientInformation.bin", std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
//    }
//
//    ~ClientInfo() {
//        file.close();
//    }
//
//    void getInfo() {
//        int n;
//        std::cout << "How many times do you want to enter client data: ";
//        std::cin >> n;
//
//        while (n < 0) {
//            std::cout << "Please enter a positive value: ";
//            std::cin >> n;
//        }
//
//        std::cout << "Entering new client data:" << std::endl;
//        
//        for (int i = 0; i < n; i++) {
//            std::cout << "Enter your ID: ";
//            std::cin >> clientID;
//            std::cout << "Enter your name: ";
//            std::cin.ignore();
//            std::cin.getline(name, sizeof(name));
//            std::cout << "Enter your Address: ";
//            std::cin.getline(address, sizeof(address));
//            std::cout << "Enter your Projects List: ";
//            std::cin.getline(projectsList, sizeof(projectsList));
//
//            file.write(reinterpret_cast<char*>(this), sizeof(*this));
//        }
//    }
//
//    void showAllClients() {
//        std::cout << "Showing ALL clients:" << std::endl;
//        std::cout << "\nID\tName\tAddress\tProjects List\n";
//        std::cout << "----------------------------------\n";
//
//        file.seekg(0);
//        while (file.read(reinterpret_cast<char*>(this), sizeof(*this))) {
//            std::cout << clientID << "\t" << name << "\t" << address << "\t" << projectsList << std::endl;
//        }
//    }
//};
//
//int main() {
//    std::cout << "Welcome to Customer Relationship Management System!" << std::endl;
//    int num;
//
//    ClientInfo client;
//    
//    do {
//        std::cout << "\n1. Enter new Client" << std::endl;
//        std::cout << "2. Show all Clients" << std::endl;
//        std::cout << "3. Quit" << std::endl;
//        std::cout << "Enter choice: ";
//        std::cin >> num;
//
//        switch (num) {
//            case 1:
//                client.getInfo();
//                break;
//            case 2:
//                client.showAllClients();
//                break;
//            case 3:
//                return 0;
//            default:
//                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
//                break;
//        }
//    } while (num != 3);
//
//    return 0;
//}
