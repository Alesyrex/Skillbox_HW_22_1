#include <iostream>
#include <map>
#include <string>
#include <vector>

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

    std::map<std::string, std::string> phonebookName;
    std::map<std::string, std::vector<std::string>> phonebookNumber;

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
            phonebookName.insert(std::pair<std::string,std::string>(phone,name));

            std::vector<std::string> vec;
            vec.push_back(phone);
            std::map<std::string, std::vector<std::string>>::iterator itName = phonebookNumber.find(name);
            if (itName == phonebookNumber.end())
                phonebookNumber.insert(std::pair<std::string, std::vector<std::string>> (name,vec));
            else
                itName->second.push_back(phone);
            std::cout << "Data added!" << std::endl;
        }

        if (request == 2) {
            std::cout << "Phone: " << phone << " Name: " << phonebookName.find(phone)->second << std::endl;
        }
        if (request == 3) {
            std::cout << "Name: " << name << " Phone: " << std::endl;

            std::map<std::string, std::vector<std::string>>::iterator itName = phonebookNumber.find(name);
            int amountNumbers = itName->second.size();
            for (int i=0;i < amountNumbers;++i){
                    std::cout << itName->second[i] << std::endl;
            }
        }
    }
    return 0;
}
