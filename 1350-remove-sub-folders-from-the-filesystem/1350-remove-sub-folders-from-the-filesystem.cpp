class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        if(folder.size() == 0)
            return folder;
        
        sort(folder.begin(), folder.end());
        vector<string>result;
        
        result.push_back(folder[0]);

        for(int i=1; i<folder.size(); i++)
        {
            if(folder[i].substr(0, result.back().size())==result.back())
            {
                if(folder[i].size() > result.back().size())
                {
                    if(folder[i][result.back().size()]!='/')
                    {
                        result.push_back(folder[i]);
                    }
                }
            }
            else{
                result.push_back(folder[i]);
            }
        }

        return result;
    }
};