#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

#include "mqtt/async_client.h"

const std::string SERVER_ADDRESS("");
const std::string CLIENT_ID("");
const std::string TOPIC("");
const std::string USERNAME = "";
const std::string PASSWORD = "";

class callback : public virtual mqtt::callback
{
    void connection_lost(const std::string &cause) override
    {
        std::cout << "Connection lost: " << cause << std::endl;
    }

    void delivery_complete(mqtt::delivery_token_ptr token) override {}

    void message_arrived(mqtt::const_message_ptr msg) override {}
};

int main(int argc, char *argv[])
{
    /* Initialize the MQTT async client with the server address and client ID */
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);

    callback cb;
    client.set_callback(cb);

    auto connOpts = mqtt::connect_options_builder()
                        .clean_session()
                        .finalize();

    /* Set MQTT username and password in connection options */

    try
    {
        /* Attempt to connect to the MQTT server */

        while (true)
        {
            std::string payload = "Test, HELLO!";
            /* Create a message object with the defined payload and topic */
            // mqtt::message_ptr =

            /* Publish the message */

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        client.disconnect()->wait();
        std::cout << ">_ Disconnected" << std::endl;
    }
    catch (const mqtt::exception &exc)
    {
        std::cerr << ">_ Error: " << exc.what() << std::endl;
        return 1;
    }

    return 0;
}
