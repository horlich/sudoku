#ifndef MATRIXVALUE_H
#define MATRIXVALUE_H

class MatrixValue
{
public:
    MatrixValue();

    int toInt() const { return m_Value; }
    void set(int i);
    inline void clear() { m_Value = 0; }
    bool isValid() const { return m_Value > 0; }

    bool operator==(const MatrixValue&);
    bool operator!=(const MatrixValue& mv) { return !(mv == *this);  }
    bool operator==(int);
    bool operator!=(int i) { return !(i == *this); }

private:
    int m_Value = 0; /* der Wert 0 bedeutet ein leeres Feld */
};

#endif // MATRIXVALUE_H
