#pragma once

struct Money {
    long pounds;
    char pence;

    bool operator==(const Money& other) const noexcept {
        return pounds == other.pounds && pence == other.pence;
    }

    Money& operator+=(const Money& other) noexcept {
        pounds += other.pounds;
        pence += other.pence;
        if(pence >= 100) {
            pounds++;
            pence -= 100;
        } else if(pounds > 0 && pence < 0) {
            pounds--;
            pence += 100;
        }
        return *this;
    }
};
