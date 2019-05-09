#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"
#include "KameHouse_main.h"

//Animación 
float movSilla = 0.0;
float rotVentana = 0.0;
float rotPuerta = 0.0;
bool g_fanimacion = false;
bool g_fanimacion1 = false;
bool flag = false;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

long int font = (long int)GLUT_BITMAP_HELVETICA_18;

char s[30];

//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

/*
GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = {22};
*/


CTexture text1;
CTexture maderaRoja;
CTexture maderaRosa;
CTexture kameLogo;
CTexture arena;
CTexture pisoMadera;
CTexture maderaB;
CTexture Refri;
CTexture refri1;
CTexture ventanita;
CTexture puerta;
CTexture grass;
CTexture sea;
CTexture sillon1;
CTexture sillon2;
CTexture closet;
CTexture escalera;
CTexture baño;
CTexture television;
CTexture television1;
CTexture alfombra;
CTexture mesa1;
CTexture mesa2;
CTexture mesa3;
CTexture cocina;
CTexture lamps;
CTexture lamps1;


CFiguras fig1;
CFiguras fig2;
CFiguras jugador;	//Para crear Monito
CFiguras figBalon;		//Para crear balon
CFiguras KHplantabaja;
CFiguras techoKH;
CFiguras CuartoKH;
CFiguras islaKH;
CFiguras piso;
CFiguras portico;
CFiguras refri;
CFiguras sillonL;
CFiguras tele;
CFiguras ventana;
CFiguras pastito;
CFiguras decoracion;
CFiguras mesa;
CFiguras silla;
CFiguras lamp;

void isla(void) 
{
	glPushMatrix();
		glTranslatef(0.0, -52.0, 0.0);
		islaKH.esfera(60.0, 50, 50, arena.GLindex);		//crea isla
	glPopMatrix();
}

