#ifndef PUBRTYPE_PAQUET_HPP
#define PUBRTYPE_PAQUET_HPP

#include <ctime>

struct Paquet {
    long int id; // growing ID
    int sequence; // sequence number / tick number
    int replication; // what replication is this
    std::time_t timestamp;
    void *data; // TO REPLACE WITH APPROPRIATE DATA STRUCTURE WHEN KNOWN
};

#endif // PUBRTYPE_PAQUET_HPP
