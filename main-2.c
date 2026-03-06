#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int prex = 0;
int prey = 0;

double dx = 0;
double dy = 0;
double nx = 0;
double ny = 0;
double px = 0;
double py = 0;
double k = 0;
double c = 0;
double offsetX = 0;
double offsetY = 0;
double velCorX = 0;
double velCorY = 0;
double offset = 0;
double dist = 0;

bool first = true;
int mapLoca[20][2];
int mapCount = 0;
bool lap1 = false;

void getMap(int tx,int ty);
int power(int a,int d,int tx,int ty);
int main(){
    // game loop
    while (1) {
        int x;
        int y;
        // x position of the next check point
        int ncx;
        // y position of the next check point
        int ncy;
        // distance to the next checkpoint
        int ncd;
        // angle between your pod orientation and the direction of the next checkpoint
        int nca;
        scanf("%d%d%d%d%d%d", &x, &y, &ncx, &ncy, &ncd, &nca);
        int oppx;
        int oppy;
        scanf("%d%d", &oppx, &oppy);

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        long double outx = ncx;
        long double outy = ncy;
        int thrust = power(nca,ncd,ncx,ncy);
        if (first == false){

        }
        dx = ncx - x;
        dy = ncy - y;
        dist = (double)hypot((double)dx,dy);
        nx = dx / dist;
        ny = dy / dist;
        px = - ny;
        py = nx;
        offset = k * dist * sin(nca);
        offsetX = px * offset;
        offsetY = py * offset;
        prex = x;
        prey = y;
        getMap(ncx,ncy);
        if (thrust > 100){//check if invalid value and boost if it is
            printf("%d %d %s\n",(int)(outx),(int)(outy),"BOOST");
        }else if (thrust >= 0){//check if trust is valid
             
        printf("%d %d %d\n", (int)(outx), (int)(outy),thrust);
        }else{
            printf("%d %d 0\n",(int)(outx),(int)(outy));
        }
        first = false;
    }
    return 0;
}

void getMap(int tx,int ty){
    if(lap1 == false){
        return;
    }else if(mapLoca[0][0] == tx && mapLoca[0][1] == ty){
        lap1 = false;
    }else if(!(mapLoca[mapCount][0] == tx && mapLoca[mapCount][1] == ty)){
        mapCount++;
        mapLoca[mapCount][0] = tx;
        mapLoca[mapCount][1] = ty;
    }
}
int power(int a,int d,int tx,int ty){
    if(d > 5000 && abs(a) < 2 && a != 0){
        return 101;
    }else if(-90 > a || a > 90 || d < 600){
        return 0;
    }else{
        return 100; 
    }
}
