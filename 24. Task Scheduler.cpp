class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        //Populate the freqency of the tasks
        vector<int>alpha(26);

        for(auto &x : tasks){
            alpha[x-'A']++;     //For A it would go to location 0, B would go to location 1 and so on....
        }

       //We sort the alpha vector, so that we can get the task with highest frequency at the end
        sort(begin(alpha),end(alpha));  //(This doesnt ruin the time complexity becuase we are sorting only 26 characters)

        int spaces_to_fill = alpha[25]-1; // We do -1 becuase we dont care aboute the last occurance of that task, becuase we dont need to fill anything after that as it is the last task. Hence no cool down after that for it.

        int idleslots = spaces_to_fill * n;  //Idle slots between the same task to be filled

        for(int i=24;i>=0;i--){
            idleslots = idleslots - min(spaces_to_fill, alpha[i]); // We could fill minimum of the frequency of other task or the spaces that need to be filled
        }

        if(idleslots > 0){
            return idleslots+tasks.size();
        }

        return tasks.size();
        
    }
};
