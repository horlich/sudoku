#include "Matrix.h"

#include <stdexcept>
#include <sstream>
#include <memory>
#include <algorithm>
#include "onumber.h"

using namespace std;

Matrix::Matrix()
{
    /* -------------------- Populate m_Positions: -------------------- */
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            MatrixPosition* mp = new MatrixPosition(col, row);
            m_Positions.push_back(mp);
        }
    }
    /* ------------ Define allies for each MatrixPosition ----------*/
    for (MatrixPosition* mp : m_Positions) {
        for (int i = 0; i < 9; ++i) {
            MatrixPosition* hallie = position(i, mp->row());
            if (hallie != mp) mp->addAllie(hallie);
            MatrixPosition* vallie = position(mp->column(), i);
            if (vallie != mp) mp->addAllie(vallie);
        }
        /* define borders of mp's square: */
        int leftBorder = mp->column() - (mp->column() % 3);
        int rightBorder = leftBorder + 2;
        int upperBorder = mp->row() - (mp->row() % 3);
        int lowerBorder = upperBorder + 2;
        /* get all members of mp's square: */
        for (int col = leftBorder; col <= rightBorder; ++col) {
            for (int row = upperBorder; row <= lowerBorder; ++row) {
                MatrixPosition* sallie = position(col, row);
                if (sallie != mp) mp->addAllie(sallie);
            }
        }
    }
}


Matrix::~Matrix() {
    for (MatrixPosition* ptr : m_Positions) delete ptr;
}


MatrixPosition* Matrix::position(int index) const {
    if ((index < 0) || (index > 80))
        throw std::invalid_argument("Ungültiger Index");
    return m_Positions.at(index);
}


MatrixPosition* Matrix::position(int col, int row) const {
    if ((col < 0) || (col > 8) || (row < 0) || (row > 8))
        throw std::invalid_argument("Ungültige Position");
    return m_Positions.at(getIndex(col, row));
}


void Matrix::setValue(int index, int val) {
    MatrixPosition* mp = m_Positions.at(index);
    mp->setValue(val);
}


void Matrix::presetValue(int index, int val) {
    if ((index < 0) || (index > 80))
        throw std::invalid_argument("Ungültiger Index");
    MatrixPosition* pos = m_Positions.at(index);
    if ((val < 1) || (val > 9) || (! pos->isAlternative(val)))
        throw std::invalid_argument("Preset mit illegalem Wert");
    pos->setValue(val);
    pos->locked();
}


void Matrix::presetValue(int col, int row, int val) {
    presetValue(getIndex(col, row), val);
}


bool Matrix::setValues() {
    for (MatrixPosition* mp : m_Positions) {
        if (mp->isLocked()) continue;
        if (! mp->setRandomValue()) return false;
    }
    return true;
}


void Matrix::clear() {
    for (MatrixPosition* mp : m_Positions) {
        mp->clear();
    }
}


bool Matrix::populate() {
    int count = 0;
    while (++count < 1000) { // set max loops
        if (setValues()) return true;
        clear();
    }
    return false;
}


void Matrix::debugPrintPositions() const {
    cout << "Starte Druck:\n";
    for (MatrixPosition* mp : m_Positions) {
        cout << *mp << '\n';
    }
    cout << m_Positions.size() << " Elemente gedruckt.\n";
}


ostream& operator<<(ostream& os, const Matrix& m) {
    for (const MatrixPosition* mp : m.positions()) {
        int col = mp->column();
        int row = mp->row();
        if(col > 0) os << " ";
        if (! mp->value().isValid()) {
            os << "\u00b7"; /* Mittel-Punkt */
        } else {
            os << mp->value().toInt();
        }
        if ((col == 2) || (col == 5)) {
            os << " "; /* extra space */
        } else if (col == 8) {
            os << "\n";
            if ((row == 2) || (row == 5)) os << "\n"; /* extra newline */
        }
    }
    return os;
}

