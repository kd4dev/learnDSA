#include <iostream>
using namespace std;

class Gun
{
public:
    int ammo;
    int damage;
    int scope;
};

class Player
{
private:
    int health;
    int age;
    int score;
    bool alive;
    Gun gun;
    class Helmet
    {
        int hp;
        int level;

    public:
        void setHp(int hp)
        {
            this->hp = hp;
        }

        void setLevel(int level)
        {
            this->level = level;
        }
        int getHp() const
        {
            return hp;
        }
        int getLevel() const
        {
            return level;
        }
    };

    Helmet helmet; // Declare Helmet object

public:
    // Setters
    void setHealth(int health)
    {
        cout << "health set ki jaa rahi he" << endl;
        this->health = health;
    }
    void setAge(int a)
    {
        cout << "age set ki jaa rahi he" << endl;
        age = a;
    }
    void setScore(int s)
    {
        cout << "score set ki jaa rahi he" << endl;
        score = s;
    }
    void setAlive(bool a)
    {
        cout << "alive set ki jaa rahi he" << endl;
        alive = a;
    }
    void setGun(Gun gun)
    {
        this->gun = gun;
    }
    void setHelmet(int level)
    {
        if (level == 1)
        {
            helmet.setHp(50);
        }
        else if (level == 2)
        {
            helmet.setHp(100);
        }
        else if (level == 3)
        {
            helmet.setHp(150);
        }
        else
        {
            cout << "Invalid level" << endl;
            return;
        }
        helmet.setLevel(level);
    }

    // Getters
    Gun getGun() const
    {
        return gun;
    }
    int getHealth() const
    {
        return health;
    }
    int getAge() const
    {
        return age;
    }
    int getScore() const
    {
        return score;
    }
    bool getAlive() const
    {
        return alive;
    }
    int getHelmetHp() const
    {
        return helmet.getHp();
    }
    int getHelmetLevel() const
    {
        return helmet.getLevel();
    }
};

int addScore(const Player &a, const Player &b)
{
    return a.getScore() + b.getScore();
}

Player getMaxScore(const Player &a, const Player &b)
{
    if (a.getScore() > b.getScore())
    {
        return a;
    }
    else if (b.getScore() > a.getScore())
    {
        return b;
    }
    else
    {
        return a; // Return any in case of tie
    }
}

int main()
{
    Gun akm = {30, 40, 4};
    Gun awm = {10, 90, 8};

    Player kedar;
    kedar.setScore(90);
    kedar.setHealth(100);
    kedar.setAge(18);
    kedar.setAlive(true);
    kedar.setGun(akm);
    kedar.setHelmet(2);

    cout << "Kedar's Info:" << endl;
    cout << "Age: " << kedar.getAge() << endl;
    cout << "Alive: " << (kedar.getAlive() ? "Yes" : "No") << endl;
    cout << "Score: " << kedar.getScore() << endl;
    cout << "Health: " << kedar.getHealth() << endl;
    cout << "Helmet HP: " << kedar.getHelmetHp() << endl;
    cout << "Helmet Level: " << kedar.getHelmetLevel() << endl;

    Player raghav;
    raghav.setScore(80);
    raghav.setHealth(90);
    raghav.setAge(19);
    raghav.setAlive(true);
    raghav.setGun(awm);
    raghav.setHelmet(3);

    cout << "\nRaghav's Info:" << endl;
    cout << "Age: " << raghav.getAge() << endl;
    cout << "Alive: " << (raghav.getAlive() ? "Yes" : "No") << endl;
    cout << "Score: " << raghav.getScore() << endl;
    cout << "Health: " << raghav.getHealth() << endl;
    cout << "Helmet HP: " << raghav.getHelmetHp() << endl;
    cout << "Helmet Level: " << raghav.getHelmetLevel() << endl;

    cout << "\nTotal Score: " << addScore(kedar, raghav) << endl;

    Player san = getMaxScore(kedar, raghav);
    cout << "Highest Score: " << san.getScore() << endl;

    //Player array[3];
    Player array[3]={kedar,raghav,san};
    array[0] = kedar;   
    array[1] = raghav;
    array[2] = san;
    cout<<array[1].getScore()<<endl;
}