void mar(void)
{
	glPushMatrix();
	glTranslatef(0.0, -3.0, 0.0);
	glScalef(150, 0.5, 150);
	glDisable(GL_LIGHTING);
	pastito.prisma2(sea.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void kameHouse(void)
{
	glPushMatrix();
	glTranslatef(0.0, 27.0, 12.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	KHplantabaja.prisma(0.5, 8, 25.5, maderaRosa.GLindex);	//crea paredes
	glPopMatrix();

	glPushMatrix();
	glTranslatef(11.2, 14.7, 12.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	KHplantabaja.prisma(0.5, 16.5, 3, maderaRosa.GLindex);	//crea paredes
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 14.7, 12.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	KHplantabaja.prisma(0.5, 16.5, 3, maderaRosa.GLindex);	//crea paredes
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9.0, 13.8, 12.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	KHplantabaja.prisma(0.5, 18.5, 7.25, maderaRosa.GLindex);	//crea paredes
	glPopMatrix(); 

	glPushMatrix();
	glTranslatef(-2.4, 10.0, 12.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	KHplantabaja.prisma(0.5, 10.0, 5.9, maderaRosa.GLindex);	//crea paredes
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 17.8, -12.5);
	glRotatef(90, 1, 0, 0);
	KHplantabaja.prisma(0.5, 25.5, 25.5, maderaRosa.GLindex);	//crea paredes
	glPopMatrix();

	glPushMatrix();
	glTranslatef(12.5, 17.8, 0);
	glRotatef(90, 0, 0, 1);
	glRotatef(90, 0, 1, 0);
	KHplantabaja.prisma(0.5, 25.5, 25.5, maderaRosa.GLindex);	//crea paredes
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.5, 18.0, 8.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	KHplantabaja.prisma(0.5, 25.5, 8.0, maderaRosa.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.5, 18.0, -8.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	KHplantabaja.prisma(0.5, 25.5, 8.0, maderaRosa.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.5, 27.0, 0.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	KHplantabaja.prisma(0.5, 8.0, 9.0, maderaRosa.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-12.5, 10.5, 0.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	KHplantabaja.prisma(0.5, 8.0, 9.0, maderaRosa.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-8, 36.5, 0);
	glRotatef(45, 0, 0, 1);
	techoKH.prisma(1, 23.5, 27, maderaRoja.GLindex);	//crea techo lado izquierdo
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, 36.5, 0);
	glRotatef(45, 0, 0, -1);
	techoKH.prisma(1, 23.5, 27, maderaRoja.GLindex);	//crea techo lado derecho
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, kameLogo.GLindex);
	glBegin(GL_QUADS);									//crea pared faltante, triangulo
	glColor3f(1, 1, 1);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-12.8, 30.5, 12.5);
	glTexCoord2f(0.5, 0.0); glVertex3f(0.0, 30.5, 12.5);
	glTexCoord2f(1.0, 0.0); glVertex3f(12.8, 30.5, 12.5);
	glTexCoord2f(0.5, 1.0); glVertex3f(0.0, 45.0, 12.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, maderaRosa.GLindex);
	glBegin(GL_QUADS);									//crea pared faltante, triangulo
	glColor3f(1, 1, 1);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-12.8, 30.5, -12.5);
	glTexCoord2f(0.5, 0.0); glVertex3f(0.0, 30.5, -12.5);
	glTexCoord2f(1.0, 0.0); glVertex3f(12.8, 30.5, -12.5);
	glTexCoord2f(0.5, 1.0); glVertex3f(0.0, 45.0, -12.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, maderaRosa.GLindex);
	glBegin(GL_QUADS);									//crea pared faltante, triangulo cuarto piso arriba.
	glColor3f(1, 1, 1);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0, 0.0); glVertex3f(-12.0, 40.0, -4.0);
	glTexCoord2f(0.5, 0.0); glVertex3f(-12.0, 40.0, 0.0);
	glTexCoord2f(1.0, 0.0); glVertex3f(-12.0, 40.0, 4.0);
	glTexCoord2f(0.5, 1.0); glVertex3f(-12.0, 44.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-8, 37, 0);
	KHplantabaja.skybox(8.0, 8.0, 8.0, maderaRosa.GLindex);		//crea cuarto piso arriba
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9, 42, 2.5);
	glRotatef(39, 1, 0, 0);
	techoKH.prisma(1, 9, 7, maderaRoja.GLindex);	//crea techo del cuarto de arriba lado derecho
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9, 42, -2.5);
	glRotatef(39, -1, 0, 0);
	techoKH.prisma(1, 9, 7, maderaRoja.GLindex);	//crea techo del cuarto de arriba lado izquierdo
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 8.0, 0);
	piso.prisma(0.5, 25.0, 25.0, pisoMadera.GLindex);	//crea piso de madera 
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.6, 6.0, 15.5);
	portico.prisma(2.0, 14.0, 6.0, maderaB.GLindex);	//crea escalones del portico
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.6, 7.5, 14.8);
	portico.prisma(1.5, 10.0, 4.0, maderaB.GLindex);	//crea escalones del portico
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 7.5, 14.5);
	portico.cilindro(0.25, 17.5, 20, maderaB.GLindex);	//crea poste izquierdo portico
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0, 7.5, 14.5);
	portico.cilindro(0.25, 17.5, 20, maderaB.GLindex);	//crea poste derecho portico
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.0, 24.0, 15.5);
	glRotatef(40, 1, 0, 0);
	techoKH.prisma(1, 9, 7, maderaRoja.GLindex);	//crea techo del portico
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 30, 0);
	techoKH.prisma(0.1, 25.5, 25.5, maderaRosa.GLindex);	//crea piso de madera 
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-1.0, 19.0, 12.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	ventana.prisma(0.5, 8.0, 3.0, ventanita.GLindex);			//crea ventana
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-4.0, 19.0, 12.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	ventana.prisma(0.5, 8.0, 3.0, ventanita.GLindex);			//crea ventana
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-12.5, 18.75, -2.3);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	ventana.prisma(0.5, 4.6, 8.5, ventanita.GLindex);		//crea ventana
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-12.5, 18.75, 2.3);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	ventana.prisma(0.5, 4.6, 8.5, ventanita.GLindex);		//crea ventana
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glTranslatef(-12.1, 37.0, 0.0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	ventana.prisma(0.1, 5.0, 5.0, ventanita.GLindex);		//crea ventana
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_ALPHA_TEST);
	glTranslatef(6.5, 15.25, 12.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	ventana.prisma(0.5, 15.5, 6.2, puerta.GLindex);		//crea puerta
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
}

