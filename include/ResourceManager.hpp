#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "./Entity.hpp"
#include "./Singleton.hpp"

class ResourceManager : public Singleton<ResourceManager>
{
public:
	bool GetTexture(std::string texturePath, sf::Texture& texture) const;
	bool LoadFont(std::string fontPath, sf::Font& font) const;
};

#endif
