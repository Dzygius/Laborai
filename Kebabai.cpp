#include <iostream>
#include <vector>
#include <algorithm>

class kebabine
{
private:
	int a;
	int SumoketaSuma = 0, PamaitinusiuSuma = 0, DidziausiaGraza = 0, SkirtingiBanknotai = 0, VienodiBanknotai = 0;
	std::vector <int> Pinigai;
	std::vector <int> Laikinas;
	std::vector <int> Kaina;
public:
	kebabine() : Pinigai(0), Laikinas(0), Kaina(0) {}
	~kebabine() {}
	void lIvedimas()
	{
		std::cin >> a;
		Laikinas.push_back(a);
	}

	void nKonvertevimas(int n)
	{
		for (int i = 0; i < n; i++)
		{
			Pinigai.push_back(Laikinas.back());
			Laikinas.pop_back();
		}
		skirtingi_Banknotai();
		vienodi_Banknotai();
	}

	void kIvedimas()
	{
		std::cin >> a;
		Kaina.push_back(a);
	}

	void LygiSuma(int n, int m)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (Pinigai.empty() == true)
				{
					break;
				}
				if (Pinigai.front() == Kaina.front())
				{

					SumoketaSuma += Kaina.front();
					Pinigai.erase(Pinigai.begin());
					PamaitinusiuSuma++;
					break;
				}
				else if (Pinigai.front() > Kaina.front())
				{
					Pinigai.push_back(Pinigai.front() - Kaina.front());
					SumoketaSuma += Kaina.front();
					PamaitinusiuSuma++;
					Pinigai.erase(Pinigai.begin());
					if (Pinigai.back() > DidziausiaGraza)
					{
						DidziausiaGraza = Pinigai.back();
					}
					break;
				}
				else
				{
					Pinigai.push_back(Pinigai.front());
					Pinigai.erase(Pinigai.begin());
				}
			}
			skirtingi_Banknotai();
			vienodi_Banknotai();
			Kaina.erase(Kaina.begin());
		}
	}

	void skirtingi_Banknotai()
	{
		int laikinasdydis = 0;
		for (int i = 0; i < Pinigai.size(); i++)
		{
			Laikinas.push_back(Pinigai[i]);
		}

		sort(Laikinas.begin(), Laikinas.end());
		Laikinas.erase(unique(Laikinas.begin(), Laikinas.end()), Laikinas.end());
		if (SkirtingiBanknotai < Laikinas.size()) SkirtingiBanknotai = Laikinas.size();
		laikinasdydis = Laikinas.size();
		for (int l = 0; l < laikinasdydis; l++)
		{
			Laikinas.pop_back();
		}
	}

	void vienodi_Banknotai()
	{
		int sup = 0;
		for (int i = 0; i < Pinigai.size(); i++)
		{
			for (int j = 0; j < Pinigai.size(); j++)
			{
				if (Pinigai[i] == Pinigai[j])
				{
					sup++;
				}
			}
			if (VienodiBanknotai < sup)
			{
				VienodiBanknotai = sup;
			}
			sup = 0;
		}
	}

	void isvedimas()
	{
		std::cout << "Petriuką pamaitinusių kavinių skaičius: " << PamaitinusiuSuma << std::endl;
		std::cout << "Petriuko sumokėta suma: " << SumoketaSuma << std::endl;
		std::cout << "Piniginėje likusių banknotų skaičius: " << Pinigai.size() << std::endl;
		std::cout << "Didžiausia grąža: " << DidziausiaGraza << std::endl;
		std::cout << "Didžiausias vienodų banknotų skaičius: " << VienodiBanknotai << std::endl;
		std::cout << "Didžiausias skirtingų banknotų skaičius: " << SkirtingiBanknotai << std::endl;

	}

};

int main()
{
	kebabine kebai;
	int n, m;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		kebai.lIvedimas();
	}
	kebai.nKonvertevimas(n);
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		kebai.kIvedimas();
	}
	kebai.LygiSuma(n, m);
	kebai.isvedimas();
	return 0;
}
