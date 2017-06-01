#define HEAD_HEIGHT 2.0
#define HEAD_RADIUS 2.0
#define TORSO_HEIGHT 5.0
#define TORSO_RADIUS 5.0
#define UPPER_ARM_HEIGHT 5.0
#define LOWER_ARM_HEIGHT 5.0
#define UPPER_ARM_RADIUS 0.5
#define LOWER_ARM_RADIUS 0.5
#define UPPER_LEG_RADIUS 0.5
#define LOWER_LEG_RADIUS 0.5
#define LOWER_LEG_HEIGHT 5.0
#define UPPER_LEG_HEIGHT 5.0

GLUquadricObj
*quad,
*babyquad,
*lua,  // quadric objek untuk kaki depan kiri atas
*lla,  // quadric objek untuk kaki depan kiri bawah
*rua,  // quadric objek untuk kaki depan kanan atas
*rla,  // quadric objek untuk kaki depan kanan bawah
*lll,  // quadric objek untuk kaki belakang kiri atas
*rll,  // quadric objek untuk kaki belakang kiri bawah
*rul,  // quadric objek untuk kaki belakang kanan atas
*lul;  // quadric objek untuk kaki belakang kanan bawah

void walkingman() {
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	setPosition(1);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	//glRotatef(0, 0.0, 0.0, -1.0);

		//kepala
		glPushMatrix();
		increment(2, 0, 10.0);
		rotateX(2, 0);
		glTranslatef(0.0, 0.0, -1.5);
		//glRotatef(theta[0], 1.0, 0.0, 0.0);

			//telinga kanan
			glPushMatrix();
			//glRotatef(theta[1], 1.0, 0.0, 0.0);
			glTranslatef(0.0, 1.0, -0.5);
			glRotatef(90.0, 0.3, 1.0, 0.0);
			gluDisk(quad, 0.0, 0.25, 10, 10);
			gluCylinder(quad, 0.25, 0.25, 0.25, 10, 10);
			glPopMatrix();

			//telinga kiri
			glPushMatrix();
			//glRotatef(theta[2], 1.0, 0.0, 0.0);
			glTranslatef(0.0, -1.0, -0.5);
			glRotatef(90.0, -0.3, 1.0, 0.0);
			gluDisk(quad, 0.0, 0.25, 10, 10);
			gluCylinder(quad, 0.25, 0.25, 0.25, 10, 10);
			glPopMatrix();

		//glTranslatef(-2.8, 0.0, 0.0);
		glutSolidSphere(1.0, 10, 10);
		glPopMatrix();

		//tangan kanan
		glPushMatrix();
		increment(2, 3, 15.0);
		rotateY(2, 3);
			//lengan bawah kanan
			glPushMatrix();
			increment(2, 7, 12.0);
			rotateZ(2, 7);
			glTranslatef(-0.25, 1.25, 2.0);
			glScalef(2.0, 0.5, 0.5);
			glutSolidCube(0.8);
			glPopMatrix();

			//lengan atas kanan
			glRotatef(-15.0, 0.0, 1.0, 0.0);
			glTranslatef(0.8, 1.25, 1.0);
			glScalef(0.5, 0.5, 2.0);
			glutSolidCube(0.8);
		glPopMatrix();

		//tangan kiri
		glPushMatrix();
		increment(2, 4, 15.0);
		rotateY(2, 4);

			glPushMatrix();
			glTranslatef(-0.25, -1.25, 2.0);
			increment(2, 8, 12.0);
			rotateY(2, 8);
			glScalef(2.0, 0.5, 0.5);
			glutSolidCube(0.8);
			glPopMatrix();

			//lengan kiri atas
			glRotatef(-15.0, 0.0, 1.0, 0.0);
			glTranslatef(0.8, -1.25, 1.0);
			glScalef(0.5, 0.5, 2.0);
			glutSolidCube(0.8);

		glPopMatrix();

			//tubuh bawah
		glPushMatrix();
		glTranslatef(-0.5, 0.0, 6.0);
	//glutSolidSphere(1.0, 10, 10);

	//kaki kanan
	glPushMatrix();
	increment(2, 5, 30.0);
	rotateY(2, 5);

	//telapak kaki kanan
	glPushMatrix();
	increment(2, 9, 12.0);
	rotateY(2, 9);
	glTranslatef(0.0, 0.5, 3.0);
	glScalef(1.0, 0.5, 0.5);
	glutSolidCube(0.8);
	glPopMatrix();

	//paha kanan
	glTranslatef(0.5, 0.5, 1.0);
	glScalef(0.5, 0.5, 5.0);
	glutSolidCube(0.8);
	glPopMatrix();

	//kaki kiri
	glPushMatrix();
	increment(2, 6, 30.0);
	rotateY(2, 6);

	//telapak kaki kiri
	glPushMatrix();
	increment(2,10, 12.0);
	glTranslatef(0.0, -0.5, 3.0);
	rotateY(2, 10);
	glScalef(1.0, 0.5, 0.5);
	glutSolidCube(0.8);
	glPopMatrix();

	//paha kiri
	glTranslatef(0.5, -0.5, 1.0);
	glScalef(0.5, 0.5, 5.0);
	glutSolidCube(0.8);
	glPopMatrix();

	glPopMatrix();

	//leher
	glPushMatrix();
	glTranslatef(0.15, 0.0, -0.50);
	gluDisk(quad, 0.0, 0.25, 10, 10);
	gluCylinder(quad, 0.25, 0.25, 2.0, 10, 10);
	glPopMatrix();

	//badan
	gluDisk(quad, 0.0, 1.0, 10, 10);
	gluCylinder(quad, 1.0, 1.0, 5.0, 10, 10);
	glPopMatrix();
}

