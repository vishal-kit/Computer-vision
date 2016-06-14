#include <stdio.h>

int main()
{
int	img[256][256], img2[256][256];
int	i, j;
int	a;
char	dum;

FILE	*in, *out;

	in = fopen("LENNA.pgm","r");
	fscanf(in,"%s",&dum);
	fscanf(in,"%d %d %d",&a,&a,&a);
	for ( i=0; i<256; i++ )
		for ( j=0; j<256; j++ )
			fscanf(in,"%d",&img[i][j]);
	fclose(in);

	printf("%d",img[0][0]);

	for ( i=1; i<255; i++ ){
		for ( j=0; j<255; j++ ){
			img2[i][j] = ( img[i-1][j-1] + img[i-1][j  ] + img[i-1][j+1] +
				       img[i  ][j-1] + img[i  ][j  ] + img[i  ][j+1] +
				       img[i+1][j-1] + img[i+1][j  ] + img[i+1][j+1] )/9;
		}
	}

	out = fopen("LENNA_mean3.pgm","w");
	fprintf(out,"P2\n256 256\n255\n");
	for ( i=0; i<256; i++ ){
		for ( j=0; j<256; j++ )
			fprintf(out,"%d ",img2[i][j]);
		fprintf(out,"\n");
	}
	fclose(out);
	fclose(in);


	return 0;

}