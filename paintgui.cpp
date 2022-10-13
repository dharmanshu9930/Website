//Instructions to run
// Run gui.exe or by ./gui
// Do not maximize the window as the code works on the basis of the window size and position of elements so by maximizing the window the elements cant be accessed properly

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define TWOPOINTLINE 0
#define RECTANGLE 1
#define POLYGON 2
#define CIRCLE 3
#define MESH 4

#define mx 800
#define my 600
#define tlbrHeight my - 80  //ToolBar
#define actbrHeight mx - 90 //ActionBar



int r = 0, b = 0, g = 0;
int tf;      // SelectTool
int cf = 0; // SelectColor
int clear = 0;
int leftrotateflag = 0;
float color[100][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}};
int meshcount = 0;

int lnpt[100][3]; //LinePoints
int sqpt[100][3]; //SquarePoints
int plpt[100][3]; //PolygonPoints
int crpt[100][3]; //CirclePoints

int lnptct = -1;
int sqptct = 0;
int plptct = -1;
int crptct = 0;
int x1, g1, x2, y2, dist;



void addlnpt(int x, int y)
{
    lnpt[lnptct][0] = x;
    lnpt[lnptct][1] = y;
    lnpt[lnptct][2] = cf;
}

void addsqpt(int x, int y)
{
    sqpt[sqptct][0] = x1;
    sqpt[sqptct][1] = g1;
    sqpt[sqptct][2] = cf;

    sqpt[sqptct + 1][0] = x;
    sqpt[sqptct + 1][1] = g1;
    sqpt[sqptct + 1][2] = cf;

    sqpt[sqptct + 2][0] = x;
    sqpt[sqptct + 2][1] = g1;
    sqpt[sqptct + 2][2] = cf;

    sqpt[sqptct + 3][0] = x;
    sqpt[sqptct + 3][1] = y;
    sqpt[sqptct + 3][2] = cf;

    sqpt[sqptct + 4][0] = x;
    sqpt[sqptct + 4][1] = y;
    sqpt[sqptct + 4][2] = cf;

    sqpt[sqptct + 5][0] = x1;
    sqpt[sqptct + 5][1] = y;
    sqpt[sqptct + 5][2] = cf;

    sqpt[sqptct + 6][0] = x1;
    sqpt[sqptct + 6][1] = y;
    sqpt[sqptct + 6][2] = cf;

    sqpt[sqptct + 7][0] = x1;
    sqpt[sqptct + 7][1] = g1;
    sqpt[sqptct + 7][2] = cf;
}

void addplpt(int x, int y)
{
    plpt[plptct][0] = x;
    plpt[plptct][1] = y;
    plpt[plptct][2] = cf;
}

void addcrpt(int x, int y)
{
    crpt[crptct][0] = x;
    crpt[crptct][1] = y;
    crpt[crptct][2] = cf;
}


void motion(int x, int y)
{
    if (x < actbrHeight && y < tlbrHeight)
    {
        
        if (tf == TWOPOINTLINE)
        {
            addlnpt(x, my - y);
            glutPostRedisplay();
        }
        else if (tf == RECTANGLE)
        {
            addsqpt(x, my - y);
            glutPostRedisplay();
        }
        else if (tf == POLYGON)
        {
            addplpt(x, my - y);
            glutPostRedisplay();
        }
        else if (tf == CIRCLE)
        {
            addcrpt(x, my - y);
            glutPostRedisplay();
        }
    }
}
void cursor(int bt, int at, int x, int y)
{
    int i;
    y = my - y;
    if (bt == GLUT_LEFT_BUTTON)
    {
        if (at == GLUT_DOWN)
        {

            if (y < my - 20 && y > my - 60)
            {
                
                if (x > 240 && x < 280)
                    tf = TWOPOINTLINE;
                if (x > 280 && x < 320)
                    tf = RECTANGLE;
                if (x > 320 && x < 360)
                    tf = POLYGON;
                if (x > 360 && x < 400)
                    tf = CIRCLE;
                if (x > 400 && x < 440)
                {
                    meshcount = (++meshcount) % 2;
                    glutPostRedisplay();
                }
                if (x > 500 && x < 570)
                {
                    clear = 1;
                }
            }

        
            if (x < mx - 20 && x > mx - 60)
            {
                if (y < 480 && y > 440)
                {
                    cf = 0;
                    r = 255;
                    g = 0;
                    b = 0;
                }
                if (y < 440 && y > 400)
                {
                    cf = 1;
                    r = 0;
                    g = 255;
                    b = 0;
                }
                if (y < 400 && y > 360)
                {
                    cf = 2;
                    r = 0;
                    g = 0;
                    b = 255;
                }
                if (y < 360 && y > 320)
                {
                    cf = 3;
                    r = 255;
                    g = 255;
                    b = 0;
                }
                if (y < 320 && y > 280)
                {
                    cf = 4;
                    r = 255;
                    g = 255;
                    b = 255;
                }
                if (y < 280 && y > 240)
                {
                    cf = 5;
                    r = 0;
                    g = 255;
                    b = 255;
                }
                
            }
            
        }
    }
  
    if (x < actbrHeight && y < tlbrHeight)
    {
        

        // line
        if (bt == GLUT_LEFT_BUTTON && at == GLUT_DOWN && tf == TWOPOINTLINE)
        {

            lnptct++;
            addlnpt(x, y);
            glutPostRedisplay();
        }

        // rectangle
        if (bt == GLUT_LEFT_BUTTON && at == GLUT_DOWN && tf == RECTANGLE)
        {
            x1 = x;
            g1 = y;
            addsqpt(x, y);
        }
        else if (bt == GLUT_LEFT_BUTTON && at == GLUT_UP && tf == RECTANGLE)
        {
            sqptct += 8;
        }

        // polygon
        if (bt == GLUT_LEFT_BUTTON && at == GLUT_DOWN && tf == POLYGON)
        {
            plptct++;
            addplpt(x, y);
        }
        if (bt == GLUT_RIGHT_BUTTON && at == GLUT_DOWN && tf == POLYGON)
        {
            if (plptct >= 0)
                plptct--;
        }

        // circle
        if (bt == GLUT_LEFT_BUTTON && at == GLUT_DOWN && tf == CIRCLE)
        {
            x1 = x;
            g1 = y;
            addcrpt(x, y);
            crptct++;
        }
        else if (bt == GLUT_LEFT_BUTTON && at == GLUT_UP && tf == CIRCLE)
        {
            crptct++;
        }
    }
}


