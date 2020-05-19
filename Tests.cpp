#include "Tests.h"
#include "Controller.h"
#include "RepositoryMovie.h"
#include "UI.h"
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

void Tests::Test()
{

  //functia de teste

	int initial_size, IdMovie;
	RepositoryMovie repo;
	
  initial_size = repo.Movie_Database.size();
	
  //test adaugare film
	assert(repo.Add_Movie("aaa", "bbb", 2000, 123, "ccc") == true);
	assert(repo.Add_Movie("aaa", "bbb", 2000, 123, "ccc") == false);
	assert(repo.Movie_Database.size() == (initial_size + 1));
	assert(repo.Movie_Database[initial_size].Get_Title() == "aaa");
	assert(repo.Movie_Database[initial_size].Get_Genre() == "bbb");
	assert(repo.Movie_Database[initial_size].Get_Publishing_Year() == 2000);
	assert(repo.Movie_Database[initial_size].Get_Likes() == 123);
	assert(repo.Movie_Database[initial_size].Get_Link() == "ccc");
	IdMovie = repo.Movie_Database[initial_size].Get_ID();
	
  //test modificare titlu
	assert(repo.Change_Title(IdMovie, "ddd") == true);
	assert(repo.Change_Title(999, "ddd") == false);
	assert(repo.Movie_Database[initial_size].Get_Title() == "ddd");
	
  //test modificare gen
	assert(repo.Change_Genre(IdMovie, "ddd") == true);
	assert(repo.Change_Genre(999, "ddd") == false);
	assert(repo.Movie_Database[initial_size].Get_Genre() == "ddd");
	
  //test modificare an
	assert(repo.Change_PublishingYear(IdMovie, 2001) == true);
	assert(repo.Change_PublishingYear(999, 2001) == false);
	assert(repo.Movie_Database[initial_size].Get_Publishing_Year() == 2001);
	
  //test modificare numar de aprecieri
	assert(repo.Change_Likes(IdMovie, 555) == true);
	assert(repo.Change_Likes(999, 555) == false);
	assert(repo.Movie_Database[initial_size].Get_Likes() == 555);
	
  //test modificare link
	assert(repo.Change_Link(IdMovie, "fff") == true);
	assert(repo.Change_Link(999, "fff") == false);
	assert(repo.Movie_Database[initial_size].Get_Link() == "fff");
	
  //test adaugare film la Watchlist
	assert(repo.Add_Movie_Watchlist(IdMovie) == true);
	assert(repo.Add_Movie_Watchlist(IdMovie) == false);
	assert(repo.Add_Movie_Watchlist(999) == false);
	assert(repo.Watchlist.size() == 1);
	
  //test stergere film din Watchlist 
	assert(repo.Delete_Movie_Watchlist(IdMovie, true) == true);
	assert(repo.Delete_Movie_Watchlist(IdMovie, true) == false);
	assert(repo.Delete_Movie_Watchlist(999, true) == false);
	assert(repo.Watchlist.size() == 0);
	assert(repo.Movie_Database[initial_size].Get_Likes() == 556);
	
  //test stergere film
	assert(repo.Delete(IdMovie) == true);
	assert(repo.Delete(IdMovie) == false);
	assert(repo.Delete(999) == false);
	assert(repo.Movie_Database.size() == initial_size);
}