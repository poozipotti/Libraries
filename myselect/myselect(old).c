#include "my.h"
#include <assert.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ncurses.h>

/*
 * Stephen McArdle
 * I pledge my honor that I have abided by the Stevens Honor System.
 */

int drawFiles(int columnWidth,int columnNumber,char **files,int fileNumber,short * highlighted, int selected){
    int rows = 0;
    int i=0;
    for(i=0;i<fileNumber;i++){
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
    return rows+1;
}

int main(int argc, char **argv){
    int columnWidth;
    unsigned int totalColumns,totalRows;
    int i;
    int selected = 0;
    int min_padding = 2;
    int padding;
    int columnNumber,rowNumber;
    short *highlighted = (short*)malloc(argc*sizeof(short));
    int inputKey;
    int columnsTooBig = 0; /*boolean to see if columns are too large for the window*/

    if(argc <=1){
        my_str("too few arguments");
        return 1;
    }
    /*find the longest string, that way we know the min column width*/
    columnWidth = my_strlen(argv[1]);
    for(i=2;i<argc;i++){
        columnWidth = (columnWidth>my_strlen(argv[i])) ? columnWidth : my_strlen(argv[i]);
    }
    columnWidth += min_padding;
    initscr();  /* Start curses mode*/
    clear();
    noecho();
    raw();
    curs_set(0);
    keypad(stdscr, TRUE);
    getmaxyx(stdscr, totalRows, totalColumns);
    if(columnWidth>totalColumns){
        columnsTooBig = 1;
    }
    if(!columnsTooBig){
        /*calculate the number of columns*/
        columnNumber = totalColumns/columnWidth;
        /*calculate additional padding padding must be at least min_padding */
        padding =(columnNumber == 1) ? 0 :(totalColumns%columnWidth)/(columnNumber-1);
    }
    while(1){
        if(columnsTooBig){
            clear();
            printw("Cannot display, screen is too small!");
        }else{
            clear();
            rowNumber=drawFiles(columnWidth+padding,columnNumber,argv+1,argc-1,highlighted,selected);
            if(rowNumber>totalRows){
                clear();
                printw("Cannot display, screen is too small!");
            }
        }
        inputKey = wgetch(stdscr);
        switch(inputKey){
            case KEY_UP:
                if (selected < columnNumber){
                    selected += (columnNumber*rowNumber)-1;
                    while(selected>argc-2){
                        selected -= columnNumber;
                    }
                }else{
                    selected -= columnNumber;
                }
                break;
            case KEY_DOWN:
                selected += columnNumber;
                if(selected > argc-2){
                    selected= (selected%columnNumber)+1;
                    if(selected >= columnNumber){
                        selected = 0;
                    }
                }
                break;
            case KEY_LEFT:
                selected--;
                if (selected < 0)
                    selected = argc-2;
                break;
            case KEY_RIGHT:
                selected ++;
                if(selected >argc-2)
                    selected = 0;
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
                /*count the characters in the output string*/
                endwin();
                free(highlighted);
                for (i=1; i<argc; i++) {
                    if (highlighted[i-1]) {
                        my_str(argv[i]);
                        my_char(' ');
                    }
                }
                return 0;
            case 27:
                endwin();
                free(highlighted);
                my_str("exited\n");
                my_int(rowNumber);
                return 0;
            case KEY_RESIZE:
                getmaxyx(stdscr, totalRows, totalColumns);
                if(columnWidth>totalColumns){
                    columnsTooBig = 1;
                }else{
                    columnsTooBig = 0;
                }
                if(!columnsTooBig){
                    /*calculate the number of columns*/
                    columnNumber = totalColumns/columnWidth;
                    /*calculate additional padding padding must be at least min_padding */
                    padding =(columnNumber == 1) ? 0 :(totalColumns%columnWidth)/(columnNumber-1);
                }
                clear();
                rowNumber=drawFiles(columnWidth+padding,columnNumber,argv+1,argc-1,highlighted,selected);
                break;

        }
    }
    free(highlighted);
    return 1;
}

