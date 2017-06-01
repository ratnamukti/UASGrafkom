float floorNormal[] = { 0.0, -1.0, 0.0 }; // matrix used to calculate our projected floor shadow
float ceilingNormal[] = { 0.0, 1.0, 0.0 };
float leftNormal[] = { -1.0, 0.0, 0.0 };
float rightNormal[] = { 1.0, 0.0, 0.0 };

float floorPointRot[] = { 0.0, -5.0, 0.0 }; //lokasi bayangan pada lantai
float ceilingPointRot[] = { 0.0, 5.0, 0.0 };  //lokasi bayangan pada dinding bagian belakang
float leftPointRot[] = { -10.0, 0.0, 0.0 };  //lokasi bayangan pada dinding bagian kiri
float rightPointRot[] = { 10.0, 0.0, 0.0 };  //lokasi bayangan pada dinding bagian kanan

void glShadowProjection(float * l, float * e, float * n) {
	float d, c;
	float mat[16];

	// These are c and d (corresponding to the tutorial)

	d = n[0] * l[0] + n[1] * l[1] + n[2] * l[2];
	c = e[0] * n[0] + e[1] * n[1] + e[2] * n[2] - d;

	// Create the matrix. OpenGL uses column by column
	// ordering

	mat[0] = l[0] * n[0] + c;
	mat[4] = n[1] * l[0];
	mat[8] = n[2] * l[0];
	mat[12] = -l[0] * c - l[0] * d;

	mat[1] = n[0] * l[1];
	mat[5] = l[1] * n[1] + c;
	mat[9] = n[2] * l[1];
	mat[13] = -l[1] * c - l[1] * d;

	mat[2] = n[0] * l[2];
	mat[6] = n[1] * l[2];
	mat[10] = l[2] * n[2] + c;
	mat[14] = -l[2] * c - l[2] * d;

	mat[3] = n[0];
	mat[7] = n[1];
	mat[11] = n[2];
	mat[15] = -d;

	// Finally multiply the matrices together *plonk*
	glMultMatrixf(mat);
}
