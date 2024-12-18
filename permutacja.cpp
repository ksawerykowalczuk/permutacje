#include <iostream>
using namespace std;
int aktualnyWiersz=0;

void wpisz(int szerokosc, int tablica[], int** Wyniki)
{
    for (int i = 0; i < szerokosc; i++)
    {
        Wyniki[aktualnyWiersz][i] = tablica[i];
    }
    aktualnyWiersz++;
}

int **zbudujTablice(int height, int width)
{
    int **Wyniki = new int *[height];
    for (int i = 0; i < height; ++i)
    {
        Wyniki[i] = new int[width];
    }
    return Wyniki;
}

void permutacje (int iloscpermutacji, int** Wyniki, int size, int tablica[], int level)
{
    if (level == size -1)
    {
        wpisz(size, tablica, Wyniki);
        return;
    }
    for (int i = level; i < size; i++)
    {
        swap(tablica[i],tablica[level]);
        permutacje (iloscpermutacji, Wyniki, size, tablica, level+1);
        swap(tablica[i],tablica[level]);
    }
}

int silnia(int size)
{
    int iloscpermutacji = 1;
    for (int i = 2; i <= size; i++)
    {
        iloscpermutacji = iloscpermutacji * (i);
    }
    return iloscpermutacji;
}

void drukujPermutacje(int** Wyniki, int szerokosc, int wysokosc)
{
    for (int i = 0; i < wysokosc; i++)
    {
        for (int j = 0; j < szerokosc; j++)
        {
            cout << Wyniki[i][j] <<" ";
        }
        cout << endl;
    }
    
}

void killEm (int** Wyniki, int szerokosc, int wysokosc)
{
    for (int i = 0; i < wysokosc; i++)
    {
        delete [] Wyniki[i];
    }
    delete [] Wyniki;
}

int main()
{
    int size;
    cin >> size;
    int tablica[size];
    int iloscpermutacji = silnia(size);
    for (int i = 0; i < size; i++)
    {
        cin >> tablica[i];
    }
    int** Wyniki = zbudujTablice(iloscpermutacji, size);
    permutacje(iloscpermutacji, Wyniki, size, tablica, 0);
    //drukujPermutacje(Wyniki, size, iloscpermutacji);
    killEm(Wyniki, size, iloscpermutacji);
    cout<< "koniec :D";
}

//W czym pisze programista który zwiększa zmienną liczbową C o 1?
//-w c++ hahahahahahaahaha xD ale smieszne japierdole.