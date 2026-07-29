class DynamicArray {
private:
    int *a;
public:
    int length;
    int cap;
    DynamicArray(int capacity) {
        cap = capacity;
        if (capacity > 0)
        {
            a = new int[cap];
        }
        else
        {
            a = nullptr;
            cap = 0;
        }
        length = 0;
    }

    int get(int i) {
        return a[i];
    }

    void set(int i, int n) {
        a[i] = n;
    }

    void pushback(int n) {
        if (length == cap)
        {
            resize();
        }
        a[length++] = n;
    }

    int popback() {
        int item = a[length-1];
        length--;
        return item;
    }

    void resize() {
        cap *= 2;
        int *newArr = new int[cap];

        for (int i = 0; i < length; i++)
        {
            newArr[i] = a[i];
        }
        a = newArr;
    }

    int getSize() {
        return length;
    }

    int getCapacity() {
        return cap;
    }
};
