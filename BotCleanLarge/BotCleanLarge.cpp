#include<iostream>
#include<vector>

struct vec2{
public:
	int x =0 , y =0;
	vec2::vec2(){};
	vec2::vec2(int x,int y){
		this->x = x;
		this->y = y;
	}
};

void next_move(int posr, int posc, int dimh, int dimw, std::vector <char*> board) {
	// Place the bot in its position
	vec2 bIndex(posr, posc);
	
	std::vector<vec2> dirtyCells;
	vec2 path;

	// Scan the dirty cells and store their positions
	for (int i = 0; i < dimh; i++){
		for (int j = 0; j < dimw; j++){
			if (board[i][j] == 'd'){
				dirtyCells.push_back(vec2(i, j));
			}
		}
	}

	// Look for dirty cell and clean it
	for (int i = 0; i < dirtyCells.size(); i++){
		path.x = dirtyCells[i].x - bIndex.x;
		path.y = dirtyCells[i].y - bIndex.y;
		
		// Move The Bot
		while (path.x != 0){
			if (path.x > 0){
				std::cout << "DOWN" << std::endl;
				path.x--;
			}
			else if (path.x < 0){
				std::cout << "UP" << std::endl;
				path.x++;
			}
		}
		while (path.y != 0){
			if (path.y > 0){
				std::cout << "RIGHT" << std::endl;
				path.y--;
			}
			else if (path.y < 0){
				std::cout << "LEFT" << std::endl;
				path.y++;
			}
		}
		std::cout << "CLEAR" << std::endl;

		// Clear the bot's position by '-', it's already moved to the dirty cell
		board[bIndex.x][bIndex.y] = '-';

		// Clear the position of the previous dirty cell 
		if (i != 0){
			board[dirtyCells[i - 1].x][dirtyCells[i - 1].y] = '-';
		}

		// Change the bot's position on the board
		bIndex.x = dirtyCells[i].x; bIndex.y = dirtyCells[i].y;
	}
	// The End ^_^
}


int main(void) {
	int pos[2];
	int dim[2];
	std::vector <char*> board;
	std::cin >> pos[0] >> pos[1];
	std::cin >> dim[0] >> dim[1];
	for (int i = 0; i<dim[0]; i++) {
		char* s = new char[]; std::cin >> s;
		board.push_back(s);
	}
	next_move(pos[0], pos[1], dim[0], dim[1], board);

	
	std::cout << std::endl;
	system("PAUSE");
	return 0;
}