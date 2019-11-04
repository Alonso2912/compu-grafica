//Semestre 2020 - 1 ALONSO ESPINOSA CABALLERO
//************************************************************//
//************************************************************//
//************** PROYECTO FINAL *********************************//


#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito


float posX =0, posY = -35, posZ =0, rotRodIzq = 0;
float giroMonito = 0;
//animacion 2
float posX2 = 10, posY2 = -28, posZ2 = -60 ;
float giroMonito2 = 0;


#define MAX_FRAMES 5
#define MAX_FRAMES2 5
int i_max_steps = 90;
int i_curr_steps = 0;

int i_max_steps2 = 90;
int i_curr_steps2 = 0;

typedef struct _frame
{

	//variables la animacion nave
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;

	
	
}FRAME;

typedef struct _frame2
{

	

	///variables 2 animacion trompo

	float posX2;		//Variable para PosicionX
	float posY2;		//Variable para PosicionY
	float posZ2;		//Variable para PosicionZ
	float incX2;		//Variable para IncrementoX
	float incY2;		//Variable para IncrementoY
	float incZ2;		//Variable para IncrementoZ


	float giroMonito2;
	float giroMonitoInc2;

}FRAME2;


FRAME2 KeyFrame2[MAX_FRAMES2];
FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 5;			   //Cuadros clave preguardados
bool play = false;
bool play2 = false;
int playIndex = 0;


int FrameIndex2 = 5;			   //Cuadros clave preguardados

int playIndex2 = 0;




int w = 500, h = 500;
int frame=0,time,timebase=0;
char s[30];

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = {22};

CTexture text1;
CTexture text2;






///////texturas proyecto
CTexture pared;
CTexture piso;
CTexture cielo;
CTexture estante;
CTexture piecama;
CTexture alfombra;
CTexture camax;
CTexture almohada;
CTexture cajonpared;
CTexture forro;
CTexture repisa;
CTexture vidrio;
CTexture vnegra;
CTexture vblanca;
CTexture television;
CTexture television2;
CTexture metal;
CTexture maderita;
CTexture garrafon;
CTexture ropa1;
CTexture ropa2;
CTexture ropa3;
CTexture repisax;
CTexture libros;
CTexture gabinete;
CTexture teclado;
CTexture balon;
CTexture terciopelo;

CTexture b1;
CTexture b2;
CTexture c;
CTexture l1;
CTexture tv;
CTexture planta;
CTexture macetaz;
CTexture padres;
CTexture foto;
CTexture puertax;
CTexture trompo;
CTexture a1;
CTexture a2;




CFiguras cubo;
CFiguras sky;


/////////////////////////////////////////////FIGURAS PROYECTO FINAL
CFiguras piso1;
CFiguras pared_derecha; //es ambas paredes de hecho
CFiguras tubo;
CFiguras bola;
CFiguras dona;



float abrirPuerta = 0;
float puerta = 0;
//END NEW//////////////////////////////////////////

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;	//Para crear Monito

bool rebota = true;
bool rebota2 = false;
bool abrir = false;
bool cerrar = false;
bool encendido = false;
float x = 0.0;
float y = 0.0;

void saveFrame ( void )
{
	
	printf("frameindex %d\n",FrameIndex);			

	KeyFrame[FrameIndex].posX=posX;
	KeyFrame[FrameIndex].posY=posY;
	KeyFrame[FrameIndex].posZ=posZ;

	KeyFrame[FrameIndex].rotRodIzq=rotRodIzq;
	KeyFrame[FrameIndex].giroMonito=giroMonito;
			
	FrameIndex++;
}
//save 2

void saveFrame2(void)
{

	printf("frameindex %d\n", FrameIndex2);

	KeyFrame2[FrameIndex2].posX2 = posX2;
	KeyFrame2[FrameIndex2].posY2 = posY2;
	KeyFrame2[FrameIndex2].posZ2 = posZ2;

	//KeyFrame[FrameIndex].rotRodIzq = rotRodIzq;
	KeyFrame2[FrameIndex2].giroMonito2 = giroMonito2;

	FrameIndex2++;
}

void resetElements( void )
{
	posX=KeyFrame[0].posX;
	posY=KeyFrame[0].posY;
	posZ=KeyFrame[0].posZ;

	rotRodIzq=KeyFrame[0].rotRodIzq;
	giroMonito=KeyFrame[0].giroMonito;

}

/////////////////////////////////2
void resetElements2(void)
{
	posX2 = KeyFrame2[0].posX2;
	posY2 = KeyFrame2[0].posY2;
	posZ2 = KeyFrame2[0].posZ2;

	//rotRodIzq = KeyFrame[0].rotRodIzq;
	giroMonito2 = KeyFrame2[0].giroMonito2;

}

void interpolation ( void )
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;	
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;	
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;	

	KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;	
	KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;

}

void interpolation2(void)
{
	KeyFrame2[playIndex2].incX2 = (KeyFrame2[playIndex2 + 1].posX2 - KeyFrame2[playIndex2].posX2) / i_max_steps2;
	KeyFrame2[playIndex2].incY2 = (KeyFrame2[playIndex2 + 1].posY2 - KeyFrame2[playIndex2].posY2) / i_max_steps2;
	KeyFrame2[playIndex2].incZ2 = (KeyFrame2[playIndex2 + 1].posZ2 - KeyFrame2[playIndex2].posZ2) / i_max_steps2;

	//KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;
	KeyFrame2[playIndex2].giroMonitoInc2 = (KeyFrame2[playIndex2 + 1].giroMonito2 - KeyFrame2[playIndex2].giroMonito2) / i_max_steps2;

}

void pelota(void)
{
	glPushMatrix();
	glTranslatef(2, y, 16); //x, y z
	bola.esfera(0.6, 30, 30, balon.GLindex); //radio //altura
	glPopMatrix();

}


//avion animado
void avion(void)
{
	//punto inicial 0,4,0
	glPushMatrix();
	glTranslatef(posX, posY, posZ); //x, y z
	glRotatef(giroMonito, 0, 1, 0);
	pared_derecha.prisma(6, 6, 15, a1.GLindex); //ALTO Y , ANCHO X ANCHO Z
	//ala
	glTranslatef(0, 4, 5); //x, y z
	pared_derecha.prisma(2, 20, 4, a2.GLindex); //ALTO Y , ANCHO X ANCHO Z
	//aleron 2
	glTranslatef(0, 0, -10); //x, y z
	pared_derecha.prisma(2, 10, 4, a2.GLindex); //ALTO Y , ANCHO X ANCHO Z
	//aleron trasero
	glTranslatef(0, 0, -3); //x, y z
	
	pared_derecha.prisma(5, 2, 2, a2.GLindex); //ALTO Y , ANCHO X ANCHO Z

	glPopMatrix();///avion cuerpo

}

