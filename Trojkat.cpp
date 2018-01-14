#include "trojkat.h"
//kk
Trojkat::Trojkat()
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

Trojkat::Trojkat(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

Trojkat::~Trojkat(void)
{
	std::cout << "destruktor!" << std::endl;
	system("pause");
}

void Trojkat::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	glutCreateWindow("okno");
}

void Trojkat::inicjalizacjaGlew(){
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK){
		std::cerr << "Nie udalo sie" << glewGetErrorString(wynik) << std::endl;
		system("pause");
		exit(1);
	}
}

void Trojkat::stworzenieVAO(){
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);



}

void Trojkat::stworzenieVBO(){
	GLfloat Wierzcholki[9] = { 0.0f, 0.5f, 0.0f,
							   0.5f, 0.0f, 0.0f,
							   -0.5f, 0.0f, 0.0f };
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Wierzcholki), Wierzcholki, GL_STATIC_DRAW);
}

void  Trojkat::wyswietl()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	/*Shaders okno(786, 1024, 100, 100);*/
	Trojkat trojkat(786, 1024, 100, 100);
	trojkat.stworzenieOkna(argc, argv);
	trojkat.inicjalizacjaGlew();
	trojkat.stworzenieVAO();
	trojkat.stworzenieVBO();
	glutDisplayFunc(trojkat.wyswietl);
	glClearColor(0.2f, 0.1f, 0.0f, 0.0f);
	glutMainLoop();

	return 0;


}
