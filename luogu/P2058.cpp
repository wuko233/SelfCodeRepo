#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#define MAX_TIME 86400

typedef long long ll;

using namespace std;

struct Boat {
    ll arriveTime;
    vector<int> nations;
};

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> countNations;

    vector<Boat> boats(n);

    queue<Boat> boatQueue;

    for (int i = 0; i < n; ++i) {
        ll t, k;
        cin >> t >> k;
        Boat boat;
        boat.arriveTime = t;

        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;

            countNations[x]++;
            boat.nations.push_back(x);
        }

        boatQueue.push(boat);

        while(!boatQueue.empty() && t - boatQueue.front().arriveTime >= MAX_TIME) {
            Boat oldBoat = boatQueue.front();
            boatQueue.pop();

            for (int nation : oldBoat.nations) {
                countNations[nation]--;
                if (countNations[nation] == 0) {
                    countNations.erase(nation);
                }
            }
        }

        std::cout << countNations.size() << endl;
    }
}