

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>



#define TRUE 1
#define FALSE 0

void scene(void);
void buttons(unsigned char key,int x,int y);
void resize(int w,int h);                                                        //screen window rescaled, snap back

int format24hrs;

struct {
		int _24hrs;
		int showDate;
		int showDay;
	} options = { FALSE, FALSE, FALSE};

int main(int argc, char* argv [])
{
	format24hrs = 0;
	
	
	
	
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(256,130);
	glutCreateWindow("SaberKat's Klock!");
	glutKeyboardFunc(buttons);
	glutReshapeFunc(resize);
	glutDisplayFunc(scene);
	glutMainLoop();
	
	return 0;	



	
}

void scene()
{
	
	int h, m, s, i, year;
	char hours[3];
	char secs[3];
	char mins[3];
	//c = '8';
	
	time_t now;
	time(&now);
	
	struct tm *local = localtime(&now);
	
	h = local -> tm_hour;
	m = local -> tm_min;
	s = local -> tm_sec;
	year = local -> tm_year;
	
	sprintf(hours, "%d", h);
	sprintf(mins, "%d", m);
	sprintf(secs, "%d", s);
	//printf("%d\n", year + 1900);
	
	i=0;
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0,0,1);

	glRasterPos2f(-0.3, 0.0);
	
	//---------------------------hours-----------------------------
	if (options._24hrs == FALSE)
	{
		if (h < 10)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, hours[0]);
		}
	
		else {
			for (i=0; i<3; i++){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, hours[i]);
			}
		}	
	}
	
	else if (options._24hrs == TRUE)
	{
		if (h > 12)
		{
			h = h -12;
			sprintf(hours, "%d", h);
		}
		
		
		if (h < 10)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, hours[0]);
		}
	
		else {
			for (i=0; i<3; i++){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, hours[i]);
			}
		}	
	}
	
	
	
	
	
	
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ':');
	
	
	//-----------------------------minutes-----------------------------
	
	if (m < 10)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mins[0]);
	}
	
	else {
		for (i=0; i<3; i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mins[i]);
		}
	}
	
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ':');
	
	//---------------------------seconds----------------------------
	
	if (s < 10)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, secs[0]);
	}
	
	else {
		for (i=0; i<3; i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, secs[i]);
		}
	}
	
	
	//--------------------------date--------------------------------
	
	
	int d, wd, y, mo;
		
	char cyear[5];
	char day[3];
	char month[3];
	char wday[4];
	
	d = local -> tm_mday;
	mo = local -> tm_mon;
	wd = local -> tm_wday;
	y = local -> tm_year;
	
	sprintf(cyear, "%d", y + 1900);
	sprintf(month, "%d", mo + 1);
	sprintf(day, "%d", d);
	
	//sprintf(wday, "%d", d);
	
	
	if (options.showDate == TRUE)
	{
		glRasterPos2f(-0.4, 0.5);
		//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
	
		if (mo < 10)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, month[0]);
		}
	
		else {
			for (i=0; i<3; i++){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, month[i]);
			}
		}
	
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '/');
	
		if (d < 10)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, day[0]);
		}
	
		else {
			for (i=0; i<3; i++){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, day[i]);
			}
		}
	
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '/');
	
		if (y < 10)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, cyear[0]);
		}
	
		else {
			for (i=0; i<5; i++){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, cyear[i]);
			}	
		}
	}
	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '/');
	
	switch (wd){
		case 0:
			sprintf(wday, "SUN");
		break;
		case 1:
			sprintf(wday, "MON");
		break;
		case 2:
			sprintf(wday, "TUE");
		break;
		case 3:
			sprintf(wday, "WED");
		break;
		case 4:
			sprintf(wday, "THU");
		break;
		case 5:
			sprintf(wday, "FRI");
		break;
		case 6:
			sprintf(wday, "SAT");
		break;
			
	}
	
	if (options.showDay == TRUE)
	{
		glRasterPos2f(-0.2, -0.5);
		//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
	
		
			for (i=0; i<4; i++){
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, wday[i]);
			}
		
	}
	
	
	//-----------------------------------------------------
	glutPostRedisplay();
	glutSwapBuffers();
	
	
}


//---------so how about if we add some extra functions?

void buttons(unsigned char key,int x,int y)
{
 if(key=='q'){ exit(0);} 	
 if(key=='f'){ if (options._24hrs == 0) options._24hrs = 1;
 				else {options._24hrs = 0;} } 
 if(key=='d'){ if (options.showDate == 0) options.showDate = 1;
 				else {options.showDate = 0;} }
 if(key=='w'){ if (options.showDay == 0) options.showDay = 1;
 				else {options.showDay = 0;}}
 glutPostRedisplay();
}//-----------------------------------------------------------------------------


void resize(int w,int h)                                                        //screen window rescaled, snap back
{
 glutReshapeWindow(256,130);
}
