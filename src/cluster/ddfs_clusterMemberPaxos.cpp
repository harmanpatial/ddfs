/*
 * @file ddfs_clusterMemberPaxos.cpp
 *
 * @brief Module containing the cluster member class.
 *
 * This is the module that contains cluster member class.
 *
 * @author Harman Patial <harman.patial@gmail.com>
 *
 */

#include <fstream>
#include <string>

#include "ddfs_clusterMemberPaxos.h"
#include "../global/ddfs_status.h"

using namespace std;

ddfsClusterMemberPaxos::ddfsClusterMemberPaxos() {
	clusterID = -1;
	memberID = -1;
	uniqueIdentification = -1;
	memberState = s_clusterMemberUnknown;
	return;
}

ddfsStatus ddfsClusterMemberPaxos::init(bool isLocalNode) {
    if (isLocalNode == false)
	    return (ddfsStatus(DDFS_FAILURE));

    /* For local node, need to initialize the underline network class */
    network.openConnection(hostName);
    return (ddfsStatus(DDFS_OK));
}

ddfsStatus ddfsClusterMemberPaxos::isOnline() {
	clustermemberLock.lock();
	clustermemberLock.unlock();
	return (ddfsStatus(DDFS_FAILURE));
}

ddfsStatus ddfsClusterMemberPaxos::isDead() {
	clustermemberLock.lock();
	clustermemberLock.unlock();
	return (ddfsStatus(DDFS_FAILURE));
}

clusterMemberState ddfsClusterMemberPaxos::getCurrentState() {
	clustermemberLock.lock();
	clustermemberLock.unlock();
	return memberState;	
}

ddfsStatus ddfsClusterMemberPaxos::setCurrentState(clusterMemberState newState) {
	clustermemberLock.lock();
	memberState = newState;
	clustermemberLock.unlock();
	return (ddfsStatus(DDFS_OK));
}

void ddfsClusterMemberPaxos::setMemberID(int newMemberID) {
	clustermemberLock.lock();
	memberID = newMemberID;
	clustermemberLock.unlock();
}

int ddfsClusterMemberPaxos::getMemberID() {
	clustermemberLock.lock();
	clustermemberLock.unlock();
	return memberID;
}

void ddfsClusterMemberPaxos::setUniqueIdentification(int newIdentifier) {
	clustermemberLock.lock();
	uniqueIdentification =  newIdentifier;
	clustermemberLock.unlock();
}
int ddfsClusterMemberPaxos::getUniqueIdentification() {
	return uniqueIdentification;
}

ddfsStatus ddfsClusterMemberPaxos::sendClusterMetaData(ddfsClusterMessagePaxos *message) {
    /* Need to have a reference of network packet and send the buffer to it */
    ddfsUdpConnection network;

    /* TODO: Register a callback function */
    network.sendData(message->returnBuffer(), message->returnBufferSize(), NULL);
	return (ddfsStatus(DDFS_OK));
}


