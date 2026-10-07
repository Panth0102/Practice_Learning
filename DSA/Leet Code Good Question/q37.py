#Q 37: Sudoko Solver

class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        def is_valid(num, row, col):
            for i in range(9):
                if board[row][i] == num or board[i][col] == num or board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == num:
                     return False
            return True
        
        def solve():
            for i in range(9):
                for j in range(9):
                    if board[i][j] == ".":
                        for num in map(str, range(1, 10)):
                            if is_valid(num, i, j):
                                board[i][j] = num
                                if solve():
                                    return True
                                board[i][j] = "."
                        return False
            return True
        solve()



# Optimal Solution

class Solution:
    def solveSudoku(self, board):
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        empty_cells = []

        for row in range(9):
            for col in range(9):
                value = board[row][col]

                if value == ".":
                    empty_cells.append((row, col))
                else:
                    rows[row].add(value)
                    cols[col].add(value)
                    boxes[(row // 3) * 3 + col // 3].add(value)

        def backtrack(index):
            if index == len(empty_cells):
                return True

            row, col = empty_cells[index]
            box = (row // 3) * 3 + col // 3

            for digit in "123456789":
                if digit not in rows[row] and digit not in cols[col] and digit not in boxes[box]:
                    board[row][col] = digit
                    rows[row].add(digit)
                    cols[col].add(digit)
                    boxes[box].add(digit)

                    if backtrack(index + 1):
                        return True

                    board[row][col] = "."
                    rows[row].remove(digit)
                    cols[col].remove(digit)
                    boxes[box].remove(digit)

            return False

        backtrack(0)