/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int pick = 1;
        int l = 0;
        int r = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (guess(mid) == 0) {
                pick = mid;
                break;
            } else if (guess(mid) > 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return pick;
    }
};