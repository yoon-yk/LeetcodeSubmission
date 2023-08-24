class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int start = 0, n = words.size();

        while (start < n) {
            int end = start, lineLength = 0;

            // max words per line ?
            while (end < n && lineLength + words[end].size() + (end - start) <= maxWidth) {
                lineLength += words[end].size();
                end++;
            }

            int spacesRequired = maxWidth - lineLength;
            int numOfWords = end - start;
            string currentLine;

            // Case 1. Single word or last line: left-justify
            if (numOfWords == 1 || end == n) {
                for (int i = start; i < end; ++i) {
                    currentLine += words[i];
                    if (i < end - 1) {
                        currentLine += ' ';
                        spacesRequired--;
                    }
                }
                currentLine += string(spacesRequired, ' '); // Fill remaining space, if any
            } else {
                // Case 2. Middle lines: distribute spaces between words
                int spacesPerGap = spacesRequired / (numOfWords - 1);
                int extraSpaces = spacesRequired % (numOfWords - 1);

                for (int i = start; i < end; ++i) {
                    currentLine += words[i];
                    
                    if (i == end - 1) continue;  // No spaces after the last word in the line

                    currentLine += string(spacesPerGap, ' ');

                    if (extraSpaces) {
                        currentLine += ' ';
                        extraSpaces--;
                    }
                }
            }

            result.push_back(currentLine);
            start = end; // new line
        }

        return result;
    }
};
