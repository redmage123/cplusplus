// CppPromisesFutures.cpp : Defines the entry point for the console application.

#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iterator>
#include <functional>
#include <exception>

// Small class to model a travel agent who can get a price on a trip

class TravelAgent {
    std::string agentName;
// Paired.  You are only allowed to retrieve the promise's future once.
    std::promise<int> price;
    std::future<int> eventualPrice;
    int delay;
    public:
        TravelAgent(std::string agentName, int delay) : agentName(agentName), eventualPrice(price.get_future()), delay(delay) {}

// Getting a price on a trip may take a while - imagine it call out to a web service
        void getPrice(std::string destination) {
           std::this_thread::sleep_for(std::chrono::milliseconds(delay));
           price.set_value(delay);
        }

        /* This function will return a true or false condition depending on whether the future status is ready or not. 
         * Note that we use a value of zero so we're not actually blocked.
        */

        bool priceNotYetAvailable() {
           return eventualPrice.wait_for(std::chrono::seconds(0)) != std::future_status::ready;
        }


        /* Here we return the actual price because the future_status::ready variable is now true.
         * Note that we guard against a possible condition where, in fact, it isn't ready
         * for some reason and throw an exception in that case.
        */
        int getPrice() {
            if (priceNotYetAvailable()) {
                throw std::logic_error("The price is not yet available");
            }
            return eventualPrice.get();
        }

        // A standard getter for the agentName field.
        std::string getName() {
            return (agentName); 
        }

};

                                                                                                                                                                                                                              

int main() {

// Set up a few travel agents with random delays and prices

    std::vector<TravelAgent> agents;
    agents.push_back(TravelAgent("George and Richard", std::rand() % 2000));
    agents.push_back(TravelAgent("Bob and Mike", std::rand() % 2000));
    agents.push_back(TravelAgent("Ben and Maurice", std::rand() % 2000));
    agents.push_back(TravelAgent("Braun and Bob", std::rand() % 2000));

/* Price up a trip.  All the travel agencies getPrice methods run 'simultaneously' on separate threads
 * The overall time should approximate to the time of the longest.  Synchronous calls would take the sum of all of them.
*/

    std::string dest("New Delhi");
    std::cout << "Just pricing your trip to " << dest << std::endl;
    std::vector<std::thread> threads;
    for (auto& agent : agents) {
        threads.push_back(std::thread([&] { agent.getPrice(dest); }));
    }

/* Here we're waiting for the delay to end per agent. The while loop only exits when
 * all of the agents have had returned prices. 
 * While waiting, we suggest that you take a trip elsewhere.  We hear that Hawaii is nice.
*/
    while (agents.end() != std::find_if(agents.begin(), agents.end(), [](TravelAgent& agent) { return agent.priceNotYetAvailable(); })) {
        std::cout << "We suggest that you take a trip somewhere else??? " << dest << " is always too hot!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
     }

    std::cout << "Ok.  I give in.  Here are some prices:" << std::endl;

/* The previous while loop has ended, so all of the agents prices are in...So, let's
 * print out the prices that were supplied by the promise/future.
*/
    for (auto& agent : agents) {
        std::cout << agent.getName() << " want " << agent.getPrice() << std::endl;
    }

// Finally, let's join on the threads.
    for (auto& thread : threads) {
        thread.join(); 
    }
    return 0;

}
