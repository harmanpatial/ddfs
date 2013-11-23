/*
 * ddfsStatus.h 
 *
 * Status used across the DDFS modules.
 *
 * Author Harman Patial <harman.patial@gmail.com>
 */
#ifndef DDFS_STATUS_H
#define DDFS_STATUS_H

enum DDFS_STATUS {
	DDFS_OK,
	DDFS_HOST_DOWN,
	DDFS_NETWORK_NO_DATA,
	DDFS_NETWORK_RETRY,
	DDFS_NETWORK_UNDERRUN,
	DDFS_NETWORK_OVERRUN,
	DDFS_FAILURE
};

class ddfsStatus {

private:
	DDFS_STATUS status;

public:
	explicit ddfsStatus(DDFS_STATUS local_status);
	/**
 	 *   statusToString
 	 *
 	 * Print the human readable string for the DDFS status.
 	 *
 	 */
	std::string statusToString();
}; // class end

#endif /* Ending DDFS_STATUS_H */