//render objek anjing
void dog(int activateShadow) {
	quad = gluNewQuadric();
	gluQuadricDrawStyle(quad, GLU_FILL);

	if (activateShadow){ //berikan nilai 0 (false) supaya bayangan tidak bertekstur
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glBindTexture(GL_TEXTURE_2D, texture[0]);
	}

	glPushMatrix();
		glScalef(0.25, 0.25, 0.25);
		setPosition(0);
		glRotatef(90.0, 1.0, 0.0, 0.0);

		//kepala
		glPushMatrix();
			increment(0, 0, 5.0);
			rotateY(0, 0);
			//telinga kanan
			glPushMatrix();
				rotateX(0, 1);
				glScalef(0.1, 0.1, 1);
				glTranslatef(-25.4, 5.5, -0.5);
				glRotatef(135.0, -1.5, 1.0, 0.0);
				glutSolidCone(1.5, 3.0, 5, 2);
			glPopMatrix();

			//telinga kiri
			glPushMatrix();
				rotateX(0, 2);
				glScalef(0.1, 0.1, 1.0);
				glTranslatef(-25.4, -5.5, -0.5);
				glRotatef(135.0, 1.5, 1.0, 0.0);
				glutSolidCone(1.5, 3.0, 5, 2);
			glPopMatrix();
			
			//hidung
			/*glPushMatrix();
				glTranslatef(-3.0, 0.0, 1.0);
				glutSolidSphere(0.5, 10, 10);
			glPopMatrix();*/

			if (activateShadow) {
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_TEXTURE_GEN_S);
				glEnable(GL_TEXTURE_GEN_T);
				glBindTexture(GL_TEXTURE_2D, texture[8]);
			}

			glTranslatef(-2.8, 0.0, 0.0);
			glutSolidSphere(1.0, 10, 10);
		glPopMatrix();

		if (activateShadow) {
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glBindTexture(GL_TEXTURE_2D, texture[0]);
		}

		//kaki depan kanan
		glPushMatrix();
			increment(0, 3, 15.0);
			rotateY(0, 3);
			//telapak kaki depan kanan
			/*glPushMatrix();
				glTranslatef(-1.6, 1.25, 2.0);
				rotateY(0, 7);
				glScalef(1.0, 0.5, 0.5);
				glutSolidCube(0.8);
			glPopMatrix();*/

			//paha depan kanan
			glRotatef(-90.0, -90.0, 0.0, 0.0);
			glTranslatef(-0.8, -1.25, -5.5);
			glScalef(1.0, 1.0, 1.0);
			glutSolidCone(0.8,5,2,3);
		glPopMatrix();

		//kaki depan kiri
		glPushMatrix();
			increment(0, 4, 15.0);
			rotateY(0, 4);
			//telapak kaki depan kiri
			/*glPushMatrix();
				glTranslatef(-1.6, -1.25, 2.0);
				rotateY(0, 8);
				glScalef(1.0, 0.5, 0.5);
				glutSolidCube(0.8);
			glPopMatrix();*/

			//paha depan kiri
			glRotatef(270.0, 1.0, 0.0, 0.0);
			glTranslatef(-0.8, 1.25, -5.5);
			glScalef(1.0, 1.0, 1.0);
			glutSolidCone(0.8, 5, 2, 3);
		glPopMatrix();

		//kaki belakang kanan
		glPushMatrix();
			increment(0, 5, 15.0);
			//rotateY(0, 5);
			//telapak kaki belakang kanan
			/*glPushMatrix();
				glTranslatef(-0.5, 1.25, 2.0);
				//rotateY(0, 9);
				glScalef(1.0, 0.5, 0.5);
				glutSolidCube(0.8);
			glPopMatrix();*/

			//paha belakang kanan
			glRotatef(15.0, 0.0, 1.0, 0.0);
			glTranslatef(-0.8, 1.25, 1.5);
			glScalef(0.2, 0.2, 3.0);
			glutSolidCube(0.5);
		glPopMatrix();

		//kaki belakang kiri
		glPushMatrix();
			increment(0, 6, 15.0);
			//rotateY(0, 6);
			//telapak kaki belakang kiri
			/*glPushMatrix();
				glTranslatef(-0.5, -1.25, 2.0);
				//rotateY(0, 10);
				glScalef(1.0, 0.5, 0.5);
				glutSolidCube(0.8);
			glPopMatrix();*/

			//paha belakang kiri
			glRotatef(15.0, 0.0, 1.0, 0.0);
			glTranslatef(-0.8, -1.25, 1.5);
			glScalef(0.2, 0.2, 3.0);
			glutSolidCube(0.5);
		glPopMatrix();

		//kaki tambahan
		glPushMatrix();
		increment(0, 6, 15.0);
		glRotatef(15.0, 0.0, 1.0, 0.0);
		glTranslatef(0.0, -1.25, 1.5);
		glScalef(0.2, 0.2, 3.0);
		glutSolidCube(0.5);
		glPopMatrix();

		//kaki tambahan
		glPushMatrix();
		increment(0, 6, 15.0);
		glRotatef(15.0, 0.0, 1.0, 0.0);
		glTranslatef(0.0, 1.25, 1.5);
		glScalef(0.2, 0.2, 3.0);
		glutSolidCube(0.5);
		glPopMatrix();

		//kaki tambahan
		glPushMatrix();
		increment(0, 6, 15.0);
		glRotatef(15.0, 0.0, 1.0, 0.0);
		glTranslatef(-0.5, -1.25, 1.5);
		glScalef(0.2, 0.2, 3.0);
		glutSolidCube(0.5);
		glPopMatrix();

		//kaki tambahan
		glPushMatrix();
		increment(0, 6, 15.0);
		glRotatef(15.0, 0.0, 1.0, 0.0);
		glTranslatef(-0.5, 1.25, 1.5);
		glScalef(0.2, 0.2, 3.0);
		glutSolidCube(0.5);
		glPopMatrix();

		//ekor
		glPushMatrix();
			increment(0, 11, 15.0);
			rotateY(0, 11);
			glScalef(0.6, 0.65, 0.65);
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glTranslatef(0.0, 0.0, 2.0);
			glutSolidCone(1.5, 3.0, 10, 10);
		glPopMatrix();

		//badan
		glScalef(1.1, 0.65, 0.65);
		glutSolidSphere(2.0, 10, 10);
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
}

