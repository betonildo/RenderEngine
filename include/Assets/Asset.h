#ifndef ASSET_H
#define ASSET_H

class Asset {

public:
    virtual void load(const char* relativePath) = 0;

};

#endif /*ASSET_H*/