void CasaDecoracion(void)
{
	glPushMatrix();
	glTranslatef(-1.5, 15.0, -12.2);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	decoracion.prisma(0.1, 16.0, 3.0, closet.GLindex);	//crea puerta closet
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 15.0, -12.2);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	decoracion.prisma(0.1, 16.0, 3.0, closet.GLindex);		//crea puerta closet
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, 15.0, -12.2);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	decoracion.prisma(0.1, 16.0, 3.0, closet.GLindex);		//crea puerta closet
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.5, 19.0, -12.2);
	glRotatef(90, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	decoracion.prisma(0.1, 22.0, 5.5, escalera.GLindex);		//crea escaleras 
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9.0, 19.0, 5.0);
	glRotatef(90, 1, 0, 0);
	decoracion.prisma(0.1, 6.0, 22.0, baño.GLindex);			//crea paredes del baño
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-9.0, 19.0, 4.9);
	glRotatef(90, 1, 0, 0);
	decoracion.prisma(0.1, 6.2, 22.0, maderaRosa.GLindex);			//crea paredes del baño
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.0, 19.0, 5.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	decoracion.prisma(0.1, 1.0, 22.0, baño.GLindex);			//crea paredes del baño
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.9, 19.0, 5.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	decoracion.prisma(0.1, 1.2, 22.0, maderaRosa.GLindex);			//crea paredes del baño
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.0, 19.0, 12.0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	decoracion.prisma(0.1, 1.0, 22.0, baño.GLindex);			//crea paredes del baño
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.9, 19.0, 12.0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	decoracion.prisma(0.1, 1.0, 22.0, maderaRosa.GLindex);			//crea paredes del baño
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.0, 27.0, 8.75);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	decoracion.prisma(0.1, 5.5, 7.0, baño.GLindex);				//crea paredes del baño
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.9, 27.0, 8.85);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	decoracion.prisma(0.1, 5.5, 7.0, maderaRosa.GLindex);				//crea paredes del baño
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0, 8.5, 2.0);
	decoracion.prisma(0.1, 12.0, 12.0, alfombra.GLindex);				//crea alfombra
	glPopMatrix();

	//COCINA
	glPushMatrix();
	glTranslatef(-10.25, 11.0, -3.75);
	decoracion.prisma(6.0, 3.3, 17.25, cocina.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-10.25, 14.0, -3.75);
	decoracion.prisma(0.1, 3.3, 17.25, mesa3.GLindex);
	glPopMatrix();

}

void refrigerador(void)
{
	glTranslatef(-0.5,0.0,0.0);
glPushMatrix();

	glPushMatrix();
	glTranslatef(-6.0, 15.0, -10.1);
	refri.prisma(14.0, 4.0, 4.0, Refri.GLindex);			//crea refrigerador
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.0, 15.0, -8.1);
	glRotatef(90, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	refri.prisma(0.1, 14.0, 4.0, refri1.GLindex);			//crea refrigerador
	glPopMatrix();

glPopMatrix();
}

