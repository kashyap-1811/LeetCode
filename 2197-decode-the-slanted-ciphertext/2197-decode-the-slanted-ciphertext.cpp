class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(rows == 1)
            return encodedText;

        int cols = encodedText.size() / rows;

        vector<int> pointers(rows);
        for(int i=0; i<rows; i++){
            pointers[i] = cols * i + i;
        }

        string ans = "";
        for(int j=0; j<cols; j++){
            for(int i=0; i<rows; i++){
                if(pointers[i] < cols * (i + 1))
                    ans += encodedText[pointers[i]++];
            }
        }

        while(ans.size() > 0 && ans[ans.size()-1] == ' ')
            ans.pop_back();

        return ans;
    }
};