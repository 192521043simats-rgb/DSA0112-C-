#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
class Time {
    int seconds;
public:
    explicit Time(int s=0) : seconds(s) {}
    Time& operator++() { ++seconds; return *this; }
    Time operator++(int) { Time old=*this; ++seconds; return old; }
    bool operator==(const Time& t) const { return seconds==t.seconds; }
    bool operator<(const Time& t) const { return seconds<t.seconds; }
    int value() const { return seconds; }
};
class Playlist {
    std::vector<std::string> tracks;
public:
    explicit Playlist(std::vector<std::string> t) : tracks(std::move(t)) {}
    std::string& operator[](std::size_t i) {
        if (i>=tracks.size()) throw std::out_of_range("Track index out of range");
        return tracks[i];
    }
    const std::string& operator[](std::size_t i) const {
        if (i>=tracks.size()) throw std::out_of_range("Track index out of range");
        return tracks[i];
    }
    std::size_t size() const { return tracks.size(); }
};
int main() {
    Time t(10);
    Time a=t++;
    Time b=++t;
    std::cout << a.value() << ' ' << b.value() << ' ' << t.value() << '\n';
    Playlist p({"Track One","Track Two"});
    std::cout << p[0] << '\n';
    try { std::cout << p[static_cast<std::size_t>(-1)] << '\n'; }
    catch (const std::out_of_range& e) { std::cout << e.what() << '\n'; }
}

