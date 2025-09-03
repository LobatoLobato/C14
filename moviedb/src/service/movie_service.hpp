#pragma once

#include <fstream>
#include <algorithm>
#include <optional>

#include "model/movie.hpp"
#include "nlohmann/json.hpp"

class MovieService {
 public:
  explicit MovieService(std::string data_path): data_path_(std::move(data_path)) {};

  std::optional<Movie> getMovie(const std::string& title) {
    std::ifstream file(data_path_);
    auto movies = nlohmann::json::parse(file).get<nlohmann::json::array_t>();
    auto it = std::find_if(movies.begin(), movies.end(), [&](const nlohmann::json& movie) {
      return movie["title"] == title;
    });

    if (it != movies.end()) { return it->get<Movie>(); }

    return std::nullopt;
  }

  std::vector<Movie> getAllMovies() {
    std::ifstream file(data_path_);
    return nlohmann::json::parse(file).get<std::vector<Movie>>();
  }

  bool addMovie(const Movie& movie) {
    std::ifstream file(data_path_);
    auto movies = nlohmann::json::parse(file).get<nlohmann::json::array_t>();
    auto it = std::find_if(movies.begin(), movies.end(), [&](const nlohmann::json& m) {
      return m["title"] == movie.title;
    });
    if (it == movies.end()) {
      movies.push_back(movie);
      std::ofstream outFile(data_path_);
      outFile << nlohmann::json(movies).dump(4);
      return true;
    }

    return false;
  }

  bool removeMovie(const std::string& title) {
    std::ifstream file(data_path_);
    auto movies = nlohmann::json::parse(file).get<nlohmann::json::array_t>();
    auto it = std::find_if(movies.begin(), movies.end(), [&](const nlohmann::json& m) {
      return m["title"] == title;
    });

    if (it != movies.end()) {
      movies.erase(it);
      std::ofstream outFile(data_path_);
      outFile << nlohmann::json(movies).dump(4);

      return true;
    }

    return false;
  }

  private:
  std::string data_path_;
};