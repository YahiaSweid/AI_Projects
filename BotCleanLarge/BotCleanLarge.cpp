#include<iostream>
#include<vector>

using namespace std;

struct vec2{
public:
	int x = 0, y = 0;
	vec2(){};
	vec2(int x, int y){
		this->x = x;
		this->y = y;
	}
};

vector<vec2> dirtyCells;

void next_move(int posr, int posc, int dimh, int dimw, vector <string> board) {
	// Place the bot in its position
	vec2 bIndex(posr, posc);

	vec2 path;
    vector<vec2> temp;
    for(int i=0; i < dirtyCells.size(); i++){
        path.x = dirtyCells[i].x - bIndex.x; path.y = dirtyCells[i].y - bIndex.y;
        
    }
    
	// Look for dirty cell and clean it
	    path.x = dirtyCells.front().x - bIndex.x;
		path.y = dirtyCells.front().y - bIndex.y;

		if (path.x > 0){
			cout << "DOWN" << endl;

		}
		else if (path.x < 0){
			cout << "UP" << endl;
			path.x++;
		}
		
		else if (path.y > 0){
			cout << "RIGHT" << endl;
			path.y--;
		}
		else if (path.y < 0){
			cout << "LEFT" << endl;
			path.y++;
		}
		
        else if(bIndex.x == dirtyCells.front().x && bIndex.y == dirtyCells.front().y){
            cout << "CLEAN" << endl;
        }
             
	// The End ^_^
}


int main(void) {
	int pos[2];
	int dim[2];
	vector <string> board;
	cin >> pos[0] >> pos[1];
	cin >> dim[0] >> dim[1];
	for (int i = 0; i<dim[0]; i++) {
		string s; cin >> s;
		board.push_back(s);
	}

	// Scan the dirty cells and store their positions
	for (int i = 0; i < dim[0]; i++){
		for (int j = 0; j < dim[1]; j++){
			if (board[i][j] == 'd'){
				dirtyCells.push_back(vec2(i, j));
			}
		}
	}


	next_move(pos[0], pos[1], dim[0], dim[1], board);

	return 0;
}