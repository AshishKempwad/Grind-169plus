int Solution::solve(vector<vector<int> > &A)
{
    sort(A.begin(),A.end()); //we sort based on first value i.e. based on start time of the meeting
    
    priority_queue<int,vector<int>,greater<int>>minheap;
    minheap.push(A[0][1]); // to know when meeting ends
    int n=A.size();
    for(int i=1;i<n;i++)
    {
        if(A[i][0] >= minheap.top())  // If the next meeting has the start time greater than the end time of the current meeting, then we can accomodate that meeting in the same conference room.
        {
            minheap.pop();
        }
        
        minheap.push(A[i][1]);  //To keep the track of end time of the meetings
    }
    
    return minheap.size();
}
