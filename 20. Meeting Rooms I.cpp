/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here

        int n = intervals.size();

        if(n==0){
            return true;
        }

        sort(intervals.begin(),intervals.end(),[](const Interval &i1, const Interval &i2){return i1.start < i2.start;}); ///Sorting based on start date

        int current_end_date = intervals[0].end;

        for(int i=1;i<n;i++){
            if(intervals[i].start < current_end_date){
                return false;
            }

            current_end_date = intervals[i].end;

        }

        return true;
    }
};
