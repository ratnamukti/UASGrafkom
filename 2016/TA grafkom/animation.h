int isPaused = 0; //status dari mode animasi (mati/nyala)
int isFilled = 1; //status dari mode render (wireframe/fill)
int selectedObject = 0; //id dari objek yang dipilih

float angle = 0.0, lx = 0.0f, lz = -1.0f, x = 0.0f, z = 30.0f, h = 0.0; //parameter kamera
float fraction = 0.1;


//theta[0] = anjing, theta[1] = laba-laba, theta[2] = manusia, theta[3] = kamera
float theta[4][15] = { { 0.0, 0.0, 0.0, 0.0, -15.0, -15.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20.0 },
{ 0.0, 0.0, 0.0, -30.0, 120.0, 30.0, -120.0, -30.0, 120.0, 30.0, -120.0 },
{ 0.0, 0.0, 0.0, 0.0, -15.0, -15.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20.0 },
{ 0.0, 0.0, 0.0, 0.0, 90.0 } };



float delta[4][15] = { { 0.0, 0.0, 0.0, 0.0, -15.0, -15.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
{ 0.0, 0.0, 0.0, 0.0, -15.0, -15.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
{ 0.0, 0.0, 0.0, 0.0, 90.0 } };

float speed[4][15] = { { 0.04, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.1, 0.4, 0.4 },
{ 0.1, 0.1, 0.025, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1 },
{ 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.02, 0.02, 0.01, 0.01, 0.01 },
{ 0.1, 0.1, 0.1, 0.0, -0.33 } };

//position[0] = anjing, position[1] = Manusia, position[2] = laba-laba,
//position[3] = cahaya1, position[4] = cahaya4, position[5] = cahaya 2, position[6] = cahaya3
float position[8][3] = { { 0.0, -17.4, 20.0 },
{ 0.0, -1.0, 7.0 },
{ 9.0, -95.0, 70.0 },
{ 9.8, 4.5, 0.0 },
////lampucahaya1{ 10.0, 5.0, 0.0 },
{ 0.0, 4.5, 0.0 },
//lampucahaya4 { -7.0, 2.0, 0.0 },
{ -9.8, 4.5, 0.0 },
//lampucahaya2{ -10.0, 5.0, 0.0 },
{ 7.0, 2.0, 0.0 },
{ 17.0, -14.0, 14.0 } };

/*menggeser objek
object = id dari objek*/
void setPosition(int object) {
	glTranslatef(position[object][0], position[object][1], position[object][2]);
}

/*menambahkan sudut putaran objek. jika besar sudut melebihi batas maka ubah arah gerakkan
objek = id dari objek hirarki
part = id anggota tubuh dari objek hirarki
limit = batas sudut putaran*/
void increment(int object, int part, float limit) {
	if (isPaused)
		return;
	theta[object][part] += speed[object][part];
	delta[object][part] += speed[object][part];
	if (delta[object][part] > limit || delta[object][part] < -limit)
		speed[object][part] = -speed[object][part];
}

/*menambahkan sudut putaran objek
objek = id dari objek hirarki
part = id anggota tubuh dari objek hirarki*/
void increase(int object, int part) {
	if (isPaused) //jangan tambahkan sudut jika mode animasi mati
		return;
	theta[object][part] += speed[object][part];
	delta[object][part] += speed[object][part];
	if (delta[object][part] > 360.0 || delta[object][part] < -360.0)
		delta[object][part] = 0.0;
	if (theta[object][part] > 360.0 || theta[object][part] < -360.0)
		theta[object][part] = 0.0;
}

/*putar objek searah sumbu x
object = id objek hirarki
part = id anggota tubuh objek hirarki*/
void rotateX(int object, int part) {
	glRotatef(theta[object][part], 1.0, 0.0, 0.0);
}

/*putar objek searah sumbu y
object = id objek hirarki
part = id anggota tubuh objek hirarki*/
void rotateY(int object, int part) {
	glRotatef(theta[object][part], 0.0, 1.0, 0.0);
}

/*putar objek searah sumbu z
object = id objek hirarki
part = id anggota tubuh objek hirarki*/
void rotateZ(int object, int part) {
	glRotatef(theta[object][part], 0.0, 0.0, 1.0);
}

//matikan/nyalakan animasi
void togglePause() {
	isPaused = !isPaused;
}