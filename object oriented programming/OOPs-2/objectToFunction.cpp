#include <iostream>
using namespace std;
class Player
{
private:
    int health;
    int age;
    int score;
    bool alive;

public:
    // setter
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
    // getter
    int getHealth()
    {
        return health;
    }
    int getAge()
    {
        return age;
    }
    int getScore()
    {
        return score;
    }
    bool getAlive()
    {
        return alive;
    }
};

int addScore(Player a, Player b)
{
    return a.getScore() + b.getScore();
}
Player getMaxScore(Player a, Player b)
{
    if (a.getScore() > b.getScore())
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    Player kedar;
    kedar.setScore(90);
    kedar.setHealth(100);
    kedar.setAge(18);
    kedar.setAlive(true);
    cout << kedar.getAge() << endl;
    cout << kedar.getAlive() << endl;
    cout << kedar.getScore() << endl;
    cout << kedar.getHealth() << endl;
    Player raghav;
    raghav.setScore(80);
    raghav.setHealth(90);
    raghav.setAge(19);
    raghav.setAlive(true);
    cout << raghav.getAge() << endl;
    cout << raghav.getAlive() << endl;
    cout << raghav.getScore() << endl;
    cout << raghav.getHealth() << endl;
    cout << addScore(kedar, raghav)<<endl;

    Player san =getMaxScore(kedar, raghav);
    cout<<san.getScore();
}
