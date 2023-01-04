#ifndef MATRIXPOSITION_H
#define MATRIXPOSITION_H

#include <iostream>
#include <vector>
#include <utility>
#include <set>

#include "MatrixValue.h"
#include "RandomSet.h"
#include "Sudoku.h"

class MatrixPosition;

using Sudoku::IntVec;
using Sudoku::PositionVec;


class MatrixPosition
{
public:
    MatrixPosition(int column = invalidArg, int row = invalidArg);

    int column() const { return m_Column; }
    int row() const { return m_Row; }
    MatrixValue value() const { return m_Value; }
    void setValue(int);
    bool setRandomValue();
    void clear();
    bool isValid() const;
    bool isLocked() const { return m_Locked; }
    void locked(bool b = true) { m_Locked = b; }
    void addAllie(MatrixPosition* mp);
    bool isAlternative(int) const;
    IntVec getAlternatives() const;
    int countAlternatives() const;
    PositionVec conflictingPositions(int val) const;

    bool operator==(const MatrixPosition& mp) const;
    bool operator != (const MatrixPosition& mp) const { return !(*this == mp); }
    bool operator<(const MatrixPosition&) const;
    bool operator>(const MatrixPosition&) const;
    bool operator<=(const MatrixPosition&) const;
    bool operator>=(const MatrixPosition&) const;

private:
    static constexpr int invalidArg {9};
    int m_Column;
    int m_Row;
    bool m_Locked = false;
    MatrixValue m_Value;
    PositionVec m_Allies;

}; // class MatrixPosition

std::ostream& operator<<(std::ostream&, const MatrixPosition&);




#endif // MATRIXPOSITION_H
