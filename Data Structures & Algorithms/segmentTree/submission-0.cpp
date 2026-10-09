class Segment {
public:
    int _L;
    int _R;
    Segment* left;
    Segment* right;
    int _sum;

    Segment(int sum, int L, int R) {
        _sum = sum;
        _L = L;
        _R = R;
        left = nullptr;
        right = nullptr;
    }

    void update(int index, int val) {
        if (_L == _R) {
            _sum = val;
            return;
        }

        int M = (_L + _R) / 2;
        if (index <= M) {
            left->update(index, val);
        } else {
            right->update(index, val);
        }

        _sum = left->_sum + right->_sum;
    }

    int query(int L, int R) {
        if (_L == L && _R == R) {
            return _sum;
        }

        int M = (_L + _R) / 2;

        // in left range
        if (R <= M) {
            return left->query(L, R);
        } else if (M < L) { // in right range
            return right->query(L, R);
        }

        return left->query(L, M) + right->query(M+1, R);
    }

    static Segment* build(vector<int>& nums, int L, int R) {
        if (L == R) {
            return new Segment(nums[L], L, R);
        }

        int M = (L + R) / 2;
        Segment* root = new Segment(0, L, R);
        root->left = build(nums, L, M);
        root->right = build(nums, M + 1, R);

        root->_sum = root->left->_sum + root->right->_sum;

        return root;
    }
};


class SegmentTree {
public:
    Segment* root;
    SegmentTree(vector<int>& nums) {
        root = Segment::build(nums, 0, nums.size() - 1);
    }
    
    void update(int index, int val) {
        root->update(index, val);
    }
    
    int query(int L, int R) {
        return root->query(L, R);
    }
};
