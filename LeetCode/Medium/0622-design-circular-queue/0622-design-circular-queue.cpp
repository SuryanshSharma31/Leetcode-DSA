class MyCircularQueue {
public:
    vector<int> arr;
    int t;
    int f;
    int r;
    int cnt;

    MyCircularQueue(int k) {
        t = k;
        arr.resize(k);
        f = 0;
        r = -1;
        cnt = 0;
    }

    bool enQueue(int value) {
        if(cnt == t) return false;

        r = (r + 1) % t;
        arr[r] = value;
        cnt++;

        return true;
    }

    bool deQueue() {
        if(cnt == 0) return false;

        f = (f + 1) % t;
        cnt--;

        return true;
    }

    int Front() {
        if(cnt == 0) return -1;
        return arr[f];
    }

    int Rear() {
        if(cnt == 0) return -1;
        return arr[r];
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == t;
    }
};