//render objek bayi

void baby(int activateShadow) {
	babyquad = gluNewQuadric();
	gluQuadricDrawStyle(babyquad, GLU_FILL);

	if (activateShadow) {
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glBindTexture(GL_TEXTURE_2D, texture[6]);
	}

	glPushMatrix();
		glScalef(0.3, 0.3, 0.3);
		setPosition(7);
		glRotatef(270.0, 0.0, 0.0, 1.0);
		glRotatef(60.0, 1.0, 0.0, 0.0);
		//rotateZ(2, 0);
		//kepala
		glPushMatrix();
			increment(2, 0, 5.0);
			rotateY(2, 0);
			glTranslatef(-3.8, -1.0, -0.7);
			glutSolidCube(1.5);
		glPopMatrix();

		if (activateShadow) {
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_TEXTURE_GEN_S);
			glEnable(GL_TEXTURE_GEN_T);
			glBindTexture(GL_TEXTURE_2D, texture[0]);
		}
		
		//kaki depan kanan
		glPushMatrix();
			increment(2, 3, 15.0);
			rotateZ(2, 3);
			//telapak kaki depan kanan
			/*glPushMatrix();
				glTranslatef(-1.6, 1.25, 1.6);
				//rotateY(0, 7);
				glRotatef(40.0, 0.0, 1.0, 0.0);
				glScalef(1.2, 0.5, 0.5);
				glutSolidCube(0.8);
			glPopMatrix();*/
			//paha depan kanan
			glRotatef(-80.0, 80.0, 1.0, 0.0);
			glTranslatef(-1.8, 1.0, 1.0);
			glScalef(0.5, 0.5, 2.8);
			glutSolidCube(0.8);
		glPopMatrix();

		//kaki depan kiri
		glPushMatrix();
			increment(2, 4, 15.0);
			rotateZ(2, 4);
			//telapak kaki depan kiri
			/*glPushMatrix();
				glTranslatef(-1.6, -1.25, 1.6);
				//rotateY(0, 8);
				glRotatef(40.0, 0.0, 1.0, 0.0);
				glScalef(1.2, 0.5, 0.5);
				glutSolidCube(0.8);
			glPopMatrix();*/
			//paha depan kiri
			glRotatef(60.0, 60.0, 0.0, 1.0);
			glTranslatef(-1.8, -1.25, 1.0);
			glScalef(0.5, 0.5, 2.8);
			glutSolidCube(0.8);
		glPopMatrix();

		//kaki belakang kanan
		glPushMatrix();
			increment(2, 5, 15.0);
			//rotateZ(2, 5);
			//telapak kaki belakang kanan
			/*glPushMatrix();
				glTranslatef(1.7, 1.25, 2.0);
				rotateY(2, 9);
				glScalef(2.0, 0.5, 0.5);
				glutSolidCube(0.8);
			glPopMatrix();*/
			//paha belakang kanan
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glTranslatef(0.3, 0.15, 1.5);
			glScalef(0.5, 0.5, 3.0);
			glutSolidCube(0.8);
		glPopMatrix();

		//kaki belakang kiri
		glPushMatrix();
			increment(2, 6, 15.0);
			//rotateZ(2, 6);
			//telapak kaki belakang kiri
			/*glPushMatrix();
				glTranslatef(1.7, -1.25, 2.0);
				rotateY(2, 10);
				glScalef(2.0, 0.5, 0.5);
				glutSolidCube(0.8);
			glPopMatrix();*/
			//paha belakang kiri
			glRotatef(90.0, 0.0, 1.0, 0.0);
			glTranslatef(0.6, -1.25, 1.5);
			glScalef(0.5, 0.5, 3.0);
			glutSolidCube(0.8);
		glPopMatrix();

		//badan
		glTranslatef(-0.8, -1.0, -0.7);
		glScalef(2.2, 1.3, 0.6);
		glutSolidCube(2.0);
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
}

