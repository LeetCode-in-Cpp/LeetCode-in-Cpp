// #Hard #Top_100_Liked_Questions #Sorting #Two_Pointers #Design #Heap_Priority_Queue #Data_Stream
// #Big_O_Time_O(n*log_n)_Space_O(n) #2024_05_24_Time_231_ms_(98.67%)_Space_121.7_MB_(55.30%)

class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;

    MedianFinder() {
    }

    void addNum(int x) {
        if (maxpq.empty() || maxpq.top() > x) {
            maxpq.push(x);
        } else {
            minpq.push(x);
        }
        balanceHeaps();
    }

    void balanceHeaps(){
        if (maxpq.size() > minpq.size() + 1) {
            minpq.push(maxpq.top());
            maxpq.pop();
        } else if(minpq.size() > maxpq.size() + 1) {
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }

    double findMedian() {
        if (maxpq.size() == minpq.size()) {
            return (minpq.top() + maxpq.top()) / 2.0;
        } else {
            return (maxpq.size() > minpq.size())? (double) maxpq.top() : (double) minpq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
