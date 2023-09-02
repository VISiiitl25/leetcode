class Solution
{
    public:
        map<string,int>mp;
        int recur(int i, string &s, string temp, vector<string> &dict)
        {
            string demo=to_string(i);
            demo=demo+"|";
            temp = temp + s[i];
            demo=demo+temp;

            if(mp.find(demo)!=mp.end()){
                return mp[demo];
            }             
            if (i == s.size())
            {
                return 0;
            }
            int x = 0, y = 0;

            bool flag = 0;
            for (int j = 0; j < dict.size(); j++)
            {
                if (temp == dict[j])
                {
                    flag = 1;
                    break;
                }
            }
            int z=recur(i+1,s,"",dict);
            if (flag)
            {
                x = temp.size() + recur(i + 1, s,"", dict);
            }
            y = recur(i + 1, s, temp, dict);

            return mp[demo]=max({x,y,z});
        }
    int minExtraChar(string s, vector<string> &dictionary)
    {
        string temp="";

        return s.size()-recur(0, s,temp, dictionary);
    }
};