// menggambar objek spider (menyatukan bagian-bagian spider)
void ant(int activateShadow) {
	lua = gluNewQuadric();
	gluQuadricDrawStyle(lua, GLU_FILL);
	lla = gluNewQuadric();
	gluQuadricDrawStyle(lla, GLU_FILL);
	rua = gluNewQuadric();
	gluQuadricDrawStyle(rua, GLU_FILL);
	rla = gluNewQuadric();
	gluQuadricDrawStyle(rla, GLU_FILL);
	lul = gluNewQuadric();
	gluQuadricDrawStyle(lul, GLU_FILL);
	lll = gluNewQuadric();
	gluQuadricDrawStyle(lll, GLU_FILL);
	rul = gluNewQuadric();
	gluQuadricDrawStyle(rul, GLU_FILL);
	rll = gluNewQuadric();
	gluQuadricDrawStyle(rll, GLU_FILL);

	if (activateShadow) {
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glBindTexture(GL_TEXTURE_2D, texture[1]);
	}

	glPushMatrix();
		glScalef(0.05, 0.05, 0.05);
		//glTranslatef(0.0, -95.0, 70.0);
		setPosition(2);
		glRotatef(90.0, 0.0, -1.0, 0.0);

		glPushMatrix();
			rotateY(1, 0);
			increment(1, 0, 5.0);
			glPushMatrix();
				glTranslatef(0.0, 2.0, -5.5);
				glScalef(TORSO_RADIUS, TORSO_HEIGHT, TORSO_RADIUS);
				glutSolidSphere(1.0, 10, 10);
			glPopMatrix();
			glScalef(TORSO_RADIUS, TORSO_HEIGHT, TORSO_RADIUS);
			glutSolidSphere(0.75, 10, 10);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0, 0.0, 0.0);
			rotateY(1, 2);
			increment(1, 2, 2.0);
			glTranslatef(0.0, -0.5*HEAD_HEIGHT, 0.0);
			glTranslatef(0.0, 0.5*HEAD_HEIGHT, 0.0);
			glTranslatef(0.0, 0.0, TORSO_RADIUS);
			glScalef(HEAD_RADIUS, HEAD_HEIGHT, HEAD_RADIUS);
			glutSolidSphere(1.0, 10, 10);
		glPopMatrix();

		glPushMatrix();
			glRotatef(90, 0.0, 0.0, 1.0);
			glTranslatef(-0.5*TORSO_RADIUS, 0.5*TORSO_HEIGHT, 2.5);
			rotateZ(1, 3);
			increment(1, 3, 5.0);
			glPushMatrix();
				glRotatef(-90.0, 1.0, 0.0, 0.0);
				gluCylinder(rua, UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT, 10, 10);
			glPopMatrix();
			glTranslatef(0.0, 0.93*UPPER_ARM_HEIGHT, 0.0);
			rotateZ(1, 4);
			increment(1, 4, 5.0);
			glRotatef(-90.0, 1.0, -0.5, 0.0);
			gluCylinder(rla, LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT, 10, 10);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90, 0.0, 0.0, 1.0);
			glTranslatef(0.5*TORSO_RADIUS, 0.5*TORSO_HEIGHT, 2.5);
			rotateZ(1, 5);
			increment(1, 5, 5.0);
			glPushMatrix();
				glRotatef(-90.0, 1.0, 0.0, 0.0);
				gluCylinder(lua, UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT, 10, 10);
			glPopMatrix();
			glTranslatef(0.0, 0.93*UPPER_ARM_HEIGHT, 0.0);
			rotateZ(1, 6);
			increment(1, 6, 5.0);
			glRotatef(-90.0, 1.0, 0.5, 0.0);
			gluCylinder(lla, LOWER_ARM_RADIUS, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT, 10, 10);
		glPopMatrix();

		glPushMatrix();
			glRotatef(90, 0.0, 0.0, 1.0);
			glTranslatef(-0.5*TORSO_RADIUS, 0.5*TORSO_HEIGHT, -2.5);
			rotateZ(1, 7);
			increment(1, 7, 5.0);
			glPushMatrix();
				glRotatef(-90.0, 1.0, 0.0, 0.0);
				gluCylinder(rul, UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT, 10, 10);
			glPopMatrix();
			glTranslatef(0.0, 0.93*UPPER_LEG_HEIGHT, 0.0);
			rotateZ(1, 8);
			increment(1, 8, 5.0);
			glRotatef(-90.0, 1.0, -1.0, 0.0);
			gluCylinder(rll, LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT, 10, 10);
		glPopMatrix();

		glPushMatrix();
			glRotatef(-90, 0.0, 0.0, 1.0);
			glTranslatef(0.5*TORSO_RADIUS, 0.5*TORSO_HEIGHT, -2.5);
			rotateZ(1, 9);
			increment(1, 9, 5.0);
			glPushMatrix();
				glRotatef(-90.0, 1.0, 0.0, 0.0);
				gluCylinder(lul, UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT, 10, 10);
			glPopMatrix();
			glTranslatef(0.0, 0.93*UPPER_LEG_HEIGHT, 0.0);
			rotateZ(1, 10);
			increment(1, 10, 5.0);
			glRotatef(-90.0, 1.0, 1.0, 0.0);
			gluCylinder(lll, LOWER_LEG_RADIUS, LOWER_LEG_RADIUS, LOWER_LEG_HEIGHT, 10, 10);
		glPopMatrix();

		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
}

