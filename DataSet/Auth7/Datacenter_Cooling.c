# include <stdio.h>
# include <stdlib.h>

# define MAX 100
# define H 7
# define W 6

int static count = 0;
char static possiblegate[8] = {-1};
int static possiblegatelen = 0;
int static len = 0;
int ispresent(char *path, char currentlen, int i, int j) {
		int k;
		for (k=0 ; k<2*currentlen ; k=k+2) {
				if (path[k]==i && path[k+1]==j)
						return 1;
		}
		return 0;
}

void copypath(char *path, char *newpath, int currentlen) {
		int i;
		for (i=0 ; i<2*currentlen ; i++)
				newpath[i] = path[i];
}

void print(char *path, int currentlen) {
		int i;
		for (i=0 ; i<2*currentlen ; i=i+2){
				printf("%d,%d ",path[i],path[i+1]);
		}
		printf("\n");
}

int isclosed(char *path, int currentlen) {
		int i, j, match = 0;
		for (i=0 ; i<2*possiblegatelen ; i=i+2)
				for (j=0 ; j<2*currentlen ; j=j+2)
						if (possiblegate[i]==path[j] && possiblegate[i+1]==path[j+1])
								match++;
		if(match == possiblegatelen)
				return 1;
		return 0;
}

void countways(int rooms[H][W], int i, int j, int currentlen, char path[MAX], int flag, int closecount) {
		char newpath[MAX] = {-1};

		if ((currentlen == len) && (rooms[i][j]==3))
				count++;

		if (closecount == possiblegatelen)
		return;

		else if((rooms[i][j] == 0) || (rooms[i][j] == 2 && !flag)) {
				if (rooms[i][j] == 0) {
						copypath(path, newpath, currentlen);
						newpath[2*currentlen] = i;
						newpath[2*currentlen+1] = j;
						currentlen++;
						if (ispresent(possiblegate, possiblegatelen, i, j))
								closecount++;
				}

				if(j-1>=0 && !ispresent(newpath, currentlen, i, j-1))
						countways(rooms, i, j-1, currentlen, newpath, 1, closecount);
				if(j+1<W && !ispresent(newpath, currentlen, i, j+1))
						countways(rooms, i, j+1, currentlen, newpath, 1, closecount);
				if(i-1>=0 && !ispresent(newpath, currentlen, i-1, j))
						countways(rooms, i-1, j, currentlen, newpath, 1, closecount);
				if(i+1<H && !ispresent(newpath, currentlen, i+1, j))
						countways(rooms, i+1, j, currentlen, newpath, 1, closecount);
		}
}

void main() {
		/*int rooms[H][W] = {
				{2, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0},
				{3, 0, 0, 0, 0, 1, 1},
				};*/
		int rooms[H][W] = {{2,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,3}};
		//int rooms[H][W] = {{2,0,0,0},{0,0,0,0},{0,0,3,1}};
		//int rooms[H][W] = {{2,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,3}};
		char path[MAX] = {-1};
		int i, j;
		char endi, endj;
		for (i=0 ; i<H ; i++)
				for (j=0 ; j<W ; j++) {
						if (rooms[i][j] == 0)
								len++;
						else if (rooms[i][j] == 3) {
								endi = i;
								endj = j;
						}
				}

		i = 0;
		if (endi-1>=0 && endi-1<H && endj>=0 && endj<W && rooms[endi-1][endj]==0) {
				possiblegate[i++] = endi-1;
				possiblegate[i++] = endj;
				possiblegatelen++;
		}
		if (endi+1>=0 && endi+1<H && endj>=0 && endj<W && rooms[endi+1][endj]==0) {
				possiblegate[i++] = endi+1;
				possiblegate[i++] = endj;
				possiblegatelen++;
		}
		if (endi>=0 && endi<H && endj-1>=0 && endj-1<W && rooms[endi][endj-1]==0) {
				possiblegate[i++] = endi;
				possiblegate[i++] = endj-1;
				possiblegatelen++;
		}
		if (endi>=0 && endi<H && endj+1>=0 && endj+1<W && rooms[endi][endj+1]==0) {
				possiblegate[i++] = endi;
				possiblegate[i++] = endj+1;
				possiblegatelen++;
		}

		countways(rooms, 0, 0, 0, path, 0, 0);
		printf("%d\n",count);
}
