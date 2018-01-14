
void clear(void){
  char *vidptr = (char*)0xb8000;
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int screensize;

	/* this loops clears the screen
	* there are 25 lines each of 80 columns; each element takes 2 bytes */
	screensize = 80 * 26 * 2;
	while (j < screensize) {
		/* blank character */
		vidptr[j] = ' ';
		/* attribute-byte */
		vidptr[j+1] = 0x07;
		j = j + 2;
	}
}

void putc(unsigned int x, unsigned int y, char value){
  char *vidptr = (char*)0xb8000;
  if (x > 80)
    x = 80;

  if (y > 26)
    y = 26;

  y = 80*y;

  vidptr[(x+y)*2] = value;
  vidptr[(x+y)*2+1] = 0x07;

}

void print(const char* data){
  char *vidptr = (char*)0xb8000;
	unsigned int i = 0;
	unsigned int j = 0;

	while (data[i] != '\0')  {
		/* blank character */
		vidptr[j] = data[i];
		/* attribute-byte */
		vidptr[j+1] = 0x07;
		j = j + 2;
    i++;
	}
}
