#Jordan Miller
#CSCI 4270, Block Path
#Create an algorithm without recursion to find the shortest path

import sys
if __name__ == "__main__":
	(height, width) = [int(x) for x in raw_input().split()]
	grid = [ [int(x) for x in raw_input().split()] for h in range(height)]	
	gridCopy = [x[:] for x in grid]	
	print("Origanal Graph")
	for i in range(height):
		for j in range(width):
			#this is cell #1				
			if i == 0 and j == 0:
				gridCopy[i][j] = grid[i][j]
			#height is the rows, if the rows are maxed out we cant go down, we need to go right
			elif i == 0 and j <> 0:
				gridCopy[i][j] = grid[i][j] + gridCopy[i][j-1]
			#width is columns, if we are all the way left we have to go down
			elif j == 0 and i <> 0:
				gridCopy[i][j] = grid[i][j] + gridCopy[i-1][j]
			elif (i < height) and (j < width):
				if gridCopy[i-1][j] < gridCopy[i][j-1]:		
					gridCopy[i][j] = gridCopy[i-1][j] + grid[i][j]
				else:					
					gridCopy[i][j] = gridCopy[i][j-1] + grid[i][j]
	print("total is", gridCopy[i][j])

	print("Our path is shown below: ")	
	for i in range(height):
		for j in range(width):
			sys.stdout.write(" " + str(gridCopy[i][j]))
		print
	
	row = height - 1
	col = width - 1
	while (row >= 0 and col >= 0):
			if row == 0:
				grid[row][col - 1] = 0
				col = col - 1
			elif col == 0:
				grid[row-1][col] = 0					
				row = row - 1			
			elif gridCopy[row - 1][col] < gridCopy[row][col - 1]:
				grid[row-1][col] = 0
				row = row - 1
			else:
				grid[row][col-1] = 0
				col = col - 1
	grid[height-1][width-1] = 0
	row = 0
	col = 0	
	grid[row][col] = 0	
	
	print("Our path is shown below: ")	
	for i in range(height):
		for j in range(width):
			if grid[i][j] == 0:
				sys.stdout.write(" " + ".")
			else:
				sys.stdout.write(" " + str(grid[i][j]))
		print
