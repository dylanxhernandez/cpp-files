#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/statvfs.h>

double getMemoryUsage() {
	struct sysinfo memInfo;
	sysinfo(&memInfo);
	return (double)(memInfo.totalram - memInfo.freeram) * memInfo.mem_unit / (1024 * 1024); // in MB
}

double getDiskUsage(const std::string &path) {
	struct statvfs diskInfo;
	statvfs(path.c_str(), &diskInfo);
	return (double)(diskInfo.f_blocks - diskInfo.f_bfree) * diskInfo.f_frsize / (1024 * 1024); // in MB
}

int main() {
	// Get memory and disk usage and assign to variables
	double memoryUsed = getMemoryUsage();
	double diskUsed = getDiskUsage("/");

	// Display the information in a table
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "| Memory and Disk in Use" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "| MEMORY USED: " << memoryUsed << " MB" << std::endl;
	std::cout << "| DISK USED: " << diskUsed << " MB" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	return 0;
}

