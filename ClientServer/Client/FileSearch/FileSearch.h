#ifndef FILE_SEARCH_H
#define FILE_SEARCH_H

#ifdef _WIN32
#include <Windows.h>
#define DEFAULT_DIRECTORY "\\"
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#define DEFAULT_DIRECTORY "/home"
#endif

#include<iostream>
#define FAIL_MESSAGE "Failure! File doesn't exist!"

class FileSearch
{
private:
	std::string fileName;
	std::string filePath;
	void recursiveFindFile(std::string folderName);
public:
	std::string doSearch(std::string requestedFile);
	bool isFound = false;
};



#endif
