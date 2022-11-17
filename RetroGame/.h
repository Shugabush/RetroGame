#pragma once
#include <iostream>
#include <fstream>
#include <Text.hpp>

void Save(std::string text, std::string filePath);

std::string Load(std::string filePath);