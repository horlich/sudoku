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
    static constexpr int getIndex(int col, int row);

    Matrix();
    virtual ~Matrix();

    void clear();
    bool populate();
    int valueSettings() const { return MatrixPosition::valueSettings(); }
    const PositionVec& positions() const { return m_Positions; }
    void debugPrintPositions() const;
    void presetValue(int col, int row, int val);

private:
    MatrixPosition* position(int col, int row);
    bool setValues();

    PositionVec m_Positions;
};


std::ostream& operator<<(std::ostream&, const Matrix&);


#endif // MATRIX_H
