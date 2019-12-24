#pragma argsused
#include <iostream>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <stdio.h>
#include <sys/file.h>
#include <dirent.h>
#include <string.h>
#include <sys/dir.h>
#include <sys/unistd.h>

using namespace std;

long GetFileSize(const char* fpath)
{
	FILE* fp = fopen(fpath, "r");
	fseek(fp, 0L, SEEK_END);
	long size = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	fclose(fp);
	return size;
}

int main(int argc, char* argv[], char* envp[])
{
	char buf[PATH_MAX];
	const char* _dirName = realpath(argv[2], buf);
	chdir(_dirName);
	const int _sort_mode = atoi(argv[1]);
	const char* outputDir = argv[3];
	char** _subdir_Names = new char*[256];

	for(int i = 0; i<256; i++) 
		_subdir_Names[i] = new char[256];

	DIR* dptr = opendir(_dirName);
	int size = 1;
	int namelength;
	struct dirent* _dir_Entry;
	struct stat stat_buffer;

	while((_dir_Entry = readdir(dptr))!= NULL)
	{
		char buf1[PATH_MAX];
		if(strcmp(_dir_Entry->d_name, ".."))
		{
			stat(_dir_Entry->d_name, &stat_buffer);
			if((stat_buffer.st_mode & S_IFMT) == S_IFDIR)
			{
				_subdir_Names[size-1] =_dir_Entry->d_name;
				++size;
			}
		} 
	}
	closedir(dptr);
	mkdir(outputDir, 0644);

	for(int i  = 0; i < size-1; ++i)
	{
		int HAindx = 1;
		int FNsize=1;
		char* cur_dir_name = _subdir_Names[i];
		int HANDLE_ARRAY[256];
		char** _file_Names = new char*[256];
		DIR* current_dir = opendir(_subdir_Names[i]);
		
		while((_dir_Entry = readdir(current_dir))!= NULL)
		{
			if(strcmp(_dir_Entry->d_name, "..") && strcmp(_dir_Entry->d_name, "."))
			{
				stat(_dir_Entry->d_name, &stat_buffer);
			
				if((stat_buffer.st_mode & S_IFMT) != S_IFDIR)
				{
					
					_file_Names[FNsize-1] =_dir_Entry->d_name;
					char path[256] = ""; 
					strcat(path, _subdir_Names[i]);
					path[strlen(path)]='/';
					strcat(path, _dir_Entry->d_name);
					path[strlen(path)]='\0';
					
				    HANDLE_ARRAY[HAindx-1] = open(path, O_RDONLY, 0);
					HAindx++;
				    ++FNsize;
				}
			}
		}
		switch(_sort_mode)
		{
			case 1:			
			{
				for(int i = 0; i< HAindx-2; ++i)
				{
					for(int j = i+1; j < HAindx-1; ++j)
					{
						char* tmp;
						fstat(HANDLE_ARRAY[i], &stat_buffer);
						int size_1 = stat_buffer.st_size;
						fstat(HANDLE_ARRAY[j], &stat_buffer);
						int size_2 = stat_buffer.st_size;
						if(size_1>size_2)
						{
						  tmp=_file_Names[i];
						  _file_Names[i] = _file_Names[j];
						  _file_Names[j] = tmp;
						}

					}
				}
				break;
			}
			case 2:			
			{
				for(int i = 0; i< HAindx-2; ++i)
				{
					for(int j = i+1; j < HAindx-1; ++j)
					{
						char* tmp;
						if((int)_file_Names[i][0]>(int)_file_Names[j][0])
						{
							tmp=_file_Names[i];
							_file_Names[i] = _file_Names[j];
							_file_Names[j] = tmp;
						}

					}
				}
				break;
			}
		}

		for(int i = 0; i < HAindx-1; i++)
		{
			char buffer1[256];
			char fpath[256] = "";
			strcat(fpath, _dirName);
			strcat(fpath, "/");
			strcat(fpath, outputDir);
			strcat(fpath, "/");
			strcat(fpath, _file_Names[i]);
			fpath[strlen(fpath)]='\0';
			char cmd[256] = "cp ";
			strcat(cmd, cur_dir_name);
			strcat(cmd, "/");
			strcat(cmd, _file_Names[i]);
			strcat(cmd, " ");
			strcat(cmd, fpath);
			system(cmd);
			cout << "Absolute file path===" << fpath << "\tSize==" << GetFileSize(fpath) << " bytes"<< endl;
			
		}
		cout << "-------------------------------------------------------------" << endl;
		fcloseall();
		delete[] _file_Names;
		closedir(current_dir);
	}
	return 0;
}
