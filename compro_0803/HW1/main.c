#include <stdio.h>
#define MAP_SIZE 11
#define EXIT_ROW 5
#define EXIT_COL 10
#define NUM_CARS 10
#define WALL '#'
#define SPACE '.'
#define EXIT '='

/* #define ONLINE_JUDGE */

int map[MAP_SIZE][MAP_SIZE];
void map_reset(void);
void map_show(void);

int cars[NUM_CARS][4];
void cars_read(void);
void cars_put_on_map(void);

void list_moves(void);

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("cars.txt", "r", stdin);
#endif

    cars_read();
    map_reset();
    cars_put_on_map();

#ifndef ONLINE_JUDGE
    map_show();
#endif

#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
#endif

    list_moves();

    return 0;
}
void cars_read(void)
{
    int i;
    int row_h, col_h, row_t, col_t;

    for (i=0; i<NUM_CARS; i++) {
        scanf("%d%d%d%d", &row_h, &col_h, &row_t, &col_t);
        cars[i][0] = row_h;
        cars[i][1] = col_h;
        cars[i][2] = row_t;
        cars[i][3] = col_t;
    }
}

void cars_put_on_map(void)
{
    int i, j, k;
    int row_h, col_h, row_t, col_t;
    for (i=0; i<NUM_CARS; i++) {
        row_h = cars[i][0];
        col_h = cars[i][1];
        row_t = cars[i][2];
        col_t = cars[i][3];
        for (j=row_h; j<=row_t; j++) {
            for (k=col_h; k<=col_t; k++) {
                map[j][k] = i + 'a';
            }
        }
    }
}
void map_reset(void)
{
    int i, j;
    for (i=0; i<MAP_SIZE; i++) {
        for (j=0; j<MAP_SIZE; j++) {
            map[i][j] = SPACE;
        }
    }
    for (i=0; i<MAP_SIZE; i++) {
        map[i][0] = WALL;
        map[i][MAP_SIZE-1] = WALL;
    }
    for (j=0; j<MAP_SIZE; j++) {
        map[0][j] = WALL;
        map[MAP_SIZE-1][j] = WALL;
    }
    map[EXIT_ROW][EXIT_COL] = EXIT;
}

void map_show(void)
{
    int i, j;
    for (i=0; i<MAP_SIZE; i++) {
        for (j=0; j<MAP_SIZE; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void list_moves(void)
{
    /* IGNORE THE FOLLOWING LINES AND WRITE YOUR OWN CODE */
    int i;
    int right=0, down=0, left=0, top=0;
    int tmpx = 0, tmpy_L=0, tmpy_R = 0;
    int pmty = 0, pmtx_T=0, pmtx_D = 0;

    for (i=0; i<NUM_CARS; i++) {
      right=0; down=0; left=0; top=0;
		//cars
		  if (cars[i][0]==cars[i][2]) {
        tmpx = cars[i][0];
        if ( cars[i][1] < cars[i][3]) {
          tmpy_L = cars[i][1]; tmpy_R = cars[i][3];
        } else {
          tmpy_L = cars[i][3]; tmpy_R = cars[i][1];
        }
        while ( map[tmpx][tmpy_L - 1] == SPACE ) {
          left = left + 1;
          tmpy_L --;
          if (tmpy_L==0 || tmpy_L==9) { break; }
        }
        while ( map[tmpx][tmpy_R + 1] == SPACE ) {
          right = right + 1;
          tmpy_R ++;
          if (tmpy_R==0 || tmpy_R==9) { break; }
        }
      } else if (cars[i][1] == cars[i][3]) {
        pmty = cars[i][1];
        if ( cars[i][0] < cars[i][2]) {
          pmtx_T = cars[i][0]; pmtx_D = cars[i][2];
        } else {
          pmtx_T = cars[i][2]; pmtx_D = cars[i][0];
        }

        while ( map[pmtx_T-1][pmty] == SPACE ) {
          top = top + 1;
          pmtx_T --;
          if (pmtx_T==0 || pmtx_T==9) { break; }
        }
        while (map[pmtx_D+1][pmty] == SPACE) {
          down = down + 1;
          pmtx_D ++;
          if (pmtx_D==0 || pmtx_D==9) { break; }
        }
      }
      printf("%d %d %d %d\n", right, down, left, top);
    }
}
