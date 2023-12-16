int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) 
{
    int surplus=0;
    int deficiet=0;
    int index=0;
    
    for(int i=0;i<A.size();i++)
    {
        surplus = surplus + (A[i] - B[i]);
        if(surplus < 0)
        {
            deficiet+=surplus;
            surplus=0;
            index=i+1;
        }
    }
    
    if(surplus+deficiet >=0)
    {
        return index;
    }
    
    return -1;
}
