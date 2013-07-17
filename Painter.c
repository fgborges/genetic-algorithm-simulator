#include<stdio.h>
#include<math.h>
#include<X11/Xlib.h>
#include<X11/Xutil.h>
#define WIDTH 1000
#define HEIGHT 1000
#define BORDER 1
#define TRUE 1
#define FALSE 0
#define PI 3.14159265
#define POINT_X_MAX 100
#define POINT_Y_MAX 50
#define POINT_LENGTH 30 

typedef struct{
	XPoint p1,p2;
}XLine;

void XDrawArrow(Display*,Window,GC,XLine);
void export(const XLine[],const XPoint[],const int,const int);

int main(int argc,char *argv[])
{
	Display *dpy;
	Window w;
	Window root;
	Window quit,save,undo,new;
	int screen;
	unsigned long black,white;
	GC gc;
	XEvent event;

	XPoint p;
	XLine tmp;
	XLine lines[256];
	int lines_last=0;
	XPoint points[256];
	int points_last=0;
	int i,j,flag = FALSE;
	
	dpy = XOpenDisplay("");
	root = DefaultRootWindow(dpy);
	screen = DefaultScreen(dpy);
	white = WhitePixel(dpy,screen);
	black = BlackPixel(dpy,screen);

	w = XCreateSimpleWindow(dpy,root,100,100,WIDTH,HEIGHT,BORDER,black,white);
	quit = XCreateSimpleWindow(dpy,w,10,3,30,12,BORDER,black,white);
	save = XCreateSimpleWindow(dpy,w,40,3,30,12,BORDER,black,white);
	undo = XCreateSimpleWindow(dpy,w,70,3,30,12,BORDER,black,white);
	new = XCreateSimpleWindow(dpy,w,100,3,30,12,BORDER,black,white);
	gc = XCreateGC(dpy,w,0,NULL);

	XSelectInput(dpy,w,ButtonPressMask|ButtonReleaseMask);
	XSelectInput(dpy,quit,ButtonPressMask);
	XSelectInput(dpy,save,ButtonPressMask);
	XSelectInput(dpy,undo,ButtonPressMask);
	XSelectInput(dpy,new,ButtonPressMask);

	XMapWindow(dpy,w);
	XMapSubwindows(dpy,w);
	XDrawString(dpy,quit,gc,4,10,"Exit",4);
	XDrawString(dpy,undo,gc,4,10,"Undo",4);
	XDrawString(dpy,new,gc,4,10,"New",4);
	XDrawString(dpy,save,gc,4,10,"Save",4);
	while(1)
	{
		XNextEvent(dpy,&event);
		switch(event.type)
		{
			case ButtonPress :
				if(event.xany.window == quit)
				{
					return 0;
				}
				else if(event.xany.window == save)
				{
					export(lines,points,lines_last,points_last);
					flag = FALSE;
				}
				else if(event.xany.window == undo)
				{
					if(event.xbutton.button == Button1)
						lines_last--;
					else
						points_last--;
					XSetForeground(dpy,gc,white);
					XFillRectangle(dpy,w,gc,0,0,WIDTH,HEIGHT); XSetForeground(dpy,gc,black);
					XDrawString(dpy,quit,gc,4,10,"Exit",4);
					XDrawString(dpy,undo,gc,4,10,"Undo",4);
					XDrawString(dpy,new,gc,4,10,"New",4);
					XDrawString(dpy,save,gc,4,10,"Save",4);
					for(i=0;i<POINT_X_MAX;i++)
						for(j=0;j<POINT_Y_MAX;j++)
							XDrawPoint(dpy,w,gc,POINT_LENGTH*i,POINT_LENGTH*j);
					for(i=0;i<lines_last;i++)
						XDrawArrow(dpy,w,gc,lines[i]);
					for(i=0;i<points_last;i++)
						XDrawArc(dpy,w,gc,points[i].x-2,points[i].y-2,4,4,0,64*360);
					flag = FALSE;
				}
				else if(event.xany.window == new)
				{
					lines_last = 0;
					points_last = 0;
					XSetForeground(dpy,gc,white);
					XFillRectangle(dpy,w,gc,0,0,WIDTH,HEIGHT);
					XSetForeground(dpy,gc,black);
					XDrawString(dpy,quit,gc,4,10,"Exit",4);
					XDrawString(dpy,undo,gc,4,10,"Undo",4);
					XDrawString(dpy,new,gc,4,10,"New",4);
					XDrawString(dpy,save,gc,4,10,"Save",4);
					for(i=0;i<POINT_X_MAX;i++)
						for(j=0;j<POINT_Y_MAX;j++)
							XDrawPoint(dpy,w,gc,POINT_LENGTH*i,POINT_LENGTH*j);
					flag = FALSE;
				}
				else if(event.xbutton.button == Button3)
				{
					if(event.xbutton.x%POINT_LENGTH>POINT_LENGTH/2)
						points[points_last].x = (event.xbutton.x-event.xbutton.x%POINT_LENGTH)+POINT_LENGTH;
					else
						points[points_last].x = event.xbutton.x-event.xbutton.x%POINT_LENGTH;
					if(event.xbutton.y%POINT_LENGTH>POINT_LENGTH/2)
						points[points_last].y = (event.xbutton.y-event.xbutton.y%POINT_LENGTH)+POINT_LENGTH;
					else
						points[points_last].y = event.xbutton.y-event.xbutton.y%POINT_LENGTH;
					XDrawArc(dpy,w,gc,points[points_last].x-2,points[points_last].y-2,4,4,0,64*360);
					flag = FALSE;
					points_last++;
				}
				else
				{
					if(event.xbutton.x%POINT_LENGTH>POINT_LENGTH/2)
						tmp.p1.x = (event.xbutton.x-event.xbutton.x%POINT_LENGTH)+POINT_LENGTH;
					else
						tmp.p1.x = event.xbutton.x-event.xbutton.x%POINT_LENGTH;
					if(event.xbutton.y%POINT_LENGTH>POINT_LENGTH/2)
						tmp.p1.y = (event.xbutton.y-event.xbutton.y%POINT_LENGTH)+POINT_LENGTH;
					else
					tmp.p1.y = event.xbutton.y-event.xbutton.y%POINT_LENGTH;
					XFillRectangle(dpy,w,gc,tmp.p1.x-2,tmp.p1.y-2,4,4);
					flag = TRUE;
				}	
				break;
			case ButtonRelease:

				if(event.xbutton.x%POINT_LENGTH>POINT_LENGTH/2)
					tmp.p2.x = (event.xbutton.x-event.xbutton.x%POINT_LENGTH)+POINT_LENGTH;
				else
					tmp.p2.x = event.xbutton.x-event.xbutton.x%POINT_LENGTH;
				if(event.xbutton.y%POINT_LENGTH>POINT_LENGTH/2)
					tmp.p2.y = (event.xbutton.y-event.xbutton.y%POINT_LENGTH)+POINT_LENGTH;
				else
					tmp.p2.y = event.xbutton.y-event.xbutton.y%POINT_LENGTH;

				if(tmp.p1.x == tmp.p2.x && tmp.p1.y == tmp.p2.y)
					flag = FALSE;

				if(flag){
					lines[lines_last] = tmp;
					lines_last++;
				}
					XSetForeground(dpy,gc,white);
					XFillRectangle(dpy,w,gc,0,0,WIDTH,HEIGHT);
					XSetForeground(dpy,gc,black);
					XDrawString(dpy,quit,gc,4,10,"Exit",4);
					XDrawString(dpy,undo,gc,4,10,"Undo",4);
					XDrawString(dpy,new,gc,4,10,"New",4);
					XDrawString(dpy,save,gc,4,10,"Save",4);
					for(i=0;i<POINT_X_MAX;i++)
						for(j=0;j<POINT_Y_MAX;j++)
							XDrawPoint(dpy,w,gc,POINT_LENGTH*i,POINT_LENGTH*j);
					for(i=0;i<lines_last;i++)
						XDrawArrow(dpy,w,gc,lines[i]);
					for(i=0;i<points_last;i++)
						XDrawArc(dpy,w,gc,points[i].x-2,points[i].y-2,4,4,0,64*360);
					flag = FALSE;
				break;
		}
	}
}
void export(const XLine lines[],const XPoint points[],const int lines_last,const int points_last)
{
	FILE *fp;
	int i;
	fp = fopen("data.txt","w");
	for(i=0;i<lines_last;i++)
		fprintf(fp,"road,%d,%d,%d,%d\n",lines[i].p1.x,lines[i].p1.y,lines[i].p2.x,lines[i].p2.y);
	for(i=0;i<points_last;i++)
		fprintf(fp,"signal,%d,%d\n",points[i].x,points[i].y);
	fclose(fp);
}
void XDrawArrow(Display* dpy,Window w,GC gc,XLine l)
{
	double ang;
	XPoint p,q;
	XPoint p2,q2;
	p.x=10*cos(PI*5/6);
	p.y=10*sin(PI*5/6);
	q.x=10*cos(PI*7/6);
	q.y=10*cos(PI*7/6);
	ang=atan2((l.p2.y-l.p1.y),(l.p2.x-l.p1.x));
	p2.x=p.x*cos(ang)-p.y*sin(ang);
	p2.y=p.x*sin(ang)+p.y*cos(ang);
	q2.x=q.x*cos(ang)-q.y*sin(ang);
	q2.y=q.x*sin(ang)+q.y*cos(ang);
	p2.x+=l.p2.x;
	p2.y+=l.p2.y;
	q2.x+=l.p2.x;
	q2.y+=l.p2.y;
	XDrawLine(dpy,w,gc, l.p1.x , l.p1.y , l.p2.x , l.p2.y );
	XDrawLine(dpy,w,gc,p2.x,p2.y,l.p2.x,l.p2.y);
	XDrawLine(dpy,w,gc,q2.x,q2.y,l.p2.x,l.p2.y);
}
