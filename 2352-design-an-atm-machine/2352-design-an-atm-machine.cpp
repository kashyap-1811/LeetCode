class ATM {
public:
    vector<int> deno;
    ATM() {
        deno.resize(5);    
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0; i<5; i++)
            deno[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5, 0);

        if(amount >= 500 && deno[4] != 0){
            int notes = amount / 500;
            if(deno[4] >= notes){
                deno[4] -= notes;
                amount -= (500 * notes);
                ans[4] = notes;
            }else{
                amount -= (500 * deno[4]);
                ans[4] = deno[4];
                deno[4] = 0;
            }
        }

        if(amount >= 200 && deno[3] != 0){
            int notes = amount / 200;
            if(deno[3] >= notes){
                deno[3] -= notes;
                amount -= (200 * notes);
                ans[3] = notes;
            }else{
                amount -= (200 * deno[3]);
                ans[3] = deno[3];
                deno[3] = 0;
            }
        }

        if(amount >= 100 && deno[2] != 0){
            int notes = amount / 100;
            if(deno[2] >= notes){
                deno[2] -= notes;
                amount -= (100 * notes);
                ans[2] = notes;
            }else{
                amount -= (100 * deno[2]);
                ans[2] = deno[2];
                deno[2] = 0;
            }
        }

        if(amount >= 50 && deno[1] != 0){
            int notes = amount / 50;
            if(deno[1] >= notes){
                deno[1] -= notes;
                amount -= (50 * notes);
                ans[1] = notes;
            }else{
                amount -= (50 * deno[1]);
                ans[1] = deno[1];
                deno[1] = 0;
            }
        }

        if(amount >= 20 && deno[0] != 0){
            int notes = amount / 20;
            if(deno[0] >= notes){
                deno[0] -= notes;
                amount -= (20 * notes);
                ans[0] = notes;
            }else{
                amount -= (20 * deno[0]);
                ans[0] = deno[0];
                deno[0] = 0;
            }
        }

        if(amount != 0){
            for(int i=0; i<5; i++)
                deno[i] += ans[i];
            return vector<int>{-1};
        }

        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */