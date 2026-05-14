#include <iostream>

using namespace std;

typedef long long ll;

class Monster {
    private:
        double maxHealth;
        double health;
        ll magic;
        bool isNotDead = false;
        bool forever = false;

    public:
        Monster(double health, ll magic) {
            this->health = health;
            this->maxHealth = health;
            this->magic = magic;
        }

        double beAttacked(double dmg) {
            if (health <= 0) {
                if (isNotDead && !forever) {
                    return 0;
                }

                if (forever) {
                    return dmg * 1.2;
                }
            }

            magic += 10;
            health -= dmg;

            if (health <= 0) {
                if (!isNotDead) {
                    notDead();
                } 
            }

            return dmg * 1.2;
        }

        void notDead() {
            health = 1;

            health += (double) magic / 100 * maxHealth;

            if (health > maxHealth) {
                health = maxHealth;
            }

            if (magic >= 100) {
                forever = true;
            }

            magic = 0;
            
            isNotDead = true;
        }
    
};

int main() {
    ll n, d, h;
    cin >> n >> d >> h;

    Monster monster(h, 0);

    double dmg = d * 1.2;
    double totalDmg = 0;
    for (int i = 0; i < n; ++i) {
        double finaldmg = 2 * dmg;
        totalDmg += monster.beAttacked(finaldmg);
        // cout << totalDmg << endl;
    }

    printf("%.2lf", totalDmg);
}

