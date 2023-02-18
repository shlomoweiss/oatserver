﻿// oat.cpp : Defines the entry point for the application.
//
#include "../controller/mycontroller.hpp"
#include "oat.h"

#include "oatpp/network/Server.hpp"

#include <iostream>
#include <thread>
#include <windows.h>


void run() {

	/* Register Components in scope of run() method */
	AppComponent components;

	/* Get router component */
	OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

	/* Create MyController and add all of its endpoints to router */
	router->addController(std::make_shared<MyController>());

	/* Get connection handler component */
	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

	/* Get connection provider component */
	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

	/* Create server which takes provided TCP connections and passes them to HTTP connection handler */
	oatpp::network::Server server(connectionProvider, connectionHandler);

	/* Print info about server port */
	OATPP_LOGI("MyApp", "Server running on port %s", connectionProvider->getProperty("port").getData());

	/* Run server */
	server.run();

}



using namespace std;

int main()
{
	cout << "Hello CMake." << endl;

	oatpp::base::Environment::init();
	std::thread t(&run);   // t starts running
	std::cout << "main thread\n";
	//t.join();

	
	while(true)
	{
		Sleep(10);
	}
	/* Print how much objects were created during app running, and what have left-probably leaked */
	/* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
	std::cout << "\nEnvironment:\n";
	std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
	std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";

	oatpp::base::Environment::destroy();
	return 0;
}