void trompox(void) {
	glPushMatrix();

	glEnable(GL_BLEND);     // Turn Blending On
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, trompo.GLindex);
	//glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, 0.7f);


	glTranslatef(posX2, posY2, posZ2); //x, y z
	glRotatef(180, 0, 0, 1);
	glRotatef(giroMonito2*100, 0, 1, 0);
	pared_derecha.cono(11, 5, 20, trompo.GLindex); //ALTO Y , ANCHO X ANCHO Z
	pared_derecha.cono(12.1, 5, 20, ropa3.GLindex); //ALTO Y , ANCHO X ANCHO Z

	glDisable(GL_BLEND);        // Turn Blending Off
	glEnable(GL_DEPTH_TEST);							  //glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glPopMatrix();

	glPopMatrix();
}


////////////////////////elementos de la casa de arnold


void garrafonx(void)
{

	//base
	glPushMatrix();
	glTranslatef(35, -14, 0); //x, y z
	tubo.cilindro(4.5, 8, 20, maderita.GLindex); //radio //altura
	glPopMatrix();

	//////////////translucidez/////////////////////////////////////


	glPushMatrix();
	glEnable(GL_BLEND);     // Turn Blending On
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, garrafon.GLindex);
	//glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, 0.5f); //Este sirve para que varies el porcentaje de opacidad segun lo necesites altera el ultimo valor que  va de 0-1 donde 0 es el 0% y 1 el 100% de opacidad
	
	///////////((((codigo aqui))))

	glPushMatrix();
	glTranslatef(35, -6, 0); //x, y z
	tubo.cilindro(1, 1, 20, garrafon.GLindex); //radio //altura
	glPopMatrix();
	//garrafon 2
	glPushMatrix();
	glTranslatef(35, -5, 0); //x, y z
	tubo.cilindro(1.2, 1, 20, garrafon.GLindex); //radio //altura
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(35, -4, 0); //x, y z
	tubo.cilindro(1.3, 1, 20, garrafon.GLindex); //radio //altura
	glPopMatrix();
	//4
	glPushMatrix();
	glTranslatef(35, -6, 0); //x, y z
	tubo.cilindro(3.7, 18.5, 20, garrafon.GLindex); //radio //altura
	glPopMatrix();
	//5
	glPushMatrix();
	glTranslatef(35, -2, 0); //x, y z
	tubo.cilindro(4, 3, 20, garrafon.GLindex); //radio //altura
	glPopMatrix();
	//6
	glPushMatrix();
	glTranslatef(35, 5, 0); //x, y z
	tubo.cilindro(4, 3, 20, garrafon.GLindex); //radio //altura
	glPopMatrix();
	//4

	glPushMatrix();
	glTranslatef(35, 12.5, 0); //x, y z
	tubo.cilindro(4, 3, 20, garrafon.GLindex); //radio //altura
	glPopMatrix();




	glDisable(GL_BLEND);        // Turn Blending Off
	glEnable(GL_DEPTH_TEST);							  //glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glPopMatrix();

	///////////////////////////acaba translucidez


	glPushMatrix();
	glTranslatef(37, -40, 3); //x, y z
	tubo.cilindro(0.5, 28, 20, maderita.GLindex); //radio //altura
	glPopMatrix();

	//patas 2

	glPushMatrix();
	glTranslatef(37, -40, -3); //x, y z
	tubo.cilindro(0.5, 28, 20, maderita.GLindex); //radio //altura
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(33, -40, -3); //x, y z
	tubo.cilindro(0.5, 28, 20, maderita.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(33, -40, 3); //x, y z
	tubo.cilindro(0.5, 28, 20, maderita.GLindex); //radio //altura
	glPopMatrix();

	//grifo

	glPushMatrix();
	glTranslatef(32, -12, 0); //x, y z
	glRotatef(90, 0, 0, 1);
	tubo.cilindro(0.5, 3, 10, metal.GLindex); //radio //altura
	glPopMatrix();

	//grifo 2

	glPushMatrix();
	glTranslatef(29, -14, 0); //x, y z
	//glRotatef(90, 0, 0, 1);
	tubo.cilindro(0.2, 3, 10, metal.GLindex); //radio //altura
	glPopMatrix();
}

