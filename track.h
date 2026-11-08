#pragma once
#include <string>

struct Track {
    std::string artist;
    std::string trackName;
    std::string genre;
    int durationMs;
    int popularity;
    double tempo;
    double energy;
    double danceability;
};

using TrackComparator = bool (*)(const Track&, const Track&);

inline bool compareTracksByPopularity(const Track& left, const Track& right) {
    return left.popularity < right.popularity;
}

inline bool compareTracksByArtist(const Track& left, const Track& right) {
    return left.artist < right.artist;
}

inline bool compareTracksByTrackName(const Track& left, const Track& right) {
    return left.trackName < right.trackName;
}

inline bool compareTracksByGenre(const Track& left, const Track& right) {
    return left.genre < right.genre;
}

inline bool compareTracksByDuration(const Track& left, const Track& right) {
    return left.durationMs < right.durationMs;
}

inline bool compareTracksByTempo(const Track& left, const Track& right) {
    return left.tempo < right.tempo;
}

inline bool compareTracksByEnergy(const Track& left, const Track& right) {
    return left.energy < right.energy;
}

inline bool compareTracksByDanceability(const Track& left, const Track& right) {
    return left.danceability < right.danceability;
}