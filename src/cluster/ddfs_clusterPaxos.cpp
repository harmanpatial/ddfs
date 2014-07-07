/*
 * @file ddfs_clusterPaxos.cpp
 *
 * @brief Module containing the cluster class.
 *
 * This is the module that contains cluster class.
 *
 * @author Harman Patial <harman.patial@gmail.com>
 *
 */

#include <fstream>
#include <string>

#include "ddfs_clusterPaxos.h"
#include "ddfs_clusterMessagesPaxos.h"
#include "ddfs_clusterPaxosInstance.h"
#include "../logger/ddfs_fileLogger.h"
#include "../global/ddfs_status.h"

#include <sys/types.h>
#include <ifaddrs.h>
#include <unistd.h>

using namespace std;

ddfsLogger &global_logger = ddfsLogger::getInstance();
 
ddfsClusterPaxos::ddfsClusterPaxos() {
	clusterID = s_clusterIDInvalid;
	localClusterMember = new ddfsClusterMemberPaxos;
	clusterMemberCount = 1; /* 1 for the local Node */
	paxosProposalNumber = 
		getLocalNode()->getUniqueIdentification();

	return;
}

uint64_t ddfsClusterPaxos::getProposalNumber() {
	return paxosProposalNumber++;
}

ddfsStatus ddfsClusterPaxos::leaderElection() {
	list<ddfsClusterMemberPaxos *>::iterator clusterMemberIter;
	list<ddfsClusterMemberPaxos *> members;
	ddfsStatus status(DDFS_FAILURE);
	
	/*  If there is no other node in the cluster, no need to start leader
	 *  election.
	 */
	if(clusterMemberCount <= 1) {
		global_logger << ddfsLogger::LOG_INFO
			<< "Cannot perform leader election. Add more nodes in the cluster";
		global_logger << ddfsLogger::LOG_INFO
			<< "Number of members in the cluster : "<< clusterMemberCount;
		return (ddfsStatus(DDFS_CLUSTER_INSUFFICIENT_NODES));
	}

	/* Push all the online members of the cluster to a local list */
	for(clusterMemberIter = clusterMembers.begin(); clusterMemberIter != clusterMembers.end(); clusterMemberIter++) {
		if((*clusterMemberIter)->isOnline().compareStatus(ddfsStatus(DDFS_OK)) == false) {
			global_logger << ddfsLogger::LOG_WARNING << "Node " << (*clusterMemberIter)->getUniqueIdentification() << " is offline";
		}
		/* Push this member to the local members list. */
		members.push_back(*clusterMemberIter);
	}

	/*  Create a ddfsClusterPaxosInstance instance and let it rip
	 *  
	 *  NOTE : As this is leader election paxos instance, there is no need
	 *  	   for async completion of the paxos instance.
	 */
	ddfsClusterPaxosInstance paxosInstance; 

	status = paxosInstance.start(getProposalNumber(), members);
	if(status.compareStatus(ddfsStatus(DDFS_OK)) == false) {
		global_logger << ddfsLogger::LOG_WARNING << "********* LEADER ELECTION FAILED *********";
	}

	global_logger << ddfsLogger::LOG_WARNING << "LEADER ELECTION SUCCESSFULL.";
	return status; 
}

void ddfsClusterPaxos::asyncEventHandling() {
	
}

ddfsStatus ddfsClusterPaxos::addMember(ddfsClusterMemberPaxos) {
	return (ddfsStatus(DDFS_FAILURE));
}

ddfsStatus ddfsClusterPaxos::addMembers() {
	return (ddfsStatus(DDFS_FAILURE));
}

ddfsStatus ddfsClusterPaxos::deleteMember() {
	return (ddfsStatus(DDFS_FAILURE));
}

ddfsStatus ddfsClusterPaxos::deleteMembers() {
	return (ddfsStatus(DDFS_FAILURE));
}

ddfsClusterMemberPaxos* ddfsClusterPaxos::getLocalNode() {
	return localClusterMember;
}