class Meeting {
public:
    int startTime;
    int endTime;
    
    Meeting* left;
    Meeting* right;
    
    Meeting(int _start, int _end) {
        startTime = _start;
        endTime = _end;
        left = nullptr;
        right = nullptr;
    }
    
    int compare(Meeting* meeting) {
        if (startTime >= meeting->endTime) {
            return 1;
        } else if (endTime <= meeting->startTime) {
            return -1;
        }
        return 0;
    }
};

class MyCalendar {
public:
    Meeting* root;
    MyCalendar() {
        root = nullptr;
    }

    bool insert(int startTime, int endTime) {
        Meeting* meeting = new Meeting(startTime, endTime);

        if (root == nullptr) {
            root = meeting;
            return true;
        }

        Meeting* current = root;
        
        while (current) {
            if (current->compare(meeting) == 1) {
                if (current->left != nullptr) {
                    current = current->left;
                } else {
                    current->left = meeting;
                    break;
                }
            } else if (current->compare(meeting) == -1) {
                if (current->right != nullptr) {
                    current = current->right;
                } else {
                    current->right = meeting;
                    break;
                }
            } else {
                return false;
            }
        }

        return true;
    }
    
    bool book(int startTime, int endTime) {
        return insert(startTime, endTime);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */