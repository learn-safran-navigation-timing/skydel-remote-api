
#include "RemoveAllMultipathForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveAllMultipathForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveAllMultipathForSV::CmdName = "RemoveAllMultipathForSV";
    const char* const RemoveAllMultipathForSV::Documentation = "Disable all multipath for the specified satellite.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------------------------------------------\n"
      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId   int    The satellite's SV ID\n"
      "Reset  bool   Reset attributes (PSR offset, power loss, Doppler shift and carrier phase offset are set to zero)";
    const char* const RemoveAllMultipathForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveAllMultipathForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveAllMultipathForSV);


    RemoveAllMultipathForSV::RemoveAllMultipathForSV()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveAllMultipathForSV::RemoveAllMultipathForSV(const std::string& system, int svId, bool reset)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setReset(reset);
    }

    RemoveAllMultipathForSVPtr RemoveAllMultipathForSV::create(const std::string& system, int svId, bool reset)
    {
      return std::make_shared<RemoveAllMultipathForSV>(system, svId, reset);
    }

    RemoveAllMultipathForSVPtr RemoveAllMultipathForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveAllMultipathForSV>(ptr);
    }

    bool RemoveAllMultipathForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Reset"])
        ;

    }

    std::string RemoveAllMultipathForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveAllMultipathForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Reset"}; 
      return names; 
    }


    int RemoveAllMultipathForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveAllMultipathForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RemoveAllMultipathForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int RemoveAllMultipathForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void RemoveAllMultipathForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool RemoveAllMultipathForSV::reset() const
    {
      return parse_json<bool>::parse(m_values["Reset"]);
    }

    void RemoveAllMultipathForSV::setReset(bool reset)
    {
      m_values.AddMember("Reset", parse_json<bool>::format(reset, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
