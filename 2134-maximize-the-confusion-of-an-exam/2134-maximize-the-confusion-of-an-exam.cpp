class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        queue<int>qT, qF;
        int mxCount = 0;
        int countT = 0, countF = 0;

        for(int i=0; i<answerKey.size(); i++){
            if(answerKey[i] == 'T'){
                countT++;

                if(qF.size() < k){
                    countF++;
                    qF.push(i);
                }else{
                    countF = i - qF.front();
                    qF.pop();
                    qF.push(i);
                }
            }else{
                countF++;

                if(qT.size() < k){
                    countT++;
                    qT.push(i);
                }else{
                    countT = i - qT.front();
                    qT.pop();
                    qT.push(i);
                }
            }

            mxCount = max({mxCount, countT, countF});
        }

        return mxCount;
    }
};