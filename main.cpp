#include <iostream>
#include <map>
#include <string>

bool correct_phone (std::string phone) {
    if (phone.length() != 8 || phone[2] != '-' || phone[5] != '-')
        return false;
    for (int i=0;i < phone.length();i++) {
        if (i == 2 || i == 5) i++;
        if (phone[i] < '0' || phone[i] > '9')
            return false;
    }
    return true;
}
bool correct_name (std::string name) {
    if (name[0] < 'A' || name[0] > 'Z')
        return false;

    for (int i=1;i < name.length();i++) {
        if (name[i] < 'a' || name[i] > 'z')
            return false;
    }
    return true;
}

int main() {

    std::map<std::string, std::string> phonebook;

    std::string answer, name = " ", phone = " ";
    int request = 0;

    while (request != -1) {
        bool Incorrect = true;
        while (Incorrect) {
            Incorrect = false;
            std::cout << "Enter your request:";
            std::getline(std::cin,answer);

            if (answer.length() > 8 && answer[8] == ' ') {
                phone = answer.substr(0,8);
                name = answer.substr(9,answer.length()-9);
                request = 1;
            } else
            if (correct_phone(answer)) {
                phone = answer;
                request = 2;
            }
            else
            if (correct_name(answer)) {
                name = answer;
                request = 3;
            }
            else {
                if (answer == "exit") request = -1;
                else {
                    std::cout << "Incorrect input data. Repeat." << std::endl;
                    Incorrect = true;
                }
            }
        }

        if (request == 1) {
            phonebook.insert(std::pair<std::string,std::string>(phone,name));
            std::cout << "Data added!" << std::endl;
        }

        if (request == 2) {
            std::cout << "Phone: " << phone << " Name: " << phonebook.find(phone)->second << std::endl;
        }
        if (request == 3) {
            std::cout << "Name: " << name << " Phone: " << std::endl;
            for (std::map<std::string,std::string>::iterator itf = phonebook.begin();
                 itf != phonebook.end();++itf){
                if (itf->second == name)
                    std::cout << itf->first << std::endl;
            }
        }
    }
    return 0;
}
