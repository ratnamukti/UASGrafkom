#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "glut.h"
#include "texture.h"
#include "animation.h"
#include "light.h"
#include "shadow.h"
#include "model.h"

float width = 800.0, height = 600.0; //resolusi awal window

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, h, z, x + lx, h, z + lz, 0.0f, 1.0f, 0.0f);

	glPushMatrix();
	lamp();
	room();
	toy();
	glTranslatef(-6.0, 0.0, -4.0); //geser sumbu dari arah gerakkan objek
	glRotatef(15.0, 0.0, 1.0, 0.0);
	baby(1);
	babyShadow();

	glRotatef(-15.0, 0.0, 1.0, 0.0);
	glTranslatef(5.0, 2.0, 4.0); //geser sumbu dari arah gerakkan objek
	increase(3, 4);
	rotateY(3, 4);
	dog(0);
	glTranslatef(0.0, -2.0, 0.0); //geser sumbu dari arah gerakkan objek
	dogShadow();

	
	rotateY(3, 4);
	walkingman();
	walkingmanShadow();
	//if (selectedObject){
		//rotateY(3, 4);
		//gluLookAt(x, h, z, x + lx, h, z + lz, 0.0f, 1.0f, 0.0f);
	//}

	glRotatef(-70.0, 0.0, 1.0, 0.0); //beri jarak antara 2 objek lain
	ant(1);
	antShadow();
	glPopMatrix();

	

	glFlush();
	glutSwapBuffers();
}

void resize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0f, (float) w / (float) h, 1.0f, 60.0f);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
	//jika objek kamera dipilih maka gerakkan penglihatan kamera,
	//selain itu gerakkan objek yang dipilih
	if (key == 'W' || key == 'w') {
		if (!selectedObject) {
			x += lx * fraction;
			z += lz * fraction;
		}
		else {
			position[selectedObject - 1][0] -= 0.1;
		}
	}
	else if (key == 'S' || key == 's') {
		if (!selectedObject) {
			x -= lx * fraction;
			z -= lz * fraction;
		}
		else {
			position[selectedObject - 1][0] += 0.1;
		}
	}
	else if (key == 'A' || key == 'a') {
		if (!selectedObject) {
			angle -= 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
		}
		else {
			position[selectedObject - 1][2] -= 0.1;
		}
	}
	else if (key == 'D' || key == 'd') {
		if (!selectedObject) {
			angle += 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
		}
		else {
			position[selectedObject - 1][2] += 0.1;
		}
	}

	//jika objek yang dipilih adalah kamera maka gerakkan pandangan kamera
	else if (key == 'Q' || key == 'q') {
		if (!selectedObject) {
			h += fraction;
		}
	}
	else if (key == 'E' || key == 'e') {
		if (!selectedObject) {
			h -= fraction;
		}
	}

	//hidupkan/matikan mode animasi
	else if (key == 'T' || key == 't') {
		togglePause();
	}

	else if (key == 'Y' || key == 'y') {
		if (isFilled)
			toggleLighting = !toggleLighting;
	}

	//hidupkan/matikan mode rendering
	else if (key == 'R' || key == 'r') {
		if (isFilled) {
			glColor3f(1.0, 1.0, 1.0);
			glDisable(GL_LIGHTING); //matikan lampu supaya wireframe terlihat jelas
			resetTexture();
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			toggleLighting = 0;
		}
		else {
			glColor3f(0.0, 0.0, 0.0);
			glEnable(GL_LIGHTING);
			initTexture();
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			toggleLighting = 1;
		}
		isFilled = !isFilled;
	}

	//hidupkan/matikan lampu
	else if (key == 'U' || key == 'u') {
		if (isLight0active)
			glDisable(GL_LIGHT0);
		else
			glEnable(GL_LIGHT0);
		isLight0active = !isLight0active;
	}
	else if (key == 'I' || key == 'i') {
		if (isLight1active)
			glDisable(GL_LIGHT1);
		else
			glEnable(GL_LIGHT1);
		isLight1active = !isLight1active;
	}
	else if (key == 'O' || key == 'o') {
		if (isLight2active)
			glDisable(GL_LIGHT2);
		else
			glEnable(GL_LIGHT2);
		isLight2active = !isLight2active;
	}
	else if (key == 'P' || key == 'p') {
		if (isLight3active)
			glDisable(GL_LIGHT3);
		else
			glEnable(GL_LIGHT3);
		isLight3active = !isLight3active;
	}

	//pilih objek
	else if (key == '0') {
		selectedObject = 0; //objek kamera dipilih
		x = 0.0f;
		z = 30.0f;
		h = 0.0;
	}
	else if (key == '1') {
		selectedObject = 1; //objek anjing dipilih
		//x = position[0][0];
		//h = position[0][1];
		//z = position[0][2];
	}
	else if (key == '2') {
		selectedObject = 2; //objek manusia dipilih
//		x = position[1][0];
//		h = position[1][1];
//		z = position[1][2];
	}
	else if (key == '3') {
		selectedObject = 3; //cahaya laba-laba dipilih
	}
	else if (key == '4') {
		selectedObject = 4; //cahaya 1 dipilih
	}
	else if (key == '5') {
		selectedObject = 5; //cahaya 4 dipilih
	}
}

void main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Proyek Akhir");
	
	initTexture();
	initLighting();
	//PlaySound(TEXT("2_fast_2_furios.mp3"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
