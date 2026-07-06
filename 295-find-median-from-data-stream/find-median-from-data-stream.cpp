class MedianFinder {
public:
    priority_queue<int> lMaxH;
    priority_queue<int, vector<int>, greater<int>> rMinH;
    void balance(){
        if(lMaxH.size() < rMinH.size()){
            lMaxH.push(rMinH.top());
            rMinH.pop();
        } else if(lMaxH.size() > rMinH.size() + 1){
            rMinH.push(lMaxH.top());
            lMaxH.pop();
        }
    }
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(lMaxH.empty()){
            lMaxH.push(num); return;
        }
        if(num > lMaxH.top()){
            rMinH.push(num);
        } else {
            lMaxH.push(num);
        }
        balance();
    }
    
    double findMedian() {
        if(lMaxH.size() > rMinH.size()) return lMaxH.top();
        else return ((double)lMaxH.top() + rMinH.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */