#ifndef TROJKAT_H
#define TROJKAT_H
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

GLuint VAO;
GLuint VBO;

class Trojkat
{
private:
	int wysokoscOkna;
	int szerokoscOkna;
	int polozenieOknaX;
	int polozenieOknaY;

public:
	Trojkat(void);
	Trojkat(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY);
	~Trojkat(void);
	void stworzenieOkna(int argc, char** argv);
	void inicjalizacjaGlew();
	static void wyswietl();
	void stworzenieVAO();
	void stworzenieVBO();
};
//-----


#endif /* TROJKAT_H*/
