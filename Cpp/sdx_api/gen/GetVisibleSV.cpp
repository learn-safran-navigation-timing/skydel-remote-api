
#include "GetVisibleSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVisibleSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVisibleSV::CmdName = "GetVisibleSV";
    const char* const GetVisibleSV::Documentation = "Get a list of visible satellites' SV IDs within a system, returns a GetVisibleSVResult\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ---------------------------------------------------------------------------------------------\n"
      "System string The system, can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
    const char* const GetVisibleSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetVisibleSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetVisibleSV);


    GetVisibleSV::GetVisibleSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetVisibleSV::GetVisibleSV(const std::string& system)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
    }

    GetVisibleSVPtr GetVisibleSV::create(const std::string& system)
    {
      return std::make_shared<GetVisibleSV>(system);
    }

    GetVisibleSVPtr GetVisibleSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVisibleSV>(ptr);
    }

    bool GetVisibleSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetVisibleSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetVisibleSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System"}; 
      return names; 
    }


    int GetVisibleSV::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string GetVisibleSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetVisibleSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
