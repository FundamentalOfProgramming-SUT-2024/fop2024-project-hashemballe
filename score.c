#define PAGE_SIZE 10
#define MAX_LINE_LENGTH 256
typedef struct {
    char name[50];
    int score;
    int gold;
} Player;

Player players[100];
int player_count = 0;

void show_experience();

void read_scores(const char *filename) {
    FILE *file = fopen(filename, "r");
    while (fscanf(file, "%49[^,], %d, %d\n", players[player_count].name, &players[player_count].score,
                  &players[player_count].gold) == 3) {
        player_count++;
    }
    fclose(file);
}

int compare_scores(const void *a, const void *b) {
    return ((Player *)b)->score - ((Player *)a)->score;
}

void scoreboard() {
	if(!logged) {
		welcome();
		return;
	} 
	player_count = 0;
	read_scores("scores.txt");
	qsort(players, player_count, sizeof(Player), compare_scores);
	start_color();
	noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    noecho();
    curs_set(0);
    int start_index = 0;
    char ch;
    
    while (1) {
        clear();
        mvprintw(0, 5, "Leaderboard");
        mvprintw(1, 2, "Rank   Name         Score   Gold");
        for (int i = 0; i < PAGE_SIZE && (start_index + i) < player_count; i++) {
            Player p = players[start_index + i];

            if (strcmp(p.name, logged_user) == 0) {
                attron(COLOR_PAIR(4) | A_BOLD);
            } else if (start_index + i == 0) {
                attron(COLOR_PAIR(1) | A_BOLD);
            } else if (start_index + i == 1) {
                attron(COLOR_PAIR(2));
            } else if (start_index + i == 2) {
                attron(COLOR_PAIR(3));
            }

            mvprintw(i + 3, 2, "%3d    %-12s %5d   %4d", start_index + i + 1, p.name, p.score, p.gold);
            if(start_index + i == 0) {
    			mvprintw(i + 3, 40, "GOAT");
            	mvaddwstr(i + 3, 15, L"\U0001F3C6");
            	mvaddwstr(i + 3, 17, L"\U0001F3C6");
            	mvaddwstr(i + 3, 19, L"\U0001F3C6");
			}
			if(start_index + i == 1) {
				mvprintw(i + 3, 40, "LEGEND");
            	mvaddwstr(i + 3, 15, L"\U0001F3C6");
            	mvaddwstr(i + 3, 17, L"\U0001F3C6");
			}
			if(start_index + i == 2) {
				mvprintw(i + 3, 40, "HERO");
            	mvaddwstr(i + 3, 15, L"\U0001F3C6");
			}
            attroff(COLOR_PAIR(1) | A_BOLD);
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(4) | A_BOLD);
        }
		show_experience();
        mvprintw(PAGE_SIZE + 4, 2, "Press UP/DOWN to scroll, Q to quit");
        show_experience();
        refresh();
        
        ch = getch();
        if (ch == 'q') {
        	welcome();
			return;
		}
        else if (ch == 'a' && start_index + PAGE_SIZE < player_count) start_index++;
        else if (ch == 'b' && start_index > 0) start_index--;
    }
    
}

void show_experience() {
	char line[MAX_LINE_LENGTH];
    mvprintw(0, 70, "experience : ");
	FILE *file = fopen("experience.txt", "r");
    
	while (fgets(line, sizeof(line), file)) {
        char name[100];
        int games;
        
        if (sscanf(line, "%s %d", name, &games) == 2) {
            if (strcmp(name, logged_user) == 0) {
            	
            	mvprintw(0, 83, "%d ", games);
            	break;
            }
		}
	}
	fclose(file);
	refresh();
}



void increment_games_for_user() {
    FILE *file = fopen("experience.txt", "r+");
    if (!file) {
        perror("Error opening file for reading");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char updated_lines[256][MAX_LINE_LENGTH]; 
    int line_count = 0;
    int user_found = 0;

    
    while (fgets(line, sizeof(line), file)) {
        char name[100];
        int games;
        
        if (sscanf(line, "%s %d", name, &games) == 2) {
            if (strcmp(name, logged_user) == 0) {
                // اگر یوزرنیم پیدا شد، تعداد بازی‌های آن را یک واحد افزایش می‌دهیم
                sprintf(line, "%s %d\n", name, games + 1); 
                user_found = 1;
            }
        }

       
        strcpy(updated_lines[line_count++], line);
    }

    
    if (!user_found) {
        sprintf(updated_lines[line_count++], "%s 1 1\n", logged_user); 
	}

    
    fclose(file);

    
    file = fopen("experience.txt", "w");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < line_count; i++) {
        fputs(updated_lines[i], file);
    }

    fflush(file);

    fclose(file);
    
}