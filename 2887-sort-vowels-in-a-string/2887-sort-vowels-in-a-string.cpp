class Solution {
public:
    string sortVowels(string s) {
        queue<int>q;
        vector<char> vowels;

        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if( c=='A' || c=='a' ||
                c=='E' || c=='e' ||
                c=='O' || c=='o' ||
                c=='I' || c=='i' ||
                c=='U' || c=='u'
            ){
                vowels.push_back(c);
                q.push(i);
            }
        }

        sort(vowels.begin(), vowels.end());

        int x = 0;
        while(!q.empty()){
            int i = q.front();
            q.pop();

            s[i] = vowels[x++];
        }

        return s;
    }
};