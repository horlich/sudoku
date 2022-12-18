#include "MatrixPosition.h"

#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

int MatrixPosition::s_ValueSettings = 0;

MatrixPosition::MatrixPosition(int column, int row)
    : m_Column(column)
    , m_Row(row)
{}


void MatrixPosition::setValue(int val) {
    if (isLocked()) {
        stringstream buf;
        buf << "Versuch, gesperrten Wert in Position " << *this << " zu verändern";
        throw std::runtime_error(buf.str());
    }
    m_Value.set(val);
    ++s_ValueSettings;
}


void MatrixPosition::clear() {
    if (isLocked()) return;
    m_Value.clear();
}


bool MatrixPosition::setValue() {
    for (int i : getAlternatives()) {
        setValue(i);
        return true;
    }
    /* no alternative */
    RandomSet rs;
    for (int val : rs) {
        std::map<MatrixPosition*, int> cmap;
        for (MatrixPosition* mp : conflictingPositions(val)) {
            if ((mp == this) || (mp->isLocked())) continue;
            IntVec altVec = mp->getAlternatives();
            if (altVec.empty()) { // found conflicting position without alternatives
                cmap.clear();
                break;
            }
            cmap[mp] = altVec.at(0);
        }
        if (cmap.empty()) continue; // try next val
        for (const auto pair : cmap) {
            pair.first->setValue(pair.second);
        }
        setValue(val);
        return true;
    }
    return false;
}


bool MatrixPosition::isValid() const {
    return ((m_Column >= 0) && (m_Row >= 0) && (m_Column < invalidArg) && (m_Row < invalidArg));
}


void MatrixPosition::addAllie(MatrixPosition* mp) {
    if (mp == this) return; /* cannot be its own allie */
    if (std::find(m_Allies.begin(), m_Allies.end(), mp) == m_Allies.end())
        m_Allies.push_back(mp);
}


bool MatrixPosition::isAlternative(int val) const {
    if (isLocked() || (val == value().toInt())) return false;
    if (val == 0) return true;
    return std::find_if(m_Allies.begin(), m_Allies.end(), [&val](MatrixPosition* mp){
        return mp->value() == val;
    }) == m_Allies.end();
}


IntVec MatrixPosition::getAlternatives() const {
    IntVec vec;
    RandomSet rs;
    for (int i : rs) {
        if (isAlternative(i)) vec.push_back(i);
    }
    return vec;
}


PositionVec MatrixPosition::conflictingPositions(int val) const {
    PositionVec vec;
    if (val == 0) return vec;
    for (MatrixPosition* mp : m_Allies) {
        if (mp->value().toInt() == val) vec.push_back(mp);
    }
    return vec;
}


bool MatrixPosition::operator==(const MatrixPosition& mp) const {
    return ((m_Column == mp.m_Column) && (m_Row == mp.m_Row));
}


bool MatrixPosition::operator<(const MatrixPosition& mp) const {
    if (m_Row < mp.m_Row) return true;
    if (m_Row > mp.m_Row) return false;
    return (m_Column < mp.m_Column);
}


bool MatrixPosition::operator>(const MatrixPosition& mp) const {
    if (m_Row > mp.m_Row) return true;
    if (m_Row < mp.m_Row) return false;
    return (m_Column > mp.m_Column);
}


bool MatrixPosition::operator<=(const MatrixPosition& mp) const {
    if (*this == mp) return true;
    return (*this < mp) ? true : false;
}


bool MatrixPosition::operator>=(const MatrixPosition& mp) const {
    if (*this == mp) return true;
    return (*this > mp) ? true : false;
}



ostream& operator<<(ostream& os, const MatrixPosition& mp) {
    os.put('(');
    os << mp.column() << ", " << mp.row();
    os.put(')');
    return os;
}
