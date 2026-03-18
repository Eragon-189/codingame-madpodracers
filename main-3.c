#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
long double errorx;
long double errory;
long double intx;
long double inty;
long double divx;
long double divy;
long double dt = 1;//run time of 1 loop
double ki = 0;
double kp = 2;
double kd = 0.05;
long double k = 2;

int prex = 0;
int prey = 0;

bool first = true;
int mapLoca[20][2];
int mapCount = 0;
bool lap1 = false;

void getMap(int tx,int ty);
int vel(int pre,int con);
long double PIDX(long double x, long double tx, long double vx, long double dt);
long double PIDY(long double y, long double ty, long double vy, long double dt);
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
        
        if (first == false){//check if first tick
            //if not run(because we now have dt and prex/y)
            outx = ncx + PIDX(x,ncx,(x-prex),dt);
            outy = ncy + PIDY(y,ncy,(y-prey),dt);
        }//reasine prex and prey
        
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
    }else if(-90 > a || a > 90 || d < 1000){
        return 0;
    }else{
        return 100; 
    }
}

long double PIDX(long double x, long double tx, long double vx, long double dt){
    errorx = tx - x;
    intx += errorx * dt;
    divx = -vx;
    long double out = kp*errorx + ki*intx + kd*divx;
    return out;
}
long double PIDY(long double y, long double ty, long double vy, long double dt){
    errory = ty - y;
    inty += errory * dt;
    divy = -vy;
    long double out = kp * errory + ki * inty + kd * divy;
    return out;
}
