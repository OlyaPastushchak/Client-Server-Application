#include"FileSearch.h"

void FileSearch::recursiveFindFile(std::string folderName)
{
	DIR* currentDir = opendir(folderName.c_str());

	if (!currentDir)
	{
		return;
	}
	dirent* pToCurrent;
	while ((pToCurrent = readdir(currentDir)) != nullptr)
	{
		if (!isFound)
		{
			if (isalpha((unsigned char)pToCurrent->d_name[0]) && pToCurrent->d_type != DT_BLK)
			{
				if (pToCurrent->d_name == fileName)
				{
					isFound = true;
					filePath ="Success! Path to file: "+ folderName + std::string("/") + std::string(pToCurrent->d_name);
				}

				if (DT_DIR & pToCurrent->d_type && strcmp(pToCurrent->d_name, ".") && strcmp(pToCurrent->d_name, ".."))
				{

					std::string next = folderName + std::string("/") + std::string(pToCurrent->d_name);
					recursiveFindFile(next);
				}
			}
		}
		else
		{
			return;
		}

	}
}

std::string FileSearch::doSearch(std::string requestedFile)
{
	fileName = requestedFile;
	filePath = FAIL_MESSAGE;

	recursiveFindFile(DEFAULT_DIRECTORY);
	isFound = true;

	return filePath;
}

