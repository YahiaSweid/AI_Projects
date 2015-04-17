#define OurCode 0
#if OurCode

#include <iostream>
#include <vector>

using namespace std;

struct vec2{
	int x, y;
};

void displayPathtoPrincess(int n, char grid[3*3]){
	vec2 pIndex; pIndex.x = pIndex.y = -1;
	vec2 bIndex; bIndex.x = bIndex.y = 1;

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (grid[i * n + j] == 'P'){
				pIndex.x = i;
				pIndex.y = j;
			}
		}
	}

	if (pIndex.x ==  -1){
		cout << "The princess is in another castle" << endl;
		exit(0);
	}

	vec2 path;
	path.x = pIndex.x - bIndex.x;
	path.y = pIndex.y - bIndex.y;

	cout <<  " X: " << path.x << " Y: " << path.y;
}

int main(void) {

	// oneDim[row * columns + column]
	const int N = 3;
	

	char grid[N* N];

	for (int i = 0; i < N*N; i++){
		grid[i] = '-';
	}
	

	// Left Top Corner
	//grid[0] = 'x';
	
	// Right top corner
	//grid[0 * N + (N - 1)] = 'R';

	// Right Bottom corner
	grid[(N-1) * N + (N-1)] = 'P';


	// Bot Position
	grid[1 * N + 1] = 'M';

	// Left Bottom corner
	//grid[(N - 1) * N + 0] = 'P';


	for (int i = 0; i < N * N; i++){
		if (i % 3 == 0)
			cout << endl;
		cout << grid[i];
	}

	displayPathtoPrincess(N, grid);

	cout << endl;
	system("PAUSE");
	return 0;
}
#else

// Hacker Rank

#include <iostream>
#include <vector>
using namespace std;

struct vec2{
	int x, y;
};

void displayPathtoPrincess(int n, vector <char*> grid){
	// Declare 2 vectors to store the position of the bot and princess
	vec2 pIndex; pIndex.x = pIndex.y = -1;
	vec2 bIndex; bIndex.x = bIndex.y = -1;

	// Scan the board and get the bot and princess positions
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (grid[i][j] == 'p'){
				pIndex.x = i;
				pIndex.y = j;
			}
			else if (grid[i][j] == 'm'){
				bIndex.x = i;
				bIndex.y = j;
			}
		}
	}

	// Check bot and princess exist in the castle
	if (pIndex.x == -1 ){
		cout << "The princess is in another castle" << endl;
		exit(0);
	}
	if (bIndex.x == -1){
		cout << "There is no bot in this game !" << endl;
		exit(0);
	}

	// Calculate the translation between the bot and princess
	vec2 path;
	path.x = pIndex.x - bIndex.x;
	path.y = pIndex.y - bIndex.y;
	
	// Print out the result of the bot's moves to reach to princess
	while (path.x != 0){
		if (path.x > 0){
			cout << "DOWN" << endl;
			path.x--;
		}
		else if (path.x < 0){
			cout << "UP" << endl;
			path.x++;
		}
	}

	while (path.y != 0){
		if (path.y > 0){
			cout << "RIGHT" << endl;
			path.y--;
		}
		else if (path.y < 0){
			cout << "LEFT" << endl;
			path.y++;
		}
	}
	
}
int main(void) {
	int m;
	vector <char*> grid;
	
	cin >> m;
	for (int i = 0; i<m; i++) {
		char* s = new char[]; 
		cin >> s;
		grid.push_back(s);
	}

	displayPathtoPrincess(m, grid);

	system("PAUSE");

	return 0;
}

#endif