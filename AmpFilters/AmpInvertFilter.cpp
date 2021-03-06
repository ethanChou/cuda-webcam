#include "AmpInvertFilter.h"
#include "amp.h"

using namespace concurrency;

/**
	\file AmpInvertFilter.cpp
	AmpInvertFilter s�n�f�n�n metodlar�n� i�eren dosya.
*/

/** G�r�nt�n�n RGB kanallar�n�n tersini al�r. */
void AmpInvertFilter::FilterImage(char* imageData)
{
	unsigned int* iImageData = (unsigned int*)malloc(3*width*height * sizeof(int));

	// AMP'de char kullanilamiyor, veriyi int'e donustur.
	for(int i=0; i<3*width*height; i++)
	{
		*( iImageData + i ) = ( unsigned int ) *( imageData + i );
	}

	const int size = 3*width*height;
	
	// Veri �zerinde do�rudan �al��abiliriz. (in-place).
	array_view<unsigned int, 1> img(size, iImageData);	

	parallel_for_each(         
        img.extent,         
        [=](index<1> idx) restrict(amp)
		{
			// Her kanal�n negatifi al�n�r.
			img[idx] = 255 - img[idx];
		}
    );

	img.synchronize();

	// AMP'de char kullanilamiyor, veriyi char'e donustur.
	for(int i=0; i<3*width*height; i++)
	{
		*( imageData + i ) = ( char ) *( iImageData + i );
	}
}
