struct Enemy {
    int damage;
    int timeToKill;
};

struct Compare {
    bool operator()(const Enemy& a, const Enemy& b) {
        // Sort by damage/timeToKill descending
        double ratioA = (double)a.damage / a.timeToKill;
        double ratioB = (double)b.damage / b.timeToKill;
        return ratioA < ratioB;  // higher ratio = higher priority
    }
};

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        priority_queue<Enemy, vector<Enemy>, Compare> pq;

        for (int i = 0; i < n; i++) {
            int t = (health[i] + power - 1) / power;  // ceil division
            pq.push({damage[i], t});
        }

        long long totalDamage = 0;
        long long time = 0;

        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();

            // While current enemy is being killed, all others alive deal damage
            totalDamage += (time * curr.damage);
            
            // Then kill this enemy
            totalDamage += (curr.damage * curr.timeToKill);
            time += curr.timeToKill;
        }

        return totalDamage;
    }
};