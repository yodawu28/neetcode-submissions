class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }
        
        if (num > maxHeap.top()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        
        if (maxHeap.size() > minHeap.size() + 1) {
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
        
        if (maxHeap.size() + 1 < minHeap.size()) {
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else if (maxHeap.size() < minHeap.size()) {
            return minHeap.top();
        }

        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
