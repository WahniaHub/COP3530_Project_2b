#include <iostream>
#include <string>
#include <vector>
#include "csv_loader.h"
#include "merge_sort.h"
#include "quick_sort.h"

static TrackComparator chooseComparator(int category) {
    switch (category) {
    case 1:
        return compareTracksByArtist;
    case 2:
        return compareTracksByTrackName;
    case 3:
        return compareTracksByGenre;
    case 4:
        return compareTracksByDuration;
    case 5:
        return compareTracksByPopularity;
    case 6:
        return compareTracksByTempo;
    case 7:
        return compareTracksByEnergy;
    case 8:
        return compareTracksByDanceability;
    default:
        return nullptr;
    }
}

static void printTrack(const Track& track) {
    std::cout << track.artist << " - " << track.trackName
              << " | genre: " << track.genre
              << " | popularity: " << track.popularity
              << " | tempo: " << track.tempo << '\n';
}

int main(int argc, char* argv[]) {
    const std::string path = argc > 1 ? argv[1] : "spotify.csv";
    std::vector<Track> tracks = loadTracks(path);
    if (tracks.empty()) {
        std::cerr << "No tracks were loaded.\n";
        return 1;
    }

    std::cout << "Choose a category to sort by:\n"
              << "1. Artist\n"
              << "2. Track name\n"
              << "3. Genre\n"
              << "4. Duration\n"
              << "5. Popularity\n"
              << "6. Tempo\n"
              << "7. Energy\n"
              << "8. Danceability\n"
              << "Category: ";

    int category = 0;
    if (!(std::cin >> category)) {
        std::cerr << "Invalid category.\n";
        return 1;
    }

    TrackComparator comparator = chooseComparator(category);
    if (comparator == nullptr) {
        std::cerr << "Category must be a number from 1 to 8.\n";
        return 1;
    }

    std::cout << "Choose a sorting algorithm:\n"
              << "1. Merge sort\n"
              << "2. Quick sort\n"
              << "Algorithm: ";

    int algorithm = 0;
    if (!(std::cin >> algorithm) || (algorithm != 1 && algorithm != 2)) {
        std::cerr << "Algorithm must be 1 or 2.\n";
        return 1;
    }

    long long comparisons = 0;
    if (algorithm == 1) {
        tracks = mergeSort(tracks, comparisons, comparator);
    } else {
        quickSort(tracks, 0, static_cast<int>(tracks.size()) - 1,
                  comparisons, comparator);
    }

    std::cout << "\nSorted " << tracks.size() << " tracks using "
              << (algorithm == 1 ? "merge sort" : "quick sort")
              << ". Comparisons: " << comparisons << "\n\n";

    const size_t tracksToPrint = tracks.size() < 10 ? tracks.size() : 10;
    for (size_t i = 0; i < tracksToPrint; ++i) {
        printTrack(tracks[i]);
    }

    return 0;
}
