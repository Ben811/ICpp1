#include "Hub.h"

Hub::Hub(int maximumPripojenychPrvku)
{
	this->maximumPripojenychPrvku = maximumPripojenychPrvku;
	this->pripojenePrvky = new ASitovyPrvek * [maximumPripojenychPrvku];
	this->zpracovaneZpravy = new Fronta<Zprava*>();
}

Hub::~Hub()
{
}
