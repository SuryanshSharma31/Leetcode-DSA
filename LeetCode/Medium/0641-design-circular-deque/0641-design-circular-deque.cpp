class MyCircularDeque {
public:
    vector<int> arr;
    int t;
    int f, r, cnt;

    MyCircularDeque(int k) {
        t = k;
        arr.resize(k);
        f = 0;
        r = -1;
        cnt = 0;
    }

    bool insertFront(int value) {
        if(cnt == t) return false;

        if(cnt == 0) {
            f = r = 0;
        }
        else {
            f = (f-1+t)%t;
        }

        arr[f] = value;
        cnt++;
        return true;
    }

    bool insertLast(int value) {
        if(cnt == t) return false;

        if(cnt == 0) {
            f = r = 0;
        }
        else {
            r = (r+1)%t;
        }

        arr[r] = value;
        cnt++;
        return true;
    }

    bool deleteFront() {
        if(cnt == 0) return false;

        if(cnt == 1) {
            f = 0;
            r = -1;
        }
        else {
            f = (f+1)%t;
        }

        cnt--;
        return true;
    }

    bool deleteLast() {
        if(cnt == 0) return false;

        if(cnt == 1) {
            f = 0;
            r = -1;
        }
        else {
            r = (r-1+t)%t;
        }

        cnt--;
        return true;
    }

    int getFront() {
        if(cnt == 0) return -1;
        return arr[f];
    }

    int getRear() {
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