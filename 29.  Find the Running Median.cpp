vector<double> runningMedian(vector<int> a) {
    int n = a.size();
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    vector<double>res;
    double temp;
    
    for(int i=0;i<n;i++){
        if(maxheap.empty() || a[i] <= maxheap.top()){
            maxheap.push(a[i]);
        }
        else{
            minheap.push(a[i]);
        }
        if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() >  maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        if((minheap.size()+maxheap.size()) % 2 == 0){
            temp = (maxheap.top() + minheap.top()) / 2.0;
            res.push_back(temp);
        }
        else{
            if(maxheap.size()>minheap.size()){
                temp = maxheap.top() * 1.0;
                res.push_back(temp);
            }
            else{
                temp = minheap.top()* 1.0;
                res.push_back(temp);
            }
        }
    }
 
return res;
}
