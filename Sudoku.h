#ifndef SUDOKU_H
#define SUDOKU_H

#include<set>
#include<vector>
#include<array>

class MatrixPosition;
class ItemStackedWidget;

namespace Sudoku {



using IntSet = std::set<int>;
using IntVec = std::vector<int>;
using PositionVec = std::vector<MatrixPosition*>;
using MatrixItemArray = std::array<ItemStackedWidget*, 81>;

using Difficulty = int;
static constexpr Difficulty very_difficult {26};
static constexpr Difficulty difficult      {28};
static constexpr Difficulty moderate       {30};
static constexpr Difficulty easy           {32};
static constexpr Difficulty very_easy      {34};


} // namespace Sudoku



#endif // SUDOKU_H