//menggambar ruangan
void room() {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[4]);

	//lantai
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-10.0, -5.0, -10);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-10.0, -5.0, 10);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(10.0, -5.0, 10);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(10.0, -5.0, -10);
	glEnd();

	
	//dinding

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[3]);


	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-10.0, -5.0, -10);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-10.0, -5.0, 10);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-10.0, 5.0, 10);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-10.0, 5.0, -10);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(10.0, -5.0, -10);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(10.0, -5.0, 10);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(10.0, 5.0, 10);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(10.0, 5.0, -10);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-10.0, 5.0, -10.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(10.0, 5.0, -10.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(10.0, -5.0, -10.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-10.0, -5.0, -10.0);
	glEnd();

	
	//atap
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[2]);

	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-10.0, 5.0, -10);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-10.0, 5.0, 10);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(10.0, 5.0, 10);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(10.0, 5.0, -10);
	glEnd();

	
}

static void
drawBox(GLfloat size, GLenum type)
{
	static GLfloat n[6][3] =
	{
		{ -1.0, 0.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 1.0, 0.0, 0.0 },
		{ 0.0, -1.0, 0.0 },
		{ 0.0, 0.0, 1.0 },
		{ 0.0, 0.0, -1.0 }
	};
	static GLint faces[6][4] =
	{
		{ 0, 1, 2, 3 },
		{ 3, 2, 6, 7 },
		{ 7, 6, 5, 4 },
		{ 4, 5, 1, 0 },
		{ 5, 6, 2, 1 },
		{ 7, 4, 0, 3 }
	};
	GLfloat v[8][3];
	GLint i;

	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	for (i = 5; i >= 0; i--) {
		glBegin(type);
		glNormal3fv(&n[i][0]);
		glTexCoord2f(0.0, 0.0);
		glVertex3fv(&v[faces[i][0]][0]);
		glTexCoord2f(1.0, 0.0);
		glVertex3fv(&v[faces[i][1]][0]);
		glTexCoord2f(1.0, 1.0);
		glVertex3fv(&v[faces[i][2]][0]);
		glTexCoord2f(0.0, 1.0);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}
}

