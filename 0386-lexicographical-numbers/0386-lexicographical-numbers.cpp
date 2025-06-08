class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ans;

        for(int i=1; i<=9; i++)
        {
            int num1 = i;
            if(num1 > n)
                break;
            ans.push_back(num1);

            for(int j=0; j<=9; j++)
            {
                int num2 = num1*10 + j;
                if(num2 > n)
                    break;
                ans.push_back(num2);

                for(int k=0; k<=9; k++)
                {
                    int num3 = num2*10 + k;
                    if(num3 > n)
                        break;
                    ans.push_back(num3);

                    for(int l=0; l<=9; l++)
                    {
                        int num4 = num3*10 + l;
                        if(num4 > n)
                            break;
                        ans.push_back(num4);

                        for(int m=0; m<=9; m++)
                        {
                            int num5 = num4*10 + m;
                            if(num5 > n)
                                break;
                            ans.push_back(num5);
                        }
                    }
                }
            }
        }

        return ans;
    }
};