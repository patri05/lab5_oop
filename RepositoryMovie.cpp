#include "RepositoryMovie.h"
#include "Movie.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <sstream>

using namespace std;

RepositoryMovie::RepositoryMovie()
{
	Initializare();
}

int RepositoryMovie::Find_Id()
{

	//functia genereaza ID-ul unui film si ii atribuie o valoare
	//mai mare ca oricare din cele din baza de date pentru a pastra unicitatea acestuia 

	int maxim = 0;
	
	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() > maxim)
			maxim = Movie_Database[i].Get_ID();
	}
	
	return maxim + 1;
}


void RepositoryMovie::Initializare()
{

	//date demo

	Add_Movie("Bolden", "Drama", 2019, 59, "https://www.imdb.com/video/imdb/vi4061838617?playlistId=tt0858419&ref_=tt_ov_vi");
	Add_Movie("Shadow", "Action", 2018, 2665, "https://www.imdb.com/video/imdb/vi1197849881?playlistId=tt6864046&ref_=tt_ov_vi");
	Add_Movie("Clara", "Sci-Fi", 2018, 1208, "https://www.imdb.com/video/imdb/vi2171517465?playlistId=tt6613878&ref_=tt_ov_vi");
	Add_Movie("Breakthrough", "Biography", 2019, 1507, "https://www.imdb.com/video/imdb/vi2244000281?playlistId=tt7083526&ref_=tt_ov_vi");
	Add_Movie("Shazam!", "Action", 2019, 87521, "https://www.imdb.com/video/imdb/vi306231833?playlistId=tt0448115&ref_=tt_ov_vi");
	Add_Movie("Dumbo", "Adventure", 2019, 22570, "https://www.imdb.com/video/imdb/vi2482814233?playlistId=tt3861390&ref_=tt_ov_vi");
	Add_Movie("Us", "Horror", 2019, 74820, "https://www.imdb.com/video/imdb/vi1333246489?playlistId=tt6857112&ref_=tt_ov_vi");
	Add_Movie("After", "Romance", 2019, 6226, "https://www.imdb.com/video/imdb/vi191412761?playlistId=tt4126476&ref_=tt_ov_vi");
	Add_Movie("Hellboy", "Fantasy", 2019, 17332, "https://www.imdb.com/video/imdb/vi3294345753?playlistId=tt2274648&ref_=tt_ov_vi");
	Add_Movie("Arctic", "Drama", 2018, 12263, "https://www.imdb.com/video/imdb/vi3020274201?playlistId=tt6820256&ref_=tt_ov_vi");
	Add_Movie("Glass", "Thriller", 2019, 114515, "https://www.imdb.com/video/imdb/vi768195097?playlistId=tt6823368&ref_=tt_ov_vi");
	Add_Movie("Aquaman", "Action", 2018, 22146, "https://www.imdb.com/video/imdb/vi3588536857?playlistId=tt1477834&ref_=tt_ov_vi");
	Add_Movie("Split", "Horror", 2016, 350896, "https://www.imdb.com/video/imdb/vi741258777?playlistId=tt4972582&ref_=tt_ov_vi");
	Add_Movie("Bumblebee", "Action", 2018, 86011, "https://www.imdb.com/video/imdb/vi1473100313?playlistId=tt4701182&ref_=tt_ov_vi");
	Add_Movie("Venom", "Action", 2018, 265501, "https://www.imdb.com/video/imdb/vi1186773529?playlistId=tt1270797&ref_=tt_ov_vi");
	Add_Movie("Vice", "Biography", 2018, 65732, "https://www.imdb.com/video/imdb/vi1144502809?playlistId=tt6266538&ref_=tt_ov_vi");
	Add_Movie("Tolkien", "Drama", 2019, 373, "https://www.imdb.com/video/imdb/vi3958881305?playlistId=tt3361792&ref_=tt_ov_vi");
}


bool RepositoryMovie::Add_Movie(string Title, string Genre, int Publishing_Year, int Likes, string Link)
{

	//functia creeaza un obiect nou de tip Movie caruia ii atribuie datele din parametrii functiei
	//se verifica daca exista deja acest film in baza de date, daca da, se returneaza 0
	//daca nu, functia returneaza 1

	Movie newMovie;

	if (Movie_Database.size() != 0)
	{
		for (unsigned int i = 0; i < Movie_Database.size(); i++)
		{
			if (Movie_Database[i].Get_Title() == Title)
			{
				//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul exista deja
				cout << "The movie is already in the list" << endl;
				return 0;
			}
		}
	}
	
	//se atribuie datele din parametrii obiectului nou si se adauga bazei de date
	newMovie.Set_Title(Title);
	newMovie.Set_Genre(Genre);
	newMovie.Set_Likes(Likes);
	newMovie.Set_Link(Link);
	newMovie.Set_Publishing_Year(Publishing_Year);
	newMovie.Set_ID(Find_Id());
	Movie_Database.push_back(newMovie);
	
	return 1;
}


