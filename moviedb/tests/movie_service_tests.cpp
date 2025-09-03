#include <memory>

#include "gtest/gtest.h"
#include "service/movie_service.hpp"

std::string root_path;
std::string data_path;
std::unique_ptr<MovieService> movie_service;

const Movie Inception = {
  .title = "Inception",
  .year = 2010,
  .duration = 148,
  .rating = 8.8,
  .synopsis = "A thief who steals corporate secrets through the use of dream-sharing technology is given the inverse task of planting an idea into the mind of a C.E.O.",

  .director = "Christopher Nolan",
  .writers = {
      "Christopher Nolan"
  },
  .studios = {
      "Warner Bros.",
      "Legendary Pictures",
      "Syncopy"
  },
  .genres = {
      "Action",
      "Adventure",
      "Sci-Fi"
  },
};

const Movie LoveExposure =  {
  .title = "Love Exposure",
  .year = 2009,
  .duration =  14220,
  .rating = 8.0,
  .synopsis = "The story of a teenage boy named Yu, who falls for Yoko, a girl he runs into while working as an \"up-skirt\" photographer in an offshoot of the porn industry. His attempts to woo her are complicated by a spot of cross-dressing – which convinces Yoko that she is lesbian – dalliances with kung-fu and crime, and a constant struggle with the guilt that's a legacy of his Catholic upbringing.",
  
  .director = "Sion Sono",
  .writers = {
    "Sion Sono"
  },
  .studios = {
    "Omega Project"
  },
  .genres = {
    "Action",
    "Comedy",
    "Drama",
    "Romance"
  },
};

const Movie ABetterTomorrow = {
  .title = "A Better Tomorrow",
  .year = 2010,
  .duration = 5700,
  .rating = 7.4,
  .synopsis = "A reforming ex-gangster tries to reconcile with his estranged policeman brother, but the ties to his former gang are difficult to break.",

  .director = "John Woo",
  .writers = {
    "John Woo",
    "Tsui Hark",
    "Chan Hing-Kai",
    "Leung Suk-Wah"
  },
  .studios = {
    "Cinema City",
    "Film Workshop"
  },
  .genres = {
    "Action",
    "Crime",
    "Drama"
  },
};

TEST(AddMovieTest, SuccesfullyAddsAMovie) {
  EXPECT_TRUE(movie_service->addMovie(LoveExposure));
  EXPECT_TRUE(movie_service->addMovie(ABetterTomorrow));
  EXPECT_TRUE(movie_service->addMovie(Inception));

}

TEST(AddMovieTest, FailsToAddAMovie) {
  bool result = movie_service->addMovie(Inception);

  EXPECT_FALSE(result);
}

TEST(GetMovieTest, SuccesfullyGetsAMovie) {
  auto movie = movie_service->getMovie("Inception");
  EXPECT_TRUE(movie.has_value());
  EXPECT_EQ("Inception", movie->title);
}

TEST(GetMovieTest, FailsToGetAMovie) {
  auto movie = movie_service->getMovie("Recep Ivedik");
  EXPECT_FALSE(movie.has_value());
}

TEST(GetAllMoviesTest, SuccesfullyGetsAllMovies) {
  auto movies = movie_service->getAllMovies();

  EXPECT_EQ(movies.size(), 3);
  EXPECT_TRUE(std::find_if(movies.begin(), movies.end(), [](const Movie& movie) {
    return movie.title == "A Better Tomorrow";
  }) != movies.end());
  EXPECT_TRUE(std::find_if(movies.begin(), movies.end(), [](const Movie& movie) {
    return movie.title == "Love Exposure";
  }) != movies.end());
  EXPECT_TRUE(std::find_if(movies.begin(), movies.end(), [](const Movie& movie) {
    return movie.title == "Inception";
  }) != movies.end());
}

TEST(RemoveMovieTest, SuccesfullyRemovesAMovie) {
  bool result = movie_service->removeMovie("Inception");

  EXPECT_TRUE(result);
}

TEST(RemoveMovieTest, FailsToRemoveAMovie) {
  bool result = movie_service->removeMovie("Inception");

  EXPECT_FALSE(result);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  root_path = argv[1];
  data_path = root_path + "/moviedb/data/movies.json";

  movie_service = std::make_unique<MovieService>(data_path);

  return RUN_ALL_TESTS();
}