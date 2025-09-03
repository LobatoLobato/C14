#include <iostream>
#include "service/movie_service.hpp"

int main(int argc, char** argv) {
  std::string root_path = argv[1];
  std::string data_path = root_path + "/dependency_management/data/movies.json";
  MovieService movie_service(data_path);

  for (const auto& movie : movie_service.getAllMovies()) {
    std::cout << movie << std::endl;
  }

  movie_service.addMovie({
    "Inception",
    2010,
    148,
    8.8,
    "A thief who steals corporate secrets through the use of dream-sharing technology is given the inverse task of planting an idea into the mind of a C.E.O.",
    "Christopher Nolan",
    {"Christopher Nolan"},
    {"Warner Bros.", "Legendary Pictures", "Syncopy"},
    {"Action", "Adventure", "Sci-Fi"}
  });

  std::cout << *movie_service.getMovie("Inception") << "\n";

  return 0;
}