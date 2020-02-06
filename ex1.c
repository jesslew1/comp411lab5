#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

#define MAX 100

char maze[MAX][MAX];
char wasHere[MAX][MAX];
char correctPath[MAX][MAX];
int width, height;
int startX, startY, endX, endY;
char tempString[MAX+2];   // To read in one line of the maze

int recursiveSolve(int x, int y);

int main() {

  int x, y;
  scanf("%d%d", &width, &height);
  scanf("\n");    // This is needed to "eat" the newline after height,
                  // before the actual maze entries begin on the next line


  /* NOTE:  maze[y][x] will refer to the (x,y) element of the maze,
	   i.e., y-th row and x-th column in the maze.
     The row is typically the first index in a 2D array because
     reading and writing is done row-wise.  This is called
     "row-major" order.

     Also note that although we have declared the maze to be 100x100,
     that is the maximum size we need.  The actual entries in the
     maze will be height * width.
  */


//   for(y=0; y < height; y++) {
//     fgets(tempString, width+2, stdin);  // Read #width chars, plus newline and NULL into tempString
//     for(x=0; x < width; x++) {          // Copy only the actual #width chars into the maze
//       maze[y][x]=tempString[x];
//       // Check for 'S' and 'F' here and use that to
//       // set values of startX, startY, endX and endY
//       if (tempString[x] == 'F') {
//         endX = x;
// 				endY = y;
// 			}
//       if (tempString[x]== 'S') {
// 				startX = x;
// 				startY = y;
// 			}

//       wasHere[y][x] = false;     
//       correctPath[y][x] = false;
//     }
//   }

//   recursiveSolve(startX, startY);
// // Code to print the output maze
// for (y=0; y < height; y++){
//   for (x=0; x < width; x++){
//     if (x == startX && y == startY){
//       maze[y][x] = 'S';
//     }
//     if (x == endX && y == endY){
//       maze[y][x] = 'F';
//     }
//     if (correctPath[y][x] == true && maze[y][x] != 'S' && maze[y][x] != 'F') {
//       maze[y][x] = '.';
// 			printf("%c", maze[y][x]);
//     }
//   }
//   printf("\n");
// }
char tempchar;

	for (y=0; y < height; y++) {
		for (x=0; x <  width; x++) {
			scanf("%c", &tempchar);
			maze[y][x] = tempchar;

			//check for S and F and set values as startx,y endx,y
			if (tempchar == 'S') {
				startX = x;
				startY = y;
			}
			if (tempchar == 'F') {
				endX = x;
				endY = y;
			}

			wasHere[y][x] = false;
			correctPath[y][x] = false;
		}
		scanf("%c", &tempchar); 
	}

	recursiveSolve(startX, startY);
		// code to print the output maze
		
	for (y=0; y < height; y++) {
		for (x=0; x < width; x++) {
			if (x == endX && y == endY)
				maze[y][x] = 'F';
			if (x == startX && y == startY)
				maze[y][x] = 'S';
			if (correctPath[y][x] == true && maze[y][x] != 'S' && maze[y][x] != 'F')
				maze[y][x] = '.';
			printf("%c", maze[y][x]);
		}
		printf("\n");
	}

}


int recursiveSolve(int x, int y) {
    if (x == endX && y == endY) return true; // If you reached the end
    if (maze[y][x] == '*' || wasHere[y][x]) return false;  
    // If you are on a wall or already were here
    wasHere[y][x] = true;
    if (x != 0) // Checks if not on left edge
        if (recursiveSolve(x-1, y)) { // Calls method one to the left
            correctPath[y][x] = true; // Sets that path value to true;
            return true;
        }
    if (x != width - 1) // Checks if not on right edge
        if (recursiveSolve(x+1, y)) { // Calls method one to the right
            correctPath[y][x] = true;
            return true;
        }
    if (y != 0)  // Checks if not on top edge
        if (recursiveSolve(x, y-1)) { // Calls method one up
            correctPath[y][x] = true;
            return true;
        }
    if (y != height - 1) // Checks if not on bottom edge
        if (recursiveSolve(x, y+1)) { // Calls method one down
            correctPath[y][x] = true;
            return true;
        }
    return false;
}