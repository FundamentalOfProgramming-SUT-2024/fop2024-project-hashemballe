

void make_hallway(room *rooms, int screen_height, int map[][screen_height]);
void make_hall(point a, point b, int w, int screen_height, int map[][screen_height]);
void make_traps(room *rooms, int screen_height, int map[][screen_height]);
void make_pillar(room *rooms, int screen_height, int map[][screen_height]);
void make_types(room *rooms);



void make_hallway(room * rooms, int screen_height, int map[][screen_height]) {
  for(int i = 0; i < 8; i++) {
    if(rooms[i].exist == 1 && rooms[i].door_exist[right] == 1) {
      make_hall(rooms[i].doors[right], rooms[i + 1].doors[left], 1, screen_height, map);
      //printw("%d- %d %d ",i, rooms[i].doors[right].x, rooms[i + 1].doors[left].x);
    }
    if(rooms[i].exist == 1 && rooms[i].door_exist[down] == 1) {
      make_hall(rooms[i].doors[down], rooms[i + 4].doors[up], 2, screen_height, map);
      //printw("%d- %d %d ",i, rooms[i].doors[down].x, rooms[i + 4].doors[up]. x, 2);
    }
  }
}


void make_hall(point a, point b, int w, int screen_height, int map[][screen_height]) {
  point hall = a;
  if(w == 1) {
  	hall.x++;
  }
  else {
  	hall.y++;
  }
  mvprintw(hall.y, hall.x, "#");
  map[hall.x][hall.y] = 1;
  while(hall.x != b.x || hall.y != b.y) {
  	
    if(rand() % 2 == 0) {
      if(hall.x < b.x) {
        if(!(hall.y != b.y && hall.x + 1 == b.x) || w != 1) {
          hall.x++;
        }
      }
      else if(hall.x > b.x) {
        if(!(hall.y != b.y && hall.x - 1 == b.x) || w != 1) {
          hall.x--;
        }
      }
    }
    else {
      if(hall.y < b.y) {
        if(!(hall.x != b.x && hall.y + 1 == b.y) || w != 2) {
          hall.y++;
        }
      }
      else if(hall.y > b.y) {
        if(!(hall.x != b.x && hall.y - 1 == b.y) || w != 2) {
          hall.y--;
        }
      }
    }
    if((hall.y != b.y || hall.x != b.x) && (hall.y != a.y || hall.x != a.x)) {
      map[hall.x][hall.y] = 1;
	  mvprintw(hall.y, hall.x, "#");
    }  	
  }
}

void make_traps(room *rooms, int screen_height, int map[][screen_height]) {
	D.health = 5;
	F.health = 10;
	G.health = 15;
	S.health = 20;
	U.health = 30;
	
	if(difficulty == 2) {
		D.health += 5;
		F.health += 5;
		G.health += 5;
	}
	for(int i = 0; i < 8; i++) {
		if(rooms[i].exist == 1 && rand() % 4 == 0) {
			int x = rooms[i].left_up.x + 1 + rand() % rooms[i].width;
			int y = rooms[i].left_up.y + 1 + rand() % rooms[i].height;
			map[x][y] = 2;
			//mvprintw(y, x, "^");
		}
		if(rooms[i].exist == 1 && rand() % 10 == 0) {
			int x = rooms[i].left_up.x + 1 + rand() % rooms[i].width;
			int y = rooms[i].left_up.y + 1 + rand() % rooms[i].height;
			map[x][y] = 19;
			mvprintw(y, x, "D");
		}
		
		if(rooms[i].exist == 1 && rand() % 10 == 0) {
			int x = rooms[i].left_up.x + 1 + rand() % rooms[i].width;
			int y = rooms[i].left_up.y + 1 + rand() % rooms[i].height;
			map[x][y] = 20;
			mvprintw(y, x, "F");
		}
		
		if(rooms[i].exist == 1 && rand() % 10 == 0) {
			int x = rooms[i].left_up.x + 1 + rand() % rooms[i].width;
			int y = rooms[i].left_up.y + 1 + rand() % rooms[i].height;
			map[x][y] = 21;
			mvprintw(y, x, "G");
		}
		
		if(rooms[i].exist == 1 && rand() % 10 == 0) {
			int x = rooms[i].left_up.x + 1 + rand() % rooms[i].width;
			int y = rooms[i].left_up.y + 1 + rand() % rooms[i].height;
			map[x][y] = 22;
			mvprintw(y, x, "S");
		}
		
		if(rooms[i].exist == 1 && rand() % 10 == 0) {
			int x = rooms[i].left_up.x + 1 + rand() % rooms[i].width;
			int y = rooms[i].left_up.y + 1 + rand() % rooms[i].height;
			map[x][y] = 23;
			mvprintw(y, x, "U");
		}
		
		
		if(rooms[i].exist == 1 && rooms[i].type == 2) {
			
			int x = rooms[i].left_up.x + 1 + rand() % rooms[i].width;
			int y = rooms[i].left_up.y + 1 + rand() % rooms[i].height;
			map[x][y] = 2;
			mvprintw(y, x, "^");
			 x = rooms[i].left_up.x + 1 + rand() % rooms[i].width;
			 y = rooms[i].left_up.y + 1 + rand() % rooms[i].height;
			map[x][y] = 2;
			mvprintw(y, x, "^");
			 x = rooms[i].left_up.x + 1 + rand() % rooms[i].width;
			 y = rooms[i].left_up.y + 1 + rand() % rooms[i].height;
			map[x][y] = 2;
			mvprintw(y, x, "^");
			 x = rooms[i].left_up.x + 1 + rand() % rooms[i].width;
			 y = rooms[i].left_up.y + 1 + rand() % rooms[i].height;
			map[x][y] = 2;
			mvprintw(y, x, "^");
			
			x = rooms[i].left_up.x + 1 + rand() % rooms[i].width;
			 y = rooms[i].left_up.y + 1 + rand() % rooms[i].height;
			 map[x][y] = 25;
			mvprintw(y, x, "W");
		}
	}
}

void make_pillar(room *rooms, int screen_height, int map[][screen_height]) {
	for(int i = 0; i < 8; i++) {
		if(rooms[i].exist == 1 && rand() % 2 == 0) {
			int x = rooms[i].left_up.x + 2 + rand() % (rooms[i].width - 2);
			int y = rooms[i].left_up.y + 2 + rand() % (rooms[i].height - 2);
			map[x][y] = 3;
			mvprintw(y, x, "O");
		}
	}
}

void make_types(room *rooms) {
	for(int i = 0; i < 8; i++) {
		rooms[i].type = 0;
		if(rand() % 4 == 0) {
			rooms[i].type = 1;
		}
		else if(rand() % 4 == 0) {
			rooms[i].type = 3;
		}
	}
	if(Floor == 0) {
		while(1) {
			int x = rand() % 8;
			if(rooms[x].exist == 1) {
				rooms[x].type = 2;
				break;
			}
		}
	}
}
void make_stairs(room *rooms, int screen_height, int map[][screen_height]) {
	if(Floor) {
	
	int i = rand() % 8;
	while(!rooms[i].exist) {
		i = rand() % 8;
	}
	int x = rooms[i].left_up.x + 2 + rand() % (rooms[i].width - 2);
	int y = rooms[i].left_up.y + 2 + rand() % (rooms[i].height - 2);
	map[x][y] = 18;
	mvprintw(y, x, "<");
	}
}