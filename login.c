void log_in();
int validate_login(const char *username, const char *password);
void loop1();
void log_in() {
	char username[50], password[50];
	
	
	clear();
    printw("--- FIRST LOG IN ! ---\n");
	
    printw("Enter username: ");
    echo();
    getstr(username);
    
    noecho();
	printw("Enter password: ");
	echo();
	getstr(password);
	
	noecho();
	
	if(validate_login(username, password)) {
	printw("\nUser logged in successfully!\n Press any button...");
	getch();
	logged = 1;
	strcpy(logged_username, username);
	welcome();
	}
}
int validate_login(const char *username, const char *password) {
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        printw("\nError opening file! Press any key to retry...");
        getch();
        return 0;
    }

    char line[250];
    char stored_username[50], stored_password[50], stored_email[50];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%s %s %s", stored_username, stored_password, stored_email) == 3) {
            if (strcmp(username, stored_username) == 0) {
                if (strcmp(password, stored_password) == 0) {
                	logged = 1;
                	strcpy(logged_user, username);	
                    fclose(file);
                    return 1;
                } else {
                    noecho();
                    printw("\nWRONG password!\n");
                    printw("\nForgot your password? (y/n)\n");
                    int c = getch();
                    if (c == 'y') {
                        printw("Enter email: ");
                        echo();
                        char email[50];
                        getnstr(email, sizeof(email) - 1);
                        noecho();

                        rewind(file);  // بازگشت به ابتدای فایل برای جستجوی ایمیل
                        int found = 0;

                        while (fgets(line, sizeof(line), file)) {
                            if (sscanf(line, "%s %s %s", stored_username, stored_password, stored_email) == 3) {
                                if (strcmp(email, stored_email) == 0) {
                                    found = 1;
                                    break;
                                }
                            }
                        }
                        fclose(file);

                        if (found) {
                            printw("\nYOUR PASSWORD: %s\n", stored_password);
                        } else {
                            printw("\nEMAIL NOT FOUND\n");
                        }

                        refresh();
                        getch();
                    }
                    printw("Try again? (y/n) ");
                    loop1();
                    return 0;
                }
            }
        }
    }

    fclose(file);
    printw("\nUsername doesn't exist!\n Press any key to retry...");
    printw("Try again? (y/n) ");
    noecho();
    loop1();
    return 0;
}
void loop1() {
	char ch = getch();
	while(1) {
		if(ch == 'y') {
			log_in();
			return;
		}
		else if(ch == 'n') {
			welcome();
			return;
		}
		else {
			ch = getch();
		}
	}
}

void profile() {
	if(!logged) {
		welcome();
		return;
	} 
	clear();
	FILE *file = fopen("scores.txt", "r");
	int gold1, score;
	char name[50];
    while (fscanf(file, "%49[^,], %d, %d\n", name, &score, &gold1) == 3) {
        if(strcmp(logged_user, name) == 0) {
        	mvprintw(1, 2, " Name   Score   Gold");
        	mvprintw(3, 2, " %s     %d      %d", name, score, gold1);
        	break;
		}
    }
    fclose(file);
    show_experience();
	
	getch();
	welcome();
}