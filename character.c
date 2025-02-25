int moves = 0;
int score;

void character_make(room *rooms, int screen_height, int screen_width, int map[][screen_height]);
void character_move(room *rooms, int screen_height, int screen_width, int map[][screen_height]);

void character_make(room *rooms, int screen_height, int screen_width, int map[][screen_height]) {
	while(1) {
		int i = rand() % 8;
		if(rooms[i].exist == 1) {
			character.x = rooms[i].left_up.x + rand() % (rooms[i].width - 2) + 1;
			character.y = rooms[i].left_up.y + rand() % (rooms[i].height - 2) + 1;
			mvprintw(character.y, character.x, "A");
			refresh();
			break;
		}
	}
}

void character_move(room *rooms, int screen_height, int screen_width, int map[][screen_height]) {
	while(1) {
		//mvprintw(0, 0, "                           ");
		mvprintw(2, 0, "Heart: %d  ", heart);
		mvprintw(4, 0, "Hunger: %d  ", hunger);
		mvprintw(6, 0, "GOLD: %d  ", GOLD);
		mvprintw(8, 0, "DARK_GOLD: %d", DARK_GOLD);
		
		char c = getch();
		
		
		switch(map[character.x - 1][character.y]) {
			case 19:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 5;
				if(weapon == 0) {
				D.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				D.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 20:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 10; 
				if(weapon == 0) {
				F.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				F.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 21:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 15; 
				if(weapon == 0) {
				G.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				G.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 22:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 20; 
				if(weapon == 0) {
				S.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				S.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 23:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 25;
				if(weapon == 0) {
				U.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				U.health -= 10;
				if(double_power) D.health -= 10;
				}  
				break;	
		}
		
		switch(map[character.x + 1][character.y]) {
			case 19:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 5;
				if(weapon == 0) {
				D.health -= 5;
				if(double_power) D.health -= 5;
				}  
				if(weapon == 4) {
				D.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 20:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 10; 
				if(weapon == 0) {
				F.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				F.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 21:
				heart -= 15;
				if(weapon == 0) {
				G.health -= 5;
				if(double_power) D.health -= 5;
				}  
				if(weapon == 4) {
				F.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 22:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 20;
				if(weapon == 0) {
				S.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				S.health -= 10;
				if(double_power) D.health -= 10;
				}  
				break;
			case 23:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 25; 
				if(weapon == 0) {
				U.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				U.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;	
		}
		
		switch(map[character.x][character.y - 1]) {
			case 19:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 5; 
				if(weapon == 0) {
				D.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				D.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 20:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 10;
				if(weapon == 0) {
				F.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				F.health -= 10;
				if(double_power) D.health -= 10;
				}  
				break;
			case 21:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 15; 
				if(weapon == 0) {
				G.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				G.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 22:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 20; 
				if(weapon == 0) {
				S.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				S.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 23:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 25; 
				if(weapon == 0) {
				U.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				U.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;	
		}
		
		switch(map[character.x][character.y + 1]) {
			case 19:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 5; 
				if(weapon == 0) {
				D.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				D.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 20:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 10; 
				if(weapon == 0) {
				F.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				F.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 21:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 15; 
				if(weapon == 0) {
				G.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				G.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 22:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 20; 
				if(weapon == 0) {
				S.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				S.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 23:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				heart -= 25; 
				if(weapon == 0) {
				U.health -= 5;
				if(double_power) D.health -= 5;
				} 
				if(weapon == 4) {
				U.health -= 10;
				if(double_power) D.health -= 10;
				} 
				break;
			case 25:
				clear();
				mvprintw(screen_height / 2, screen_width / 2 - 3, "YOU WON");
				score = 25 * DARK_GOLD + 10 * GOLD;
				mvprintw(screen_height / 2 + 2, screen_width / 2 - 3, "YOUR SCORE: %d", score);
				FILE *file = fopen("scores.txt", "a");
				fprintf(file, "\n%s, %d, %d", logged_user, score, GOLD);
				fclose(file);
				getch();
				welcome();
				return;
		}
		
		switch(map[character.x][character.y]) {
			case 1:
				mvprintw(character.y, character.x, "#");
				break;
			case 2:
				mvprintw(character.y, character.x, "^");
				heart -= 5;
				mvprintw(0, 0, "TRAP!                              ");
				break;
			case 5:	
				mvprintw(character.y, character.x, "+");
				mvprintw(0, 0, "LET'S GO OUT!                         ");
				break;
			case 6:
				if(map[character.x - 1][character.y] == 7) {
					mvprintw(0, 0, "YUMMY!                             ");
					mvprintw(character.y, character.x - 1, ".");
					add_food_to_menu(character.x - 1, character.y, screen_height, map);
					map[character.x - 1][character.y] = 6;
				}
				if(map[character.x - 1][character.y] == 8) {
					mvprintw(0, 0, "MONEY MONEY!                          ");
					mvprintw(character.y, character.x - 1, ".");
					GOLD ++;
					map[character.x - 1][character.y] = 6;
				}
				if(map[character.x - 1][character.y] == 9) {
					mvprintw(0, 0, "NOW YOU'RE A BILLIONAIRE!              ");
					mvprintw(character.y, character.x - 1, ".");
					DARK_GOLD ++;
					map[character.x - 1][character.y] = 6;
				}
				if(map[character.x - 1][character.y] == 10) {
					mvprintw(0, 0, "NOW YOU'RE A BILLIONAIRE!              ");
					mvprintw(character.y, character.x - 1, ".");
					backpack[0] = 1;
					map[character.x - 1][character.y] = 6;
				}
				if(map[character.x - 1][character.y] == 11) {
					mvprintw(0, 0, "NOW YOU'RE A BILLIONAIRE!              ");
					mvprintw(character.y, character.x - 1, ".");
					backpack[1] = 1;
					map[character.x - 1][character.y] = 6;
				}
				if(map[character.x - 1][character.y] == 12) {
					mvprintw(0, 0, "NOW YOU'RE A BILLIONAIRE!              ");
					mvprintw(character.y, character.x - 1, ".");
					backpack[2] = 1;
					map[character.x - 1][character.y] = 6;
				}
				if(map[character.x - 1][character.y] == 13) {
					mvprintw(0, 0, "NOW YOU'RE A BILLIONAIRE!              ");
					mvprintw(character.y, character.x - 1, ".");
					backpack[3] = 1;
					map[character.x - 1][character.y] = 6;
				}
				if(map[character.x - 1][character.y] == 14) {
					mvprintw(0, 0, "NOW YOU'RE A BILLIONAIRE!              ");
					mvprintw(character.y, character.x - 1, ".");
					backpack[4] = 1;
					map[character.x - 1][character.y] = 6;
				}
				if(map[character.x - 1][character.y] == 15) {
					mvprintw(0, 0, "CHEERS!                            ");
					mvprintw(character.y, character.x - 1, ".");
					spells[0] = 1;
					map[character.x - 1][character.y] = 6;
				}
				if(map[character.x - 1][character.y] == 16) {
					mvprintw(0, 0, "CHEERS!                            ");
					mvprintw(character.y, character.x - 1, ".");
					spells[1] = 1;
					map[character.x - 1][character.y] = 6;
				}
				if(map[character.x - 1][character.y] == 17) {
					mvprintw(0, 0, "CHEERS!                            ");
					mvprintw(character.y, character.x - 1, ".");
					spells[2] = 1;
					map[character.x - 1][character.y] = 6;
				}	
				mvprintw(character.y, character.x, ".");
				break;
			case 7:
				mvprintw(0, 0, "YUMMY!                           ");
				map[character.x][character.y] = 6;
				map[character.x + 1][character.y] = 6;
				add_food_to_menu(character.x, character.y, screen_height, map);
				mvprintw(character.y, character.x, ".");
				mvprintw(character.y, character.x + 1, ".");
				break;
			case 8:
				mvprintw(0, 0, "MONEY MONEY!                             ");
				map[character.x][character.y] = 6;
				map[character.x + 1][character.y] = 6;
				GOLD++;
				mvprintw(character.y, character.x, ".");
				mvprintw(character.y, character.x + 1, ".");
				break;
			case 9:
				mvprintw(0, 0, "NOW YOU'RE A BILLIONAIRE!               ");
				map[character.x][character.y] = 6;
				map[character.x + 1][character.y] = 6;
				DARK_GOLD++;
				mvprintw(character.y, character.x, ".");
				mvprintw(character.y, character.x + 1, ".");
				break;
			case 10:
				mvprintw(0, 0, "YOU CAN KILL ANYONE YOU WANT!         ");
				map[character.x][character.y] = 6;
				map[character.x + 1][character.y] = 6;
				backpack[0] = 1;
				mvprintw(character.y, character.x, ".");
				mvprintw(character.y, character.x + 1, ".");
				break;
			case 11:
				mvprintw(0, 0, "YOU CAN KILL ANYONE YOU WANT!         ");
				map[character.x][character.y] = 6;
				map[character.x + 1][character.y] = 6;
				backpack[1] = 1;
				mvprintw(character.y, character.x, ".");
				mvprintw(character.y, character.x + 1, ".");
				break;
			case 12:
				mvprintw(0, 0, "YOU CAN KILL ANYONE YOU WANT!         ");
				map[character.x][character.y] = 6;
				map[character.x + 1][character.y] = 6;
				backpack[2] = 1;
				mvprintw(character.y, character.x, ".");
				mvprintw(character.y, character.x + 1, ".");
				break;
			case 13:
				mvprintw(0, 0, "YOU CAN KILL ANYONE YOU WANT!         ");
				map[character.x][character.y] = 6;
				map[character.x + 1][character.y] = 6;
				backpack[3] = 1;
				mvprintw(character.y, character.x, ".");
				mvprintw(character.y, character.x + 1, ".");
				break;
			case 14:
				mvprintw(0, 0, "YOU CAN KILL ANYONE YOU WANT!         ");
				map[character.x][character.y] = 6;
				map[character.x + 1][character.y] = 6;
				backpack[4] = 1;
				mvprintw(character.y, character.x, ".");
				mvprintw(character.y, character.x + 1, ".");
				break;	
			case 15:
				mvprintw(0, 0, "CHEERS!                            ");
				map[character.x][character.y] = 6;
				map[character.x + 1][character.y] = 6;
				spells[0] = 1;
				mvprintw(character.y, character.x, ".");
				mvprintw(character.y, character.x + 1, ".");
				break;
			case 16:
				mvprintw(0, 0, "CHEERS!                            ");
				map[character.x][character.y] = 6;
				map[character.x + 1][character.y] = 6;
				spells[1] = 1;
				mvprintw(character.y, character.x, ".");
				mvprintw(character.y, character.x + 1, ".");
				break;
			case 17:
				mvprintw(0, 0, "CHEERS!                            ");
				map[character.x][character.y] = 6;
				map[character.x + 1][character.y] = 6;
				spells[2] = 1;
				mvprintw(character.y, character.x, ".");
				mvprintw(character.y, character.x + 1, ".");
				break;
			case 18:
				Floor--;
				play();
				return;	
			case 19:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				mvprintw(character.y, character.x, "D");
				heart -= 5; 
				break;
			case 20:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				mvprintw(character.y, character.x, "F");
				heart -= 10; 
				break;
			case 21:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				mvprintw(character.y, character.x, "G");
				heart -= 15; 
				break;
			case 22:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				mvprintw(character.y, character.x, "S");
				heart -= 20; 
				break;
			case 23:
				mvprintw(0, 0, "ENEMY HURT YOU!                             ");
				mvprintw(character.y, character.x, "U");
				heart -= 25; 
				break;						
														
		}
		if(c == 'j') {
			if(map[character.x][character.y - 1] != 4 && map[character.x][character.y - 1] != 3 && map[character.x][character.y - 1] != 0) {
				character.y --;
				if(double_speed == 1) {
					if(map[character.x][character.y - 1] != 4 && map[character.x][character.y - 1] != 3 && map[character.x][character.y - 1] != 0) 
						character.y --;
				}	
			}
		}
		if(c == 'k') {
			if(map[character.x][character.y + 1] != 4 && map[character.x][character.y + 1] != 3 && map[character.x][character.y + 1] != 0) {
				character.y ++;
				if(double_speed == 1) {
					if(map[character.x][character.y + 1] != 4 && map[character.x][character.y + 1] != 3 && map[character.x][character.y + 1] != 0) 
						character.y ++;
				}
			}
		}
		if(c == 'h') {
			if(map[character.x - 1][character.y] != 4 && map[character.x - 1][character.y] != 3 && map[character.x - 1][character.y] != 0) {
				character.x --;
				if(double_speed == 1) {
					if(map[character.x - 1][character.y] != 4 && map[character.x - 1][character.y] != 3 && map[character.x - 1][character.y] != 0)
						character.x --;
				}
			}
		}
		if(c == 'l') {
			if(map[character.x + 1][character.y] != 4 && map[character.x + 1][character.y] != 3 && map[character.x + 1][character.y] != 0) {
				character.x ++;
				if(double_speed == 1) {
					if(map[character.x + 1][character.y] != 4 && map[character.x + 1][character.y] != 3 && map[character.x + 1][character.y] != 0)
						character.x ++;
				}
			}
		}
		if(c == 'u') {
			if(map[character.x + 1][character.y - 1] != 4 && map[character.x + 1][character.y - 1] != 3 && map[character.x + 1][character.y - 1] != 0) {
				character.x ++;
				character.y --;
			}
		}
		if(c == 'y') {
			if(map[character.x - 1][character.y - 1] != 4 && map[character.x - 1][character.y - 1] != 3 && map[character.x - 1][character.y - 1] != 0) {
				character.x --;
				character.y --;
			}
		}
		if(c == 'n') {
			if(map[character.x + 1][character.y + 1] != 4 && map[character.x + 1][character.y + 1] != 3 && map[character.x + 1][character.y + 1] != 0) {
				character.x ++;
				character.y ++;
			}
		}
		if(c == 'b') {
			if(map[character.x - 1][character.y + 1] != 4 && map[character.x - 1][character.y + 1] != 3 && map[character.x - 1][character.y + 1] != 0) {
				character.x --;
				character.y ++;
			}
		}
		if(c == 'e') {  
			consume_food();
		}
		if(c == 'r') {
			wear_weopon();
		}
		if(c == 't') {
			drink_spell();
		}
		if(c == 'f') {
			c = getch();
			if(c == 'j') {
				while(map[character.x][character.y - 1] != 4 && map[character.x][character.y - 1] != 3 && map[character.x][character.y - 1] != 0) {
					character.y --;
					if(map[character.x][character.y] == 2) {
						heart--;
						break;
					}
				}
			}
			if(c == 'k') {
				while(map[character.x][character.y + 1] != 4 && map[character.x][character.y + 1] != 3 && map[character.x][character.y + 1] != 0) {
					character.y ++;
					if(map[character.x][character.y] == 2) {
						heart--;
						break;
					}
				}
			}
			if(c == 'h') {
				while(map[character.x - 1][character.y] != 4 && map[character.x - 1][character.y] != 3 && map[character.x - 1][character.y] != 0) {
					character.x --;
					if(map[character.x][character.y] == 2) {
						heart--;
						break;
					}
				}
			}
			if(c == 'l') {
				while(map[character.x + 1][character.y] != 4 && map[character.x + 1][character.y] != 3 && map[character.x + 1][character.y] != 0) {
					character.x ++;
					if(map[character.x][character.y] == 2) {
						heart--;
						break;
					}
				}
			}
		}
		if(c == 27) {
			welcome();
			return;
		}
		mvprintw(character.y, character.x, "A");
		moves++;
		if(moves % 10 == 0) {
			if(moves % 20 == 0) {
			update_hunger();
				if(hunger < 10) {
					heart += 5;
					if(double_health) heart += 5;
					if (heart > 100) heart = 100;
				}
			}
			if(moves % 40 == 0)	{
				for(int i = 0; i < 20; i++) {
					food_items[i].health_value -= 10;
					if(food_items[i].health_value < -20) 
						food_items[i].health_value = -20;
				}
			}
			double_speed = 0;
			double_power = 0;
			double_health = 0;
		}
		if(heart <= 0) {
			clear();
			mvprintw(screen_height / 2, screen_width / 2 - 3, "YOU LOST");
			getch();
			welcome();
			return;
		}
		//mvprintw(0, 0, "                           ");
		refresh();
	}
}