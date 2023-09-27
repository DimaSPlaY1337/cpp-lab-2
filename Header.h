
enum class ChetOrNechet : int
{
	None,
	Chet = 2,
	NeChet = 1
};

enum class FactUpOrDown : int
{
	None,
	Up,
	Down
};

ChetOrNechet Chetnost;
FactUpOrDown PlaceOfFactorial;
long float LastNumberOfDwFact;

long double CalculateDoubleFactorial(int k, FactUpOrDown Place)
{
	long double dwfact = 1;
	switch (Place)
	{
	case FactUpOrDown::Up:
	{
		LastNumberOfDwFact = 2 * k + 1;
		break;
	}

	case FactUpOrDown::Down:
	{
		LastNumberOfDwFact = 2 * k;
		break;
	}
	default:
		break;
	}

	if ((int)LastNumberOfDwFact % 2 == 1)
	{
		Chetnost = ChetOrNechet::NeChet;
	}
	else
	{
		Chetnost = ChetOrNechet::Chet;
	}
	for (int i = (int)Chetnost; i <= LastNumberOfDwFact; i += 2)
	{
		dwfact = dwfact * i;
	}
	return dwfact;
}

long double t(double x)
{
	long double SummUp = 0;
	long double SummDown = 0;
	long double t;
	for (int k = 0; k <= 10; k++)
	{
		SummUp += pow(x, 2 * k + 1)
			/
			CalculateDoubleFactorial(k, FactUpOrDown::Up);

		SummDown += pow(x, 2 * k)
			/
			CalculateDoubleFactorial(k, FactUpOrDown::Down);
	}
	t = SummUp / SummDown;
	return t;
}