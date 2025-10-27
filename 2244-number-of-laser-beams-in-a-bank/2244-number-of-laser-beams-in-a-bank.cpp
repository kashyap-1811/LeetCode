class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        vector<int> beams(n, 0);

        for(int i=0; i<n; i++){
            for(auto device : bank[i]){
                if(device == '1')
                    beams[i]++;
            }
        }

        // number of beams count
        int count = 0;
        
        // find first row with atleast one device
        int i = 0;
        while(i < n && beams[i] == 0)
            i++;
        
        int j = i+1;
        while(j < n){
            if(beams[j] != 0){
                count += (beams[i] * beams[j]);
                i = j;
            }
            j++;
        }

        return count;
    }
};