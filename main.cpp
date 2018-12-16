#include<windows.h>
#include <GL/glut.h>
#include <cmath>
#include<iostream>
#include<stdlib.h>
using namespace std;
float control_x=10.0;
float control_y=80.0,s=45,f=-45,left_hand_angle=-78.75,right_hand_angle=33.75;
int cnt=0,pos=0,boat_pos=0,end_boat=1,building_light=0;;
int test=0,flag=0,flag_hand=0;
int light=1;
double rope_control=62.0;
int color_cnt=0;
void DrawHead( float inner, float outer, unsigned int pts )
{
    glBegin( GL_QUAD_STRIP );
    for( unsigned int i = 0; i <= pts; ++i )
    {
        float angle = ( i / (float)pts ) * 3.14159f * 2.0f;
        glVertex2f( inner * cos( angle ), inner * sin( angle ));
        glVertex2f( outer * cos( angle ), outer * sin( angle ));

    }
    glEnd();
}
void DrawBody()
{
    glBegin(GL_QUADS);
    glVertex2f( 9, 65 );
    glVertex2f( 9, 75);
    glVertex2f( 11, 75);
    glVertex2f( 11, 65);
    glEnd();
}
void DrawLeftupper_leg()
{
    glBegin(GL_QUADS);
    glVertex2f( 0, 0 );
    glVertex2f( 0,5 );
    glVertex2f( 1, 5);
    glVertex2f( 1, 0);
    glEnd();

}
void Drawleftlower_leg()
{
    glBegin(GL_QUADS);
    glVertex2f( 0, 0 );
    glVertex2f( 0,15 );
    glVertex2f( 1, 15);
    glVertex2f( 1, 0);
    glEnd();
}
void Drawrightupper_leg()
{
    glBegin(GL_QUADS);
    glVertex2f( 0, 0 );
    glVertex2f( 0,5 );
    glVertex2f( 1, 5);
    glVertex2f( 1, 0);
    glEnd();

}
void Drawrightlower_leg()
{
    glBegin(GL_QUADS);
    glVertex2f( 0, 0 );
    glVertex2f( 0,14 );
    glVertex2f( 1, 14);
    glVertex2f( 1, 0);
    glEnd();
}
void Drawlefthand()
{
    glBegin(GL_QUADS);
    glVertex2f( 0, 0 );
    glVertex2f( 0,9 );
    glVertex2f( 1, 9);
    glVertex2f( 1, 0);
    glEnd();
}
void Drawrighthand()
{
    glBegin(GL_QUADS);
    glVertex2f( 0, 0 );
    glVertex2f( 0,9 );
    glVertex2f( 1, 9);
    glVertex2f( 1, 0);
    glEnd();
}
void Drawlowerhand()
{
    glBegin(GL_QUADS);
    glVertex2f( 0, 0 );
    glVertex2f( 0,7);
    glVertex2f( 1, 7);
    glVertex2f( 1, 0);
    glEnd();
}
void Drawboat()
{
    glBegin(GL_QUADS);
    glVertex2f( 10, 0 );
    glVertex2f( 0,7);
    glVertex2f( 29, 7);
    glVertex2f( 20, 0);
    glEnd();
}
void motor()
{
    glColor3ub( 178, 164, 129 );
    glBegin(GL_QUADS);
    glVertex2f( 0, 0 );
    glVertex2f( 0, 50);
    glVertex2f( 40, 50);
    glVertex2f( 40, 0);
    glEnd();
}
void arrow_left()
{
    glScaled(.8,.8,0);
    if(light%3==1)
    {
        glColor3ub( 13,255,38);
    }

    else glColor3ub( 255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(4, 0);
    glVertex2f(4,15);
    glVertex2f(14, 15);
    glVertex2f(14, 0);
    glEnd();

    glTranslatef(9,25,0);
    glRotatef(225,0,0,1);
    glBegin(GL_TRIANGLES);
//   glColor3ub( 13,255,38);
    glVertex3f(0, 0, 0);
    glVertex3f(15, 0, 0);
    glVertex3f(0, 15, 0);
    glEnd();
}
void arrow_right()
{
    glScaled(.8,.8,0);
    if(light%3==2)
        glColor3ub( 13,255,38);
    else glColor3ub( 255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(6, 10.5);
    glVertex2f(6,25.5);
    glVertex2f(16, 25.5);
    glVertex2f(16, 10.5);
    glEnd();
    glTranslatef(11,0,0);
    glRotatef(45,0,0,1);
    glBegin(GL_TRIANGLES);
    glVertex3f(0, 0, 0);
    glVertex3f(15, 0, 0);
    glVertex3f(0, 15, 0);
    glEnd();
}
void ship()
{

    glScaled(3,3,0);
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(3.5,5.5);
    glVertex2f(3.5,8.5);
    glVertex2f(19.5,8.5);
    glVertex2f(19.5,5.5);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1,5.5);
    glVertex2f(4,1);
    glVertex2f(19,1);
    glVertex2f(21.5,5.5);
    glEnd();
    glColor3f(0.7,0.4,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(4,5.5);
    glVertex2f(4,8);
    glVertex2f(5,8);
    glVertex2f(5,5.5);
    glEnd();
    glColor3f(0.9,0.9,0.9);
    glBegin(GL_POLYGON);
    glVertex2f(7,7.5);
    glVertex2f(7,8);
    glVertex2f(10,8);
    glVertex2f(10,7.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(11.5,7.5);
    glVertex2f(11.5,8);
    glVertex2f(15,8);
    glVertex2f(15,7.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(16,7.5);
    glVertex2f(16,8);
    glVertex2f(19,8);
    glVertex2f(19,7.5);
    glEnd();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(4.5,8.5);
    glVertex2f(4.5,10);
    glVertex2f(18.5,10);
    glVertex2f(18.5,8.5);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(5.5,10);
    glVertex2f(5.5,12.9);
    glVertex2f(7,12.9);
    glVertex2f(7,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(5.5,12.9);
    glVertex2f(5.5,13.5);
    glVertex2f(7,13.5);
    glVertex2f(7,12.9);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(8.5,10);
    glVertex2f(8.5,12.9);
    glVertex2f(10,12.9);
    glVertex2f(10,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(8.5,12.9);
    glVertex2f(8.5,13.5);
    glVertex2f(10,13.5);
    glVertex2f(10,12.9);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(11.5,10);
    glVertex2f(11.5,12.9);
    glVertex2f(13,12.9);
    glVertex2f(13,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(11.5,12.9);
    glVertex2f(11.5,13.5);
    glVertex2f(13,13.5);
    glVertex2f(13,12.9);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(14.5,10);
    glVertex2f(14.5,12.9);
    glVertex2f(16,12.9);
    glVertex2f(16,10);
    glEnd();
    glColor3f(0.9,0.5,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(14.5,12.9);
    glVertex2f(14.5,13.5);
    glVertex2f(16,13.5);
    glVertex2f(16,12.9);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(1.5,5.5);
    glVertex2f(1.5,6.5);
    glVertex2f(2,6.2);
    glVertex2f(3,6.2);
    glVertex2f(3.5,6.5);
    glVertex2f(3.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(3.5,5.5);
    glVertex2f(3.5,6.5);
    glVertex2f(4,6.2);
    glVertex2f(5,6.2);
    glVertex2f(5.5,6.5);
    glVertex2f(5.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.5,5.5);
    glVertex2f(5.5,6.5);
    glVertex2f(6,6.2);
    glVertex2f(7,6.2);
    glVertex2f(7.5,6.5);
    glVertex2f(7.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(7.5,5.5);
    glVertex2f(7.5,6.5);
    glVertex2f(8,6.2);
    glVertex2f(9,6.2);
    glVertex2f(9.5,6.5);
    glVertex2f(9.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(9.5,5.5);
    glVertex2f(9.5,6.5);
    glVertex2f(10,6.2);
    glVertex2f(11,6.2);
    glVertex2f(11.5,6.5);
    glVertex2f(11.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(11.5,5.5);
    glVertex2f(11.5,6.5);
    glVertex2f(12,6.2);
    glVertex2f(13,6.2);
    glVertex2f(13.5,6.5);
    glVertex2f(13.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(13.5,5.5);
    glVertex2f(13.5,6.5);
    glVertex2f(14,6.2);
    glVertex2f(15,6.2);
    glVertex2f(15.5,6.5);
    glVertex2f(15.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(15.5,5.5);
    glVertex2f(15.5,6.5);
    glVertex2f(16,6.2);
    glVertex2f(17,6.2);
    glVertex2f(17.5,6.5);
    glVertex2f(17.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(17.5,5.5);
    glVertex2f(17.5,6.5);
    glVertex2f(18,6.2);
    glVertex2f(19,6.2);
    glVertex2f(19.5,6.5);
    glVertex2f(19.5,5.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(19.5,5.5);
    glVertex2f(19.5,6.5);
    glVertex2f(20,6.2);
    glVertex2f(20.5,6.2);
    glVertex2f(21,6.5);
    glVertex2f(21,5.5);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(4.5,3.5);
    glVertex2f(4.5,4.5);
    glVertex2f(5.5,4.5);
    glVertex2f(5.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(7,3.5);
    glVertex2f(7,4.5);
    glVertex2f(8,4.5);
    glVertex2f(8,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(9.5,3.5);
    glVertex2f(9.5,4.5);
    glVertex2f(10.5,4.5);
    glVertex2f(10.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(12,3.5);
    glVertex2f(12,4.5);
    glVertex2f(13,4.5);
    glVertex2f(13,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(14.5,3.5);
    glVertex2f(14.5,4.5);
    glVertex2f(15.5,4.5);
    glVertex2f(15.5,3.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(17,3.5);
    glVertex2f(17,4.5);
    glVertex2f(18,4.5);
    glVertex2f(18,3.5);
    glEnd();
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(5,10);
    glVertex2f(5,11);
    glVertex2f(5.5,10.8);
    glVertex2f(6.5,10.8);
    glVertex2f(7,11);
    glVertex2f(7,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(7,10);
    glVertex2f(7,11);
    glVertex2f(7.5,10.8);
    glVertex2f(8.5,10.8);
    glVertex2f(9,11);
    glVertex2f(9,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(9,10);
    glVertex2f(9,11);
    glVertex2f(9.5,10.8);
    glVertex2f(10.5,10.8);
    glVertex2f(11,11);
    glVertex2f(11,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(11,10);
    glVertex2f(11,11);
    glVertex2f(11.5,10.8);
    glVertex2f(12.5,10.8);
    glVertex2f(13,11);
    glVertex2f(13,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(13,10);
    glVertex2f(13,11);
    glVertex2f(13.5,10.8);
    glVertex2f(14.5,10.8);
    glVertex2f(15,11);
    glVertex2f(15,10);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(15,10);
    glVertex2f(15,11);
    glVertex2f(15.5,10.8);
    glVertex2f(16.5,10.8);
    glVertex2f(17,11);
    glVertex2f(17,10);
    glEnd();
}
void draw_wheel_1()
{
    int iTimeElapsed = glutGet(GLUT_ELAPSED_TIME);
    float fRevolveScale1,fRevolveScale2 ;
    if(control_x==10)
    {
        if(light%3==1)fRevolveScale1 = -0.2f;
        else if(light%3==2) fRevolveScale1 = 0.2f;
        fRevolveScale2 = 0.4f;

    }
    else fRevolveScale1 = 0.0f,fRevolveScale2 = 0.0f;
    long i;

    // clear all pixels
    //  glClear(GL_COLOR_BUFFER_BIT);
    // push temp state
    glPushMatrix();

    // translate to center
    glTranslatef(99.5f, 80.0f, 0.0);

    // rotate around pivot
    glRotatef(iTimeElapsed * fRevolveScale1,0.0,0.0,1.0);

    glTranslatef(0.0, 0.0, 0.0);///not important for me

    glRotatef(iTimeElapsed * fRevolveScale2,0.0,0.0,1.0); ///not important for me

    glColor3f(0.0f, 0.0f, 0.0f);

    DrawHead(1,15,100);
    // five bolts, step 72 degree (72*5=360 degree)
    glColor3f(0.0, 1.0, 1.0);
    for(i=0; i<5; ++i)
    {
        glPushMatrix();
        glRotatef(72.0f*i,0.0,0.0,1.0); // rotate coordinate 72 degree
        glTranslatef(6.0f, 0.0, 0.0);// translate on the rotated coordinate
        glutSolidSphere(1.0f, 20, 20);
        glPopMatrix();
    }

    glTranslatef(0.0f, 0.0f, 0.0f);// translate on the rotated coordinate
    glutSolidSphere(1.0f, 20, 20);

    // pop temp state
    glPopMatrix();
    // glutSwapBuffers();
//    glutPostRedisplay();

}
void draw_wheel_2()
{
    int iTimeElapsed = glutGet(GLUT_ELAPSED_TIME);
    float fRevolveScale1,fRevolveScale2;
    if(control_x==10.0)
    {
        if(light%3==1)fRevolveScale1 = -0.2f;
        else if(light%3==2) fRevolveScale1 = 0.2f;
        fRevolveScale2 = 0.4f;

    }
    else fRevolveScale1 = 0.0f,fRevolveScale2 = 0.0f;
    long i;

    // clear all pixels
    //  glClear(GL_COLOR_BUFFER_BIT);
    // push temp state

    glPushMatrix();

    // translate to center
    glTranslatef(181.0f, 180.0f, 0.0);

    // rotate around pivot
    glRotatef(iTimeElapsed * fRevolveScale1,0.0,0.0,1.0);

    glTranslatef(0.0, 0.0, 0.0);///not important for me

    glRotatef(iTimeElapsed * fRevolveScale2,0.0,0.0,1.0); ///not important for me

    glColor3f(0.0f, 0.0f, 0.0f);

    DrawHead(1,10,100);
    // five bolts, step 72 degree (72*5=360 degree)
    glColor3f(0.0, 1.0, 1.0);
    for(i=0; i<5; ++i)
    {
        glPushMatrix();
        glRotatef(72.0f*i,0.0,0.0,1.0); // rotate coordinate 72 degree
        glTranslatef(4.0f, 0.0, 0.0);// translate on the rotated coordinate
        glutSolidSphere(1.0f, 20, 20);
        glPopMatrix();
    }
    glTranslatef(0.0f, 0.0f, 0.0f);// translate on the rotated coordinate
    glutSolidSphere(1.0f, 20, 20);

    glPopMatrix();

}
void magnet()
{
    glPushMatrix();
    glTranslatef(165.0,73.5,0);
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,5);
    glVertex2f(32,5);
    glVertex2f(32,0);
    glEnd();
    glTranslatef(14.0,30.0,0);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,5);
    glVertex2f(4,5);
    glVertex2f(4,0);
    glEnd();
    glRotatef(-29,0,0,1);
    glTranslatef(0,-30,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex3f(0,1,0);
    glVertex3f(0,30,0);
    glEnd();
    glRotatef(58,0,0,1);
    glTranslatef(29,-16,0);
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex3f(0,1,0);
    glVertex3f(0,30,0);
    glEnd();
    glPopMatrix();
}
void another_rope()
{
    cnt++;
    glPushMatrix();
    if(control_x==10.0)
    {
        if(cnt%2)
        {

            for(int i=1,j=0; i<=104; i++,j++)
            {
                glPushMatrix();
                glTranslatef(106,94,0);
                glRotatef(-39,0,0,1);
                if(i%2==0)
                    glColor3ub(248,255,203);
                else  glColor3ub(239,203,255);
                glBegin(GL_POLYGON);
                glVertex2f(0,j);
                glVertex2f(0,j+2);
                glVertex2f(4,j+2);
                glVertex2f(4,j);
                glEnd();
                glPopMatrix();
            }

        }
        else
        {

            for(int i=1,j=0; i<=104; i++,j++)
            {
                glPushMatrix();
                glTranslatef(106,94,0);
                glRotatef(-39,0,0,1);
                if(i%2)
                    glColor3ub(248,255,203);
                else  glColor3ub(239,203,255);
                glBegin(GL_POLYGON);
                glVertex2f(0,j);
                glVertex2f(0,j+2);
                glVertex2f(4,j+2);
                glVertex2f(4,j);
                glEnd();
                glPopMatrix();
            }


        }
    }
    else

    {
        for(int i=1,j=0; i<=104; i++,j++)
        {
            glPushMatrix();
            glTranslatef(106,94,0);
            glRotatef(-39,0,0,1);
            if(i%2)
                glColor3ub(239,203,255);
            else glColor3ub(248,255,203);
            glBegin(GL_POLYGON);
            glVertex2f(0,j);
            glVertex2f(0,j+2);
            glVertex2f(4,j+2);
            glVertex2f(4,j);
            glEnd();
            glPopMatrix();
        }
    }

    glPopMatrix();
//glutPostRedisplay();
}
void drawSmile()
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(-.5,1);
    glVertex2f(0,0);
    glVertex2f(2,0);
    glVertex2f(2.5,1.5);
    glVertex2f(2,.5);
    glVertex2f(0,.5);
    glEnd();


}
void building ()
{
     glColor3f(.8, .8, 1);
    glBegin (GL_POLYGON);
    glVertex3d(590,480,0);
    glVertex3d(320,480,0);
    glVertex3d(320,60,0);
    glVertex3d(590,60,0);
    glEnd();
    if(building_light==0)
    glColor3f(0, 0, 0);
    else glColor3f(.92, .89, 0);
    glRectf(570.0,460.0,500.0,350.0);
    glRectf(570.0,340.0,500.0,230.0);
    glRectf(570.0, 220.0, 500.0, 110.0);

}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    draw_wheel_1();
    draw_wheel_2();
    glPushMatrix();
    glTranslatef(179,108.5,0);
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(0,0+rope_control);
    glVertex2f(0,62);
    glVertex2f(4,62);
    glVertex2f(4,0+rope_control);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0+rope_control,0);
    magnet();
    glPopMatrix();

    ///another rope

    /// main platform
    glPushMatrix();
    glColor3ub( 0, 0, 0 );
    glBegin(GL_QUADS);
    glVertex2f( 0, 0 );
    glVertex2f( 0, 50);
    glVertex2f( 150, 50);
    glVertex2f( 150, 0);
    glEnd();
    glColor3f( .04, .9, .78 );
    glBegin(GL_QUADS);
    glVertex2f( 3, 3 );
    glVertex2f( 3, 47);
    glVertex2f( 147, 47);
    glVertex2f( 147, 3);
    glEnd();

    ///water
    glColor3f( 0.25, 0.64, 0.87 );
    glBegin(GL_QUADS);
    glVertex2f( 150, 0 );
    glVertex2f( 150, 43);
    glVertex2f( 290, 43);
    glVertex2f( 290, 0);
    glEnd();


    /// other platform

    glColor3ub( 0, 0, 0 );
    glBegin(GL_QUADS);
    glVertex2f( 290, 0 );
    glVertex2f( 290, 50);
    glVertex2f( 400, 50);
    glVertex2f( 400, 0);
    glEnd();
    glColor3f( .04, .9, .78 );
    glBegin(GL_QUADS);
    glVertex2f( 293, 3 );
    glVertex2f( 293, 47);
    glVertex2f( 397, 47);
    glVertex2f( 397, 3);
    glEnd();

    glPopMatrix();
    ///motor
    glPushMatrix();
    glTranslatef(30,50,0);

    motor();
    glPopMatrix();

    ///arrow left
    glPushMatrix();
    glTranslatef(34,65,0);
    arrow_left();
    glPopMatrix();
    ///arrow right
    glPushMatrix();
    glTranslatef(50,65,0);
    arrow_right();
    glPopMatrix();
    ///boat
    glPushMatrix();
    // glColor3ub( 0, 0, 0 );
    //if(light%3==2)
    glTranslatef(149+pos,33+(rope_control*end_boat),0);

    // else if(pos==0)glTranslatef(149+pos,95,0);
    //  glTranslatef(149+pos,33,0);
    ship();
    glPopMatrix();

    ///positioning of head
    glPushMatrix();
    glColor3ub( 0, 0, 0 );
    glTranslatef(control_x,control_y,0);
    DrawHead( 4, 5, 100 );
    glPopMatrix();
    ///positioning of body
//    glPushMatrix();
//    glTranslatef((control_x-10)*test,(control_y-80)*test,0);
//    DrawBody();
//    glPopMatrix();
    ///positioning of left upper leg
    glPushMatrix();
    if(s==45)
        glTranslatef(control_x+3,control_y-19,0);
    else if(s==33.75)
        glTranslatef(control_x+2,control_y-19,0);
    else if(s==22.5)
        glTranslatef(control_x+1.5,control_y-19.5,0);
    else   glTranslatef(control_x+.5,control_y-19.5,0);
    glRotatef(s, 0.0, 0.0, 1.0);
    DrawLeftupper_leg();
    glPopMatrix();

    ///positioning of left lower leg
    glPushMatrix();
    if(s==45)
        glTranslatef(control_x-3.5,control_y-32,0);
    else if(s==33.75)
        glTranslatef(control_x-4.5,control_y-31,0);
    else if(s==22.5)
        glTranslatef(control_x-6.5,control_y-31,0);
    else glTranslatef(control_x-8.5,control_y-30,0);
    glRotatef(f/2, 0.0, 0.0, 1.0);
    Drawleftlower_leg();
    glPopMatrix();
    ///positioning of right upper leg
    glPushMatrix();
    if(s==11.25)
        glTranslatef(control_x+3.5,control_y-19,0);
    else if(s==22.5)
        glTranslatef(control_x+3.5,control_y-19,0);
    else if(s==33.75)
        glTranslatef(control_x+4,control_y-19,0);
    else glTranslatef(-2,0,0);
    glRotatef(s+20, 0.0, 0.0, 1.0);
    Drawrightupper_leg();
    glPopMatrix();
    ///positioning of right lower leg
    glPushMatrix();
    if(s==11.25)
        glTranslatef(control_x+3.5,control_y-32,0);
    else if(s==22.5)
        glTranslatef(control_x+2,control_y-32,0);
    else if(s==33.75)
        glTranslatef(control_x+1.5,control_y-32,0);
    else  glTranslatef(-2,0,0);
    glRotatef(-s/2+5, 0.0, 0.0, 1.0);
    Drawrightlower_leg();
    glPopMatrix();

    /// positioning of left hand
    glPushMatrix();
    if(left_hand_angle==-45)glTranslatef(control_x-4,control_y-14,0);
    else if(left_hand_angle==-56.25)glTranslatef(control_x-5,control_y-14,0);
    else if(left_hand_angle==-67.5)glTranslatef(control_x-5,control_y-13,0);
    else if(left_hand_angle==-78.75) glTranslatef(control_x-6,control_y-13,0);
    else if(left_hand_angle==-33.75) glTranslatef(control_x-3,control_y-15,0);
    else if(left_hand_angle==-22.5) glTranslatef(control_x-2,control_y-14.5,0);
    else if(left_hand_angle==-11.25) glTranslatef(control_x-1,control_y-14.5,0);
    else if(left_hand_angle==0) glTranslatef(control_x,control_y-15,0);
    else if(left_hand_angle==11.25)glTranslatef(control_x,control_y-15,0);
    else if(left_hand_angle==22.5)glTranslatef(control_x+1,control_y-15,0);
    else if(left_hand_angle==33.75) glTranslatef(control_x+2,control_y-15,0);
    glRotatef(left_hand_angle/2, 0.0, 0.0, 1.0);
    Drawlefthand();
    glPopMatrix();
    glPushMatrix();
    if(left_hand_angle==-45)glTranslatef(control_x-2.5,control_y-19.5,0);
    else if(left_hand_angle==-56.25)glTranslatef(control_x-5,control_y-20,0);
    else if(left_hand_angle==-67.5)glTranslatef(control_x-6.5,control_y-19,0);
    else if(left_hand_angle==-78.75) glTranslatef(control_x-8.5,control_y-18.5,0);
    else if(left_hand_angle==-33.75) glTranslatef(control_x-.5,control_y-20.5,0);
    else if(left_hand_angle==-22.5) glTranslatef(control_x+1.5,control_y-20.5,0);
    else if(left_hand_angle==-11.25) glTranslatef(control_x+3.5,control_y-20,0);
    else if(left_hand_angle==0) glTranslatef(control_x+5.5,control_y-18.5,0);
    else if(left_hand_angle==11.25) glTranslatef(control_x+4.5,control_y-19,0);
    else if(left_hand_angle==22.5) glTranslatef(control_x+4,control_y-19.5,0);
    else if(left_hand_angle==33.75) glTranslatef(control_x+4,control_y-19.5,0);
    if(left_hand_angle==11.25)
        glRotatef(-11.25+90/2+10, 0.0, 0.0, 1.0);
    else if(left_hand_angle==22.5)
        glRotatef(-22.5+90/2+10, 0.0, 0.0, 1.0);
    else if(left_hand_angle==33.75)
        glRotatef(-33.75+90/2+10, 0.0, 0.0, 1.0);
    else glRotatef(left_hand_angle+90/2+10,0,0,1);
    Drawlowerhand();
    glPopMatrix();

    /// positioning of right hand
    glPushMatrix();
    if(right_hand_angle==-45)glTranslatef(control_x-4,control_y-14,0);
    else if(right_hand_angle==-56.25)glTranslatef(control_x-5,control_y-14,0);
    else if(right_hand_angle==-67.5)glTranslatef(control_x-5,control_y-13,0);
    else if(right_hand_angle==-78.75) glTranslatef(control_x-6,control_y-13,0);
    else if(right_hand_angle==-33.75) glTranslatef(control_x-3,control_y-15,0);
    else if(right_hand_angle==-22.5) glTranslatef(control_x-2,control_y-14.5,0);
    else if(right_hand_angle==-11.25) glTranslatef(control_x-1,control_y-14.5,0);
    else if(right_hand_angle==0) glTranslatef(control_x,control_y-15,0);
    else if(right_hand_angle==11.25)glTranslatef(control_x,control_y-15,0);
    else if(right_hand_angle==22.5)glTranslatef(control_x+1,control_y-15,0);
    else if(right_hand_angle==33.75) glTranslatef(control_x+2,control_y-15,0);
    glRotatef(right_hand_angle/2, 0.0, 0.0, 1.0);
    Drawlefthand();
    glPopMatrix();

    glPushMatrix();
    if(right_hand_angle==-45)glTranslatef(control_x-2.5,control_y-19.5,0);
    else if(right_hand_angle==-56.25)glTranslatef(control_x-5,control_y-20,0);
    else if(right_hand_angle==-67.5)glTranslatef(control_x-6.5,control_y-19,0);
    else if(right_hand_angle==-78.75) glTranslatef(control_x-8.5,control_y-18.5,0);
    else if(right_hand_angle==-33.75) glTranslatef(control_x-.5,control_y-20.5,0);
    else if(right_hand_angle==-22.5) glTranslatef(control_x+1.5,control_y-20.5,0);
    else if(right_hand_angle==-11.25) glTranslatef(control_x+3.5,control_y-20,0);
    else if(right_hand_angle==0) glTranslatef(control_x+5.5,control_y-18.5,0);
    else if(right_hand_angle==11.25) glTranslatef(control_x+4.5,control_y-19,0);
    else if(right_hand_angle==22.5) glTranslatef(control_x+4,control_y-19.5,0);
    else if(right_hand_angle==33.75) glTranslatef(control_x+4,control_y-19.5,0);
    if(right_hand_angle==11.25)
        glRotatef(-11.25+90/2+10, 0.0, 0.0, 1.0);
    else if(right_hand_angle==22.5)
        glRotatef(-22.5+90/2+10, 0.0, 0.0, 1.0);
    else if(right_hand_angle==33.75)
        glRotatef(-33.75+90/2+10, 0.0, 0.0, 1.0);
    else glRotatef(right_hand_angle+90/2+10,0,0,1);
    Drawlowerhand();
    glPopMatrix();
    another_rope();

    glPushMatrix();

    glTranslatef(270,38,0);
    glScalef(.2,.2,0);
    building();

    glPopMatrix();
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(377,75,0);
    DrawHead( 4, 5, 100 );
    glTranslatef(-10,-80,0);
    DrawBody();
    glTranslatef(55.5,15,0);
    glRotatef(45,0,0,1);
    DrawBody();
    glTranslatef(76,64.5,0);
    glRotatef(90,0,0,1);
    DrawBody();

    glPopMatrix();
    glPushMatrix();
  //  glScalef(2,2,0);
     glTranslatef(376,73,0);
    glColor3ub(0,0,0);
     drawSmile();
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(375,76,0);
    glutSolidSphere(.5f, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(379,76,0);
    glutSolidSphere(.5f, 20, 20);
    glPopMatrix();
    glutSwapBuffers();
}

void spe_key(int key, int x, int y)
{

    switch (key)
    {

    case GLUT_KEY_UP:

        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:
        control_x+=2.5;
        if(s==45)
            flag=1;
        if(s==11.25)
            flag=0;
        if(flag)s-=11.25,f-=11.25;
        else s+=11.25,f+=11.25;
        if(left_hand_angle==-78.75)
            flag_hand=1;
        if(left_hand_angle==33.75)
            flag_hand=0;
        if(flag_hand) left_hand_angle+=11.25,right_hand_angle-=11.25;
        else  left_hand_angle-=11.25,right_hand_angle+=11.25;
        cout<<s<<" "<<f<<" "<<left_hand_angle<<endl;
        test=1;

        glutPostRedisplay();

        break;

    case GLUT_KEY_LEFT:
        control_x-=2;

        glutPostRedisplay();

        break;
    default:
        break;
    }
}

void boat_fnc()
{
    pos+=1;
    control_x+=1;
    glutPostRedisplay();
    if(pos==76) glutIdleFunc(NULL);
    else Sleep(100);

}
void rope_animation()
{
    color_cnt+=1.0;
    if(light%3==1)
    {
        rope_control+=.5;
        glutPostRedisplay();
        if(rope_control==62)
            glutIdleFunc(NULL);
        else Sleep(50);
    }

    else if(light%3==2)
    {
        rope_control-=.5;
        glutPostRedisplay();
        if(rope_control==0)
            glutIdleFunc(NULL);
        else Sleep(50);
        //  end_boat=0;
    }
}
void my_keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 'c':
        glutIdleFunc(boat_fnc);
        break;
    case 'l':
        light++;
        cout<<light<<endl;
        glutIdleFunc(another_rope);
        glutIdleFunc(rope_animation);
        break;
    case 's':
        end_boat=0;
        break;
    case 'b':
        building_light=1;
        control_x=500;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}
void init(void)
{
    glClearColor (0.6, 0.0, 0.6, 0.0);
    double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    const double ar = w / h;
    glOrtho( 0 * ar, 200 * ar, 0, 200, -1, 1);
}
int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitWindowSize( 1200, 600 );
    glutInitWindowPosition(10,10);
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE |GLUT_DEPTH );
    glutCreateWindow( "BOAT CROSSING" );
    init();
    glutDisplayFunc( display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(my_keyboard);
    glutMainLoop();
    return 0;
}
