//https://leetcode.com/problems/find-median-from-data-stream/description/
class MedianFinder {
    double median;
    int sz;
    priority_queue<int> pql;
    priority_queue<int, vector<int>, greater<int> > pqr;
public:
    MedianFinder() {
        median = 0.0;sz=0;
    }
    void updMedian(int old, int addition) {
        if(sz%2==1) {
            median = addition;
        }
        else {
            median = (old + addition + 0.0)/2.0;
            int l = min(old, addition);
            int r = max(old, addition);
            pql.push(l);
            pqr.push(r);
        }
    }
    void addNum(double num) {
        sz++;
        if(sz==1) {
            median = num;
            return;
        }
        if(num<median) {
            pql.push(num);
        }
        else pqr.push(num);
        int addition = median;
        if(pql.size() > pqr.size()) {
            addition = pql.top();pql.pop();
        }
        else {
            addition = pqr.top();pqr.pop();
        }
        updMedian(median, addition);
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
