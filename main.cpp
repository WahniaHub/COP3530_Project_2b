#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "csv_loader.cpp"
#include "merge_sort.cpp"
#include "quick_sort.cpp"

static TrackComparator chooseComparator(std::string category) {
    if (category ==  "artists") return compareTracksByArtist;
    if (category == "track_name") return compareTracksByTrackName;
    if (category ==  "track_genre") return compareTracksByGenre;
    if (category ==   "duration") return compareTracksByDuration;
    if (category ==   "popularity") return compareTracksByPopularity;
    if (category ==   "tempo") return compareTracksByTempo;
    if (category ==   "energy") return compareTracksByEnergy;
    if (category ==  "danceability") return compareTracksByDanceability;
    return nullptr;
}

static void printTrack(const Track& track) {
    std::cout << track.artist << "|" << track.trackName << "|" << track.genre << "|" << track.durationMs << "|" << track.popularity 
    << "|" << track.tempo << "|" << track.energy << "|" << track.danceability << '\n';
}

int main(int argc, char* argv[]) {
    const std::string path = "spotify.csv";
    std::vector<Track> tracks = loadTracks(path);
    if (tracks.empty()) {
        std::cerr << "No tracks were loaded.\n";
        return 1;
    }

    std::string category = argv[1];
    TrackComparator comparator = chooseComparator(category);
    if (comparator == nullptr) {
        std::cerr << "Unknown\n";
        return 1;
    }

    std::string algorithm = argv[2];

    long long comparisons = 0;
    if (algorithm == "merge") {
        tracks = mergeSort(tracks, comparisons, comparator);
    } else {
        quickSort(tracks, 0, static_cast<int>(tracks.size()) - 1,
                  comparisons, comparator);
    }
    
    std::cout << "\nSorted " << tracks.size() << " tracks using "
              << (algorithm == "merge" ? "merge sort" : "quick sort")
              << ". Comparisons: " << comparisons << "\n";

    const size_t tracksToPrint = tracks.size() < 10 ? tracks.size() : 10;
    std::string direction = argv[3];
    if (direction == "descending"){
        std::reverse(tracks.begin(), tracks.end());
    }

    for (size_t i = 0; i < tracksToPrint; ++i) {
        printTrack(tracks[i]);
    }
    return 0;
}
