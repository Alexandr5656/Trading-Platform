#include "resource_owner.h"

#include <iostream>

ResourceOwner::ResourceOwner(int buffLength) : buffLength(buffLength), rawBuff(new int[buffLength]) {
    std::cout << "ResourceOwner: acquired\n";
}

ResourceOwner::ResourceOwner(const ResourceOwner& other)
    : buffLength(other.buffLength),             // matches declaration order in the header (buffLength, then rawBuff)
      rawBuff(new int[other.buffLength])
{
    std::copy(other.rawBuff, other.rawBuff + buffLength, rawBuff);
}


ResourceOwner& ResourceOwner::operator=(const ResourceOwner& other) {
    if (this == &other) return *this;
    int* newBuff = new int[other.buffLength];
    std::copy(other.rawBuff, other.rawBuff + other.buffLength, newBuff);
    delete[] rawBuff;
    rawBuff = newBuff;
    buffLength = other.buffLength;
    return *this;
}

ResourceOwner::ResourceOwner(ResourceOwner&& other) noexcept : buffLength(other.buffLength), rawBuff(other.rawBuff) {
    other.rawBuff = nullptr;
    other.buffLength = 0;
}

ResourceOwner& ResourceOwner::operator=(ResourceOwner&& other) noexcept {
    if (this == &other) return *this;
    delete[] rawBuff;
    rawBuff = other.rawBuff;
    buffLength = other.buffLength;
    other.rawBuff = nullptr;
    other.buffLength = 0;
    return *this;
}
ResourceOwner::~ResourceOwner() {
    // TODO: release the resource here.
    delete[] rawBuff;
    std::cout << "ResourceOwner: released\n";
}

// TODO: define any of the Rule of Five members you declared in the header.