void sillon(void) 
{
	glPushMatrix();
	glTranslatef(-1.0, 9.6, 3.0);
	glRotatef(90, 1, 0, 0);
	sillonL.prisma(8.0, 2.0, 1.5, sillon2.GLindex);			//crea sillon largo
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 9.6, -2.0);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 0, 1);
	sillonL.prisma(8.0, 2.0, 1.5, sillon2.GLindex);			//crea sillon largo
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 10.8, 6.0);
	sillonL.prisma(1.0, 2.0, 2.0, sillon1.GLindex);			//crea cojin sillon largo
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 10.8, 4.0);
	sillonL.prisma(1.0, 2.0, 2.0, sillon1.GLindex);			//crea cojin sillon largo
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 10.8, 2.0);
	sillonL.prisma(1.0, 2.0, 2.0, sillon1.GLindex);			//crea cojin sillon largo
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 10.8, 0.0);
	sillonL.prisma(1.0, 2.0, 2.0, sillon1.GLindex);			//crea cojin sillon largo
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, 10.8, -2.0);
	sillonL.prisma(1.0, 2.0, 2.0, sillon1.GLindex);			//crea cojin sillon largo
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, 10.8, -2.0);
	sillonL.prisma(1.0, 2.0, 2.0, sillon1.GLindex);			//crea cojin sillon largo
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0, 10.8, -2.0);
	sillonL.prisma(1.0, 2.0, 2.0, sillon1.GLindex);			//crea cojin sillon largo
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.0, 10.8, -2.0);
	sillonL.prisma(1.0, 2.0, 2.0, sillon1.GLindex);			//crea cojin sillon largo
	glPopMatrix();

}

void tv(void) 
{
	glPushMatrix();
	glTranslatef(11.5, 10.0, 3.0);
	tele.prisma(10.0, 1.0, 7.0, television.GLindex);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(11.0, 11.5, 3.0);
	glRotatef(90, 0, 0, 1);
	glRotatef(180, 0, 1, 0);
	tele.prisma(0.1, 6.0, 6.0, television1.GLindex);
	glPopMatrix();
}

void mesaCentro(void) 
{
	glPushMatrix();
		glTranslatef(4.0, 10.0, 4.0);
		mesa.prisma(0.5, 4.0, 4.0, mesa1.GLindex);				//crea mesa de centro
	glPopMatrix();

	glPushMatrix();
		glTranslatef(5.5, 9.0, 5.0);
		mesa.cilindro(0.25, 1.0, 10.0, mesa1.GLindex);			//crea pata de mesa
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.5, 9.0, 3.0);
	mesa.cilindro(0.25, 1.0, 10.0, mesa1.GLindex);			//crea pata de mesa
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, 9.0, 5.0);
	mesa.cilindro(0.25, 1.0, 10.0, mesa1.GLindex);			//crea pata de mesa
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, 9.0, 3.0);
	mesa.cilindro(0.25, 1.0, 10.0, mesa1.GLindex);			//crea pata de mesa
	glPopMatrix();
}

void comedor(void) 
{
	glTranslatef(0.0, 0.0, 1.5);
glPushMatrix();
	glPushMatrix();
	glTranslatef(3.0, 13.0, -7.0);
	mesa.prisma(1.0, 8.0, 3.0, mesa2.GLindex);				//crea comedor
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.0, 8.0, -6.0);
	mesa.cilindro(0.25, 5.0, 10.0, mesa2.GLindex);			//crea pata de mesa
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.0, 8.0, -8.0);
	mesa.cilindro(0.25, 5.0, 10.0, mesa2.GLindex);			//crea pata de mesa
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 8.0, -8.0);
	mesa.cilindro(0.25, 5.0, 10.0, mesa2.GLindex);			//crea pata de mesa
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 8.0, -6.0);
	mesa.cilindro(0.25, 5.0, 10.0, mesa2.GLindex);			//crea pata de mesa
	glPopMatrix();
glPopMatrix();
}

