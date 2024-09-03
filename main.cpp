#include <boost/optional.hpp>
#include <string>
#include <vector>
#include <viam/sdk/robot/client.hpp>

using namespace viam::sdk;

std::string getenv_str(const char *name)
{
    return std::getenv(name);
}

int main()
{
    std::string host(getenv_str("VIAM_HOST"));
    Credentials credentials("api-key", getenv_str("VIAM_API_KEY"));
    DialOptions dial_opts;
    dial_opts.set_entity(getenv_str("VIAM_ENTITY_ID"));
    dial_opts.set_credentials(credentials);

    auto machine = RobotClient::at_address(host, Options(0, dial_opts));

    std::cout << "Resources:\n";
    for (const Name &resource : machine->resource_names())
    {
        std::cout << "\t" << resource << "\n";
    }

    return EXIT_SUCCESS;
}
