#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};
int top = 0;

#define DFSSTACK
#ifdef DFSSTACK
struct point {
	int row;
	int col;
} stack[512];

void push(point p)
{
	stack[top++] = p;	
}

point pop()
{
	return stack[--top];
}

bool is_empty()
{
	return top == 0;
}


void print_maze(void)
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++) {
		for (j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		putchar('\n');
	}
	printf("*********\n");
}

struct point predecessor[MAX_ROW][MAX_COL] = {
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
};

void visit(int row, int col, struct point pre)
{
	struct point visit_point = { row, col };
	maze[row][col] = 2;
	predecessor[row][col] = pre;
	push(visit_point);
}

int main(void)
{
	struct point p = { 0, 0 };

	maze[p.row][p.col] = 2;
	push(p);	
	
	while (!is_empty()) {
		p = pop();
		if (p.row == MAX_ROW - 1  /* goal */
		    && p.col == MAX_COL - 1)
			break;
		if (p.col+1 < MAX_COL     /* right */
		    && maze[p.row][p.col+1] == 0)
			visit(p.row, p.col+1, p);
		if (p.row+1 < MAX_ROW     /* down */
		    && maze[p.row+1][p.col] == 0)
			visit(p.row+1, p.col, p);
		if (p.col-1 >= 0          /* left */
		    && maze[p.row][p.col-1] == 0)
			visit(p.row, p.col-1, p);
		if (p.row-1 >= 0          /* up */
		    && maze[p.row-1][p.col] == 0)
			visit(p.row-1, p.col, p);
		print_maze();
	}
	if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
		printf("(%d, %d)\n", p.row, p.col);
		while (predecessor[p.row][p.col].row != -1) {
			p = predecessor[p.row][p.col];
			printf("(%d, %d)\n", p.row, p.col);
		}
	} else
		printf("No path!\n");

	return 0;
}
#endif

// #define DFSRECURSION
#ifdef DFSRECURSION

int DFS(int row, int col)
{
	if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL)
		return 0;
	if (maze[row][col] == 1 || maze[row][col] == 2)
		return 0;
	maze[row][col] = 2;
	if (row == MAX_ROW - 1 && col == MAX_COL - 1) {
		printf("(%d, %d)\n", row, col);
		return 1;
	}
	if (DFS(row, col+1)   /* right */
	    || DFS(row+1, col)   /* down */
	    || DFS(row, col-1)   /* left */
	    || DFS(row-1, col)) { /* up */
		printf("(%d, %d)\n", row, col);
		return 1;
	}
	return 0;
}

int main()
{
	if (!DFS(0, 0))
		printf("No path!\n");
	return 0;
}

#endif