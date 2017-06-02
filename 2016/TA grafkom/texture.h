GLuint texture[10]; //array untuk menyimpan semua tekstur yang akan digunakan

GLuint LoadTextureRAW(const char * filename, int wrap, GLuint texture)
{
	int width, height;
	BYTE * data;
	FILE * file;
	file = fopen(filename, "rb");
	if (file == NULL) return 0;

	width = 256;
	height = 256;
	data = (unsigned char *)malloc(width * height * 3);
	fread(data, width * height * 3, 1, file);
	fclose(file);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
	free(data);
	return texture;
}

//hapus tekstur
void freeTexture(GLuint texture){
	glDeleteTextures(1, &texture);
}

//inisiasi semua tekstur yang akan digunakan
void initTexture() {
	texture[0] = LoadTextureRAW("fur1.raw", TRUE, texture[0]);
	texture[1] = LoadTextureRAW("fur2.raw", TRUE, texture[1]);
	texture[2] = LoadTextureRAW("ceiling.raw", TRUE, texture[2]);
	texture[3] = LoadTextureRAW("wall.raw", TRUE, texture[3]);
	texture[4] = LoadTextureRAW("floor.raw", TRUE, texture[4]);
	texture[5] = LoadTextureRAW("bodymanusia.raw", TRUE, texture[5]);
	texture[6] = LoadTextureRAW("mukamanusia.RAW", TRUE, texture[6]);
	texture[7] = LoadTextureRAW("mukahewan.raw", TRUE, texture[7]);
	texture[8] = LoadTextureRAW("mukakucing.raw", TRUE, texture[8]);
}

//hapus semua tekstur yang akan digunakan
void resetTexture() {
	freeTexture(texture[0]);
	freeTexture(texture[1]);
	freeTexture(texture[2]);
	freeTexture(texture[3]);
	freeTexture(texture[4]);
	freeTexture(texture[5]);
	freeTexture(texture[6]);
	freeTexture(texture[7]);
	freeTexture(texture[8]);
	freeTexture(texture[9]);
}