void chair(void) 
{

	

glPushMatrix();

	glPushMatrix();
	glTranslatef(10.0, 10.0, -6.0);
	silla.prisma(2.0, 0.25, 0.25, mesa2.GLindex);		//crea pata de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.0, 10.0, -6.0);
	silla.prisma(2.0, 0.25, 0.25, mesa2.GLindex);		//crea pata de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.0, 10.0, -4.0);
	silla.prisma(2.0, 0.25, 0.25, mesa2.GLindex);		//crea pata de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 10.0, -4.0);
	silla.prisma(2.0, 0.25, 0.25, mesa2.GLindex);		//crea pata de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0, 11.0, -5.0);
	silla.prisma(0.5, 2.3, 2.3, mesa2.GLindex);			//crea asiento silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 11.0, -4.0);
	silla.cilindro(0.15, 4.0, 20.0, mesa2.GLindex);		//crea respaldo de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 11.0, -5.0);
	silla.cilindro(0.15, 4.0, 20.0, mesa2.GLindex);		//crea respaldo de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 11.0, -6.0);
	silla.cilindro(0.15, 4.0, 20.0, mesa2.GLindex);		//crea respaldo de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 15.0, -5.0);
	silla.prisma(1.0, 0.25, 2.8, mesa2.GLindex);		//crea respaldo de la silla
	glPopMatrix();

glPopMatrix();

}

void chair1(void)
{
glPushMatrix();

	

glPushMatrix();
	glRotatef(180,0,1,0);
	glTranslatef(-6.0, -0.5, 10.0);

	glPushMatrix();

	glPushMatrix();
	glTranslatef(10.0, 10.0, -6.0);
	silla.prisma(2.0, 0.25, 0.25, mesa2.GLindex);		//crea pata de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.0, 10.0, -6.0);
	silla.prisma(2.0, 0.25, 0.25, mesa2.GLindex);		//crea pata de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.0, 10.0, -4.0);
	silla.prisma(2.0, 0.25, 0.25, mesa2.GLindex);		//crea pata de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 10.0, -4.0);
	silla.prisma(2.0, 0.25, 0.25, mesa2.GLindex);		//crea pata de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0, 11.0, -5.0);
	silla.prisma(0.5, 2.3, 2.3, mesa2.GLindex);			//crea asiento silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 11.0, -4.0);
	silla.cilindro(0.15, 4.0, 20.0, mesa2.GLindex);		//crea respaldo de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 11.0, -5.0);
	silla.cilindro(0.15, 4.0, 20.0, mesa2.GLindex);		//crea respaldo de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 11.0, -6.0);
	silla.cilindro(0.15, 4.0, 20.0, mesa2.GLindex);		//crea respaldo de la silla
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 15.0, -5.0);
	silla.prisma(1.0, 0.25, 2.8, mesa2.GLindex);		//crea respaldo de la silla
	glPopMatrix();

glPopMatrix();
}

void lampara(void) 
{
glPushMatrix();

	glTranslatef(-16.0,-1.0,8.5);

glPushMatrix();
	glPushMatrix();
	glTranslatef(10.0, 10.0, -6.0);
	mesa.prisma(2.0, 0.25, 0.25, mesa3.GLindex);		//crea mesa
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.0, 10.0, -6.0);
	mesa.prisma(2.0, 0.25, 0.25, mesa3.GLindex);		//crea mesa
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.0, 10.0, -4.0);
	mesa.prisma(2.0, 0.25, 0.25, mesa3.GLindex);		//crea mesa
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 10.0, -4.0);
	mesa.prisma(2.0, 0.25, 0.25, mesa3.GLindex);		//crea mesa
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0, 11.0, -5.0);
	mesa.prisma(0.5, 2.3, 2.3, mesa3.GLindex);		//crea mesa
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0, 11.5, -5.0);
	lamp.esfera(0.5, 20, 20, lamps.GLindex);			//crea lampara
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0, 12.0, -5.0);
	lamp.cilindro(0.75, 1.0, 20, lamps1.GLindex);	//crea lampara
	glPopMatrix();

glPopMatrix();

