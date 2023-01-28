#include "MatrixValue.h"

#include <stdexcept>

MatrixValue::MatrixValue()
{
}


void MatrixValue::set(int i) {
    if ((i < 0) || (i > 9))
            throw std::invalid_argument("Ungültiger Wert");
    m_Value = i;
}


bool MatrixValue::operator==(const MatrixValue& other) const {
    return this->toInt() == other.toInt();
}


bool MatrixValue::operator!=(const MatrixValue& other) const {
    return this->toInt() != other.toInt();
}


bool MatrixValue::operator==(int other) const {
    return this->toInt() == other;
}
