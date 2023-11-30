#include <SFML/Graphics.hpp>
#include "../include/ResourceManager.hpp"
#include "../include/Logger.hpp"

const std::string ASSET_FILE = "../assets/";

bool ResourceManager::GetTexture(std::string texturePath, sf::Texture& texture) const
{
	std::string filePath = ASSET_FILE + "images/" + texturePath;

	if (texture.loadFromFile(filePath))
	{
		Logger::GetInstance()->log(LogLevel::INFO, "Able to open texture '" + texturePath + "'");
		return true;
	}

	Logger::GetInstance()->log(LogLevel::ERROR, "Unable to open texture '" + texturePath + "'");
	return false;
}

bool ResourceManager::LoadFont(std::string fontPath, sf::Font& font) const
{
	std::string filePath = ASSET_FILE + "fonts/" + fontPath;

	if (font.loadFromFile(filePath))
	{
		Logger::GetInstance()->log(LogLevel::INFO, "Loaded Font:" + fontPath);
		return true;
	}

	Logger::GetInstance()->log(LogLevel::ERROR, "Unable to load Font:" + fontPath);
	return false;
}
