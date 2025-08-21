class Solution {
public:
    string RLE(string str)
    {
        string s = "";
        int count = 1;

        for(int i=1; i<str.size(); i++)
        {
            if(str[i] == str[i-1])
                count++;
            else
            {
                s += to_string(count);
                s += str[i-1];
                count = 1;
            }
        }

        s += to_string(count);
        s += str[str.size()-1];

        return s;
    }

    string countAndSay(int n) {
        string str = "1";
        n--;

        while(n > 0)
        {
            str = RLE(str);
            n--;
        }

        return str;
    }
};