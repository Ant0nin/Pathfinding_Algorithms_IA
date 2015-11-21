#pragma once

#include <string>

struct ExecutionResult {
	std::string controllerName;
	Noeud *arrive;
	std::list<Noeud*> *cheminement;
	time_t *duration;
};