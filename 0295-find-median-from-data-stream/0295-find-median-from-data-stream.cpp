class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {
    }
    void balanceheap(){
        if(minheap.size()<maxheap.size()-1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }else if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    void addNum(int num) {
        if(maxheap.empty()){
            maxheap.push(num);
        }else if(maxheap.top()>num){
            maxheap.push(num);
        }else{
            minheap.push(num);
        }
        balanceheap();
    }
    
    double findMedian() {
        double ans;
        if(maxheap.size()>minheap.size()){
            return maxheap.top();
        }else if(maxheap.size()==minheap.size()){
            ans=maxheap.top()+minheap.top();
            ans/=2;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */