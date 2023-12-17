//Watch for understanding : https://www.youtube.com/watch?v=eGf-26OTI-A
// Run it on the example : tasks = ["A","A","A","B","B","B"], n = 2



//Q : 
//Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
//However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.
//Return the least number of units of times that the CPU will take to finish all the given tasks.

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
