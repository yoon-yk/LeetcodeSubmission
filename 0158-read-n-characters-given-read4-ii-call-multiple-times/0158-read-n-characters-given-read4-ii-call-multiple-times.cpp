/***** CHEATED *******/

class Solution {
public:
    // Buffer to store characters read by read4
    char buf4[4];
    // Current index in buf4
    int buf4Index = 0;
    // Number of characters left to read in buf4
    int buf4CharsLeft = 0;

    int read(char *buf, int n) {
        // Number of characters read into buf
        int totalCharsRead = 0;

        // Continue reading until we've read n characters 
        // or there are no more characters left to read
        while (totalCharsRead < n) {
            // If there are no characters left in buf4, read more characters
            if (buf4CharsLeft == 0) {
                buf4CharsLeft = read4(buf4);
                buf4Index = 0;

                // If read4 returns 0, there are no more characters to read
                if (buf4CharsLeft == 0) {
                    break;
                }
            }

            // Copy characters from buf4 to buf
            while (totalCharsRead < n && buf4CharsLeft) {
                buf[totalCharsRead++] = buf4[buf4Index++];
                buf4CharsLeft--;
            }
        }

        // Return the total number of characters read into buf
        return totalCharsRead;
    }
};
