class Solution {
public:
    int addMinimum(string word) {
        int count = 0;
        char current = word[0];

        if(current == 'b')
            count = 1;
        else if(current == 'c')
            count = 2;

        for(int i=1; i<word.size(); i++){
            char c = word[i];

            if((current == 'a' && c == 'c') || (current == 'b' && c == 'a') || (current == 'c' && c == 'b'))
                count++;
            else if(current == c)
                count += 2;

            current = c;
        }

        if(current == 'a')
            count += 2;
        else if(current == 'b')
            count++;
        
        return count;
    }
};