glPopMatrix();
}

void InitGL(void)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	maderaRoja.LoadTGA("maderaRoja.TGA");
	maderaRoja.BuildGLTexture();
	maderaRoja.ReleaseImage();

	maderaRosa.LoadTGA("maderaRosa.TGA");
	maderaRosa.BuildGLTexture();
	maderaRosa.ReleaseImage();

	kameLogo.LoadTGA("kameLogo.TGA");
	kameLogo.BuildGLTexture();
	kameLogo.ReleaseImage();

	arena.LoadTGA("arena.TGA");
	arena.BuildGLTexture();
	arena.ReleaseImage();

	pisoMadera.LoadTGA("pisoMadera.TGA");
	pisoMadera.BuildGLTexture();
	pisoMadera.ReleaseImage();

	maderaB.LoadTGA("maderaB.TGA");
	maderaB.BuildGLTexture();
	maderaB.ReleaseImage();

	Refri.LoadTGA("refri.TGA");
	Refri.BuildGLTexture();
	Refri.ReleaseImage();

	refri1.LoadTGA("refri1.TGA");
	refri1.BuildGLTexture();
	refri1.ReleaseImage();

	ventanita.LoadTGA("vidrio.TGA");
	ventanita.BuildGLTexture();
	ventanita.ReleaseImage();

	puerta.LoadTGA("puerta.TGA");
	puerta.BuildGLTexture();
	puerta.ReleaseImage();

	grass.LoadTGA("pasto01.TGA");
	grass.BuildGLTexture();
	grass.ReleaseImage();

	sea.LoadTGA("mar.TGA");
	sea.BuildGLTexture();
	sea.ReleaseImage();

	sillon1.LoadTGA("sillon1.TGA");
	sillon1.BuildGLTexture();
	sillon1.ReleaseImage();

	sillon2.LoadTGA("sillon2.TGA");
	sillon2.BuildGLTexture();
	sillon2.ReleaseImage();

	closet.LoadTGA("closet.TGA");
	closet.BuildGLTexture();
	closet.ReleaseImage();

	escalera.LoadTGA("escaleras.TGA");
	escalera.BuildGLTexture();
	escalera.ReleaseImage();

	baño.LoadTGA("baño.TGA");
	baño.BuildGLTexture();
	baño.ReleaseImage();

	television.LoadTGA("tv1.TGA");
	television.BuildGLTexture();
	television.ReleaseImage();

	television1.LoadTGA("tv2.TGA");
	television1.BuildGLTexture();
	television1.ReleaseImage();

	alfombra.LoadTGA("alfombra.TGA");
	alfombra.BuildGLTexture();
	alfombra.ReleaseImage();

	mesa1.LoadTGA("mesa1.TGA");
	mesa1.BuildGLTexture();
	mesa1.ReleaseImage();

	mesa2.LoadTGA("mesa2.TGA");
	mesa2.BuildGLTexture();
	mesa2.ReleaseImage();

	mesa3.LoadTGA("wood.TGA");
	mesa3.BuildGLTexture();
	mesa3.ReleaseImage();

	lamps.LoadTGA("lamp.TGA");
	lamps.BuildGLTexture();
	lamps.ReleaseImage();

	lamps1.LoadTGA("lamp1.TGA");
	lamps1.BuildGLTexture();
	lamps1.ReleaseImage();

	cocina.LoadTGA("cocina.TGA");
	cocina.BuildGLTexture();
	cocina.ReleaseImage();

	objCamera.Position_Camera(0, 30.0f, 35.0, 0, 2.5f, 0, 0, 1, 0);

}


