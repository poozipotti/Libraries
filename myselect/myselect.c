#include "my.h"
#include <assert.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ncurses.h>

/*
 * Stephen McArdle
 * I pledge my honor that I have abided by the Stevens Honor System.
 */


int drawFiles(int columnWidth, int columnNumber, char **files, int numFiles, short * highlighted, int selected){
	int i;
	int rows = 0;
    if(columnNumber==0){
        clear();
        printw("please enlarge window");
    }else{
	for(i = 0; i < numFiles; ++i){
                if(i%columnNumber == 0){
                        rows++;
                }
                if(i==selected)
                        attron(A_UNDERLINE);
                if(highlighted[i]==1){
                    attron(A_STANDOUT);
                }
            mvprintw(rows,(i%columnNumber)*columnWidth,files[i]);
            attroff(A_STANDOUT);
            attroff(A_UNDERLINE);
        }
    }
	return rows;
}


int main(int argc, char **argv){
    int columnWidth;
    unsigned int totalColumns, totalRows;
    int i, padding, numColumns, numRows, inputKey;
    int selected = 0;
    int min_padding = 2;
	short tooSmall = 0;
    short *highlighted = (short*)malloc(argc*sizeof(short));
    if(argc <= 1){
        my_str("usage: myselect arg1 [...] [argn]");
        return 1;
    }
    numColumns = 1;
    /*find the longest string so we know the min column width*/
    columnWidth = my_strlen(argv[1]);
    for(i = 2; i < argc; ++i) {
        columnWidth = (columnWidth>my_strlen(argv[i])) ? columnWidth : my_strlen(argv[i]);
    }
    columnWidth += min_padding;
    initscr();  /* Start curses mode*/
    clear();
    noecho();
    raw();

    keypad(stdscr, TRUE);
    getmaxyx(stdscr, totalRows, totalColumns);
    /*calculate the number of columns*/

	if (columnWidth > totalColumns) {
		tooSmall = 1;
	}
	if (tooSmall) {
		padding = min_padding;
	} else {
    		numColumns = totalColumns/columnWidth;
    		padding = (totalColumns%columnWidth) / (numColumns-1);
	}

    while(1) {
	if (tooSmall) {
		clear();
		printw("please enlarge the window");
	} else {
        numRows = drawFiles(columnWidth+padding, numColumns, argv+1, argc-1, highlighted, selected);
		if (numRows > totalRows) {
			clear();
			printw("please enlarge the window");
		}
	}
        inputKey = wgetch(stdscr);
        switch(inputKey){
		case KEY_RESIZE:
			getmaxyx(stdscr, totalRows, totalColumns);
            if(!tooSmall){
                numColumns = totalColumns/columnWidth;
            }
		    	padding = 1; /*(totalColumns%columnWidth)/(numColumns-1);*/
			clear();
		        numRows = drawFiles(columnWidth+padding, numColumns, argv+1, argc-1, highlighted, selected);
            break;
            case KEY_UP:
		if (selected < numColumns) {
			selected += (numColumns * numRows) - 1;
			while (selected > argc - 2) {
				selected -= numColumns;
			}
		} else {
	        	selected -= numColumns;
		}
                break;
            case KEY_DOWN:
		selected += numColumns;
		if (selected > argc - 2) {
			selected = (selected%numColumns) + 1;
			if (selected >= numColumns) {
				selected = 0;
			}
		}
                break;
            case KEY_LEFT:
                selected--;
                if (selected < 0)
                    selected = 0;
                break;
            case KEY_RIGHT:
                selected ++;
                if(selected > argc-2)
                    selected = argc-2;
                break;
            case 32:
                if(highlighted[selected]==1) {
			highlighted[selected] = 0;
                } else {
                    highlighted[selected] = 1;
			selected++;
			if (selected > argc - 2) {
				selected = 0;
			}
                }
                break;
            case '\n':
                /* close the ncurses window and write the output to stdout */
		endwin();
                for (i=1; i<argc; i++) {
                    if (highlighted[i-1]) {
			my_str(argv[i]);
			my_char(' ');
                    }
                }
		my_char('\n');
            case 27:
                endwin();
                return 0;

        }
    }
    return 1;
}