void APIENTRY
glutSolidCube(GLdouble size)
{
	drawBox(size, GL_QUADS);
}

void toy() {
	//kotak
	
	/*glPushMatrix();
	glTranslatef(0.0, -4.0, -3.0);
	glTranslatef(0.0, 0.0, -1.0);
	glTranslatef(8.5, 0.0, 0.0);
	glutSolidCube(2.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -4.0, -3.0);
	glTranslatef(0.0, 0.0, -1.0);
	glTranslatef(-8.0, 0.0, 0.0);
	glRotatef(45.0, 0.0, 0.0, 0.0);
	glutSolidCube(2.5);
	glPopMatrix();*/

	//mainan bocah
	/*glPushMatrix();
	glTranslatef(0.0, 0.0, 3.5);
	glTranslatef(6.0, 0.0, 0.0);
	glTranslatef(0.0, -5.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutSolidTorus(0.5, 1.0, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0, 2.5, 0.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glutSolidTorus(0.5, 1.0, 10, 10);
	glPopMatrix();*/

	glPushMatrix();
	glTranslatef(-7.0, 1.30, -10.5);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glScalef(1.0, 3.5, 2.0);
	glTranslatef(-10.85, -0.5, -1.0);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glutSolidCube(2);
	glPopMatrix();

}

