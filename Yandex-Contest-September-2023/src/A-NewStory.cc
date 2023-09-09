#include <bits/stdc++.h>

struct Time {
    int year = 0, month = 0, day = 0;
    int hour = 0, minutes = 0, seconds = 0;
};

struct LiveTime {
    int days = 0, seconds = 0;

    LiveTime(const Time &start, const Time &finish) {
        int days_finish = 0, days_start  = 0, seconds_finish = 0, seconds_start = 0;

        days_finish += finish.year * 365;
        days_start  += start.year * 365;

        constexpr std::array<int, 12> month_days_count {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        days_finish += std::accumulate(month_days_count.begin(), month_days_count.begin() + finish.month - 1, 0);
        days_start  += std::accumulate(month_days_count.begin(), month_days_count.begin() + start.month - 1, 0);

        days_finish += finish.day;
        days_start  += start.day;

        days = days_finish - days_start;

        seconds_finish += finish.hour * 3600 + finish.minutes * 60 + finish.seconds;
        seconds_start  += start.hour * 3600 + start.minutes * 60 + start.seconds;

        if (seconds_finish < seconds_start) {
            days -= 1;
            seconds_finish += 24 * 3600;
        }

        seconds = seconds_finish - seconds_start;
    }
};

std::istream &operator>>(std::istream &in, Time &t) {
    in >> t.year >> t.month >> t.day >> t.hour >> t.minutes >> t.seconds;
    return in;
}

int main() {
    Time live_begin, live_end;
    std::cin >> live_begin >> live_end;

    LiveTime live_time(live_begin, live_end);
    std::cout << live_time.days << ' ' << live_time.seconds << std::endl;
    return EXIT_SUCCESS;
}

// Time complex: O(N), where N is Month index of date minus January index | Example: 5 - 1 = 4 => O(4) -> O(1)