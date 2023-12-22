//
// Created by rita on 17-03-2023.
//

#include <iostream>
#include "dataRepository.h"

using namespace std;

DataRepository::DataRepository() = default;

const stationTable &DataRepository::getStations() const {
    return stations;
}

void DataRepository::setStations(const stationTable &stations) {
    this->stations = stations;
}

const unordered_map<std::string, std::list<Station>> &DataRepository::getDistrictToStations() const {
    return districtToStations;
}

void DataRepository::setDistrictToStations(const unordered_map<std::string, std::list<Station>> &districtToStations) {
    DataRepository::districtToStations = districtToStations;
}

const unordered_map<std::string, std::list<Station>> &DataRepository::getMunicipalityToStations() const {
    return municipalityToStations;
}

void DataRepository::setMunicipalityToStations(
        const unordered_map<std::string, std::list<Station>> &municipalityToStations) {
    DataRepository::municipalityToStations = municipalityToStations;
}

const unordered_map<std::string, std::list<Station>> &DataRepository::getTownshipToStations() const {
    return townshipToStations;
}

void DataRepository::setTownshipToStations(const unordered_map<std::string, std::list<Station>> &townshipToStations) {
    DataRepository::townshipToStations = townshipToStations;
}

/**
 * Adds a new entry to the unordered_set of Stations, creating the corresponding Station object
 * Time Complexity: O(1) (average case) | O(size(stations)) (worst case)
 * @param name - Name of the station to be created
 * @param district - District of the Station to be created
 * @param municipality - Municipality of the Station to be created
 * @param township - Township of the Station to be created
 * @param line - Line of the station to be created
 * @return New Station object created
 */
Station
DataRepository::addStationEntry(const std::string &name, const std::string &district, const std::string &municipality,
                                const std::string &township,
                                const std::string &line) {
    Station newStation = Station(name, district, municipality, township, line);
    stations.insert(newStation);
    return newStation;
}


/**
 * Adds a new Station value to an entry in the districtToStations unordered_map
 * Time Complexity: O(1) (average case) | O(size(districtToStations)) (worst case)
 * @param district - District of the new Station
 * @param station - Station to add
 */
void DataRepository::addStationToDistrictEntry(const string &district, const Station &station) {
    districtToStations[district].push_back(station);
}

/**
 * Adds a new Station value to an entry in the municipalityToStations unordered_map
 * Time Complexity: O(1) (average case) | O(size(municipalityToStations)) (worst case)
 * @param municipality - Municipality of the new Station
 * @param station - Station to add
 */
void DataRepository::addStationToMunicipalityEntry(const std::string &municipality, const Station &station) {
    municipalityToStations[municipality].push_back(station);
}

/**
 * Adds a new Station value to an entry in the townshipToStations unordered_map
 * Time Complexity: O(1) (average case) | O(size(townshipToStations)) (worst case)
 * @param township - Township of the new Station
 * @param station - Station to add
 */
void DataRepository::addStationToTownshipEntry(const std::string &township, const Station &station) {
    townshipToStations[township].push_back(station);
}


/**
 * Finds the Station object with the given name
 * Time Complexity: O(1) (average case) | O(size(stations)) (worst case)
 * @param name - Name of the Station to be returned
 * @return optional<Station> value which will contain the Station object, or be empty if no such Station was found
 */
std::optional<Station> DataRepository::findStation(const string &name) {
    std::optional<Station> result;
    auto it = stations.find(Station(name));
    if (it != stations.end()) result = *it;
    return result;
}


/**
 * Finds the Station objects with the given district
 * Time Complexity: O(1) (average case) | O(size(districtToStations)) (worst case)
 * @param district - District whose Stations should be found
 * @return list<Station> containing the Stations in the given district
 */
list<Station> DataRepository::findStationsInDistrict(const std::string &district) {
    return districtToStations.at(district);
}

/**
 * Finds the Station objects with the given municipality
 * Time Complexity: O(1) (average case) | O(size(municipalityToStations)) (worst case)
 * @param municipality - Municipality whose Stations should be found
 * @return list<Station> containing the Stations in the given municipality
 */
list<Station> DataRepository::findStationsInMunicipality(const std::string &municipality) {
    return municipalityToStations.at(municipality);
}

/**
 * Finds the Station objects with the given township
 * Time Complexity: O(1) (average case) | O(size(townshipToStations)) (worst case)
 * @param township - Township whose Stations should be found
 * @return list<Station> containing the Stations in the given township
 */
list<Station> DataRepository::findStationsInTownship(const std::string &township) {
    return townshipToStations.at(township);
}

/**
 * Checks if the given district is valid, that is, if there is stored data referencing it
 * Time Complexity: O(1) (average case) | O(size(districtToStations)) (worst case)
 * @param district - District to be validated
 * @return true if the district is valid, false if it is not
 */
bool DataRepository::checkValidDistrict(const std::string &district) {
    return districtToStations.find(district) != districtToStations.end();
}

/**
 * Checks if the given municipality is valid, that is, if there is stored data referencing it
 * Time Complexity: O(1) (average case) | O(size(municipalityToStations)) (worst case)
 * @param municipality - Municipality to be validated
 * @return true if the municipality is valid, false if it is not
 */
bool DataRepository::checkValidMunicipality(const std::string &municipality) {
    return municipalityToStations.find(municipality) != municipalityToStations.end();
}

/**
 * Checks if the given township is valid, that is, if there is stored data referencing it
 * Time Complexity: O(1) (average case) | O(size(townshipToStations)) (worst case)
 * @param township - Township to be validated
 * @return true if the township is valid, false if it is not
 */
bool DataRepository::checkValidTownship(const std::string &township) {
    return townshipToStations.find(township) != townshipToStations.end();
}