void twopointline()
{
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2i(250, my - 50);
    glVertex2i(270, my - 30);
    glEnd();

    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2i(250, my - 50);
    glVertex2i(270, my - 30);
    glEnd();
}

void rectangle()
{
    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glVertex2i(290, my - 30);
    glVertex2i(310, my - 30);
    glVertex2i(310, tlbrHeight + 30);
    glVertex2i(290, tlbrHeight + 30);
    glEnd();
}
void polygon()
{
    glLineWidth(1.5);
    glBegin(GL_LINE_LOOP);
    glVertex2i(325, my - 40);
    glVertex2i(335, my - 30);
    glVertex2i(345, my - 30);
    glVertex2i(355, my - 40);
    glVertex2i(345, my - 50);
    glVertex2i(335, my - 50);
    glEnd();
}
void circle(int r, int x, int y)
{
    int i;
    glPointSize(1.5);
    glBegin(GL_POINTS);
    for (i = 0; i < 360; i += 5)
    {
        glVertex2i(x + r * cos(i), y + r * sin(i));
    }
    glEnd();
}

void mesh()
{
    int j, i;
    glLineWidth(1.5);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            glBegin(GL_LINE_LOOP);
            glVertex2i(410 + i * 5, my - 30 - j * 5);
            glVertex2i(410 + i * 5 + 5, my - 30 - j * 5);
            glVertex2i(410 + i * 5 + 5, my - 30 - j * 5 - 5);
            glVertex2i(410 + i * 5, my - 30 - j * 5 - 5);
            glEnd();
        }
    }
}




