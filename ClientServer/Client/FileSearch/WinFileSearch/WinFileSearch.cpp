#include"FileSearch.h"

void FileSearch::recursiveFindFile(std::string folderName)
{
	WIN32_FIND_DATA fileData;
	std::string validPath = folderName + "*";
	HANDLE first = FindFirstFile(&validPath[0], &fileData);

	while (FindNextFile(first, &fileData))
	{
		if (!isFound)
		{
			if (isalpha((unsigned char)fileData.cFileName[0]))
			{

				if (fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)//if directory
				{
					std::string NewPath = folderName + fileData.cFileName;
					NewPath = NewPath + "\\";

					recursiveFindFile(NewPath);
				}
				else
				{
					if (fileData.cFileName == fileName)
					{
						isFound = true;
						filePath ="Success! Path to file: "+ folderName + fileName;
					}
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

