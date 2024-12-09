#include <iostream>
#include <list>
using namespace std;

class Human
{
protected:
    int ID;
    string Address;

public:
    int Age;
    string Name;
    string Surname;
    string Gender;

    Human(int age, const string& name, const string& surname, int id): Age(age), Name(name), Surname(surname), ID(id) {}

    int getID() const { return ID; }
    string getAddress() const { return Address; }
};

class Worker : public Human 
{
private:
    string login;
    string password;

public:
    string position;

    Worker(int age, const string& name, const string& surname, int id, const string& pos): Human(age, name, surname, id), position(pos) {}

    void setLogin(const string& newLogin) {
        login = newLogin;
    }
    void setPassword(const string& newPassword) {
        password = newPassword;
    }

    bool signIn(string& enteredlogin, string& enteredpassword) 
    {
        return enteredlogin == login && enteredpassword == password; 
    }
    bool signOut() { return true; }
    void uploadWorkReport(const string& report) {}

};

int main()
{
    Worker emploee_1(25, "Robert", "Shalame", 20068, "programmer");
    emploee_1.setLogin("robert_sh");
    emploee_1.setPassword("password123");

    string ent_login;
    string ent_password;
    cout << "Enter login:";
    cin >> ent_login;
    cout << "Enter password:";
    cin >> ent_password;

    if (emploee_1.signIn(ent_login, ent_password)) 
    {
        cout << "Авторизація успішна" << std::endl;
    }
    else {
        cout << "Невірний логін або пароль" << std::endl;
    }

	return 0;
}