void dogShadow() {
	if (!toggleLighting)
		return;
	if (isLight0active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[3], ceilingPointRot, ceilingNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[3], leftPointRot, leftNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[3], rightPointRot, rightNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[3], floorPointRot, floorNormal);
		dog(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight1active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[5], ceilingPointRot, ceilingNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], leftPointRot, leftNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], rightPointRot, rightNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], floorPointRot, floorNormal);
		dog(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight2active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[6], ceilingPointRot, ceilingNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], leftPointRot, leftNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], rightPointRot, rightNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], floorPointRot, floorNormal);
		dog(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight3active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[4], ceilingPointRot, ceilingNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], leftPointRot, leftNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], rightPointRot, rightNormal);
		dog(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], floorPointRot, floorNormal);
		dog(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
}

void babyShadow() {
	if (!toggleLighting)
		return;
	if (isLight0active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[3], ceilingPointRot, ceilingNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[3], leftPointRot, leftNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[3], rightPointRot, rightNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[3], floorPointRot, floorNormal);
		baby(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight1active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[5], ceilingPointRot, ceilingNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], leftPointRot, leftNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], rightPointRot, rightNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], floorPointRot, floorNormal);
		baby(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight2active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[6], ceilingPointRot, ceilingNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], leftPointRot, leftNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], rightPointRot, rightNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], floorPointRot, floorNormal);
		baby(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight3active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[4], ceilingPointRot, ceilingNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], leftPointRot, leftNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], rightPointRot, rightNormal);
		baby(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], floorPointRot, floorNormal);
		baby(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
}

void walkingmanShadow() {
	if (!toggleLighting)
		return;
	if (isLight0active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[3], ceilingPointRot, ceilingNormal);
		walkingman();
		glPopMatrix();

		

		glPushMatrix();
		glShadowProjection(position[3], rightPointRot, rightNormal);
		walkingman();
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[3], floorPointRot, floorNormal);
		walkingman();
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight1active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[5], ceilingPointRot, ceilingNormal);
		walkingman();
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], leftPointRot, leftNormal);
		walkingman();
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], rightPointRot, rightNormal);
		walkingman();
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], floorPointRot, floorNormal);
		walkingman();
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight2active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[6], ceilingPointRot, ceilingNormal);
		walkingman();
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], leftPointRot, leftNormal);
		walkingman();
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], rightPointRot, rightNormal);
		walkingman();
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], floorPointRot, floorNormal);
		walkingman();
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight3active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[4], ceilingPointRot, ceilingNormal);
		walkingman();
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], leftPointRot, leftNormal);
		walkingman();
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], rightPointRot, rightNormal);
		walkingman();
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], floorPointRot, floorNormal);
		walkingman();
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
}

void antShadow() {
	if (!toggleLighting)
		return;
	if (isLight0active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[3], ceilingPointRot, ceilingNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[3], leftPointRot, leftNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[3], rightPointRot, rightNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[3], floorPointRot, floorNormal);
		ant(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight1active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[5], ceilingPointRot, ceilingNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], leftPointRot, leftNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], rightPointRot, rightNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[5], floorPointRot, floorNormal);
		ant(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight2active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[6], ceilingPointRot, ceilingNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], leftPointRot, leftNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], rightPointRot, rightNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[6], floorPointRot, floorNormal);
		ant(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
	if (isLight3active) {
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glShadowProjection(position[4], ceilingPointRot, ceilingNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], leftPointRot, leftNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], rightPointRot, rightNormal);
		ant(0);
		glPopMatrix();

		glPushMatrix();
		glShadowProjection(position[4], floorPointRot, floorNormal);
		ant(0);
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}
}