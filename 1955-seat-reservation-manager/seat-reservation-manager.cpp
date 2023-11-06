class SeatManager {
private:
    set<int> s;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }
    }

    int reserve() {
        if (s.empty()) {
            return -1;
        }
        auto i = s.begin();
        int seatNumber = *i;
        s.erase(i);
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        s.insert(seatNumber);
    }
};
