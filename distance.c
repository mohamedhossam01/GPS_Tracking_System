double distance(double xstart,double ystart,double xend,double yend)
{
	double calctemp;
	xstart *= convert;
	xend *= convert;
	ystart *= convert;
	yend *= convert;
	theta = hav(xend-xstart)+cos(xstart)*cos(xend)*hav(yend-ystart);
	calctemp = 2*atan2(sqrt(theta),sqrt(1-theta));
	calctemp = calctemp * 6372795;
	return calctemp;
}