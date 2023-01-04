#ifndef MATRIX_H
#define MATRIX_H

#include <array>
#include <vector>
#include <iostream>
#include <map>
#include <memory>

#include "MatrixPosition.h"


class Matrix
{
public:
    static constexpr int getIndex(int col, int row) {
        return row * 9 + col;
    }

    Matrix();
    virtual ~Matrix();

    void clear();
    MatrixPosition* position(int index) const;
    bool populate();
    const PositionVec& positions() const { return m_Positions; }
    void debugPrintPositions() const;
    void setValue(int positionIndex, int val);
    void presetValue(int positionIndex, int val);
    void presetValue(int col, int row, int val);

private:
    MatrixPosition* position(int col, int row) const;
    bool setValues();

    PositionVec m_Positions;
};


std::ostream& operator<<(std::ostream&, const Matrix&);


#endif // MATRIX_H
