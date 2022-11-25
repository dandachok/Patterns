#include <cmath>
#include <iostream>

using namespace std;

class SquarePeg {
    public:
        SquarePeg(double width) : width(width) {}

        double getWidth() {
            return width;
        }

        double width;
};

class RoundPeg {
    public:

        RoundPeg() {}

        RoundPeg(double radius): radius(radius) {}

        virtual double getRadius() {
            return radius;
        }
    
        double radius;
};

class RoundHole {
    public:

        RoundHole(double radius): radius(radius) {}

        double getRadius() {
            return radius;
        }

        bool fits(RoundPeg& peg) {
            return radius >= peg.getRadius();
        }

        double radius;
};


class SquarePegToRoundPegAdapter: public RoundPeg {
    public:
        SquarePegToRoundPegAdapter(SquarePeg& peg) : peg(peg) {}

        double getRadius() override {
            return peg.getWidth() * sqrt(2) / 2;
        }

        SquarePeg& peg;
};

int main() {

    RoundHole hole(5);
    RoundPeg rpeg(5);

    cout << hole.fits(rpeg) << "\n";

    SquarePeg speg(5);
    SquarePegToRoundPegAdapter sradapter(speg);
    cout << hole.fits(sradapter) << "\n";

    return 0;
}