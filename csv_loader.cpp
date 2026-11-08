#include "csv_loader.h"
#include <fstream>
#include <iostream>
#include <unordered_map>

static std::vector<std::string> parseLine(const std::string& line) {
    std::vector<std::string> fields;
    std::string cur;
    bool inQuotes = false;

    for (size_t i = 0; i < line.size(); ++i) {
        char c = line[i];
        if (inQuotes) {
            if (c == '"') {
                if (i + 1 < line.size() && line[i + 1] == '"') {
                    cur += '"';
                    ++i;
                } else {
                    inQuotes = false;
                }
            } else {
                cur += c;
            }
        } else {
            if (c == '"') inQuotes = true;
            else if (c == ',') { fields.push_back(cur); cur.clear(); }
            else if (c != '\r') cur += c;
        }
    }
    fields.push_back(cur);
    return fields;
}

std::vector<Track> loadTracks(const std::string& path) {
    std::vector<Track> tracks;
    std::ifstream file(path);
    if (!file) {
        std::cerr << "Could not open " << path << "\n";
        return tracks;
    }

    std::string line;
    std::getline(file, line);
    std::unordered_map<std::string, int> col;
    std::vector<std::string> header = parseLine(line);
    for (int i = 0; i < static_cast<int>(header.size()); ++i) col[header[i]] = i;

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::vector<std::string> f = parseLine(line);
        if (f.size() < header.size()) continue;

        try {
            Track t;
            t.artist       = f[col["artists"]];
            t.trackName    = f[col["track_name"]];
            t.genre        = f[col["track_genre"]];
            t.durationMs   = std::stoi(f[col["duration_ms"]]);
            t.popularity   = std::stoi(f[col["popularity"]]);
            t.tempo        = std::stod(f[col["tempo"]]);
            t.energy       = std::stod(f[col["energy"]]);
            t.danceability = std::stod(f[col["danceability"]]);
            tracks.push_back(t);
        } catch (...) {
        }
    }
    return tracks;
}