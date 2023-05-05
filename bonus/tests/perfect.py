#!/usr/bin/python3
from sys import argv
import random
def is_solvable(maze):
    rows = len(maze)
    cols = len(maze[0])
    visited = [[False for j in range(cols)] for i in range(rows)]
    stack = [(0, 0)]
    while stack:
        row, col = stack.pop()
        if row == rows - 1 and col == cols - 1:
            return True
        visited[row][col] = True
        for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
            new_row, new_col = row + dx, col + dy
            if 0 <= new_row < rows and 0 <= new_col < cols and not visited[new_row][new_col] and maze[new_row][new_col] != "X":
                stack.append((new_row, new_col))
    return False

def get_unvisited_neighbors(row, col, maze):
    neighbors = []
    rows = len(maze)
    cols = len(maze[0])
    if row > 0 and maze[row - 1][col] == "X":
        neighbors.append((row - 1, col))
    if row < rows - 1 and maze[row + 1][col] == "X":
        neighbors.append((row + 1, col))
    if col > 0 and maze[row][col - 1] == "X":
        neighbors.append((row, col - 1))
    if col < cols - 1 and maze[row][col + 1] == "X":
        neighbors.append((row, col + 1))
    return neighbors

def remove_wall(row, col, neighbor_row, neighbor_col, maze):
    if neighbor_row == row - 1:
        maze[row - 1][col] = "."
    elif neighbor_row == row + 1:
        maze[row + 1][col] = "."
    elif neighbor_col == col - 1:
        maze[row][col - 1] = "."
    elif neighbor_col == col + 1:
        maze[row][col + 1] = "."

def is_perfect(maze):
    start = (0, 0)
    end = (len(maze)-1, len(maze[0])-1)
    visited = set()
    stack = [start]
    while stack:
        curr = stack.pop()
        if curr == end:
            return len(visited) == len(maze)*len(maze[0])
        if curr in visited:
            continue
        visited.add(curr)
        for move in [(0,1),(0,-1),(1,0),(-1,0)]:
            x, y = curr[0]+move[0], curr[1]+move[1]
            if 0 <= x < len(maze) and 0 <= y < len(maze[0]) and maze[x][y] != "*":
                stack.append((x, y))
    components = 0
    for i in range(len(maze)):
        for j in range(len(maze[0])):
            if maze[i][j] != "*" and (i,j) not in visited:
                stack = [(i,j)]
                while stack:
                    curr = stack.pop()
                    if curr in visited:
                        continue
                    visited.add(curr)
                    for move in [(0,1),(0,-1),(1,0),(-1,0)]:
                        x, y = curr[0]+move[0], curr[1]+move[1]
                        if 0 <= x < len(maze) and 0 <= y < len(maze[0]) and maze[x][y] != "*":
                            stack.append((x, y))
                components += 1
                
    return components == 1

def load_maze(filename):
    with open(filename) as f:
        return [list(line.strip()) for line in f.readlines()]

def main():
    maze = load_maze(argv[1])
    print("verif :", is_perfect(maze))

main()