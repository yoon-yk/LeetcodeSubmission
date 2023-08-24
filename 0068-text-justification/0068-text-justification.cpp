class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int i = 0, n = words.size();

        while (i < n) {
            int j = i, lineLen = 0;

            // Calculate how many words fit on this line
            while (j < n && lineLen + words[j].size() + (j - i) /* inbetween */ <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }

            int spaces = maxWidth - lineLen;
            int wordsCount = j - i;
            string cur;

            // 1. Left-justify if it's a single word or the last line
            if (wordsCount == 1 || j == n) {
                for (int k = i; k < j; ++k) {
                    cur += words[k];
                    if (k < j - 1) cur += ' ';
                    else cur += string(spaces, ' ');
                    spaces--;
                }
            } else {
                // 2. Greedy approach


                // Calculate spaces between words
                int sp = spaces / (wordsCount - 1);
                int extra = spaces % (wordsCount - 1);

                for (int k = i; k < j; ++k) {
                    cur += words[k];

                    // distribute spaces
                    if (k >= j - 1) continue;
                    cur += string(sp, ' ');
                    if (extra) {
                        cur += ' ';
                        extra--;
                    }
                }
            }

            ret.push_back(cur);
            i = j;  // Move to the next word
        }

        return ret;
    }
};
