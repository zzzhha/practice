#include"controller.h"
extern int c;
extern const char* musciplay[3];
int main()
{
	mciSendString("open music\\¸ÒÉ±ÎÒµÄÂí.mp3 ", NULL, 0, NULL);
	mciSendString(musciplay[c], NULL, 0, NULL);
	controller();
	return 0;
}