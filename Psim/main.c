#include <stdio.h>
#include <math.h>
#include <time.h>
#include "gfx.h"
#define pi 3.141592652

void ground();
void origin();
void _tracexy();
void delay();
void ball();
void castle();
double _Vo();
double _Vox();
double _Voy();

int main(){
    int c,xs,ys,xp,yp,yps,x0=900,y0=900; 
    double mass,_angle,_r,_a,_tr,k;   
    gfx_open(1440,900,"Projectile Simulator");
    ground();
    printf("Mass of Projectile(kg):\t");
    scanf("%lf",&mass);
    printf("Spring constant(N/m?\t");
    scanf("%lf",&k);


    while(1){
            c=gfx_wait();
            if(c==2){
            gfx_clear();
            ground();
            castle();
            gfx_color(0,255,0);
            gfx_circle(gfx_xpos(),gfx_ypos(),20);
            x0=gfx_xpos(); //touch position x
            y0=gfx_ypos(); //touch position y
            }

            if(c==1){
                gfx_clear();
                ground();
                castle();
                gfx_line(x0,y0,gfx_xpos(),gfx_ypos()); 
                gfx_color(0,72,186);
                gfx_fillcircle(gfx_xpos(),gfx_ypos(),20); //projectile ready
                yps=gfx_ypos(); 
                xp=gfx_xpos();
                yp=800-gfx_ypos(); //Position relative to ground
                xs=x0-xp; //length x 
                ys=yps-y0; //length y
                _r=sqrt((xs*xs)+(ys*ys));
                _tr=ys/_r;
                _a=asin(_tr);
                double b=_Vo(mass,_r,k);
                double e=_Vox(_a,b);
                double d=_Voy(_a,b);
                printf("Pull \t angle \t\t Vo \t\t Vox \t\t Voy \n");
                printf("%.2f \t %lf \t %lf \t %lf \t %lf \n",_r,_a,b,e,d);
                printf("Initial Displacement: %d,%d\n",xp,yps);
                c=gfx_wait();
                if(c==3){
                    _tracexy(e,d,xp,yps);
                    c=gfx_wait();


                }
                }
            if(c=='q')break;
            
            
            
          
    }
}


void ground(){
    gfx_clear_color(140,190,214);
    gfx_color(0,0,0);
    gfx_text("200m",1000,720);
    gfx_line(986,700,1186,700);
    gfx_line(986,675,986,725);
    gfx_line(1186,675,1186,725);
    gfx_color(0,255,0);
    gfx_fillrectangle(0,800,1440,100);
}

void _tracexy(double _Vox,double _Voy,int xp,int yp){
    double t=0;
    double a=9.81;
    double _dispx=0,_dispy=0;
    double _array[1][2]={{xp,yp}};
    int i=0;
    printf("[%.2f,%.2f]\t\t%.2f\n",_array[0][0],_array[0][1],t);
    gfx_color(204,0,0);
    for(t=0.05;t>-1;t=t+0.05){
        gfx_clear();
        ground();
        castle();
        _dispx=xp+(_Vox*t);
        _dispy=yp+(-(_Voy)*t)+((a*t*t)/2);
        i=i+1;
        //double _array[i+1][2];
        //_array[i][0]=_dispx;
        //_array[i][1]=_dispy;
        if(_dispy>800 || _dispx>1440){
            gfx_color(0,72,186);
            gfx_circle(_dispx,_dispy,20);
        break;}
        //gfx_point(_dispx,_dispy);
        ball(_dispx,_dispy);
        printf("[%.2f,%.2f]\t\t%.2f\n",_dispx,_dispy,t);
        delay();
    }

}

double _Vo(double m,double r,double k){
    double _p;
    _p=(((k*r*r)/m));
    return sqrt(_p);
}

double _Vox(double a,double v){
    return v*cos(a);
}

double _Voy(double a, double v){
    return v*sin(a);
}

void delay(){
    int t=clock();
    while(clock()<t+CLOCKS_PER_SEC*0.05){}
}

void ball(double dpx, double dpy){
    gfx_color(0,0,255);
    gfx_fillcircle(dpx,dpy,20);
    ground();
}

void castle(){
    gfx_color(132,132,130);
    gfx_fillrectangle(1240,700,200,100);
}
