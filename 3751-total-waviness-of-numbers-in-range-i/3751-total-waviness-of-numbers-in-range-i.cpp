class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total = 0;

        for(int i=num1; i<=num2; i++) {
            int a = i;

            vector<int> temp;
            while(a != 0) {
                temp.push_back(a % 10);
                a /= 10;
            }

            for(int j=1; j<(int)temp.size()-1; j++) {
                if((temp[j] > temp[j-1] && temp[j] > temp[j+1])
                    ||
                   (temp[j] < temp[j-1] && temp[j] < temp[j+1]))
                    total++;
            }
        }

        return total;
    }
};