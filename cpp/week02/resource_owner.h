#pragma once

#include <algorithm>

class ResourceOwner {
public:
    // Constructor and Destructor
    explicit ResourceOwner(int buffLength);
    ~ResourceOwner();
    
    ResourceOwner(const ResourceOwner& other);

    ResourceOwner& operator=(const ResourceOwner& other);

    ResourceOwner(ResourceOwner&& other) noexcept;

    ResourceOwner& operator=(ResourceOwner&& other) noexcept;

private:
    int buffLength;
    int* rawBuff;
};