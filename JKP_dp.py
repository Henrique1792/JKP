import random
from collections import OrderedDict

LineNbr=[-1, 1, 0, 0]
ColNbr=[0, 0, -1, +1]



class Game:
    def __init__(self, rows, columns):
        self.rows=rows
        self.columns=columns
        self.pieces=0
        self.memo=OrderedDict()
        self.board=[[0 for x in range(columns)] for y in range(rows)]
        self.solutions=[]
        self.nSolutions=0


        #Zobrist hash table
        #colocar o link do youtube
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
                    print (self.board[i][j], end=' ')
            print()

    """def Dynammic_Solver(self):

    def printSolution(self)  """ 

    def DFS(self, i, j, visited):
           visited[i][j]=True

           #test right
           if()
           #test left
           #test up
           #test down





def main():
    sR, sC = input().split()
    game=Game(int(sR), int(sC))
    game.readGame()
    game.printGame()



if __name__ == '__main__':
    main()
