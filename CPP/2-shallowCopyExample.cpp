// Program to show how shallow copying works in C++
#include <iostream>
#include <string>

// Class Declaration
class Player;
class MalePlayer;
class FemalePlayer;

class Player{
    public:
        std::string sName;
        unsigned int *iHealth;
        char cGender;

    public:
        Player();   //Default constr
        ~Player();  //Default destr

        void showDetails() const;
        void setDetails(std::string name, unsigned int* health, char gender);
};

::Player::Player()
:   sName("emptyName"), iHealth(nullptr), cGender('n')
{

};

::Player::~Player()
{
    delete iHealth;
    iHealth = nullptr;
}

void ::Player::showDetails() const
{
    std::cout << "Details of Male Player" << std::endl;

    std::cout << "Name : " << sName << std::endl;
    std::cout << "Health : " << *iHealth  << std::endl;
    std::cout << "Gender : " << cGender << std::endl;

    std::cout << std::endl;
}

void ::Player::setDetails(std::string name, unsigned int* health, char gender)
{
    if(name != "empty")
        this->sName = name;

    if(health != 0)
        this->iHealth = health;

    if(gender != 'n')
        this->cGender = gender;
}

class MalePlayer : public Player
{
    public:
    MalePlayer()
    {
        
    };
};

class FemalePlayer : public Player
{
    public:
    FemalePlayer()
    {

    };
};

int main(){
    Player *male1 = new ::MalePlayer;
    Player *female1 = new ::FemalePlayer;

    male1->setDetails("Aditya", new unsigned int(100), 'M');

    male1->showDetails();

    //male1->iHealth = 99;

    Player *male2 = male1;
    Player *male3(male2);

    male2->setDetails("Rahul", new unsigned int(88), 'F');
    male1->showDetails();

    //male3->iHealth = 33;

    //delete male2;
    //male2 = nullptr;

    male3->setDetails("Namoh", new unsigned int(66), 'M');
    male1->showDetails();

    male1->setDetails("Aditya", new unsigned int(100), 'M');
    male3->showDetails();

    return 0;
}
