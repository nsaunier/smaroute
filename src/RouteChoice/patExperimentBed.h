/*
 * patExperimentBed.h
 *
 *  Created on: Jul 11, 2012
 *      Author: jchen
 */

#ifndef PATEXPERIMENTBED_H_
#define PATEXPERIMENTBED_H_

#include "patNetworkEnvironment.h"
#include "patTransportMode.h"
#include "patRandomNumber.h"

#include "patNode.h"
#include "patLinkAndPathCost.h"
#include "MHWeightFunction.h"
#include "patUtilityFunction.h"
#include "patObservation.h"
#include "MHPathGenerator.h"
#include "RWPathGenerator.h"
#include "patMultiModalPath.h"



#include <map>
#include <vector>
class patExperimentBed {
public:
	patExperimentBed( bool network_real,
			bool observation_real, TransportMode transport_mode, unsigned nbr_observations=INT_MAX);
	void initiateNetworks();
	void initCostFunctions();

	vector<string> getObservationFiles();
	void readSyntheticObservations();
	void readRealObservations();
	void readObservations();

	void sampleChoiceSetWithOd(const unsigned count);
	void sampleChoiceSet();

	void simulateObservations();
	/**
	 * Enumerate paths with MH sampling algorithm.
	 * It is only used in real network where the actual universal path set can not be enumerated.
	 * It uses parameters with higher variances (mh_link_scale=0.1).
	 * Record a path whenever a shuffle occurs.
	 * WARMUP_ITERATIONS 0, SAMPLEINTERVAL_ELEMENT 1, SAMPLE_COUNT 1000, 000.
	 *
	 * @return a choice set as universal_choice_set.kml in the observationDirecotry.
	 */
	void enumerateMHPaths();

	void readChoiceSetForObservations();
	virtual ~patExperimentBed();
	void writeBiogeme();
protected:
	 string m_experiment_folder;
	 string m_observation_folder;
	 string m_choice_set_foler;

	bool m_network_real;
	bool m_observation_real;

	unsigned m_nbr_observations;

	const patRandomNumber m_rnd;

	string m_algorithm;

	TransportMode m_transport_mode;
	patLinkAndPathCost* m_mh_router_link_cost;
	MHWeightFunction* m_mh_weight_function;
	patLinkAndPathCost* m_rw_router_link_cost;
	patUtilityFunction* m_utility_function;
	patNetworkEnvironment* m_network_environment;

	std::vector<patObservation> m_observations;

	MHPathGenerator* m_mh_path_generator;
	RWPathGenerator* m_rw_path_generator;

	std::map<const patMultiModalPath, double> m_obs_path_probas;
	std::map<const patMultiModalPath, double> m_path_size;
};

#endif /* PATEXPERIMENTBED_H_ */