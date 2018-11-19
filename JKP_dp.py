#Camila 8530952
#Henrique 8937225

import random
from collections import OrderedDict

#globals, don't touch (couldnt find anything as #define)
EMPTY = 0
ROCK = 1
SCISSORS = 2
PAPER = 3

posVizinhoLinha=[-1, 1, 0, 0]
posVizinhoColuna=[0, 0, -1, +1]

class Game:
    def __init__(self, rows, columns):
        self.rows=rows
        self.columns=columns
        self.pieces=0
        self.memo=OrderedDict()
        self.board=[[0 for x in range(columns)] for y in range(rows)]
        self.solutions=[]
        self.nsolutions=0


        #Zobrist hash table
        #https://www.youtube.com/watch?v=QYNRvMolN20
        self.hashTable = [[[random.randint(1, 2**64-1)for i in range(4)]
                       for j in range(columns)]
                      for k in range(rows)]

    def readGame(self):
        for i in range(self.rows):
            row=input().split()
            for j in range(self.columns):
                self.board[i][j]=int(row[j])
        

    def printGame(self):
        for i in range(self.rows):
            for j in range(self.columns):
                print (self.board[i][j])
                print (' ')
            print()

    """def Dynammic_Solver(self):

    def printSolution(self)  """ 

    def DFS(self, i, j, visited):
       visited[i][j]=True

       #test right
       if(j-1>=0):
           if(not visited[i][j-1] and self.board[i][j-1]):
               DFS(i, j-1, visited)
       #test left
       elif(j+1<=self.columns):
           if(not visited[i][j+1] and self.board[i][j-1]):
               DFS(i, j+1, visited)
       #test up
       elif(i-1>=0):
           if(not visited[i-1][j] and self.board[i][j-1]):
               DFS(i-1, j, visited)
       #test down
       elif(i+1<=self.rows):
           if(not visited[i+1][j] and self.board[i][j-1]):
               DFS(i, j-1, visited)
    
    def islandCheck(self):
        visited = [[False for j in range(self.columns)] for i in range(self.rows)] 
        islands=0
        for(i in range(self.rows)):
            for(j in range(self.columns)):
                if(visited[i][j]==False and self.board[i][j]!=0):
                    DFS(i, j, visited)
                    islands+=1
                if(islands > 1):
                    return False
        return True    

    def checkWin(self):
        if (self.pieces == 1):
            return True
        elif :
            return False

    def calculateKey(self):
        key = 0
        for i in range(len(self.board)):
            for j in range(len(self.board[i])):
                if self.board[i][j] != 0:
                    key ^= self.hashtable[i][j][self.board[i][j]]
        return key

    def play (self):
        success = False
        state_hits = 0

        self.rows = len(self.board)
        self.columns = len(self.board[0])

        key = computeKey(table, self.board)
        if key in self.memo:
            return self.memo[key]

        if (not checkIslands(self.board)):
            self.memo[key] = [False, 0]
            return self.memo[key]
            
        if (checkWin(self)):
            for i in range(len(self.board)):
                for j in range(len(self.board[i])):
                    if (self.board[i][j] != 0):
                        self.solutions.append([i+1, j+1, self.board[i][j]])
                        self.memo[key] = [True, 1]
                        return self.memo[key]

        for i in range(len(self.board)):
            for j in range(len(self.board[i])):
                current = self.board[i][j]
                if (current != 0):
                    for k in range(4): 
                        iNbr = i + posVizinhoLinha[k]
                        jNbr = j + posVizinhoColuna[k]
                        if ((iNbr >= 0 and iNbr < self.rows) and (jNbr >= 0 and jNbr < self.columns)):
                            neighbor = self.board[iNbr][jNbr]
                            if (neighbor not in invalid_moves[current]):
                                self.board[iNbr][jNbr] = current
                                self.board[i][j] = 0
                                self.pieces -= 1
                                jump = solve(self.memo, table, self.board, self.solutions, self.pieces)
                                if (jump[0]):
                                    success = True
                                    state_hits += jump[1]
                                self.board[iNbr][jNbr] = neighbor
                                self.board[i][j] = current
                                self.pieces += 1
        if (not success):
            self.memo[key] = [False, 0]
        else:
            self.memo[key] = [True, state_hits]
        return self.memo[key]


def checkJanken (x1, x2):
    if ((x1!=EMPTY and x2!=EMPTY) and ((x1==SCISSORS and x2==PAPER) or (x1==PAPER and x2==ROCK) or (x1==ROCK and x2==SCISSORS)))
        return True
    elif 
        return False


def main():
    sR, sC = input().split()
    game=Game(int(sR), int(sC))
    game.readGame()
    game.printGame()
    
    # search for solutions
    play(game)
    hits = game.memo.popitem()[1][1]

    print(hits)
    print(len(game.solutions))
    # display sorted unique solutions
    for solution in sorted(game.solutions):
        for value in solution:
            print(str(value), end=' ')
        print()

if __name__ == '__main__':
    main()
