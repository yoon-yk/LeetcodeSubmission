class Solution {
public:
    string decodeString(string s) {
        stringstream ss(s);
        return ProcessExp(ss);
    }
    string ProcessExp(stringstream& in)
    {
        stringstream out;
        char c;
        int times = 0;
        while (in >> c)
        {
            if (isdigit(c)) times = 10 * times + (c - '0');
            else if (c == '[')
            {
                string inner = ProcessExp(in);
                for (int i = 0; i < times; i++) out << inner;
                times = 0;
            }      
            else if (c == ']') break;
            else out << c;
        }
        return out.str();
    }
};
