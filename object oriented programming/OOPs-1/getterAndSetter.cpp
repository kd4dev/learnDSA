#include <iostream>
using namespace std;
class Player
{
private:
    int score;
    int health;

public:
    // setter
    void setScore(int s)
    {
        cout << "score set  kiya jaa rha he" << endl;
        score = s;
    }
    void setHealth(int h)
    {
        cout << "health set ki jaa rahi he" << endl;
        health = h;
    }

    // getter
    int getScore()
    {
        return score;
    }
    int getHealth()
    {
        return health;
    }
};
int main()
{
    Player kedar;
    kedar.setScore(90);
    kedar.setHealth(100);
    cout << kedar.getScore() << endl;
    cout << kedar.getHealth() << endl;
}
