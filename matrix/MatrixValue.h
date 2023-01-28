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

    bool operator==(const MatrixValue&) const;
    bool operator!=(const MatrixValue&) const;
    bool operator==(int) const;
    bool operator!=(int i) const { return !(i == *this); }

private:
    int m_Value = 0; /* der Wert 0 bedeutet ein leeres Feld */
};

#endif // MATRIXVALUE_H
