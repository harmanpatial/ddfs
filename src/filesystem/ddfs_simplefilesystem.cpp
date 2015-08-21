/*!
 *    \file  ddfs_simplefilesystem.cpp
 *   \brief  
 *  
 *  <+DETAILED+>
 *  
 *  \author  Harman Patial, harman.patial@gmail.com
 *  
 *  \internal
 *      Compiler:  g++
 *     Copyright:  
 *  
 *  This source code is released for free distribution under the terms of the
 *  GNU General Public License as published by the Free Software Foundation.
 */

#include <cstdio>

#include "ddfs_simplefilesystem.hpp"

ddfsStatus ddfsSimpleFilesystem::init() {
	metaData.init("/tmp/ddfsMetaDatafile");
	return metaData.fillInMemDirectoryTree();
}

ddfsStatus ddfsSimpleFilesystem::init(string metaFileName) {
	metaData.init(metaFileName);
	return metaData.fillInMemDirectoryTree();
}

ddfsStatus open(string path, int mode, void *handler) {
	return (ddfsStatus(DDFS_FAILURE));
}

ddfsStatus closeFile(void * handler) {
	return (ddfsStatus(DDFS_FAILURE));

}
ddfsStatus readFile(void *handler, int size, void *buffer) {
	return (ddfsStatus(DDFS_FAILURE));

}

ddfsStatus readFile(void * handler, int size, void *buffer, int offset) {
	return (ddfsStatus(DDFS_FAILURE));

}

ddfsStatus writeFile(void * handler, int size, void *buffer) {
	return (ddfsStatus(DDFS_FAILURE));

}

ddfsStatus writeFile(void * handler, int size, void *buffer, int offset) {
	return (ddfsStatus(DDFS_FAILURE));

}	

ddfsStatus seekFile(void * handler, int offset){
	return (ddfsStatus(DDFS_FAILURE));

}

ddfsStatus createFile(string directory, string fileName, int mode) {
	return (ddfsStatus(DDFS_FAILURE));

}

ddfsStatus makedirectory(string directory, string directoryName) {
	return (ddfsStatus(DDFS_FAILURE));

}

ddfsStatus deleteFile(void *handler){
	return (ddfsStatus(DDFS_FAILURE));

}


