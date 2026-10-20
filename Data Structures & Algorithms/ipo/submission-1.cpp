struct Item {
    int capital;
    int profit;
    
    Item(int capital, int profit): capital(capital), profit(profit){}
    
    bool operator<(const Item& p) const
    {
        return profit < p.profit;
    }
    
    bool operator>(const Item& p) const {
        return this->profit > p.profit;
    }
};

struct CompareCapital {
    // Đảo dấu '>' thành '<' để phần tử có capital nhỏ nhất lên top (Min-Heap)
    bool operator()(const Item& a, const Item& b) {
        return a.capital > b.capital;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<Item> heap1;
        priority_queue<Item, vector<Item>, CompareCapital> heap2;

        for (int i = 0; i < profits.size(); i++) {
            Item item = Item(capital[i], profits[i]);
            
            if (item.capital <= w) {
                heap1.push(item);
            } else {
                heap2.push(item);
            }
        }
        
        while (k > 0) {
            if (heap1.empty()) {
                return w;
            }
            w += heap1.top().profit;
            heap1.pop();
            k--;
            
            while (!heap2.empty()) {
                if (heap2.top().capital > w) {
                    break;
                }
                heap1.push(heap2.top());
                heap2.pop();
            }
        }
        
        return w;
    }
};