void toolbar()
{
    char string[] = "GUI INTERFACE";
    int i;
    glColor3ub(80,80,80);
    glBegin(GL_QUADS);
    glVertex2i(0, my);
    glVertex2i(mx, my);
    glVertex2i(mx, tlbrHeight);
    glVertex2i(0, tlbrHeight);
    glEnd();

    
    glColor3ub(0, 0, 0);
    for (i = 0; string[i] != '\0'; i++)
    {
        glRasterPos2i(30 + i * 14, tlbrHeight / 2 - 9);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
   

    glLineWidth(3.0);
    for (i = 0; i < 5; i++)
    {
        glColor3ub(0, 0, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2i(240 + i * 40, my - 20);
        glVertex2i(240 + i * 40 + 40, my - 20);
        glVertex2i(240 + i * 40 + 40, tlbrHeight + 20);
        glVertex2i(240 + i * 40, tlbrHeight + 20);
        glEnd();
    }
    

    glBegin(GL_LINE_LOOP);
    glVertex2i(500, my - 20);
    glVertex2i(570, my - 20);
    glVertex2i(570, tlbrHeight + 20);
    glVertex2i(500, tlbrHeight + 20);
    glEnd();

    char string2[] = "CLEAR";
    glColor3ub(0, 0, 0);
    for (i = 0; string2[i] != '\0'; i++)
    {
        glRasterPos2i(502 + i * 12, tlbrHeight / 2 - 9);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string2[i]);
    }

   
    twopointline();
    rectangle();
    polygon();
    circle(10, 380, my - 40);
    mesh();
}
void actionbar()
{
    float color[6][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 1.0, 0.0}, {0.0,0.0,0.0,}, {0.0, 1.0, 1.0}};
    int i;
    glColor3ub(80,80,80);
    glBegin(GL_QUADS);
    glVertex2i(actbrHeight, tlbrHeight);
    glVertex2i(mx, tlbrHeight);
    glVertex2i(mx, 0);
    glVertex2i(actbrHeight, 0);
    glEnd();


    glColor3ub(0, 0, 0);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2i(0, tlbrHeight);
    glVertex2i(actbrHeight, tlbrHeight);
    glVertex2i(actbrHeight, tlbrHeight);
    glVertex2i(actbrHeight, 0);
    glEnd();


    glLineWidth(3.0);

    for (i = 0; i < 6; i++)
    {
        glColor3ub(0, 0, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2i(actbrHeight + 20, my - 120 - i * 40);
        glVertex2i(mx - 20, my - 120 - i * 40);
        glVertex2i(mx - 20, my - 120 - i * 40 - 40);
        glVertex2i(actbrHeight + 20, my - 120 - i * 40 - 40);
        glEnd();

        glBegin(GL_QUADS);
        glColor3fv(color[i]);
        glVertex2i(actbrHeight + 20, my - 120 - i * 40);
        glVertex2i(mx - 20, my - 120 - i * 40);
        glVertex2i(mx - 20, my - 120 - i * 40 - 38);
        glVertex2i(actbrHeight + 20, my - 120 - i * 40 - 38);
        glEnd();
    }

    
}

void statusbar()
{
    glColor3ub(80,80,80);
    glBegin(GL_QUADS);
    glVertex2i(0, 30);
    glVertex2i(mx, 30);
    glVertex2i(mx, 0);
    glVertex2i(0, 0);
    glEnd();

    glColor3ub(0, 0, 0);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2i(0, 30);
    glVertex2i(mx, 30);
    glEnd();
}

void display()
{
    int i, j = 0;
    glClear(GL_COLOR_BUFFER_BIT);

    toolbar();
    actionbar();
    statusbar();


    if (meshcount)
    {
        glLineWidth(0.5);
        glBegin(GL_LINES);
        for (i = 0; i < actbrHeight; i += 40)
            for (j = 30; j < tlbrHeight; j += 40)
            {
                glVertex2i(i, 30);
                glVertex2i(i, tlbrHeight);
                glVertex2i(0, j);
                glVertex2i(actbrHeight, j);
            }
    }
    j = 0;
   
    
    i = 0;
    glPointSize(4.0);
    glBegin(GL_POINTS);
    while (i <= lnptct)
    {
        glColor3fv(color[lnpt[i][2]]);
        glVertex2i(lnpt[i][0], lnpt[i][1]);
        i++;
    }
    glEnd();

    i = 0;
    if (lnptct != 0)
    {
        glLineWidth(3.0);
        glBegin(GL_LINES);
        while (i <= lnptct)
        {
            glColor3fv(color[lnpt[i][2]]);
            glVertex2i(lnpt[i][0], lnpt[i][1]);
            ++i;
        }
    }
    glEnd();

    
    i = 0;
    glPointSize(4.0);
    glBegin(GL_POINTS);
    while (i <= sqptct)
    {
        glColor3fv(color[sqpt[i][2]]);
        glVertex2iv(sqpt[i]);
        i++;
    }
    glEnd();

    i = 0;
    glLineWidth(3.0);
    glBegin(GL_LINES);
    while (i <= sqptct + 8)
    {
        glColor3fv(color[sqpt[i][2]]);
        glVertex2iv(sqpt[i]);
        i++;
    }
    glEnd();

    i = 0;
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    while (i <= plptct)
    {
        glColor3fv(color[plpt[i][2]]);
        glVertex2i(plpt[i][0], plpt[i][1]);
        i++;
    }
    glEnd();

    i = 0;
    
    glPointSize(4.0);
    while (j <= crptct)
    {
        glColor3fv(color[crpt[j][2]]);
        if (crptct != 0)
        {
            glBegin(GL_POINTS);
            dist = sqrt((crpt[j + 1][0] - crpt[j][0]) * (crpt[j + 1][0] - crpt[j][0]) + (crpt[j + 1][1] - crpt[j][1]) * (crpt[j + 1][1] - crpt[j][1]));
            for (i = 0; i < 360; i += 1)
            {
                glVertex2i(crpt[j][0] + dist * cos(i * 3.14 / 180), crpt[j][1] + dist * sin(i * 3.14 / 180));
            }
            glEnd();
        }
        j += 2;
    }

    

    glFlush();
}

void idle()
{
    int i;
    if (clear)
    {

        for (i = 0; i < sqptct; i++)
            sqpt[i][0] = sqpt[i][1] = sqpt[i][2] = 0;
        sqptct = 0;

        for (i = 0; i < plptct; i++)
            plpt[i][0] = plpt[i][1] = plpt[i][2] = 0;
        plptct = -1;

        for (i = 0; i < crptct; i++)
            crpt[i][0] = crpt[i][1] = crpt[i][2] = 0;
        crptct = 0;

        for (i = 0; i < lnptct; i++)
            lnpt[i][0] = lnpt[i][1] = lnpt[i][2] = 0;
        lnptct = -1;
    }
    clear = 0;
    glutPostRedisplay();
}
void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, mx, 0, my);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(mx, my);
    glutCreateWindow("GUI");
    glutDisplayFunc(display);
    glutMouseFunc(cursor);
    glutMotionFunc(motion);
    glutIdleFunc(idle);
    init();
    glutMainLoop();
}