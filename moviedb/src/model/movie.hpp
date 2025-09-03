#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include "nlohmann/json.hpp"

struct Movie {
  std::string title;
  int year;
  uint32_t duration;
  double rating;
  std::string synopsis;

  std::string director;
  std::vector<std::string> writers;
  std::vector<std::string> studios;
  std::vector<std::string> genres;

  friend std::ostream& operator<<(std::ostream& os, const Movie& movie) {
    os << "Title: " << movie.title << "\n"
       << "Year: " << movie.year << "\n"
       << "Duration: " << movie.duration << " minutes\n"
       << "Rating: " << movie.rating << "\n"
       << "Synopsis: " << movie.synopsis << "\n"
       << "Director: " << movie.director << "\n"
       << "Writers: ";
    for (const auto& writer : movie.writers) {
      os << writer << ", ";
    }
    os << "\nStudios: ";
    for (const auto& studio : movie.studios) {
      os << studio << ", ";
    }
    os << "\nGenres: ";
    for (const auto& genre : movie.genres) {
      os << genre << ", ";
    }
    os << std::endl;
    return os;
  }
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Movie, title, year, duration, rating, synopsis, director, writers, studios, genres)
