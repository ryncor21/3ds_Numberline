#include <string.h>
#include <3ds.h>
#include <stdio.h>

/* One of my Computer Science 1 assignments that I converted to run on the 3ds.
*/

int power (int value, int exponent) {
   int x;
   if (exponent == 0){
      x = 1;
   }
   else {
      x = value;
      for (int i = 1; i != exponent; i++) {
         x = x*value;
      }
   }
   return x;
}

int countDigits(int value) {
   int result = 1;
   for (int i = 0; value >= 10; i++){
      value = value / 10;
      result = result + 1;
   }
   return result;
}

int main()
{
   gfxInitDefault();
	//gfxSet3D(true); // uncomment if using stereoscopic 3D
   consoleInit(GFX_TOP, NULL);
   
   int upperBound = 150;
   int lowerBound = 100;
   
   int digits = countDigits(upperBound);
      
   for(int i = (digits - 1);  i >= 0 ; i--){
      for(int x = lowerBound; x < upperBound; x++){
         int place = power(10, i);
         //printf("%d",place);
         int currentDigit = (x / place) % 10;           
            printf("%d",currentDigit);                  
      }
      printf("\n");       
   }
                       
   for(int i = lowerBound; i < upperBound; i++) {
      printf("|");
   }
   
	// Main loop
   while (aptMainLoop())
   {
      gspWaitForVBlank();
      hidScanInput();
   
      u32 kDown = hidKeysDown();
      if (kDown & KEY_START)
         break; // break in order to return to hbmenu
   
   	// Flush and swap framebuffers
      gfxFlushBuffers();
      gfxSwapBuffers();
   }

   gfxExit();
   return 0;
}