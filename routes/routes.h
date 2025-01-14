#ifndef ROUTES_H
#define ROUTES_H

#include <crow.h>

using namespace crow;

void setupUtilitiesRoutes(SimpleApp& app);
void setupAccountsRoutes(SimpleApp& app);

#endif