void pintaTexto(float x, float y, float z, void* font, char* string)
{

	char* c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
	//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glPushMatrix();
		glRotatef(g_lookupdown, 1.0f, 0, 0);

		gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
			objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
			objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);

		glPushMatrix();
		//CREAMOS CIELO
			glPushMatrix(); 
				glDisable(GL_LIGHTING);
				glTranslatef(0, 60, 0);
				fig1.skybox(150.0, 150.0, 150.0, text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

		//KAMEHOUSE
			glPushMatrix();
				glEnable(GL_ALPHA_TEST);
				glDisable(GL_LIGHTING);
				kameHouse();
				glDisable(GL_ALPHA_TEST);
			glPopMatrix();

		//REFRIGERADOR (1.- OBJETO A MODELAR)
			glPushMatrix();
				refrigerador();
			glPopMatrix();
				
		//COMEDOR (2.- OBJETO A MODELAR)
			glPushMatrix();
				comedor();
			glPopMatrix();

		//SILLAS (3.- OBJETO A MODELAR)

			glPushMatrix();
			glTranslatef(movSilla, -0.5, 0.0);
			chair();
			glPopMatrix();

			glPushMatrix();
			chair1();
			glPopMatrix();
	
		//SILLON LARGO (4.- OBJETO A MODELAR)
			glPushMatrix();
				sillon();
			glPopMatrix();

		//MESA CENTRO (5.- OBJETO A MODELAR)
			glPushMatrix();
				mesaCentro();
			glPopMatrix();

		//LAMPARA (6.- OBJETO A MODELAR)
			glPushMatrix();
			lampara();
			glPopMatrix();

		//TELEVISION (7.- OBJETO A MODELAR)
			glPushMatrix();
				tv();
			glPopMatrix();

		//DECORACION
			glPushMatrix();
				CasaDecoracion();
			glPopMatrix();

		//ISLA KH
			glPushMatrix();
				isla();
			glPopMatrix();

		//MAR
			glPushMatrix();
				mar();
			glPopMatrix();

		glPopMatrix();

	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	pintaTexto(-11, 12.0, -14.0, (void*)font, "Kame House");
	pintaTexto(-11, 8.5, -14, (void*)font, s);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	if (g_fanimacion)
	{
		if (movSilla <= 3.0 && flag == false)
			movSilla += 1.0;
		if (movSilla == 3.0)
			flag = true;
	}

	{
		if (movSilla >= 0.0 && flag == true)
		{
			movSilla -= 1.0;
			if (movSilla == 0.0)
				g_fanimacion = false;
		}

	}

}


void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {

	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;

	case 'z':		//Poner algo en movimiento
	case 'Z':
		g_fanimacion^= true; //Activamos/desactivamos la animacíon
		break;

	case 'x':		//Poner algo en movimiento
	case 'X':
		g_fanimacion1 ^= true; //Activamos/desactivamos la animacíon
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		break;

		//Teclas para cámara
	case GLUT_KEY_F1:
		objCamera.Position_Camera(0, 8.0f, 3, 0, 2.5f, 0, 0, 1, 0);
		break;

	case GLUT_KEY_F2:
		//Cámara de transmisión
		objCamera.Position_Camera(0, 20.0f, 35, 0, 2.5f, 0, 0, 1, 0);
		break;

	case GLUT_KEY_F3:
		//Cámara desde el centro hacia la porteria
		objCamera.Position_Camera(5, 10.0f, 0, 20, 2.5f, 0, 0, 1, 0);
		break;

	case GLUT_KEY_F4:
		//Cámara del tiro de esquina
		objCamera.Position_Camera(25, 10.0f, 20, 20, 2.5f, 0, 0, 1, 0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)  						 // Main Function
{
	int submenu;
	glutInit(&argc, argv);						 // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);							 // Tamaño de la Ventana
	glutInitWindowPosition(0, 0);							 //Posicion de la Ventana
	glutCreateWindow("Kame House"); 						 // Nombre de la Ventana
	//glutFullScreen     ( );         						 // Full Screen
	InitGL();												 // Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  						 //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);							 //Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);							 //Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);						 //Otras
	glutIdleFunc(animacion);


	glutMainLoop();          // 

	return 0;
}