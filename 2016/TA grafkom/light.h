int isLight0active = 1; //status cahaya 1 (nyala/mati)
int isLight1active = 1; //status cahaya 2 (nyala/mati)
int isLight2active = 1; //status cahaya 3 (nyala/mati)
int isLight3active = 1; //status cahaya 4 (nyala/mati)
int toggleLighting = 1;

void initLighting(void) {
	glColor3f(0.0, 0.0, 0.0); //warnai bayangan menjadi hitam

	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 0.0 };
	GLfloat light_specular[] = { 0.0, 0.0, 0.0, 0.0 };

	GLfloat light_diffuse1[] = { 1.0, 1.0, 1.0, 0.0 }; //nilai diffusi cahaya 1
	GLfloat light_diffuse2[] = { 1.0, 0.0, 0.0, 0.0 }; //nilai diffusi cahaya 2
	GLfloat light_diffuse3[] = { 0.0, 1.0, 0.0, 0.0 }; //nilai diffusi cahaya 3
	GLfloat light_diffuse4[] = { 0.0, 0.0, 1.0, 0.0 }; //nilai diffusi cahaya 4

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);

	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse3);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);

	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse4);
	glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);

	GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 0.0 };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 0.0 };
	GLfloat mat_shininess = { 30.0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

	//parameter spotlight dari cahaya 1
	GLfloat dirVector[] = { -1.0, -1.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dirVector);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 60.0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 1000.0);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_NORMALIZE);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
}

//render objek representasi dari lampu
void lamp(void){
	GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };

	if (isLight0active) {
		glPushMatrix();
		setPosition(3);
		glutSolidSphere(0.5, 20, 20);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		glPopMatrix();
	}

	if (isLight1active) {
		glPushMatrix();
		setPosition(5);
		glutSolidSphere(0.5, 20, 20);
		glLightfv(GL_LIGHT1, GL_POSITION, light_position);
		glPopMatrix();
	}

	if (isLight2active) {
		glPushMatrix();
		rotateY(3, 0);
		increase(3, 0);
		setPosition(6);
		glutSolidSphere(0.5, 20, 20);
		glLightfv(GL_LIGHT2, GL_POSITION, light_position);
		glPopMatrix();
	}

	if (isLight3active) {
		glPushMatrix();
		rotateY(3, 1);
		increase(3, 1);
		setPosition(4);
		glutSolidCone(1, 1, 3, 1);
		glLightfv(GL_LIGHT3, GL_POSITION, light_position);
		glPopMatrix();
	}
}