bool RepositoryMovie::Change_Title(int ID, string newTitle)
{

	//functia modifica titlul unui film din baza de date
	//cautarea filmului se face pe baza id-ului 
	//daca modificarea a fost facuta cu succes se returneaza 1
	//daca nu se returneaza 0
	
	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			//daca filmul este gasit se efectueaza modificarea si se iese din functie
			Movie_Database[i].Set_Title(newTitle);
			return 1;
		}
	}
	
	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The movie wasn't found!" << endl;
	return 0;
}


bool RepositoryMovie::Change_Genre(int ID, string newGenre)
{

	//functia modifica genul unui film din baza de date
	//cautarea filmului se face pe baza id-ului 
	//daca modificarea a fost facuta cu succes se returneaza 1
	//daca nu se returneaza 0

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			//daca filmul este gasit se efectueaza modificarea si se iese din functie
			Movie_Database[i].Set_Genre(newGenre);
			return 1;
		}
	}

	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The movie wasn't found!" << endl;
	return 0;
}


bool RepositoryMovie::Change_PublishingYear(int ID, int newPublishingYear)
{

	//functia modifica anul de publicare a unui film din baza de date
	//cautarea filmului se face pe baza id-ului 
	//daca modificarea a fost facuta cu succes se returneaza 1
	//daca nu se returneaza 0

	unsigned int i;

	for (i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			//daca filmul este gasit se efectueaza modificarea si se iese din functie
			Movie_Database[i].Set_Publishing_Year(newPublishingYear);
			return 1;
		}
	}

	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The movie wasn't found!" << endl;
	return 0;
}


bool RepositoryMovie::Change_Likes(int ID, int newLikes)
{
	//functia modifica numarul de aprecieri a unui film din baza de date
	//cautarea filmului se face pe baza id-ului 
	//daca modificarea a fost facuta cu succes se returneaza 1
	//daca nu se returneaza 0

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			//daca filmul este gasit se efectueaza modificarea si se iese din functie
			Movie_Database[i].Set_Likes(newLikes);
			return 1;
		}
	}

	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The movie wasn't found!" << endl;
	return 0;
}


bool RepositoryMovie::Change_Link(int ID, string newLink)
{

	//functia modifica link-ul unui film din baza de date
	//cautarea filmului se face pe baza id-ului 
	//daca modificarea a fost facuta cu succes se returneaza 1
	//daca nu se returneaza 0

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			//daca filmul este gasit se efectueaza modificarea si se iese din functie
			Movie_Database[i].Set_Link(newLink);
			return 1;
		}
	}

	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The movie wasn't found!" << endl;
	return 0;
}


bool RepositoryMovie::Delete(int ID)
{

	//functia sterge un film din baza de date
	//cautarea filmului se face pe baza id-ului 
	//daca modificarea a fost facuta cu succes se returneaza 1
	//daca nu se returneaza 0

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			//daca filmul este gasit, acesta se sterge si se iese din functie
			Movie_Database.erase(Movie_Database.begin() + i);
			return 1;
		}
	}

	//se afiseaza un mesaj de pe ecran si se iese din functie daca filmul nu exista
	cout << "The movie wasn't found!" << endl;
	return 0;
}


void RepositoryMovie::Play_Trailer(int ID)
{
	
	//functia afiseaza pe ecran trailer-ul filmului

	string url;

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == ID)
		{
			url = Movie_Database[i].Get_Link().c_str();
			ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
			return;
		}
	}
}


vector<Movie> RepositoryMovie::Get_Movies()
{
	return Movie_Database;
}


bool RepositoryMovie::Add_Movie_Watchlist(int Id)
{

	//functia adauga un film in watchlist
	//daca modificarea a fost facuta cu succes se returneaza true
	//daca nu se returneaza false

	for (unsigned int i = 0; i < Watchlist.size(); i++)
	{
		if (Watchlist[i].Get_ID() == Id)
		{
			//daca filmul este deja in watchlist atunci se afiseaza mesaj pe ecran si se iese din functie
			cout << "Movie is already in the Watchlist" << endl;
			return false;
		}
	}

	for (unsigned int i = 0; i < Movie_Database.size(); i++)
	{
		if (Movie_Database[i].Get_ID() == Id)
		{
			//se adauga filmul si se iese din functie
			Watchlist.push_back(Movie_Database[i]);
			return true;
		}
	}

	return false;
}


bool RepositoryMovie::Delete_Movie_Watchlist(int Id, bool like)
{
	
	//functia sterge un film din watchlist
	//daca operatia a avut loc cu succes functia returneaza true
	//daca nu functia returneaza false

	for (unsigned int i = 0; i < Watchlist.size(); i++)
	{
		if (Watchlist[i].Get_ID() == Id)
		{
			if (like == true)
			{
				for (unsigned int j = 0; j < Movie_Database.size(); j++)
				{
					if (Movie_Database[j].Get_ID() == Id)
					{
						Movie_Database[j].Set_Likes(Movie_Database[j].Get_Likes() + 1);
					}
				}
			}
			//filmul este sters cu succes si functia returneaza true
			Watchlist.erase(Watchlist.begin() + i);
			return true;
		}
	}

	//daca filmul nu este in watchlist atunci se afiseaza mesaj pe ecran si se iese din functie
	cout << "The Movie wasn't found" << endl;
	return false;
}


vector<Movie> RepositoryMovie::Get_Watchlist()
{
	return Watchlist;
}





