# Sortify

Sortify is a comparative application for sorting many large sets of Spotify track
dataset with either merge sort or quick sort. It includes a C++ command-line
program and a small Express web interface for selecting the sort options.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Project Structure](#project-structure)
- [Build and Run](#build-and-run)
- [Command-Line Usage](#command-line-usage)
- [Web Interface](#web-interface)
- [Data](#data)
- [Notes](#notes)

## Features

- Loads track records from `spotify.csv` (loaded from the `kaggle.py`).
- Sorts tracks with merge sort or quick sort.
- Tracks the number of element comparisons.
- Sorts by:
  - Artist
  - Track name
  - Track genre
  - Duration
  - Popularity
  - Tempo
  - Energy
  - Danceability
- Supports ascending and descending output.
- Prints the first ten sorted tracks (quantity can be adjusted).

## Requirements

- A C++17-compatible compiler, such as MinGW-w64 `g++`
- Node.js and npm for the web interface
- The included `spotify.csv` dataset

## Project Structure

| File or directory | Purpose |
| --- | --- |
| `main.cpp` | Command-line application entry point |
| `track.h` | Track model and comparison functions |
| `csv_loader.cpp` / `csv_loader.h` | CSV loading and parsing |
| `merge_sort.cpp` / `merge_sort.h` | Merge sort implementation |
| `quick_sort.cpp` / `quick_sort.h` | Quick sort implementation |
| `spotify.csv` | Input Spotify track dataset |
| `frontend/web.html` | Browser user interface |
| `frontend/web.js` | Sends sort requests and displays results |
| `frontend/webnode.js` | Express server |

## Build and Run

From the repository root, compile the C++ program:

```powershell
g++ -std=c++17 -O2 main.cpp -o sortify.exe
```

The program expects `spotify.csv` in its working directory. Start the web
server from the `frontend` directory:

```powershell
cd frontend
npm install
node webnode.js
```

Open the application at [http://localhost:3020](http://localhost:3020).

## Command-Line Usage

The executable accepts a category, algorithm, and direction:

```text
sortify.exe <category> <algorithm> <direction>
```

Example:

```powershell
.\sortify.exe popularity merge descending
```

Valid values are:

| Argument | Values |
| --- | --- |
| `category` | `artists`, `track_name`, `track_genre`, `duration`, `popularity`, `tempo`, `energy`, `danceability` |
| `algorithm` | `merge`, `quick` |
| `direction` | `ascending`, `descending` |

The command prints the number of loaded tracks, the comparison count, and up
to ten tracks in pipe-delimited format.

## Web Interface

After starting the server, choose a category, algorithm, and direction in the
browser, then select **Click to Sort**. The page displays the comparison count
and the first ten results.

## Data

The loader expects a CSV header containing these columns:

```text
artists,track_name,track_genre,duration_ms,popularity,tempo,energy,danceability
```

The included dataset is based on the
[Spotify Tracks Dataset](https://www.kaggle.com/datasets/maharshipandya/-spotify-tracks-dataset).
`kaggle.py` contains the dataset download/export code used to create
`spotify.csv`.

## Notes

- Run the executable from the repository root so it can find `spotify.csv`.
- Run `node webnode.js` from `frontend`; the server launches the executable
  from the repository root.
- The generated executable is ignored by Git through `.gitignore`.
