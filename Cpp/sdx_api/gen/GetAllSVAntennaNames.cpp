
#include "GetAllSVAntennaNames.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSVAntennaNames
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSVAntennaNames::CmdName = "GetAllSVAntennaNames";
    const char* const GetAllSVAntennaNames::Documentation = "Get a list of all space vehicle antenna names.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ --------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const GetAllSVAntennaNames::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllSVAntennaNames);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllSVAntennaNames);


    GetAllSVAntennaNames::GetAllSVAntennaNames()
      : CommandBase(CmdName, TargetId)
    {}

    GetAllSVAntennaNames::GetAllSVAntennaNames(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    GetAllSVAntennaNamesPtr GetAllSVAntennaNames::create(const std::string& system)
    {
      return std::make_shared<GetAllSVAntennaNames>(system);
    }

    GetAllSVAntennaNamesPtr GetAllSVAntennaNames::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllSVAntennaNames>(ptr);
    }

    bool GetAllSVAntennaNames::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetAllSVAntennaNames::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllSVAntennaNames::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int GetAllSVAntennaNames::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllSVAntennaNames::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllSVAntennaNames::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
