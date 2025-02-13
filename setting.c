

void setting() {
	clear();
	printw("1. Difficulty\n2. Change music\n3. Color of the player");
	int c = getch() - '0';
	switch(c) {
		case 1:
			clear();
			printw("1. EASY\n2. HARD");
			int c = getch() - '0';
			switch(c) {
				case 1:
					difficulty = 1;
					break;
				case 2:
					difficulty = 2;
					break;	
			}
			break;
		case 2:
			clear();
			printw("0. OFF!\n");
			printw("1. Jostojou\n");
			printw("2. Freak\n");
			printw("3. Disease\n");
			printw("4. TaneZakhmi\n");
			printw("5. InBoodZendegi\n");
			printw("6. FourthOfJuly\n");
			c = getch() - '0';
			if (music != NULL) {
                Mix_HaltMusic();
                Mix_FreeMusic(music);
                music = NULL;
            }
			switch(c) {
			case 0:
				Mix_CloseAudio();
				break;
			case 1:
			    Mix_OpenAudio(44100, AUDIO_F32SYS, 2, 2048);
 	            music = Mix_LoadMUS("Jostojou.mp3");
 	            break;
 	        case 2:
 	            Mix_OpenAudio(44100, AUDIO_F32SYS, 2, 2048);
 	            music = Mix_LoadMUS("Freak.wav");
 	            break;    
 	        case 3:
 	       	    Mix_OpenAudio(44100, AUDIO_F32SYS, 2, 2048);
				music = Mix_LoadMUS("Disease.wav");
				break;
 	        case 4:
 	        	Mix_OpenAudio(44100, AUDIO_F32SYS, 2, 2048);
				music = Mix_LoadMUS("TaneZakhmi.wav");
				break;
			case 5:
				Mix_OpenAudio(44100, AUDIO_F32SYS, 2, 2048);
				music = Mix_LoadMUS("InBoodZendegi.wav");
				break;
			case 6:
				Mix_OpenAudio(44100, AUDIO_F32SYS, 2, 2048);
 	            music = Mix_LoadMUS("FourthOfJuly.wav");
 	            break;
			}
			break;
		case 3:
			clear();
			printw("1. YELLOW\n2. White\n3. MAGENTA");
			c = getch() - '0';
			switch(c) {
        		case 1: break;
        		case 2: break;
        		case 3: break;	
			}
		//init_pair(5, selected_color, COLOR_BLACK);
	}
	welcome();
}