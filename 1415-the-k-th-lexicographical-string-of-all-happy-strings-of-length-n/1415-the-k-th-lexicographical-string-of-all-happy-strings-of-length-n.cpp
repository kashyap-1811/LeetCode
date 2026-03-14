class Solution {
public:
    string make(int n, int &k, string str, int idx)
    {
        if(idx == n)
        {
            k--;
            if(k == 0)  return str;
            else return "";
        }

        for(char ch='a'; ch<'d'; ch++)
        {
            if(ch != str[idx-1])
            {
                string ans = make(n, k, str+ch, idx+1);
                if(ans != "")
                    return ans; 
            }
        }

        return "";
    }

    string getHappyString(int n, int k) {
        for(char ch='a'; ch<'d'; ch++)
        {
            string str = "";
            str += ch;
            string ans = make(n, k, str, 1);
            if(k == 0)
                return ans;
        }

        return "";
    }
};