void calentador(void)
{
	//transversal abajo
	glPushMatrix();
	glTranslatef(40, -20, 13); //x, y z
	glRotatef(90, 1, 0, 0);
	tubo.cilindro(1.6, 18, 20, metal.GLindex); //radio //altura
	glPopMatrix();
	

	glPushMatrix();
	glTranslatef(40, -40, 30); //x, y z
	tubo.cilindro(1, 34, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	//1

	glPushMatrix();
	glTranslatef(40, -40, 26); //x, y z
	tubo.cilindro(1, 34, 20, metal.GLindex); //radio //altura
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslatef(40, -40, 22); //x, y z
	tubo.cilindro(1, 34, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40, -40, 18); //x, y z
	tubo.cilindro(1, 34, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40, -40, 14); //x, y z
	tubo.cilindro(1, 34, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	//frente

	glPushMatrix();
	glTranslatef(35, -40, 30); //x, y z
	tubo.cilindro(1, 34, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	//1

	glPushMatrix();
	glTranslatef(35, -40, 26); //x, y z
	tubo.cilindro(1, 34, 20, metal.GLindex); //radio //altura
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslatef(35, -40, 22); //x, y z
	tubo.cilindro(1, 34, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35, -40, 18); //x, y z
	tubo.cilindro(1, 34, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35, -40, 14); //x, y z
	tubo.cilindro(1, 34, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	//parte arriba

	glPushMatrix();
	glTranslatef(40.8, -5.5, 14); //x, y z
	glRotatef(90, 0, 0, 1);
	tubo.cilindro(0.8, 6, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40.8, -5.5, 18); //x, y z
	glRotatef(90, 0, 0, 1);
	tubo.cilindro(0.8, 6, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40.8, -5.5, 22); //x, y z
	glRotatef(90, 0, 0, 1);
	tubo.cilindro(0.8, 6, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40.8, -5.5, 26); //x, y z
	glRotatef(90, 0, 0, 1);
	tubo.cilindro(0.8, 6, 20, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(40.8, -5.5, 30); //x, y z
	glRotatef(90, 0, 0, 1);
	tubo.cilindro(0.8, 6, 20, metal.GLindex); //radio //altura
	glPopMatrix();
	//curvas

	glPushMatrix();
	glTranslatef(35, -5.5, 30); //x, y z
	bola.esfera(1.15, 340, 10, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35, -5.5, 14); //x, y z
	bola.esfera(1.15, 340, 10, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35, -5.5, 18); //x, y z
	bola.esfera(1.15, 340, 10, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35, -5.5, 22); //x, y z
	bola.esfera(1.15, 340, 10, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35, -5.5, 26); //x, y z
	bola.esfera(1.15, 340, 10, metal.GLindex); //radio //altura
	glPopMatrix();

	glPushMatrix();
	glTranslatef(35, -5.5, 14); //x, y z
	bola.esfera(1.15, 340, 10, metal.GLindex); //radio //altura
	glPopMatrix();
}




void pc(void)
{

	//////mesa///
	glPushMatrix();
	glTranslatef(0, -1, -68); //x, y z
	pared_derecha.prisma(2, 18, 10, maderita.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	

	//////patas
	glPushMatrix();
	glTranslatef(-7, -22, -72); //x, y z
	pared_derecha.prisma(42, 1, 1, maderita.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//////patas 2
	glPushMatrix();
	glTranslatef(-7, -22, -64); //x, y z
	pared_derecha.prisma(42, 1, 1, maderita.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//////patas
	glPushMatrix();
	glTranslatef(6.5, -22, -72); //x, y z
	pared_derecha.prisma(42, 1, 1, maderita.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//////patas 2
	glPushMatrix();
	glTranslatef(6.5, -22, -64); //x, y z
	pared_derecha.prisma(42, 1, 1, maderita.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//teclado

	
	glPushMatrix();
	glTranslatef(0, 0, -64); //x, y z
	glRotatef(-90, 1, 0, 0);
	pared_derecha.prisma(1.5, 3, 0.2, teclado.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//pantalla
	glPushMatrix();
	glTranslatef(0, 11, -65); //x, y z
	pared_derecha.prisma(7, 4, 0.2, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	
	//////pc monitor
	glPushMatrix();
	glTranslatef(0, 11, -67); //x, y z
	pared_derecha.prisma(10, 6, 4, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//////pc cpu
	glPushMatrix();
	glTranslatef(0, 2, -67); //x, y z
	pared_derecha.prisma(4, 4, 4, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2, -65); //x, y z
	pared_derecha.prisma(4, 4, 0.1, gabinete.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//////pc base monitor
	glPushMatrix();
	glTranslatef(0, 5, -67); //x, y z
	pared_derecha.prisma(2, 1, 1, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	
}

void librero1(void)
{
	//////parte1
	glPushMatrix();
	glTranslatef(38, 7, -40); //x, y z
	pared_derecha.prisma(100, 10, 2, terciopelo.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//////parte2
	glPushMatrix();
	glTranslatef(38, 7, -20); //x, y z
	pared_derecha.prisma(100, 10, 2, terciopelo.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//reoisa ariba
	glPushMatrix();
	glTranslatef(38.5, 56, -30); //x, y z
	pared_derecha.prisma(1,10 , 20, terciopelo.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//reoisa abajo
	glPushMatrix();
	glTranslatef(38.5, -39, -30); //x, y z
	pared_derecha.prisma(1, 10, 20, terciopelo.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//1
	glPushMatrix();
	glTranslatef(38.5, -20, -30); //x, y z
	pared_derecha.prisma(1, 10, 20, terciopelo.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//2
	glPushMatrix();
	glTranslatef(38.5, -5, -30); //x, y z
	pared_derecha.prisma(1, 10, 20, terciopelo.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//3
	glPushMatrix();
	glTranslatef(38.5, 15, -30); //x, y z
	pared_derecha.prisma(1, 10, 20, terciopelo.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//3
	glPushMatrix();
	glTranslatef(38.5, 30, -30); //x, y z
	pared_derecha.prisma(1, 10, 20, terciopelo.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//elementos bocina 1

	glPushMatrix();
	glTranslatef(38.5, -30, -30); //x, y z
	pared_derecha.prisma(19, 7, 20, b1.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//elementos bocina 2

	glPushMatrix();
	glTranslatef(38.5, -15, -30); //x, y z
	pared_derecha.prisma(10, 7, 20, b2.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//mini componente hifi

	glPushMatrix();
	glTranslatef(38.5, 5, -30); //x, y z
	pared_derecha.prisma(18, 7, 20, c.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//libros1

	glPushMatrix();
	glTranslatef(38.5, 23, -30); //x, y z
	pared_derecha.prisma(14, 7, 20, ropa1.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//jueguetes //balon
	{
		glPushMatrix();
		glTranslatef(38.5, 35, -33); //x, y z
		bola.esfera(5, 340, 10, balon.GLindex); //radio //altura
		glPopMatrix();
		//libros arriba
		glPushMatrix();
		glTranslatef(38.5, 36, -25); //x, y z
		pared_derecha.prisma(12, 7, 5, libros.GLindex); //ALTO Y , ANCHO X ANCHO Z
		glPopMatrix();

	}

}
void juguetes(void) {
	glPushMatrix();
	glTranslatef(0, 0, 6); //x, y z
	pared_derecha.prisma(30, 10, 30, repisax.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

}

void maceta(void)
{

	//cuerpo
	glPushMatrix();
	glTranslatef(-40, 53, -15); //x, y z
	glRotatef(180, 0, 0, 1);

	pared_derecha.cono(6, 1, 30, macetaz.GLindex); //ALTO cono , ANCHO cono X resolucion
	glPopMatrix();

	//planos

	glPushMatrix();
	glTranslatef(-40, 56, -15); //x, y z
	pared_derecha.prisma(7, 0.0001, 4, planta.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//1

	glPushMatrix();
	glTranslatef(-40, 56, -15); //x, y z
	glRotatef(20, 0, 1, 0);
	pared_derecha.prisma(7, 0.0001, 4, planta.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//2
	glPushMatrix();
	glTranslatef(-40, 56, -15); //x, y z
	glRotatef(40, 0, 1, 0);
	pared_derecha.prisma(7, 0.0001, 4, planta.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(-40, 56, -15); //x, y z
	glRotatef(60, 0, 1, 0);
	pared_derecha.prisma(7, 0.0001, 4, planta.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//4
	glPushMatrix();
	glTranslatef(-40, 56, -15); //x, y z
	glRotatef(80, 0, 1, 0);
	pared_derecha.prisma(7, 0.0001, 4, planta.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40, 56, -15); //x, y z
	glRotatef(100, 0, 1, 0);
	pared_derecha.prisma(7, 0.0001, 4, planta.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40, 56, -15); //x, y z
	glRotatef(120, 0, 1, 0);
	pared_derecha.prisma(7, 0.0001, 4, planta.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40, 56, -15); //x, y z
	glRotatef(140, 0, 1, 0);
	pared_derecha.prisma(7, 0.0001, 4, planta.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-40, 56, -15); //x, y z
	glRotatef(160, 0, 1, 0);
	pared_derecha.prisma(7, 0.0001, 4, planta.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


}

void cuadrox()
{

	glPushMatrix();
	glTranslatef(42, 35, 12); //x, y z
	
	pared_derecha.prisma(18, 1, 11, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//foto
	glPushMatrix();
	glTranslatef(41.5, 35, 12); //x, y z

	pared_derecha.prisma(15, 0.1, 9, padres.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//2
	glPushMatrix();
	glTranslatef(42, 50, 30); //x, y z

	pared_derecha.prisma(18, 1, 11, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//foto
	glPushMatrix();
	glTranslatef(41.5, 50, 30); //x, y z

	pared_derecha.prisma(15, 0.1, 9, foto.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();



}
//*************************************************************************************************************
/////////////////////////////////////////////////////////////////////////////////////cuarto ARNOLD*****
void cuarto(void)
{
	avion();
	
	//pantalla animada
	if (encendido) {

		//pantalla en movimiento

		glPushMatrix(); //Flecha
		glTranslatef(0, 11, -64.9);
		glRotatef(90, 1, 0, 0);
		glScalef(4, 0.1, 6.5);


		//glDisable(GL_LIGHTING);
		fig3.prisma_anun(foto.GLindex, 0);
		//glEnable(GL_LIGHTING);
		glPopMatrix();
	}


	//puerta animada

	glPushMatrix();
	
	glTranslatef(-35, 3, -7.5);
	glRotatef(-puerta, 0.0f, 1.0f, 0.0f);
	glTranslatef(0, 0, -8.7);
	pared_derecha.prisma(90, 1, 20, puertax.GLindex);
	glTranslatef(-1, 0, 0);
	glRotatef(180, 0, 0, 1);
	pared_derecha.prisma(90, 1, 20, puertax.GLindex);//x y z
	//glTranslatef(-35, 3, -9); //x, y z
	//glRotatef(puerta, 0.0f, 0.0f, 1);
	
	glPopMatrix();


	//elementos
	
	cuadrox();
	glPushMatrix();
	maceta();
	
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 5);
	maceta();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(46, -49, -51);
	maceta();
	glPopMatrix();

	calentador();
	garrafonx();
	pc();
	librero1();
	//piso
	glPushMatrix();
	glTranslatef(0, -40, 0); //x, y z
	piso1.prisma(1, 85, 150, piso.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//pared  izquierda
	glPushMatrix();
	glTranslatef(43, 32.5, 0); //x, y z
	pared_derecha.prisma(145.5, 1, 150, pared.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//pared  frente

	glPushMatrix();
	glTranslatef(-19, 33, -75); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(145, 1, 125, pared.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//pared derecha inclinada primera parte

	glPushMatrix();
	glTranslatef(-62, 33, 37); //x, y z
	glRotatef(15, 0.0f, 0.0f, 1);
	pared_derecha.prisma(150, 1, 85, pared.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//pared derecha inclinada segunda parte

	glPushMatrix();
	glTranslatef(-62, 33, -51); //x, y z
	glRotatef(15, 0.0f, 0.0f, 1);
	pared_derecha.prisma(150, 1, 48, pared.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//pared derecha inclinada arriba de la puerta

	glPushMatrix();
	glTranslatef(-74, 77, -17); //x, y z
	glRotatef(15, 0.0f, 0.0f, 1);
	pared_derecha.prisma(60, 1, 27, pared.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//////////////////////////forros


	//pared derecha inclinada arriba de la puerta

	glPushMatrix();
	glTranslatef(-82.7, 77, -0); //x, y z
	//glRotatef(15, 0.0f, 0.0f, 1);
	pared_derecha.prisma(55, 6, 140, forro.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//pared derecha inclinada primera parte

	glPushMatrix();
	glTranslatef(-82, 32.5, 38); //x, y z
	//glRotatef(15, 0.0f, 0.0f, 1);
	pared_derecha.prisma(145.5, 6, 86, forro.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//pared derecha inclinada segunda parte

	glPushMatrix();
	glTranslatef(-82, 33, -51); //x, y z
	//glRotatef(15, 0.0f, 0.0f, 1);
	pared_derecha.prisma(145.5, 6, 48, forro.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga pared derecha

	glPushMatrix();
	glTranslatef(-79, 102, 2.5); //x, y z

	pared_derecha.prisma(8, 5, 156, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();



	//pared  izquierda
	glPushMatrix();
	glTranslatef(44, 32.5, 2.5); //x, y z
	pared_derecha.prisma(145.5, 1, 156, forro.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga pared izquierda

	glPushMatrix();
	glTranslatef(41, 102.5, 2.5); //x, y z

	pared_derecha.prisma(5, 5, 156, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//pared fondo
	glPushMatrix();
	glTranslatef(-19, 33, 81); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(145, 2, 125, forro.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//pared frente

	glPushMatrix();
	glTranslatef(-19, 33, -76); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(145, 1, 125, forro.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga pared enfrente

	glPushMatrix();
	glTranslatef(-19, 102, -72); //x, y z

	pared_derecha.prisma(5, 125, 5, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//puerta techo

	glPushMatrix();
	glTranslatef(-60, 48, -16.5); //x, y z
	glRotatef(90, 0.0f, 0.0f, 1);
	pared_derecha.prisma(50, 1, 22.5, pared.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();



	//entrada1

	glPushMatrix();
	glTranslatef(-60, 4, -5.5); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(87, 1, 50, pared.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//entrada 2
	glPushMatrix();
	glTranslatef(-60, 4, -27); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(87, 1, 50, pared.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6, -47, 30.1);
	maceta();
	glPopMatrix();

	//elemento pared1 ///posiblemente modificar o usar para cuadrosmuebleblanco
	glPushMatrix();
	glTranslatef(-49.5, 0, 16.1); //x, y z
	glRotatef(90, 0.0f, 0.0f, 1);
	pared_derecha.prisma(10, 4, 34, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//parte de abajo mueble 2

	glPushMatrix();
	glTranslatef(-40, -38, 17); //x, y z
	glRotatef(90, 0.0f, 0.0f, 1);
	pared_derecha.prisma(10, 4, 32.5, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//puerta

	glPushMatrix();
	glTranslatef(-40, -18, 25); //x, y z
	glRotatef(15, 0.0f, 0.0f, 1);
	pared_derecha.prisma(38, 2, 16.25, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//fondo
	glPushMatrix();
	glTranslatef(-48, -18, 17); //x, y z
	glRotatef(15, 0.0f, 0.0f, 1);
	pared_derecha.prisma(38, 1, 32.5, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//repisita

	glPushMatrix();
	glTranslatef(-46, -23, 17); //x, y z
	glRotatef(90, 0.0f, 0.0f, 1);
	pared_derecha.prisma(10, 4, 32.5, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//tapa izquierda
	glPushMatrix();
	glTranslatef(-43.5, -25, 0); //x, y z
	glRotatef(17, 0.0f, 0.0f, 1);
	pared_derecha.prisma(43, 10, 2, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//parte 2

	glPushMatrix();
	glTranslatef(-50.0, -2.2, 0); //x, y z
	glRotatef(90, 0.0f, 0.0f, 1);
	glRotatef(180, 1.0f, 0.0f, 0.0f);
	pared_derecha.prisma(10, 8, 1.9, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//tapa derecha

	//tapa derecha
	glPushMatrix();
	glTranslatef(-43.5, -25, 32.3); //x, y z
	glRotatef(17, 0.0f, 0.0f, 1);
	pared_derecha.prisma(43, 10, 2, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//parte 2

	glPushMatrix();
	glTranslatef(-50.0, -2.2, 32); //x, y z
	glRotatef(90, 0.0f, 0.0f, 1);
	glRotatef(180, 1.0f, 0.0f, 0.0f);
	pared_derecha.prisma(10, 8, 1.9, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//ropa y cosas

	glPushMatrix();
	glTranslatef(-43, -20, 7); //x, y z
	//glRotatef(90, 0.0f, 0.0f, 1);

	pared_derecha.prisma(2, 4, 7, ropa3.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//ropa arriba fondo
	glPushMatrix();
	glTranslatef(-43, -20, 16); //x, y z
	//glRotatef(90, 0.0f, 0.0f, 1);

	pared_derecha.prisma(2, 4, 5, ropa2.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//ropa abajo
	glPushMatrix();
	glTranslatef(-38, -35, 7); //x, y z
	//glRotatef(90, 0.0f, 0.0f, 1);

	pared_derecha.prisma(2, 4, 9, ropa1.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//maceta grande

	glPushMatrix();
	
	glTranslatef(60, -11, 90);
	
	maceta();
	glPopMatrix();
	//maceta 2
	glPushMatrix();

	glTranslatef(65, -11, 90);

	maceta();
	glPopMatrix();

	//maceta 3
	glPushMatrix();

	glTranslatef(70, -11, 90);

	maceta();
	glPopMatrix();

	//elemento librero

	glPushMatrix();
	glTranslatef(24, 17, 74); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(35, 0.5, 22, l1.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//2

	glPushMatrix();
	glTranslatef(-2, 53, 74); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(28, 0.5, 25, l1.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//cosas librero

	glPushMatrix();
	glTranslatef(-2.5, 80, 76); //x, y z
	pared_derecha.prisma(12, 10, 5, libros.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//cosas librero 2

	glPushMatrix();
	glTranslatef(-30, 80, 76); //x, y z
	pared_derecha.prisma(12, 15, 5, ropa2.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//

	glPushMatrix();
	glTranslatef(25, 78, 76); //x, y z
	bola.esfera(5, 50, 10, balon.GLindex); //radio //altura
	glPopMatrix();
	


	//pared librero



	glPushMatrix();
	glTranslatef(-19, 33, 80); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(145, 1, 125, estante.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//repisa horizontal 1

	glPushMatrix();
	glTranslatef(26.5, 70, 76.5); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(7, 8, 32, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//television

	glPushMatrix();
	glTranslatef(-30, 46, 75.5); //x, y z
	//glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(14, 13, 4, television2.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-30, 51, 73.75); //x, y z
	//glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(1, 12, 1, television2.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//television pantalla

	glPushMatrix();
	glTranslatef(-30, 45, 73.4); //x, y z
	//glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(13, 13, .005, television.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//////////////////////////////////////////
	//tele2

	glPushMatrix();
	glTranslatef(0, 10, 76); //x, y z
	//glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(18, 15, 4, television2.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//pantalla2

	glPushMatrix();
	glTranslatef(0, 10, 74.3); //x, y z
	//glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(15, 13, 1, tv.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//bocina en librero

	glPushMatrix();
	glTranslatef(-30, 10, 76); //x, y z
	//glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(18, 20, 4, b2.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	

	


	///repisa horizontal no larga

	glPushMatrix();
	glTranslatef(-19.5, 70, 76.5); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(7, 8, 60, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//pequeñña rapisa

	glPushMatrix();
	glTranslatef(-60, 60, 76.5); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(7, 8, 20, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//pequeña rapisa 2

	glPushMatrix();
	glTranslatef(-63, 80, 76.5); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(7, 8, 26, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();



	//repisa horizontal 2

	glPushMatrix();
	glTranslatef(25.5, 35, 76.5); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(7, 8, 33.5, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//repisa horizontal larga

	glPushMatrix();
	glTranslatef(-27, 35, 76.5); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(7, 8, 75, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//repisa superior

	glPushMatrix();
	glTranslatef(-19, 103, 76.5); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(7, 8, 126, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//inferior

	glPushMatrix();
	glTranslatef(-19, -3, 76.5); //x, y z
	glRotatef(90, 0.0f, 1.0f, 0.0f);
	pared_derecha.prisma(7, 8, 126, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//repisa librero

	glPushMatrix();
	glTranslatef(40, 49.2, 76); //x, y z

	pared_derecha.prisma(113, 7, 8, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//2
	glPushMatrix();
	glTranslatef(12, 49.2, 76); //x, y z

	pared_derecha.prisma(113, 3, 8, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(-16, 49.2, 76); //x, y z

	pared_derecha.prisma(113, 3, 8, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//4
	glPushMatrix();
	glTranslatef(-50, 49.2, 76); //x, y z

	pared_derecha.prisma(113, 3, 8, repisa.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//vigas techo

	//viga superior izquierda

	glPushMatrix();
	glTranslatef(22.8, 134.5, 0); //x, y z

	pared_derecha.prisma(2, 5, 150, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//////viga superior derecha

	glPushMatrix();
	glTranslatef(-61.8, 134.5, 0); //x, y z

	pared_derecha.prisma(2, 5, 150, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga superior enmedio derecha

	glPushMatrix();
	glTranslatef(-39.0, 134.5, 0); //x, y z

	pared_derecha.prisma(5, 5, 150, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga de lampara derecha

	glPushMatrix();
	glTranslatef(-39.0, 107.5, 0); //x, y z

	pared_derecha.prisma(2, 7, 150, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga lampara izquierda

	glPushMatrix();
	glTranslatef(0, 107.5, 0); //x, y z

	pared_derecha.prisma(2, 7, 150, vblanca.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga superior enmedio izquierda

	glPushMatrix();
	glTranslatef(0, 134.5, 0); //x, y z

	pared_derecha.prisma(5, 5, 150, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga fondo

	glPushMatrix();
	glTranslatef(-19.3, 134.5, 75); //x, y z

	pared_derecha.prisma(5, 90, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//izquierda

	glPushMatrix();
	glTranslatef(32.5, 120, 75); //x, y z
	glRotatef(-60, 0.0f, 0.0f, 1);
	pared_derecha.prisma(6, 33, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//1

	glPushMatrix();
	glTranslatef(32.5, 120, 30); //x, y z
	glRotatef(-60, 0.0f, 0.0f, 1);
	pared_derecha.prisma(6, 33, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//2

	glPushMatrix();
	glTranslatef(32.5, 120, -12.4); //x, y z
	glRotatef(-60, 0.0f, 0.0f, 1);
	pared_derecha.prisma(6, 33, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//3 

	glPushMatrix();
	glTranslatef(32.5, 120, -72.6); //x, y z
	glRotatef(-60, 0.0f, 0.0f, 1);
	pared_derecha.prisma(6, 33, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga enmedio

	glPushMatrix();
	glTranslatef(-19.3, 134.5, 30); //x, y z

	pared_derecha.prisma(5, 90, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga en medio 2

	glPushMatrix();
	glTranslatef(-19.3, 134.5, -72.6); //x, y z

	pared_derecha.prisma(5, 90, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga 3

	glPushMatrix();
	glTranslatef(-19.3, 134.5, -12.4); //x, y z

	pared_derecha.prisma(5, 90, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//viga inclinadaderecha

	glPushMatrix();
	glTranslatef(-70.5, 120, -72.6); //x, y z
	glRotatef(60, 0.0f, 0.0f, 1);
	pared_derecha.prisma(6, 33, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//1
	glPushMatrix();
	glTranslatef(-70.5, 120, -12.4); //x, y z
	glRotatef(60, 0.0f, 0.0f, 1);
	pared_derecha.prisma(6, 33, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//2
	glPushMatrix();
	glTranslatef(-70.5, 120, 30); //x, y z
	glRotatef(60, 0.0f, 0.0f, 1);
	pared_derecha.prisma(6, 33, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//3
	glPushMatrix();
	glTranslatef(-70.5, 120, 75); //x, y z
	glRotatef(60, 0.0f, 0.0f, 1);
	pared_derecha.prisma(6, 33, 5, vnegra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	///cama y partes de la cama
	///primer escalon
	glPushMatrix();
	glTranslatef(-0.2, -37, 55); //x, y z
	glRotatef(-90, 0.0f, 0.0f, 1);
	pared_derecha.prisma(85, 7, 40, piecama.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//pie cama dos
	glPushMatrix();
	glTranslatef(-0.2, -30, 60); //x, y z
	glRotatef(-90, 0.0f, 0.0f, 1);
	pared_derecha.prisma(88, 7, 30, piecama.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//tapa de pie de cama 1

	glPushMatrix();
	glTranslatef(-0.2, -37, 35.1); //x, y z
	glRotatef(-90, 0.0f, 0.0f, 1);
	pared_derecha.prisma(85, 7, 1, alfombra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//tapa pie de cama 2

	glPushMatrix();
	glTranslatef(-0.2, -30, 44.2); //x, y z
	glRotatef(-90, 0.0f, 0.0f, 1);
	pared_derecha.prisma(89, 7, 1, alfombra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//tapa pie cama 3 

	glPushMatrix();
	glTranslatef(-3, -23, 49.0); //x, y z
	glRotatef(-90, 0.0f, 0.0f, 1);
	pared_derecha.prisma(92, 7, 1, alfombra.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//cama

	glPushMatrix();
	glTranslatef(-3, -17, 62); //x, y z
	glRotatef(-90, 0.0f, 0.0f, 1);
	pared_derecha.prisma(92, 20, 25, camax.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//almohada

	glPushMatrix();
	glTranslatef(38, -5, 62); //x, y z
	glRotatef(17, 0.0f, 0.0f, 1);
	pared_derecha.prisma(5, 9, 13, almohada.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	glPushMatrix();
	
	//pelota();
	
	//animaciones simples////////////////////////////////////////////////////
	if (y >= 8)
	{
		rebota = false;
		rebota2 = true;
	}

	if (y <= -3)
	{
		rebota = true;
		rebota2 = false;
	}

	if (puerta >= 90)
	{
		abrir = false;
	}

	if (puerta <= 0)
	{
		cerrar = false;
	}


	///////////////techo
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glAlphaFunc(GL_GREATER, 0.1);

	////techo parte1///////////////////////////////////////////////////////////////////////////



	//translucidez
	glPushMatrix();
	glEnable(GL_BLEND);     // Turn Blending On
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, vidrio.GLindex);
	//glBegin(GL_QUADS);
	glColor4f(1.0, 1.0, 1.0, 0.6f); //Este sirve para que varies el porcentaje de opacidad segun lo necesites altera el ultimo valor que  va de 0-1 donde 0 es el 0% y 1 el 100% de opacidad
	

	//codigo aqui


	//tapas laterales

	glPushMatrix();
	glTranslatef(-20, 117, -75); //x, y z
	//glRotatef(-30, 0.0f, 0.0f, 1);
	pared_derecha.prisma(30, 90, 1, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-20, 117, 78); //x, y z
	//glRotatef(-30, 0.0f, 0.0f, 1);
	pared_derecha.prisma(30, 90, 1, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//retoques
	glPushMatrix();
	glTranslatef(31.5, 112.5, 78); //x, y z
	//glRotatef(-30, 0.0f, 0.0f, 1);
	pared_derecha.prisma(12, 10, 1, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	glPushMatrix();
	glTranslatef(27.5, 116.5, 78); //x, y z
	//glRotatef(-30, 0.0f, 0.0f, 1);
	pared_derecha.prisma(21, 5, 1, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//retoques 2

	glPushMatrix();
	glTranslatef(-69.5, 112.5, 78); //x, y z
	//glRotatef(-30, 0.0f, 0.0f, 1);
	pared_derecha.prisma(12, 10, 1, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-67, 116.5, 78); //x, y z
	//glRotatef(-30, 0.0f, 0.0f, 1);
	pared_derecha.prisma(21, 5, 1, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//frontales


	glPushMatrix();
	glTranslatef(-69.5, 112.5, -75); //x, y z
	//glRotatef(-30, 0.0f, 0.0f, 1);
	pared_derecha.prisma(12, 10, 1, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-67, 116.5, -75); //x, y z
	//glRotatef(-30, 0.0f, 0.0f, 1);
	pared_derecha.prisma(21, 5, 1, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	//frontales 2

	glPushMatrix();
	glTranslatef(31.5, 112.5, -75); //x, y z
	//glRotatef(-30, 0.0f, 0.0f, 1);
	pared_derecha.prisma(12, 10, 1, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();


	glPushMatrix();
	glTranslatef(27.5, 116.5, -75); //x, y z
	//glRotatef(-30, 0.0f, 0.0f, 1);
	pared_derecha.prisma(21, 5, 1, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();




	////////////////////////////////////////////
	//////
	glPushMatrix();
	glTranslatef(-73, 120.5, 0); //x, y z
	glRotatef(-30, 0.0f, 0.0f, 1);
	pared_derecha.prisma(35, 0.3, 150, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();
	//techo arriba
	glPushMatrix();

	glTranslatef(-19.5, 136, 0); //x, y z
	glRotatef(-90, 0.0f, 0.0f, 1);
	pared_derecha.prisma(90, 0.3, 150, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();

	//techo 2//////////////////////////////////////////////////////////////////////////////////////
	glPushMatrix();

	
	glTranslatef(34.2, 120.5, 0); //x, y z
	glRotatef(30, 0.0f, 0.0f, 1);
	glRotatef(180, 0.0f, 0.0f, 1);
	pared_derecha.prisma(35, 0.4, 150, vidrio.GLindex); //ALTO Y , ANCHO X ANCHO Z
	glPopMatrix();





	glDisable(GL_BLEND);        // Turn Blending Off
	glEnable(GL_DEPTH_TEST);							  //glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glPopMatrix();

	trompox();




}	///////////////////////////////////////////////////////////////////////////////////////////



	

GLuint createDL() 
{
	GLuint ciudadDL;
	//GLuint cieloDL;

	// Create the id for the list
	ciudadDL = glGenLists(1);
	// start list
	glNewList(ciudadDL,GL_COMPILE);
	
	glEndList();

	return(ciudadDL);
}
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);

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

    /////////////////////////////////////texturas proyecto*******************************************************
	trompo.LoadTGA("estructura/trompo.tga");
	trompo.BuildGLTexture();
	trompo.ReleaseImage();


	pared.LoadTGA("estructura/pared.tga");
	pared.BuildGLTexture();
	pared.ReleaseImage();
	//texturas librero

	l1.LoadTGA("estructura/l1.tga");
	l1.BuildGLTexture();
	l1.ReleaseImage();

	//macetaz

	macetaz.LoadTGA("estructura/maceta.tga");
	macetaz.BuildGLTexture();
	macetaz.ReleaseImage();
	///textura piso

	piso.LoadTGA("estructura/piso.tga");
	piso.BuildGLTexture();
	piso.ReleaseImage();
	//textura ventanas superiores
	cielo.LoadTGA("estructura/cielo.tga");
	cielo.BuildGLTexture();
	cielo.ReleaseImage();

	//repisa juguetes

	
	repisax.LoadTGA("estructura/repisax.tga");
	repisax.BuildGLTexture();
	repisax.ReleaseImage();

	//textura teclado

	//balon
	balon.LoadTGA("estructura/balon.tga");
	balon.BuildGLTexture();
	balon.ReleaseImage();

	//terciolepo azul
	terciopelo.LoadTGA("estructura/terciopelo.tga");
	terciopelo.BuildGLTexture();
	terciopelo.ReleaseImage();

	teclado.LoadTGA("estructura/teclado.tga");
	teclado.BuildGLTexture();
	teclado.ReleaseImage();
	//textura estante morado
	estante.LoadTGA("estructura/estante.tga");
	estante.BuildGLTexture();
	estante.ReleaseImage();

	//libros
	libros.LoadTGA("estructura/libros.tga");
	libros.BuildGLTexture();
	libros.ReleaseImage();
	//textura piecama  escalones
	piecama.LoadTGA("estructura/piecama.tga");
	piecama.BuildGLTexture();
	piecama.ReleaseImage();
	//alfombra cafe
	alfombra.LoadTGA("estructura/alfombra.tga");
	alfombra.BuildGLTexture();
	alfombra.ReleaseImage();

	//textura cama
	camax.LoadTGA("estructura/cama.tga");
	camax.BuildGLTexture();
	camax.ReleaseImage();
	//almohada
	almohada.LoadTGA("estructura/almohada.tga");
	almohada.BuildGLTexture();
	almohada.ReleaseImage();

	//cajon pared
	cajonpared.LoadTGA("estructura/cajonpared.tga");
	cajonpared.BuildGLTexture();
	cajonpared.ReleaseImage();

	//forro
	forro.LoadTGA("estructura/forro.tga");
	forro.BuildGLTexture();
	forro.ReleaseImage();

	//forro
	repisa.LoadTGA("estructura/repisa.tga");
	repisa.BuildGLTexture();
	repisa.ReleaseImage();

	//gabinete
		
	gabinete.LoadTGA("estructura/gabinete.tga");
	gabinete.BuildGLTexture();
	gabinete.ReleaseImage();


	//forro
	vidrio.LoadTGA("estructura/vidrio.tga");
	vidrio.BuildGLTexture();
	vidrio.ReleaseImage();

	//vnegra
	vnegra.LoadTGA("estructura/vnegra.tga");
	vnegra.BuildGLTexture();
	vnegra.ReleaseImage();

	//metal
	metal.LoadTGA("estructura/metal.tga");
	metal.BuildGLTexture();
	metal.ReleaseImage();

	//vnegra
	vblanca.LoadTGA("estructura/vblanca.tga");
	vblanca.BuildGLTexture();
	vblanca.ReleaseImage();

	//fotos

	//vnegra
	padres.LoadTGA("estructura/padres.tga");
	padres.BuildGLTexture();
	padres.ReleaseImage();

	///ropas

	//vnegra
	ropa1.LoadTGA("estructura/ropa1.tga");
	ropa1.BuildGLTexture();
	ropa1.ReleaseImage();

	//vnegra
	foto.LoadTGA("estructura/foto.tga");
	foto.BuildGLTexture();
	foto.ReleaseImage();

	//vnegra
	ropa2.LoadTGA("estructura/ropa2.tga");
	ropa2.BuildGLTexture();
	ropa2.ReleaseImage();

	//vnegra
	ropa3.LoadTGA("estructura/ropa3.tga");
	ropa3.BuildGLTexture();
	ropa3.ReleaseImage();

	//bocinas

		//vnegra
	b1.LoadTGA("estructura/bocina1.tga");
	b1.BuildGLTexture();
	b1.ReleaseImage();

	//vnegra
	b2.LoadTGA("estructura/bocina2.tga");
	b2.BuildGLTexture();
	b2.ReleaseImage();

	//avion2
	a2.LoadTGA("estructura/a2.tga");
	a2.BuildGLTexture();
	a2.ReleaseImage();

	//avion2
	a1.LoadTGA("estructura/a1.tga");
	a1.BuildGLTexture();
	a1.ReleaseImage();

	//vnegra
	c.LoadTGA("estructura/componente.tga");
	c.BuildGLTexture();
	c.ReleaseImage();

	//vnegra
	television.LoadTGA("estructura/television.tga");
	television.BuildGLTexture();
	television.ReleaseImage();

	//vnegra
	television2.LoadTGA("estructura/television2.tga");
	television2.BuildGLTexture();
	television2.ReleaseImage();

	//vnegra
	maderita.LoadTGA("estructura/maderita.tga");
	maderita.BuildGLTexture();
	maderita.ReleaseImage();

	//vnegra
	garrafon.LoadTGA("estructura/garrafon.tga");
	garrafon.BuildGLTexture();
	garrafon.ReleaseImage();
	//tv2
	tv.LoadTGA("estructura/tv.tga");
	tv.BuildGLTexture();
	tv.ReleaseImage();
	//planta
	planta.LoadTGA("estructura/planta.tga");
	planta.BuildGLTexture();
	planta.ReleaseImage();

	//puerta
	puertax.LoadTGA("estructura/puerta.tga");
	puertax.BuildGLTexture();
	puertax.ReleaseImage();


	/////////////////////////////////////////////////////////////////////////////TEXTURAS PROYECTO
    text1.LoadBMP("01.bmp"); //textura skybox
	text1.BuildGLTexture();
	text1.ReleaseImage();

	


	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

	//NEW Crear una lista de dibujo
	ciudad_display_list = createDL();

	

	/*******Valores por default para la animación por keyframes para animación guardada*****/
	KeyFrame[0].posX = 0;
	KeyFrame[0].posY = -35;
	KeyFrame[0].posZ = -20.5;
	KeyFrame[0].rotRodIzq = 0;
	KeyFrame[0].giroMonito = 0;
	

	KeyFrame[1].posX = 0;
	KeyFrame[1].posY = 72.5;
	KeyFrame[1].posZ = 43.5;
	KeyFrame[1].rotRodIzq = 60;
	KeyFrame[1].giroMonito = -90.0;
	

	KeyFrame[2].posX = -40;
	KeyFrame[2].posY = 22.5;
	KeyFrame[2].posZ = 40.0;
	KeyFrame[2].rotRodIzq = -20.0;
	KeyFrame[2].giroMonito = 0;


	KeyFrame[3].posX = 20;
	KeyFrame[3].posY = 2.5;
	KeyFrame[3].posZ = 4.0;
	KeyFrame[3].rotRodIzq = 40.0;
	KeyFrame[3].giroMonito = 45;
	

	KeyFrame[4].posX = 0;
	KeyFrame[4].posY = -35;
	KeyFrame[4].posZ = -20.5;
	KeyFrame[4].rotRodIzq = -40.0;
	KeyFrame[4].giroMonito = -45;


	///animacion guardada 2 

	/*******Valores por default para la animación por keyframes para animación guardada*****/
	KeyFrame2[0].posX2 = 10;
	KeyFrame2[0].posY2 = -28;
	KeyFrame2[0].posZ2 = -60.5;
	
	KeyFrame2[0].giroMonito2 = 0;
	

	KeyFrame2[1].posX2 = 30;
	KeyFrame2[1].posY2 = -28;
	KeyFrame2[1].posZ2 = 27;

	KeyFrame2[1].giroMonito2 = -90.0;


	KeyFrame2[2].posX2 = -30;
	KeyFrame2[2].posY2 = -28;
	KeyFrame2[2].posZ2 = 17;

	KeyFrame2[2].giroMonito2 = 50;


	KeyFrame2[3].posX2 = 26;
	KeyFrame2[3].posY2 = -10;
	KeyFrame2[3].posZ2 = 4.0;
	
	KeyFrame2[3].giroMonito2 = -45;


	KeyFrame2[4].posX2 = -15;
	KeyFrame2[4].posY2 = -28;
	KeyFrame2[4].posZ2 = -20.5;
	
	KeyFrame2[4].giroMonito2 = 45;








}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}
//////////////////////////////////////////////////////////////funcion de dibujado
void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glPushMatrix();
	

	glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	
		glPushMatrix();
			glTranslatef(-20, 0, -20);
		pelota();
		glPopMatrix();


		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			////////////////////////////////////////////////////////creamos cuarto hey
			glPushMatrix();
			glScalef(1.0, 0.5, 1.0);
			glTranslatef(-15, 4, -10); //X, Y , Z
			glRotatef(180, 0, 1, 0);
			glDisable(GL_LIGHTING);
			glScalef(0.3, 0.3, 0.3);
			cuarto(); ///funcion que dibuja el cuarto y todos los elementos dentro de el
			
			glPopMatrix();
			glPopMatrix();
			glPopMatrix();

			
	
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion() //funcion animaciones sencillaz
{

	fig3.text_izq -= 0.001;
	fig3.text_der -= 0.001;
	if (fig3.text_izq < -1)
		fig3.text_izq = 0;
	if (fig3.text_der < 0)
		fig3.text_der = 1;



	if (rebota) {

		y += 0.2;

		
	}
	if (rebota2) {
		y -= 0.2;
	}

	if (abrir)
	{
		puerta += 1.0;
		
	}

	if (cerrar)
	{
		
		puerta -= 1.0;
	}




	//animacion de la nave
	if (play)
	{
		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex > FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();
			}
		}
		else
		{
			//Draw animation
			posX += KeyFrame[playIndex].incX;
			posY += KeyFrame[playIndex].incY;
			posZ += KeyFrame[playIndex].incZ;

			rotRodIzq += KeyFrame[playIndex].rotInc;
			giroMonito += KeyFrame[playIndex].giroMonitoInc;
			//movBrazoDer += KeyFrame[playIndex].movBrazoDerInc;

			i_curr_steps++;
		}

	}
	//////////////animacion2

	if (play2)
	{
		if (i_curr_steps2 >= i_max_steps2) //end of animation between frames?
		{
			playIndex2++;
			if (playIndex2 > FrameIndex2 - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex2 = 0;
				play2 = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps2 = 0; //Reset counter
								  //Interpolation
				interpolation2();
			}
		}
		else
		{
			//Draw animation
			posX2 += KeyFrame2[playIndex2].incX2;
			posY2 += KeyFrame2[playIndex2].incY2;
			posZ2 += KeyFrame2[playIndex2].incZ2;

			//rotRodIzq += KeyFrame[playIndex].rotInc;
			giroMonito2 += KeyFrame2[playIndex2].giroMonitoInc2;
			//movBrazoDer += KeyFrame[playIndex].movBrazoDerInc;

			i_curr_steps2++;
		}

	}


	/*frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
		timebase = time;
		frame = 0;
	}*/



			

		
		

	
	glutPostRedisplay();
}


void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'u':
				objCamera.UpDown_Camera(CAMERASPEED + 0.2);

				break;

		case 'n':
					objCamera.UpDown_Camera(CAMERASPEED - 0.2);
					break;


		case 'k':		//
		case 'K':
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}

			break;

		case 'l':						
		case 'L':
			if(play==false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;


			///segunda animacion
		case 'm':
		case 'M':
			if (play2 == false && (FrameIndex2 > 1))
			{

				resetElements2();
				//First Interpolation				
				interpolation2();

				play2 = true;
				playIndex2 = 0;
				i_curr_steps2 = 0;
			}
			else
			{
				play2 = false;
			}
			break;


		case 'y':						
		case 'Y':
			posZ++;
			printf("%f \n", posZ);
			break;

		case 'g':						
		case 'G':
			posX--;
			printf("%f \n", posX);
			break;

		case 'h':						
		case 'H':
			posZ--;
			printf("%f \n", posZ);
			break;

		case 'j':						
		case 'J':
			posX++;
			printf("%f \n", posX);
			break;

		case 'b':						
			rotRodIzq++;
			printf("%f \n", rotRodIzq);
			break;

		case 'B':						
			rotRodIzq--;
			printf("%f \n", rotRodIzq);
			break;

		/*case 'p':						
			giroMonito++;
			break;

		case 'P':						
			giroMonito--;
			break;*/

		case 'o':
				abrir = true;
				cerrar = false;
				break;

		case 'O':
					abrir = true;
					cerrar = false;
					break;

		case 'c':
						cerrar = true;
						abrir = false;
						break;

		case 'C':
							cerrar = true;
							abrir = false;
							break;

		case 'p':
			encendido = true;
			
			break;

		case 'P':
			encendido = true;
			break;

		case 'q':
			encendido = false;
			break;
		case 'Ñ':
			encendido = false;
			break;


		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
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
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

void menuKeyFrame( int id)
{
	switch (id)
	{
		case 0:	//Save KeyFrame
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}
			break;

		case 1:	//Play animation
			if(play==false && FrameIndex >1)
			{

				resetElements();
				//First Interpolation
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;


	}
}


void menu( int id)
{
	
}



int main ( int argc, char** argv )   // Main Function
{
  int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Proyecto final Alonso Espinosa Caballero"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );

  submenu = glutCreateMenu	  ( menuKeyFrame );
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion Monito", submenu);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);


  glutMainLoop        ( );          // 

  return 0;
}