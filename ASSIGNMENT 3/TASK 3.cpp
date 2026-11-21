#include <iostream>
#include <algorithm>
class Event {
    int rows, seats, booked;
    bool** map;
public:
    Event(int r, int s) : rows(r), seats(s), booked(0), map(nullptr) {
        if (rows < 0 || seats < 0) throw std::invalid_argument("Invalid dimensions");
        if (rows > 0) {
            map = new bool*[rows]{};
            try {
                for (int i=0; i<rows; ++i) map[i] = new bool[seats]{};
            } catch (...) {
                for (int i=0; i<rows; ++i) delete[] map[i];
                delete[] map;
                throw;
            }
        }
        std::cout << "Event created: " << rows << " x " << seats << '\n';
    }
    bool book(int r, int s) {
        if (r<0 || r>=rows || s<0 || s>=seats || map[r][s]) return false;
        map[r][s]=true; ++booked; return true;
    }
    bool cancel(int r, int s) {
        if (r<0 || r>=rows || s<0 || s>=seats || !map[r][s]) return false;
        map[r][s]=false; --booked; return true;
    }
    ~Event() {
        for (int i=0; i<rows; ++i) delete[] map[i];
        delete[] map;
        std::cout << "Event closed; booked seats remaining: " << booked << '\n';
    }
};
int main() {
    Event stackEvent(2,3);
    stackEvent.book(0,1); stackEvent.book(1,2); stackEvent.cancel(0,1);
    Event* heapEvent = new Event(1,4);
    heapEvent->book(0,0);
    delete heapEvent;
    {
        Event blockEvent(1,2);
        blockEvent.book(0,1);
    }
    Event emptyEvent(0,5);
}
