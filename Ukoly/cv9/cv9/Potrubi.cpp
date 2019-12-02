#include "Potrubi.h"
#include "PrvkyPotrubi.h"

Potrubi::Potrubi(std::istringstream* ss)
{
	*ss >> rozmer;

	prvky = new APotrubniPrvek * [rozmer * rozmer];
	for (int i = 0; i < rozmer * rozmer; i++)
		prvky[i] = nullptr;

	ss->get();

	for (int i = 0; i < rozmer; i++)
		for (int j = 0; j < rozmer; j++)
		{
			char znak = ss->get();
			APotrubniPrvek* prvek = nullptr;

			switch (znak)
			{
			case '-':
				prvek = new PrvekMinus(i,j);
				break;
			case 'I':
				prvek = new PrvekI(i, j);
				break;
			case '+':
				prvek = new PrvekPlus(i, j);
				break;
			case 'O':
				prvek = new PrvekO(i, j);
				break;
			case 'T':
				prvek = new PrvekT(i, j);
				break;
			default:
				break;
			}						
			prvky[i * rozmer + j] = prvek;
		}
}



const APotrubniPrvek* Potrubi::DejPrvek(int x, int y) const
{
	if (x < 0 || y < 0 || x < rozmer || y < rozmer)
		return nullptr;
	
	return prvky[x*rozmer+y];
}

bool Potrubi::JePotrubiOk() const
{
	for (int i = 0; i <rozmer*rozmer; i++)
	{
		if (prvky[i] == nullptr)
		{
			continue;;
		}
			if (!prvky[i]->JeKorektneZapojen(this))
				return false;
	}
		
		
	return true;
}
